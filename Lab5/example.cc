/* This strange and alien code is easier to generate from C than it
	   was to type in manually. It does something slightly magic: this is an
	   executable intermediate point during the assignment. Normally if you
	   are 50% through implementing a compiler there is nothing that works
	   enough to be tested. Here, you are at a stage where big chunks of the
	   code-generation are working and they are being embedded in another language
	   for testing. The theory behind it is something called language-embedding:
	   a particular subset of the assembly generated is isomorphic to structures
	   in the C code so can be embedded piece-wise in this style. Practically, it
	   is easier to understand - if you develop the compiler in small pieces like
	   this then you can test parts of it before other parts are complete. This
	   will dramatically improve your development cycle. The template that you
	   have been given is simply an isomorphic projection of the IR semantics
	   onto a piece of code that is compatible with the implied constraints
	   of injecting code into the compiled output of this version of gcc.
	   (or in English: it is a way to simulate the 3-address instruction
	    using a bit of code that is compatible with the code-generator inside
	    gcc so that you can mix up bits of compiled and uncompiled (raw-C)
	    code in the same program).
	   The trick comes from: https://link.springer.com/chapter/10.1007%2F11561347_5
	*/
#include <iostream>

int main()
{
  // Use long rather than int: gcc on linux outputs 4/8/8 memory model.
  long x = 10, y = 0, _t0 = 17, _t1 = 17, _t2 = 17, _t3 = 17, _t4 = 17;
block0:
  // Expand:  _t0 := x + 1
  asm(
      "  movq %[x], %%rax\n\t"
      "  movq %[const1], %%rbx\n\t"
      "  addq %%rbx, %%rax\n\t"
      "  movq %%rax, %[_t0]\n\t"
      : [_t0] "=g"(_t0)
      : [x] "g"(x),
        [const1] "g"(1)
      : "rax", "rbx", "cc");

  // Expand:  x := _t0 c _t0
  asm(
      "  movq %[_t0], %%rax\n\t"
      "  movq %[_t0], %%rbx\n\t"
      // copy is a dummy operation
      "  movq %%rax, %[x]\n\t"
      : [x] "=g"(x)
      : [_t0] "g"(_t0)
      : "rax", "rbx", "cc");

  // Block: x = 10 block2 / block1 otherwise
  std::cout << "Debugging example, end of block0 x=" << x << std::endl;
  if (x == 10)
    goto block1;
  else
    goto block2;

// this is the true-branch of the if in the test-case
block1:

  // Expand:  _t1 := x + 1
  asm(
      "  movq %[x],      %%rax\n\t"
      "  movq %[const1], %%rbx\n\t"
      "  addq %%rbx,     %%rax\n\t"
      "  movq %%rax,     %[_t1]\n\t"
      : [_t1] "=g"(_t1)
      : [x] "g"(x),
        [const1] "g"(1)
      : "rax", "rbx", "cc");

  // Expand:  y := _t1 c _t1
  asm(
      "  movq %[_t1], %%rax\n\t"
      "  movq %[_t1], %%rbx\n\t"
      // copy is a dummy operation
      "  movq %%rax, %[y]\n\t"
      : [y] "=g"(y)
      : [_t1] "g"(_t1)
      : "rax", "rbx", "cc");
  std::cout << "Debugging example, end of block1 y=" << y << std::endl;

  goto block3;

block2:
  // this is the false-branch of the if in the test-case

  // Expand:  _t2 := x * 2
  asm(
      "  movq %[x],      %%rax\n\t"
      "  movq %[const2], %%rbx\n\t"
      "  mulq %%rbx\n\t"
      "  movq %%rax, %[_t2]\n\t"
      // Dropping upper 64-bits of product in rdx: 64-bits is enough result for anyone :)
      : [_t2] "=g"(_t2)
      : [x] "g"(x),
        [const2] "g"(2)
      : "rax", "rbx", "rdx", "cc");

  asm(
      // Expand:  y := _t2 c _t2
      "  movq %[_t2], %%rax\n\t"
      "  movq %[_t2], %%rbx\n\t"
      // copy is a dummy operation
      "  movq %%rax, %[y]\n"
      : [y] "=g"(y)
      : [_t2] "g"(_t2)
      : "rax", "rbx", "cc");
  std::cout << "Debugging example, end of block2 y=" << y << std::endl;
  goto block3;

// Merge control-flows after if-then-else
block3:

  asm(
      // Expand: _t3 := y + 1
      "  movq %[y],  %%rax\n\t"
      "  movq $1,    %%rbx\n\t"
      "  addq %%rbx, %%rax\n\t"
      "  movq %%rax, %[_t3]\n\t"
      : [_t3] "=g"(_t3)
      : [y] "g"(y),
        [const1] "g"(1)
      : "rax", "rbx", "cc");

  asm(
      // Expand: x := _t3 c _t3
      "  movq %[_t3], %%rax\n\t"
      "  movq %[_t3], %%rbx\n\t"
      // copy is a dummy operation
      "  movq %%rax, %[x]\n\t"
      : [x] "=g"(x)
      : [_t3] "g"(_t3)
      : "rax", "rbx", "cc");
  std::cout << "Debugging example, final x=" << x << std::endl;
}