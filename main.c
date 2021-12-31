#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

//#define eps 0.0001

unsigned int method_select( void );
double f( double x );
void print_result(double a, double b, unsigned int n, double I );
double left_rectangle( double a, double b, unsigned int n );
double right_rectangle( double a, double b, unsigned int n );
double trapez( );
double simpsonn();


int main()
{
    unsigned int num_of_method; // 1 - left, 2 - right, 3 - trap, 4 - Simpson
    const double a = 0;
    const double b = 1;
    unsigned int n = 200;
    double I;
    double I1, I2;
    unsigned int N;
    double eps = 0.00001;


    num_of_method  =  method_select();

    if (num_of_method == 1 ){
        I = left_rectangle(a, b, n);
        print_result(a, b, n, I);

        eps=I2-I1;
       N = 0;
       do{
           N = N + 2;
           I1 = left_rectangle(a, b, n);
           I2 = left_rectangle(a, b, n+2);
        }while(  fabs(I2-I1) > eps );

        printf("\n\nN=%u,  I1(N)=%.8lf\n", N, I1);




    }
    else if( num_of_method == 2 ){
        I=right_rectangle(a, b, n);
        print_result(a, b, n, I);


       N = 0;
       do{
           N = N + 2;
           I1 = right_rectangle(a, b, n);
           I2 = right_rectangle(a, b, n+2);
        }while(  fabs(I2-I1) > eps );

        printf("\n\nN=%u,  I1(N)=%.8lf\n", N, I1);

    }else if( num_of_method == 3 ){
        do {
            I1 = trapez(a ,b ,n);
            N = N + 2;
            I2 = trapez(a ,b ,n);
            }
            while(  fabs(I2-I1) > eps );
            print_result(a ,b ,n ,I2);
            printf("\n\nN=%u,  I1(N)=%.8lf\n", N, I1);

    }
    else{

        do {
            double simpsonn();
            I1 = simpsonn(a ,b ,n);
            N = N + 2;
            I2 = simpsonn(a ,b ,n);
            }
            while(  fabs(I2-I1) > eps );
            print_result(a ,b ,n ,I2);
            printf("\n\nN=%u,  I1(N)=%.8lf\n", N, I1);
    }


    return 0;
}



//---------------------------------------------------------------------

unsigned int method_select(void)
{
    unsigned int temp;

    printf("\n\n Choose your method:\n1 - left \n2 - right \n3 - trap \n4 - Simpson\n>");
    scanf("%u", &temp);

    while(  temp < 1  ||   temp > 4 ){
        printf("\n!!!!Invalid data. Method: 1, 2, 3 or 4: ");
        scanf("%u", &temp);
    }

    switch(temp){
      case 1:
             printf("\nYou chose method of LEFT RECTANGLE");
             break;

      case 2:
             printf("\nYou chose  RIGHT RECTANGLE method");
             break;

      case 3:
             printf("\nYou chose  TRAPEZOID method");
             break;

      case 4:
             printf("\nYou chose  SIMPSON method");
             break;
    }

printf("\nPress any button to continue");
getch();

    return temp;
}

//-------------------------------------------------------------------

double f( double x )
{
    double y;

    y = 1/(4 + x*x);

    return y;
}


//---------------------------------------------------------------------


double left_rectangle(double a, double b, unsigned int n)
{
    double h;
    unsigned int k;
    double x;
    double sum = 0;

    h = ( b - a ) / n;
    x = a;

    for (k = 0;  k <= n-1;  k++ ){
      sum = sum + f(x);
      x = x + h;
    }

   return sum * h;
}

//-------------------------------------------------------------------


double right_rectangle(double a, double b, unsigned int n)
{
    double h;
    unsigned int k;
    double x;
    double sum = 0;

    h = ( b - a ) / n;
    x = a;

    for (k = 1;  k <= n;  k++ ){
      sum = sum + f(x);
      x = x + h;
    }

   return sum * h;
}

//-------------------------------------------------------------------

double trapez (double a, double b, unsigned int n) {
    double h = 0, x = 0, sum = 0;
    unsigned int k = 0;

    h = (b - a)/n;
    x = a;

    for (k = 0; k <= n-1; k++) {
        sum = sum + (f(x) + f(x + h))/2;
        x = x + h;
    }
    return h*sum;
}

//-------------------------------------------------------------------
double simpsonn (double a, double b, unsigned int n) {
double h = 0, x = 0, sum = 0;
    unsigned int k = 0;
    double parna_suma = 0 , neparna_suma = 0;
    h = (b - a)/n;
    x = a + h;
    for (k = 1; k <= n;k = k+2) {
        neparna_suma = neparna_suma + f(x);
        x = x + 2*h;
    }
    x = a + 2*h;
    for(k = 2; k <= n-2;k = k+2) {
        parna_suma = parna_suma + f(x);
        x = x + 2*h;
    }
    x = a;
    sum = f(x) + 4*neparna_suma + 2*parna_suma + f(x + n*h);
    return sum*h/3;
}
//-------------------------------------------------------------------


void print_result(double a, double b, unsigned int n, double I)
{
    system("cls");
    printf("\n***********************");
    printf("\n*       Results       *");
    printf("\n***********************\n");

    printf("a=%.2lf  b=%.2lf   n=%u    I = %.8lf", a, b, n, I);


}



