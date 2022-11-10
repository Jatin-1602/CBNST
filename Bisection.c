#include<stdio.h>
#include<math.h>

double solve(int a, int b, int c, int d, double x){
    return a*pow(x,3)*(1.0) + b*pow(x,2)*(1.0) + c*x*(1.0) + d;
}

void main(){
    int a, b, c, d;
    printf("Enter a, b, c, d : ");
    scanf("%d%d%d%d", &a, &b, &c, &d);

    double u = 0, w = 1;
    double prev = d;
    double curr = solve(a, b, c, d, w);

    double curr_t = 0, prev_t = 0;

    while (prev*curr >= 0){
        w++;
        prev = curr;
        curr = solve(a, b, c, d, w);
    }

    u = w-1;
    double t = (u + w) / 2.0;
    printf("%lf ", t);

    double t_solve = solve(a, b, c, d, t);

    if (t_solve*prev < 0){
        curr = t_solve;
        w = t;
    }
    else{
        prev = t_solve;
        u = t;
    }
    curr_t = t;

    while (curr_t >= prev_t){
        double t = (u + w) / 2.0;
        printf("%lf ", t);
        double t_solve = solve(a, b, c, d, t);
        if (t_solve*prev < 0){
            curr = t_solve;
            w = t;
        }
        else{
            prev = t_solve;
            u = t;
        }
        prev_t = curr_t;
        curr_t = t;
    }

    printf("\n\nRoot lies b/w %lf and %lf", u, w);
}

// #include<stdio.h>
// #include<math.h>
// float fun(float x)
// {
//     return (x*x*x -4*x -9);
// }
// void bisection(float *x,int a,int b,int *itr)
// {
//     *x=(a+b)/2.0;
//     ++(*itr);
//     printf("iterations %3d X=%7.5f\n",*itr,*x);
// }
// int main()
// {
//     int itr=0,maxitr;
//     float a,b,aller,x1,x;
//     scanf("%f%f%f%d",&a,&b,&aller,&maxitr);
//     bisection(&x,a,b,&itr);
//     do
//     {
//         if(fun(a)*fun(x)<0)
//             b=x;
//         else
//             a=x;
//         bisection(&x1,a,b,&itr);
//         if(fabs(x1-x)<aller)
//         {
//             printf("iteration %d root %6.4f\n",itr,x1);
//             return 0;
//         }
//         x=x1;
//     }
//     while(itr<maxitr);
//     printf("insufficient itteration");
//     return 1;
// }