#include "shared_inner.h"

struct InnerResults1 InnerCalc0(double p0[]) {
    struct InnerResults1 ret;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            if (p0[0] < (i) || p0[0] > j) {
                ret.A += 1.0;
                ret.B += 1.5;
                ret.C += 1.6;
            }
            ret.A *= p0[0];
            ret.B /= p0[0];
            ret.C += p0[0];
        }
    }
    ret.D.A = p0[0] * 13.56;

    return ret;
}

struct InnerResults2 InnerCalc2(struct InnerResults0 p0, double p1, double p2) {
    struct InnerResults2 ret;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            if (p1 < (i) || p2 > j) {
                ret.A += 1.0;
                ret.B += 1.5;
                ret.C += 1.6;
            }
            ret.A *= p1;
            ret.B /= p2;
            ret.C += p0.A;
        }
    }
    return ret;
}

struct InnerResults3 InnerCalc3(struct InnerResults0 p0, double p1, double p2, double p3) {
    struct InnerResults3 ret;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            if (p1 < (i) || p2 > j) {
                ret.A += 1.0;
                ret.B += 1.5;
                ret.C += 1.6;
                ret.D += 1.6;
            }
            ret.A *= p1;
            ret.B /= p2;
            ret.C += p0.A;
            ret.D += p3;
        }
    }
    return ret;
}

struct InnerResults4 InnerCalc4(double p0[], double p1, double p2) {
    struct InnerResults4 ret;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            if (p2 < (i) || p1 > j) {
                ret.A += 1.0;
                ret.B += 1.5;
                ret.C += 1.6;
                ret.D += 1.6;
            }
            ret.A *= p2;
            ret.B /= p1;
            ret.C += p2;
            ret.D += p1;
        }
    }
    return ret;
}
