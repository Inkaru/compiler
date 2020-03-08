#include <iostream>
#include <cmath>

int main() {

double t_0 = 0;
double t_1 = 0;
double t_2 = 0;
double t_3 = 0;
double t_4 = 0;
double t_5 = 0;
double t_6 = 0;
double t_7 = 0;

blk0:
t_0 = 4.0 * 2.0;
t_1 = pow(2.0,t_0);
t_2 = t_1 + 10.0;
t_3 = 2.0 * 6.0;
t_4 = t_2 - t_3;
t_5 = 1.0 / 4.0;
t_6 = t_4 + t_5;
t_7 = t_6 * 2.0;
printf("%f \n", t_7);

exit(0);

}
