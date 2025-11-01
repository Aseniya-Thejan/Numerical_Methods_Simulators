#include <stdio.h>
#include <math.h>

#define f(x) (32*exp(0.09 * x) - 39)

int isvalid(double a,double b)
{
    if( f(a) * f(b) < 0){
        return 1;
    }
    else
    {
        return 2;
    }
}
double finderror(double approximation, double prewapprocimation) {
    double result = fabs((approximation - prewapprocimation) /(approximation)) * 100;
    return result;
}

int main()
{
    double error=100;
    double upper;
    double errorthreshold;
    int sigd;
    int iteration=1;
    double approximation;
    double prewapproximation=0;
    printf("Enter the upper bracket :-");
    scanf("%lf",&upper);
    double lower;
    printf("Enter the lover bracket :-");
    scanf("%lf",&lower);
    if (f(upper)==0)
    {
        printf("Root is %lf\n", upper);
        return 0;
    }
    if (f(lower)==0)
    {
        printf("Root is %lf\n", lower);
        return 0;
    }
    printf("Enter the required no of significant digits required :-");
    scanf("%d",&sigd);
    errorthreshold=(0.5*pow(10,(2-sigd)));
    printf("X-lower = %lf\n X-upper = %lf\n",lower,upper);
    while (isvalid(upper,lower)==2)
    {
        printf("No solution between entered bounds. Please re enter upper and lower bounds\n");
        printf("Enter the upper bracket :- ");
        scanf("%lf",&upper);
        printf("Enter the lover bracket :- ");
        scanf("%lf",&lower);
    }
    printf("You have chosen two guesses correctly.\n");
    printf("\t   |   Lower   |   Upper   |   Approximation   |   Error   |\n");
    printf("\t   ---------------------------------------------------------\n");
    do
    {
        approximation = (upper+lower)/2;
        if(iteration==1)
        {
            printf("\t    %lf   %lf \t%lf \t  N/A  \n",lower,upper,approximation);
        }
        else{
            printf("\t    %lf   %lf \t%lf \t%lf%%\n",lower,upper,approximation,error);
        }
        if (f(approximation)==0)
        {
            break;
        }
        else if(isvalid(lower,approximation)==1)
        {
            upper=approximation;
        }
        else if(isvalid(lower,approximation)==2)
        {
            lower=approximation;
        }
        error=finderror(approximation,prewapproximation);
        prewapproximation = approximation;
        iteration++;
    }while(error>=errorthreshold);
    printf("\t    %lf   %lf \t%lf \t%lf%%\n",lower,upper,approximation,error);
    printf("\n");
    printf("Root is %lf\n",approximation);
    return 0;
}