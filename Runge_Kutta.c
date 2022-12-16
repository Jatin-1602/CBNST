#include<stdio.h>

double solve(double x, double y){
    return x+y;
}

void main(){
    double x0, y0, h, x;
    scanf("%lf%lf%lf%lf", &x0, &y0, &h, &x);

    int n = (x - x0) / h;
    int i = 0;

    while (i < n){
        double k1 = h * solve(x0, y0);
        double k2 = h * solve(x0 + h/2, y0 + k1/2);
        double k3 = h * solve(x0 + h/2, y0 + k2/2);
        double k4 = h * solve(x0 + h, y0 + k3);

        double k = (k1 + 2*k2 + 2*k3 + k4) / 6;

        y0 = y0 + k;
        x0 = x0 + h;
        i++;
    }

    printf("\n\n%lf\n\n", y0);
}