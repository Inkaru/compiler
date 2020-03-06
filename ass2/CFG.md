```graphviz
digraph {
node [shape=box];
BB0x564484c59ed0 [label="blk0
printf("enter a number:");
std::cin >> t_0;
n  = t_0 ;
factorial  = 1.0 ;
x  = 1.0 ;
i = 2.0;
goto blk1;
"];
BB0x564484c59ed0 -> BB0x564484c5a2a0
BB0x564484c5a2a0 [label="blk1
if(i<=n) 
	goto blk3;
else 
	goto blk2;
"];
BB0x564484c5a2a0 -> BB0x564484c5a400
BB0x564484c5a2a0 -> BB0x564484c5a390
BB0x564484c5a390 [label="blk2
printf("factorial of  ");
printf("%f ", n);
printf(" is  ");
printf("%f \n", x);
"];
BB0x564484c5a400 [label="blk3
t_1 = x * i;
x  = t_1 ;
i++;
goto blk1;
"];
BB0x564484c5a400 -> BB0x564484c5a2a0
}
```