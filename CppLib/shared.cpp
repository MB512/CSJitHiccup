#include "shared.h"
#include "shared_inner.h"

#include "math.h"

struct MainCalcResults MainCalc(double x21[], double p, double T) {
    static const double Z = 1.1;

    struct InnerResults1 init_res = InnerCalc0(x21);
    double A = init_res.A;
    double B = init_res.B;
    double C = init_res.C;

    struct InnerResults2 DZofPT_res = InnerCalc2(init_res.D, p, T);
    double D = DZofPT_res.A;
    double E = DZofPT_res.B;
    double F = DZofPT_res.C;

    struct InnerResults3 DFofDT_res = InnerCalc3(init_res.D, D, T, E);
    double G = DFofDT_res.A;
    double H = DFofDT_res.B;
    double I = DFofDT_res.C;
    double J = DFofDT_res.D;

    struct InnerResults4 cp0_res = InnerCalc4(x21, T, D);
    double K = cp0_res.A;
    double L = cp0_res.B;
    double M = cp0_res.C;
    double N = cp0_res.D;

    struct InnerResults2 DZofPT0_res = InnerCalc2(init_res.D, 1.2, 1.3);
    double O = DZofPT0_res.B;

    double P = G + L;
    double Q = H + M;
    double R = I + N;
    double S = E;

    struct MainCalcResults ret;

    ret.A = E;
    ret.C = D * A;
    ret.D = Z * T / A * Q;
    ret.E = Z * T / A * (Q + S);
    ret.F = Z / A * (Q - F);
    ret.G = -Z * R / A;
    ret.H = Z / A * (-R + (J * J) / F);
    ret.I = K;
    ret.L = 1e3 / Z / D * ((-F + J) / (pow(J, 2) - R * F));
    ret.K = (F - pow(J, 2) / R) / S;
    ret.J = sqrt(1e3 * Z * T / A * (F - pow(J, 2) / R));
    ret.B = E / O;

    return ret;
}