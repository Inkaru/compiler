#include <iostream>
#include <cmath>

int main() {

double hasChanged = 0;
double i = 0;
double itemCount = 0;
double t_0 = 0;
double t_1 = 0;
double t_10 = 0;
double t_11 = 0;
double t_12 = 0;
double t_13 = 0;
double t_14 = 0;
double t_2 = 0;
double t_3 = 0;
double t_4 = 0;
double t_5 = 0;
double t_6 = 0;
double t_7 = 0;
double t_8 = 0;
double t_9 = 0;

blk0:
double list[12] = {5,6,1,2,9,14,2,15,6,7,8,97};
t_0 = 12;
itemCount  = t_0 ;
goto blk2;

exit(0);

blk2:
hasChanged  = false ;
t_1 = itemCount - 1.0;
itemCount  = t_1 ;
i = 1.0;
goto blk3;

blk3:
if(i<=itemCount) 
	goto blk5;
else 
	goto blk4;

blk5:
t_2=list[(int)i];
t_4 = i + 1.0;
t_3=list[(int)t_4];
t_5 = t_2 > t_3;
if(t_5 != 0)
	goto blk7;
else
	goto blk6;

blk4:
t_12 = hasChanged == false;
if(t_12!= 1)
	goto blk2;
else
	goto blk1;

exit(0);

blk7:
t_6=list[(int)i];
t_8 = i + 1.0;
t_7=list[(int)t_8];
t_10 = i + 1.0;
t_9=list[(int)t_10];
t_11=list[(int)i];
t_6 t_7  = t_9 t_11 ;
hasChanged  = true ;
goto blk6;

blk6:
i++;
goto blk3;

exit(0);

blk1:
t_13 = 12;
i = 1.0;
goto blk8;

blk8:
if(i<=t_13) 
	goto blk10;
else 
	goto blk9;

blk10:
t_14=list[(int)i];
printf("%f \n", t_14);
i++;
goto blk8;

blk9:

exit(0);

}
