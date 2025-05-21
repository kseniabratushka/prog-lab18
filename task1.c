#include <stdio.h>

// Оголошення функцій
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double a, double b);

int main() 
{
    system("chcp 65001");
    double (*functions[5])(double, double) = {
        add,
        subtract,
        multiply,
        divide,
        power
    };
    
    double x, y;
    printf("Введіть два числа: ");
    scanf("%lf %lf", &x, &y);
    
    for (int i = 0; i < 5; i += 1) 
    {
        double result = functions[i](x, y);
        printf("Функція %d: результат = %.2lf\n", i+1, result);
    }
    
    return 0;
}

double add(double a, double b) 
{
    return a + b;
}

double subtract(double a, double b) 
{
    return a - b;
}

double multiply(double a, double b) 
{
    return a * b;
}

double divide(double a, double b) 
{
    if (b != 0) 
    {
        return a / b;
    } 
    else 
    {
        printf("Помилка: ділення на нуль!\n");
        return 0;
    }
}

double power(double a, double b) 
{
    double result = 1;
    for (int i = 0; i < b; i += 1) 
    {
        result *= a;
    }
    return result;
}