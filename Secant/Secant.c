#include <stdio.h>
#include <math.h>

#define f(x) (pow(x,3)-(5*(x))-5)

double nextapproximation(double x1, double x2)
{
    return (x2-((f(x2)*(x2-x1))/(f(x2)-f(x1))));
}

double finderror(double approximation, double nextapprocimation) {
    double result = fabs((nextapprocimation - approximation) /(nextapprocimation)) * 100;
    return result;
}

int main()
{
    double x1;
    double x2;
    double approximation;
    double error=100;
    double errorthreshold;
    int sigd;
    int iteration=1;
    printf("Enter the first guess :- ");
    scanf("%lf",&x1);  
    if(f(x1)==0)
    {
        printf("Root is %lf\n", x1);
        return 0;
    }
    printf("Enter the Second guess :- ");
    scanf("%lf",&x2);if(f(x2)==0)
    {
        printf("Root is %lf\n", x2);
        return 0;
    }
    printf("Enter the required no of significant digits required :-");
    scanf("%d",&sigd);
    errorthreshold=(0.5*pow(10,(2-sigd)));
    printf("\t   |   x1     |     x2     |   Approximation   |   Error   |\n");
    printf("\t   ---------------------------------------------------------\n");
    while(error>=errorthreshold)
    {
        approximation=nextapproximation(x1,x2);
        error=finderror(x2,approximation);
        if(iteration==1)
        {
            printf("\t    %lf   %lf \t%lf \t  N/A  \n",x1,x2,approximation);
        }
        else{
            printf("\t    %lf   %lf \t%lf \t%lf%%\n",x1,x2,approximation,error);
        }
        if (f(approximation)==0)
        {
            break;
        }
        x1=x2;
        x2=approximation;
        iteration++;
    }
    printf("\t    %lf   %lf \t%lf \t%lf%%\n",x1,x2,approximation,error);
    printf("\n");
    printf("Root is %lf\n", approximation);
    return 0;
}