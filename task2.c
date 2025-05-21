#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void input_array(double *arr, int size, const char *name) 
{
    printf("Введіть %d елементів масиву %s:\n", size, name);
    for (int i = 0; i < size; i += 1) 
    {
        printf("%s[%d] = ", name, i);
        scanf("%lf", &arr[i]);
    }
}

void process_array(double *arr, int size, 
                  double (*func1)(double), double (*func2)(double),
                  double *sum, double *prod,
                  double *result1, double *result2, double *result3) 
{
    *sum = 0.0;
    *prod = 1.0;
    *result1 = 0.0;
    *result2 = 0.0;
    *result3 = 0.0;
    
    for (int i = 0; i < size; i += 1) 
    {
        *sum += arr[i];
        *prod *= arr[i];
    }

    for (int i = 0; i < size; i += 1) 
    {
        *result1 += arr[i] * func1(arr[i]);
        *result2 += arr[i] * func2(arr[i]);
        *result3 += arr[i] * sin(arr[i]);
    }
}

double exp_func(double x) { return exp(x); }
double cos_func(double x) { return cos(x); }
double sin_func(double x) { return sin(x); }
double tan_func(double x) { return tan(x); }
double abs_func(double x) { return fabs(x); }

int main() 
{
    system("chcp 65001");
    int n, m;
    printf("Введіть кількість елементів масиву z (n): ");
    scanf("%d", &n);
    printf("Введіть кількість елементів масиву β (m): ");
    scanf("%d", &m);
    
    double *z = (double*)malloc(n * sizeof(double));
    double *beta = (double*)malloc(m * sizeof(double));
    
    input_array(z, n, "z");
    input_array(beta, m, "β");

    double s_z, p_z, A, B, C;
    double s_beta, p_beta, D, E, F;
    
    process_array(z, n, exp_func, cos_func, &s_z, &p_z, &A, &B, &C);
    A = s_z * A;
    B = p_z * B;
    C = p_z * C;

    process_array(beta, m, sin_func, tan_func, &s_beta, &p_beta, &D, &E, &F);
    D = s_beta * D;
    E = p_beta * E;
    F = p_beta * F;
    
    double omega = (A + B + sin(C)) / (D + E + cos(F));
    
    printf("\nРезультати:\n");
    printf("A = %lf\n", A);
    printf("B = %lf\n", B);
    printf("C = %lf\n", C);
    printf("D = %lf\n", D);
    printf("E = %lf\n", E);
    printf("F = %lf\n", F);
    printf("ω = %lf\n", omega);
    
    free(z);
    free(beta);
    
    return 0;
}