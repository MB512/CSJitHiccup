 * Crashing code is in CppLib/shared.cpp line 50
   * It is a quite simple method:
   * calling some inner calculations (conained in shared_inner.cpp)
   * doing some math (+ - * / pow)
   * returning a struct
 * Behaviour in DotNet 8 is strange:
   * Debug build is working
   * Release build is working for > 1000 calls
   * JIT stage 2 Assembly code crashes
   * When adding a break point in release build to inspect
     * No problem, no exception
     * Removing break point and continue execution => NO exception !

Assembly code on crash:

        ret.I = K;
    00007FF87B39ABC7  vmovsd      xmm1,qword ptr [rsp+398h]  
    00007FF87B39ABD0  vmovsd      qword ptr [rsp+468h],xmm1  
        ret.L = 1e3 / Z / D * ((-F + J) / (pow(J, 2) - R * F));
    00007FF87B39ABD9  vmovsd      xmm1,qword ptr [<Module>.MainCalc(Double*, Double, Double)+0468h (07FF87B39AD38h)]  
    00007FF87B39ABE1  vmovaps     xmm0,xmm7  
    00007FF87B39ABE5  call        00007FF8DAECF140  
    00007FF87B39ABEA  vsubsd      xmm1,xmm7,mmword ptr [rsp+300h]  
    00007FF87B39ABF3  vmulsd      xmm2,xmm8,mmword ptr [rsp+300h]  
    00007FF87B39ABFC  vsubsd      xmm2,xmm0,xmm2  
    00007FF87B39AC00  vdivsd      xmm1,xmm1,xmm2  
    00007FF87B39AC04  vmovsd      xmm2,qword ptr [<Module>.MainCalc(Double*, Double, Double)+0470h (07FF87B39AD40h)]  
    00007FF87B39AC0C  vdivsd      xmm2,xmm2,mmword ptr [rsp+2D0h]  
    00007FF87B39AC15  vmulsd      xmm1,xmm1,xmm2  
    00007FF87B39AC19  vmovsd      qword ptr [rsp+480h],xmm1  
        ret.K = (F - pow(J, 2) / R) / S;
    00007FF87B39AC22  vdivsd      xmm0,xmm0,xmm8  
    00007FF87B39AC27  vmovsd      xmm0,qword ptr [rsp+300h]  
    00007FF87B39AC30  vmovdqu     xmm0,xmmword ptr [rax]  
    00007FF87B39AC34  vmovdqu     xmmword ptr [rsp+410h],xmm0  
    00007FF87B39AC3D  mov         rax,qword ptr [rax+10h]  
    00007FF87B39AC41  mov         qword ptr [rsp+420h],rax  
    00007FF87B39AC49  vmovsd      xmm0,qword ptr [rsp+410h]  
    00007FF87B39AC52  vdivsd      xmm0,xmm0,mmword ptr [rsp+2E8h]  
    00007FF87B39AC5B  vmovsd      qword ptr [rsp+478h],xmm0  

It is crashing on the following line:

    00007FF87B39AC30  vmovdqu     xmm0,xmmword ptr [rax]

I have seen in debugging that the previous call at address 00007FF87B39ABE5 (which seams to be the call for pow or Math.Pow) is changing the rax register and that the optimized assembly in JIT Stage 2 seams to think that this call schould not change rax.
