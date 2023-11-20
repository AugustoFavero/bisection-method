#include <stdio.h>
#include <math.h>

float f(float x){
    return (x*x - x - 2.0);
}

int main(void)
{
    float a = 0, b = 0, c = 0, x0 = 0;
    int cont = 0;
    int Ni = 100;
    float l = 0.001;
    float t = 0.0001;

    printf("\nInsira o ponto 'a' do intervalo entre [a;b]: \n");
    scanf("%f", &a);
    printf("\nInsira o ponto 'b' do intervalo entre [a;b]: \n");
    scanf("%f", &b);

    c = b - a;
    x0 = (a + b)/2.0;

    while(c > 1 || fabs(f(x0)) > t){

        if(f(a)*f(x0) < 0.0){
            b = x0;
        }
        if(f(a)*f(x0) > 0.0){
            a = x0;
        }

        c = b - a;
        x0 = (a + b)/2.0;
        cont++;
        if(cont >= Ni){
        break;     
        }
    }

    printf("\nRaiz: %f\nInteracoes: %d\nf(%f) = %f \n",x0,cont,x0,f(x0));

    return 0;
}