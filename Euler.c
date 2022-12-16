#include<stdio.h>

double solve(double x, double y){
    return x+y;
}

void main(){
    double n;
    scanf("%lf", &n);

    double prev = 0.0, curr = 0.0;
    double x, y;
    scanf("%lf%lf", &x, &y);

    double h = 0.1;
    prev = y;

    for(int i = 0; i < n; i++){
        curr = prev + h*solve(x+i*h, prev);
        prev = curr;
    }   

    printf("\n\n%lf\n\n", curr);
}