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


#### 一些小技巧
1. 在 VIM 中使用 `SHIFT + V` 全选代码, 此时按`"="`可以自动缩进代码
2. 在 VIM 中使用 `CTRL + N` 可以快速补全代码
3. 在 SHELL 终端中, 使用 `man ascii` 命令可以查询 ASCII 码
4. 函数声明的时候一般要加 `extern` 关键字
5. 一般定义全局变量时, 要加一个 `g_` , 例如 `g_x` , `g_` 表示 `global` , 这是一个好的编程习惯
6. 在 Linux 编译多文件时, 例如: var.c负责变量和函数的定义, var1负责调用,使用 `gcc var.c var1.c -o var` 命令来进行编译
7. 当程序中用到一个宏参数, 但是并没有用 `#define` 定义时, 可以使用 ` gcc -D[宏参数]=[参数值] filename -o outname`, 例如: ` gcc -DSIZE=5 -DMAX=10 hello.c o hello`

---
### **大型程序文件分类**
#### ***根据产品的的不同模块进行划分***
- 摄像头
- 电池管理
- 屏幕
- 网卡
- sim卡
- ...
#### 分为以下三类:
头文件: _声明_
1. 包含公共头文件 ` #include <stdio.h> `
2. 宏定义 `#define TRUE 1`
3. 类型定义 `typedef int BOOL`
4. 函数声明 `int ConnectServer(const char* URL);`
5. 尾部变量声明 `extern const char* g_dns;`

源文件: _定义_
1. 全局变量的定义
2. 函数的定义
3. 源文件包含自己的头文件

主文件:(main函数所在的文件, 例如 `main.c `) _调用_
- main 函数和调用

### **Makefile**
#### ***make 与 makefile***
- _Makefile_ -> 本质上就是一个文本文件 -> 存储的是文件的编译规则 -> ***将来可以让程序按照文件中的编译规则进行编译***

- _Makefile_ 需要描述的就是**目标**、**依赖**以及从依赖产生目标所需要执行的各种命令
  - 目标:依赖
  - <制表符> 命令1
  - <制表符> 命令2
- 一个 _Makefile_ 可以包含多个目标, 通过 `make` 命令的参数期望实现的目标, **缺省**实现第一个
- 命令可以是 `gcc` 命令, 也可以是普通的 **SHELL** 命令
- 目标的依赖 和/或 命令可以为空

``` 
Linux 下使用 Makefile
=======================
vim Makefile
hello:hello.c
    gcc hello.c -o hello

```
Makefile的一些使用技巧:
1. 变量: 类似于 C语言里的宏
<br><t>` OBJ=main.o `</t> 
<br>使用:
<br> ` $(OBJ) ` 等价于 `main.o`
```
OBJ=main.o fila_A.o file_B.o
BIN=main

# 编译规则1
# main: main.o file_A.o file_B.o
$(BIN): $(OBJ)
    # gcc main.o file_A.o file_B.o -o main
    gcc $(OBJ) -o $(BIN)

# 编译规则2
main.o: main.c
    gcc -c main.c -o main.o

# 编译规则3
file_A.o: file_A.c
    gcc -c file_A.c -o file_A.o

# 编译规则4
file_B.o: file_B.c
    gcc -c file_B.c -o file_B.o
```
2. 让 ` .c `文件生成对应的 ` .o `文件
```
%.o: %.c
    gcc -c $< -o $@

%.o, $@ - 目标文件 - .o文件
%.c, $< - 依赖文件 - .c文件
==========================
OBJ=main.o fila_A.o file_B.o
BIN=main
CC=gcc
# 编译规则1
# main: main.o file_A.o file_B.o
$(BIN): $(OBJ)
    # gcc main.o file_A.o file_B.o -o main
    $(CC) $(OBJ) -o $(BIN)

# 编译规则2
%.o: %.c
    $(CC) -c $< -o $@
```
3. 伪目标
<br>目标 - 只有目标文件, 没有依赖文件 -> 伪目标
```
clean:
    命令
==========================
OBJ=main.o fila_A.o file_B.o
BIN=main
CC=gcc
# 编译规则1
# main: main.o file_A.o file_B.o
$(BIN): $(OBJ)
    # gcc main.o file_A.o file_B.o -o main
    $(CC) $(OBJ) -o $(BIN)

# 编译规则2
%.o: %.c
    $(CC) -c $< -o $@

# 伪目标
clean:
    rm $(OBJ) $(BIN)
==========================
make clean - clean对应的命令
rm main.o cal.o arr.o main
```
---

