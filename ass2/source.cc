#include <iostream>
#include <cmath>

int main() {

double i = 0;
double n = 0;
double t_0 = 0;
double t_1 = 0;
double t_2 = 0;

blk0:
printf("enter a number:");
std::cin >> t_0;
n  = t_0 ;
i = 2.0;
goto blk1;

blk1:
if(i<=n) 
	goto blk3;
else 
	goto blk2;

blk3:
t_1 = fmod(n,i);
t_2 = t_1 == 0.0;
if(t_2 != 0)
	goto blk5;
else
	goto blk4;

blk2:
printf("end \n");

exit(0);

blk5:
printf("%f ", i);
printf(" is a factor of  ");
printf("%f \n", n);
goto blk4;

blk4:
i++;
goto blk1;

exit(0);

}
