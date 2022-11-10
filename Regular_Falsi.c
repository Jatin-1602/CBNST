#include<stdio.h>
#include<math.h>
#define MAX_ITER 100000

double fun(double x){
    double y = (x*x*x) - (2*x) - 5;
    return y;
}

double value_c(double a, double b){
    double c = (a*fun(b) - b*fun(a)) / (fun(b) - fun(a));
    return c;
}

void main(){
    // f(x) = x*x*x - 2*x - 5
    int a = 0, b = 1;
    double fa = fun(a), fb = fun(b);
    int x = 5;
    while (fa*fb >= 0){
        b++;
        fa = fb;
        fb = fun(b);
    }
    a = b-1;
    int i = 0;
    double c = 0;
    double fc = 0;
    while (i < MAX_ITER){
        c = value_c(a, b);
        fc = fun(c);
        if (fc < 0)
            a = c;
        else if (fc > 0)
            b = c;
        else   
            break;
        i++;
    }
    printf("\nRoot = %lf\n", c);
}