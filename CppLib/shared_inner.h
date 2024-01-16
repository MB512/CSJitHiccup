#pragma once

struct InnerResults0
{
    double A;
    double B[59];
    double C[19];
};

struct InnerResults1
{
    double A;
    double B;
    double C;
    struct InnerResults0 D;
};

struct InnerResults1 InnerCalc0(double p0[]);

struct InnerResults2 {
    double A;
    double B;
    double C;
};

struct InnerResults2 InnerCalc2(struct InnerResults0 p0, double p1, double p2);

struct InnerResults3
{
    double A;
    double B;
    double C;
    double D;
};

struct InnerResults3 InnerCalc3(struct InnerResults0 p0, double p1, double p2, double p3);

struct InnerResults4 {
    double A;
    double B;
    double C;
    double D;
};

struct InnerResults4 InnerCalc4(double p0[], double p1, double p2);
