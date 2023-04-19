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

#if 1
// 结构体大小和字节对齐
#include <iostream>
using namespace std;

//指定对齐值=8
struct st_1
{
	// 空结构体大小1
	char c1;	// 1
	char c2;	// 2
	int i1;		// 8  int  起始地址按照字节对齐的原理应该是它长度4的整数倍
	char c3;	// 12
	short s4;	// 12 short 起始地址按照字节对齐的原理应该是它长度2的整数倍 12 + 2 = 12
	double d;	// 24 double 起始地址按照字节对齐的原理应该是它长度8的整数倍 12->16 + 8 = 24
	char c4; 	// 32 24 + 4 = 28 结构体的总大小为8的整数倍 28->32
	int i2;		// 32 28+4 = 32
	int i3;		// 40   
	short s5;	// 40
};

// 指定对齐值=4
#pragma  pack(4)
struct st_2
{
	//1 空结构体大小1
	char c1;//1
	char c2;//2
	int i1;//8
	char c3;//12
	short s4;//12
	double d;//20
	char c4;//24
	int i2;//28
	int i3;//32
	short s5;//36
}s;
int main()
{
	cout << sizeof(st_1) << endl;		// 40
	cout << sizeof(st_2) << endl;		// 36
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

#if 0
#include <iostream>
using namespace std;

int main()
{
    return 0;
}
#endif

