#include <stdio.h>
#include <math.h>

#define f(x) (pow(x,2)-(9*x)+10)
#define dy_dx(x) ((2*x)-9)

double nextapproximation(double x)
{
    return (x-(f(x)/dy_dx(x)));
}

double finderror(double approximation, double nextapprocimation) {
    double result = fabs((nextapprocimation - approximation) /(nextapprocimation)) * 100;
    return result;
}

int main()
{
    double x;
    double error=100;
    int iteration=1;
    double approximation;
    double errorthreshold;
    int sigd;
    printf("Enter the initial guess :- ");
    scanf("%lf",&x);
    if(f(x)==0)
    {
        printf("The root is %lf\n",x);
        return 0;
    }
    printf("Enter the required no of significant digits required :-");
    scanf("%d",&sigd);
    errorthreshold=(0.5*pow(10,(2-sigd)));
    printf("\t   |   X   |   Approximation   |   Error   |\n");
    printf("\t   -----------------------------------------\n");
    while(error>=errorthreshold)
    {
        approximation=nextapproximation(x);
        error=finderror(x,approximation);
        printf("\t    %lf   %lf \t%lf  \n",x,approximation,error);
        if (f(approximation)==0)
        {
            break;
        }
        x=approximation;
        iteration++;
    }
    printf("\t    %lf   %lf \t%lf  \n",x,approximation,error);
    printf("Root is %lf\n", approximation);
    return 0;
}