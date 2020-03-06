```graphviz
digraph {
node [shape=box];
BB0x558458586a40 [label="blk0
printf("enter a number:");
std::cin >> t_0;
n  = t_0 ;
i = 2.0;
goto blk1;
"];
BB0x558458586a40 -> BB0x558458586cc0
BB0x558458586cc0 [label="blk1
if(i<=n) 
	goto blk3;
else 
	goto blk2;
"];
BB0x558458586cc0 -> BB0x558458586e20
BB0x558458586cc0 -> BB0x558458586db0
BB0x558458586db0 [label="blk2
printf("end \n");
"];
BB0x558458586e20 [label="blk3
t_1 = fmod(n,i);
t_2 = t_1 == 0.0;
if(t_2 != 0)
	goto blk5;
else
	goto blk4;
"];
BB0x558458586e20 -> BB0x558458586fc0
BB0x558458586e20 -> BB0x558458586f50
BB0x558458586f50 [label="blk4
i++;
goto blk1;
"];
BB0x558458586f50 -> BB0x558458586cc0
BB0x558458586fc0 [label="blk5
printf("%f ", i);
printf(" is a factor of  ");
printf("%f \n", n);
goto blk4;
"];
BB0x558458586fc0 -> BB0x558458586f50
}
```