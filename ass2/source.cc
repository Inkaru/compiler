#include <iostream>
#include <cmath>

int main() {

double factorial = 0;
double i = 0;
double n = 0;
double t_0 = 0;
double t_1 = 0;
double x = 0;

blk0:
printf("enter a number:");
std::cin >> t_0;
n  = t_0 ;
factorial  = 1.0 ;
x  = 1.0 ;
i = 2.0;
goto blk1;

blk1:
if(i<=n) 
	goto blk3;
else 
	goto blk2;

blk3:
t_1 = x * i;
x  = t_1 ;
i++;
goto blk1;

blk2:
printf("factorial of  ");
printf("%f ", n);
printf(" is  ");
printf("%f \n", x);

exit(0);

}
