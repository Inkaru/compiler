```graphviz
digraph {
node [shape=box];
BB0x564792f992a0 [label="blk0
double list[12] = {5,6,1,2,9,14,2,15,6,7,8,97};
t_0 = 12;
itemCount = t_0;
goto blk2;
"];
BB0x564792f992a0 -> BB0x564792f999b0
BB0x564792f999b0 [label="blk2
hasChanged = false;
t_1 = itemCount - 1.0;
itemCount = t_1;
i = 1.0;
goto blk3;
"];
BB0x564792f999b0 -> BB0x564792f99ca0
BB0x564792f99ca0 [label="blk3
if(i<=itemCount) 
	goto blk5;
else 
	goto blk4;
"];
BB0x564792f99ca0 -> BB0x564792f99e00
BB0x564792f99ca0 -> BB0x564792f99d90
BB0x564792f99d90 [label="blk4
t_8 = hasChanged == false;
if(t_8!= 1)
	goto blk2;
else
	goto blk1;
"];
BB0x564792f99d90 -> BB0x564792f999b0
BB0x564792f99d90 -> BB0x564792f99940
BB0x564792f99940 [label="blk1
t_9 = 12;
i = 1.0;
goto blk8;
"];
BB0x564792f99940 -> BB0x564792f9a890
BB0x564792f99e00 [label="blk5
t_2 = i + 1.0;
t_3 = list[(int)i-1 ] > list[(int)t_2-1 ];
if(t_3 != 0)
	goto blk7;
else
	goto blk6;
"];
BB0x564792f99e00 -> BB0x564792f99f70
BB0x564792f99e00 -> BB0x564792f99f00
BB0x564792f99f00 [label="blk6
i++;
goto blk3;
"];
BB0x564792f99f00 -> BB0x564792f99ca0
BB0x564792f99f70 [label="blk7
t_4 = i + 1.0;
t_5 = list[(int)t_4-1 ];
t_6 = list[(int)i-1 ];
list[(int)i-1 ] = t_5;
t_7 = i + 1.0;
list[(int)t_7-1 ] = t_6;
hasChanged = true;
goto blk6;
"];
BB0x564792f99f70 -> BB0x564792f99f00
BB0x564792f9a890 [label="blk8
if(i<=t_9) 
	goto blk10;
else 
	goto blk9;
"];
BB0x564792f9a890 -> BB0x564792f9a9f0
BB0x564792f9a890 -> BB0x564792f9a980
BB0x564792f9a980 [label="blk9
"];
BB0x564792f9a9f0 [label="blk10
printf("%f \n", list[(int)i-1 ]);
i++;
goto blk8;
"];
BB0x564792f9a9f0 -> BB0x564792f9a890
}
```