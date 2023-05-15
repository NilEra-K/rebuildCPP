#### GCC编译程序的过程
```
1. 预处理
    将源文件包含的头文件拷贝到当前的 .c 文件中
    #include <stdio.h>  GCC编译器第一步会将 stdio.h 头文件的内容拷贝到源文件中
        - GCC Command:
        gcc -E hello.c -o hello.i

2. 编译
    将预处理得到的 .i 文件进行编译得到汇编文件
    汇编文件后缀: .s
        - GCC Command:
        gcc -S hello.i -o hello.s

3. 汇编
    将编译后得到的 .s 文件经过汇编得到计算机可以识别的机器文件
    该文件叫做目标文件(Object File): .o object 无法运行
        - GCC Command
        gcc -c hello.s -o hello.o

4. 链接
    将他人的代码与自己的代码进行整合, 如 printf() 实现代码和自己的代码进行整合 -> 形成二进制可执行程序
    hello.o (self) + others.o -> .exe
        - GCC Command
        gcc hello.o -o hello
```

===

#### 一些小技巧
1. 在 VIM 中使用 `SHIFT + V` 全选代码, 此时按`"="`可以自动缩进代码
2. 在 VIM 中使用 `CTRL + N` 可以快速补全代码
3. 在 SHELL 终端中, 使用 `man ascii` 可以查询 ASCII 码
4. 




