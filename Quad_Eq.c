#include<stdio.h>
#include<math.h>

void main(){
    int a, b, c;
    scanf("%d%d%d",&a,&b,&c);

    int d = b*b - 4*a*c;

    if (d < 0){
        printf("Roots are Imaginary");
    }
    else{
        double r = (b*(-1) + (sqrt(d)))/(2*a);
        double s = (b*(-1) - (sqrt(d)))/(2*a);

        printf("Roots are : %lf , %lf", r, s);
    }
}