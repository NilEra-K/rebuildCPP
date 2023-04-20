/**
 * @file 03_ObjectPart.cpp
 * @author nilera (you@domain.com)
 * @brief 类与对象部分
 * @version 0.1
 * @date 2023-04-18
 * @copyright Copyright (c) 2023
 * 
 */

#if 0
/* =============================================
- 结构体 Struct 语法结构
struct 结构体类型名
{
	成员类型1 成员名1;
	成员类型2 成员名2;
	... ...
	成员类型n 成员名n;
};

- 定义结构体同时声明结构体变量名
struct 结构体类型名
{
	成员类型1 成员名1;
	成员类型2 成员名2;
	... ...
	成员类型n 成员名n;
}变量名1,变量名2,...变量名n;
============================================= */

#include <iostream>
using namespace std;
// 结构体变量名的定义和初始化
struct  person {
	int year;
	int age;
	string name;
}p1 = {2019, 24, "heiren"}, p2 = {2020, 24, "heiren"};

// struct person {
// 	int year;
// 	int age;
// 	string name;
// };
// struct person p1 = { 2019,24,"heiren" }, p1 = { 2020,24,"heiren" };

// struct {
// 	int year;
// 	int age;
// 	string name;
// }p1 = {2019,24,"heiren"}, p2 = { 2020,24,"heiren" };

// struct person
// {
// 	int year;
// 	int age;
// 	string name;
// }p[2] ={ {2019,24,"heiren"}, { 2020,24,"heiren" }}; //可以不指定数组元素个数

int main()
{
	// cout<<p[1].age;
    return 0;
}
#endif

#if 0
// 结构体大小和字节对齐
#include <iostream>
using namespace std;

// 指定对齐值=8
struct st_1
{
	// 空结构体大小 1
	char c1;
	char c2;
	int i1;
	char c3;
	short s4;
	double d;
	char c4;
	int i2;
	int i3;
	short s5;
	/* st_1 内存结构如下 
		+--------+--------+--------+--------+--------+--------+--------+--------+
		|  char  |  char  |                 |                int                |
		+--------+--------+--------+--------+--------+--------+--------+--------+
		|  char  |        |      short      |
		+--------+--------+--------+--------+--------+--------+--------+--------+
		|                                 double                                |
		+--------+--------+--------+--------+--------+--------+--------+--------+
		|  char  |                          |                int                |
		+--------+--------+--------+--------+--------+--------+--------+--------+
		|                int                |      short      |
		+--------+--------+--------+--------+--------+--------+
	*/
};

// 可以通过 
// # pragma pack(n)来设定变量以n字节对齐方式
// 指定对齐值=4
# pragma pack(4)
struct st_2
{
	// 1 空结构体大小1
	char c1;
	char c2;
	int i1;
	char c3;
	short s4;
	double d;
	char c4;
	int i2;
	int i3;
	short s5;
	/* st_2 内存结构如下 
		+--------+--------+--------+--------+--------+--------+--------+--------+
		|  char  |  char  |                 |                int                |
		+--------+--------+--------+--------+--------+--------+--------+--------+
		|  char  |        |      short      |              double_1             |
		+--------+--------+--------+--------+--------+--------+--------+--------+
		|              double_2             |  char  |
		+--------+--------+--------+--------+--------+--------+--------+--------+
		|                int                |                int                |
		+--------+--------+--------+--------+--------+--------+--------+--------+
		|      short      |
		+--------+--------+
	*/
};
int main()
{
	cout << sizeof(st_1) << endl;		// 40
	cout << sizeof(st_2) << endl;		// 36
    return 0;
}
#endif

#if 1
// 共用体 union
// 几个不同的变量共享同一个地址开始的内存空间。

// 公用体变量初始化时, 只能对第一个成员赋值(原因与共用体的特性有关)
// 公用体变量所占的内存长度等于最长的成员长度
// 公用体变量在一个时刻只能一个成员发挥作用, 赋值时, 成员之间会互相覆盖, 最后一次被赋值的成员起作用

// 共用体语法结构
// union 共同体类型名
// {
//     成员类型1 成员名1;
// 	成员类型2 成员名2;
// 	... ...
// 	成员类型n 成员名n;
// };

// C++ 17 提供了 variant, 可以实现 Union 类似的效果, 并且会自动析构
#include <iostream>
using namespace std;

union self_datatype
{
	int i;
	float f;
	char c;
}x = {123};

// self_datatype x = {12.3};
int main()
{
	cout << x.i << " " << x.f << " " << x.c << endl;//12 1.68156e-44 
	x.c = 'c';
	cout << x.i <<" "<< x.f << " " << x.c << endl;//99 1.38729e-43 c
    return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

int main()
{
    return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

int main()
{
    return 0;
}
#endif

