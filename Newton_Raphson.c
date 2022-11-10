#include<stdio.h>
#include<math.h>

#define f "x*x*x - 3*x - 5"
#define fd "3*x*x - 3"

#define MAX_ITER 10000

double fun(double x){
    double y = x*x*x - 3*x - 5;
    return y;
}

double fun_derivative(double x){
    double y = 3*x*x - 3;
    return y;
}

double solve(double x){
    double y = x - (fun(x) / fun_derivative(x));
    return y;
}

void main(){
    int a = 0, b = 1;
    double fa = fun(a), fb = fun(b);

    while (fa*fb >= 0){
        b++;
        fa = fb;
        fb = fun(b);
    }
    double x = 0;
    a = b-1;
    if (abs(fa) < abs(fb))
        x = a;
    else
        x = b;
    int i = 0;
    double val = solve(x);

    while (i < MAX_ITER && val != 0){
        val = solve(val);
        i++;
    }
    printf("\nRoot = %lf\n", val);
}