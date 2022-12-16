#include<stdio.h>

double solve(double x){
    double y = x*x;
    return y;
}

void main(){
    double n, a, b;
    scanf("%lf%lf%lf", &n, &a, &b);

    double h;
    h = (b-a) / n;

    double s = 0.0;

    for(int i = 1; i < n; i++){
        double y = solve(a + i*h);
        if(i%2==0){
            s = s + 2*y;
        }
        else{
            s = s + 4*y;
        }
    }

    s = (h/3)*(solve(a) + solve(b) + s);

    printf("\n\n%lf\n\n", s);
}