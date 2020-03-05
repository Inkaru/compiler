```graphviz
digraph {
node [shape=box];
BB0x560a85ad2940 [label="blk0
t_0 = 1.0 / 7.0;
x  = t_0 ;
t_1 = 10.0 + x;
t_2 = t_1 * 2.0;
y  = t_2 ;
t_3 = x * x;
t_4 = y - t_3;
z  = t_4 ;
printf("%f %f %f ", x, y, z);
t_5 = z * z;
z  = t_5 ;
t_6 = -z;
z  = t_6 ;
printf("hello %f ", x);
"];
}
```