#include <iostream>

int main() {

long t_0 = 0;
long t_1 = 0;
long t_2 = 0;
long t_3 = 0;
long x = 0;
long y = 0;

blk0:
  asm(
      "  movq %[x], %%rax\n\t"
      "  movq %[const1], %%rbx\n\t"
      "  addq %%rbx, %%rax\n\t"
      "  movq %%rax, %[t_0]\n\t"
      : [t_0] "=g"(t_0)
      : [x] "g"(x),
			[const1] "g"(1)
      : "rax", "rbx", "cc");

  asm(
      "  movq %[t_0], %%rax\n\t"
      "  movq %[t_0], %%rbx\n\t"
      "  movq %%rax, %[x]\n\t"
      : [x] "=g"(x)
      : [t_0] "g"(t_0)
      : "rax", "rbx", "cc");

  asm(
      "  movq %[y], %%rax\n\t"
      "  movq %[const1], %%rbx\n\t"
      "  addq %%rbx, %%rax\n\t"
      "  movq %%rax, %[t_1]\n\t"
      : [t_1] "=g"(t_1)
      : [y] "g"(y),
			[const1] "g"(1)
      : "rax", "rbx", "cc");

  asm(
      "  movq %[t_1], %%rax\n\t"
      "  movq %[t_1], %%rbx\n\t"
      "  movq %%rax, %[y]\n\t"
      : [y] "=g"(y)
      : [t_1] "g"(t_1)
      : "rax", "rbx", "cc");

if (x == 0)


goto blk2;
 else 
 goto blk6;



blk2:
if (y == 0)


goto blk4;
 else 
 goto blk5;



blk6:
  asm(
      "  movq %[const3], %%rax\n\t"
      "  movq %[const3], %%rbx\n\t"
      "  movq %%rax, %[y]\n\t"
      : [y] "=g"(y)
      : [const3] "g"(3)
      : "rax", "rbx", "cc");

goto blk1;



blk4:
  asm(
      "  movq %[const1], %%rax\n\t"
      "  movq %[const1], %%rbx\n\t"
      "  movq %%rax, %[x]\n\t"
      : [x] "=g"(x)
      : [const1] "g"(1)
      : "rax", "rbx", "cc");

goto blk3;



blk5:
  asm(
      "  movq %[const2], %%rax\n\t"
      "  movq %[const2], %%rbx\n\t"
      "  movq %%rax, %[y]\n\t"
      : [y] "=g"(y)
      : [const2] "g"(2)
      : "rax", "rbx", "cc");

goto blk3;



blk1:

exit(0);

blk3:
goto blk1;



}
