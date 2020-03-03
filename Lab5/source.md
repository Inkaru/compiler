```graphviz
digraph {
node [shape=box];
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
      "  movq %[y], %%rax\n\t"
      "  movq %[const1], %%rbx\n\t"
      "  addq %%rbx, %%rax\n\t"
      "  movq %%rax, %[t_1]\n\t"
      : [t_1] "=g"(t_1)
      : [y] "g"(y),
			[const1] "g"(1)
      : "rax", "rbx", "cc");

blk2:

blk4:

blk3:

blk1:

blk5:

blk6:

}
```