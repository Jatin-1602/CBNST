#include<stdio.h>

double solve(double x){
    double y = 1 / (1 + (x*x));
    return y;
}

void main(){
    int n, a, b;
    scanf("%d%d%d",&n, &a, &b);

    double h;
    h = (b-a) / n;

    double s = 0.0;

    for(int i = 1; i < n; i++){
        double y = solve(a + i*h);
        s += y;
    }

    s = (h/2)*(solve(a) + solve(b) + (2*s));

    printf("\n\n%lf\n\n", s);
}