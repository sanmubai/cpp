--lua 调用c模块 c_so.c
require ("c_so");

print("平方"..square(1.414));
print("立方："..cube(3));