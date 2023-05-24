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
#include <iostream>
using namespace std;
struct Student{
	char name[32];
	int age;
};
typedef Student Stu;

typedef struct Person{
	char name[32];
}Ps;

int main(void){
	// 定义结构体类型变量
	struct Student s1 = {"James", 10};
	// 标记初始化
	Stu s2 = {.name = "ZhangSan", .age = 20};
	cout << s1.name << ' ' << s1.age << endl;
	cout << s2.name << ' ' << s2.age << endl;

	// 定义结构体指针变量
	struct Student* ps1 = &s1;
	// 通过指针变量访问结构体成员语法
	cout << ps1->name <<  ' ' << ps1->age << endl;
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;
/* 结构体和函数的关系 */
// - 结构体作为函数的参数
//   建议使用指针 -> 效率更高
//   A 函数 -> 结构体变量 -> B 函数
//   A 函数 -> 结构体变量指针 -> B 函数
// - 结构体作为函数的返回值
typedef struct Student{
	char name[32];
	int age;
}Stu;

void show(Stu stu){
	printf("%s, %d\n", stu.name, stu.age);
}

void grow(Stu stu){
	stu.age++;
}

void grow_p(Stu* pstu){
	pstu->age++;
}

int main(void){
	Stu stu1 = {"ZhangSan", 10};
	show(stu1);		// [Out]: ZhangSan 10
	grow(stu1);		
	show(stu1);		// [Out]: ZhangSan 10 -> 未发生变化
	grow_p(&stu1);
	show(stu1);		// [Out]: ZhangSan 11
	
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
// 使用 #pragma pack(pop)可以恢复默认
# pragma pack(pop)

int main()
{
	cout << sizeof(st_1) << endl;		// 40
	cout << sizeof(st_2) << endl;		// 36
    return 0;
}
#endif

#if 0
// 共用体/联合体 union
// 几个不同的变量共享同一个地址开始的内存空间。

// 公用体变量初始化时, 只能对第一个成员赋值(原因与共用体的特性有关)
// 公用体变量所占的内存长度等于最长的成员长度
// 公用体变量在一个时刻只能一个成员发挥作用, 赋值时, 成员之间会互相覆盖, 最后一次被赋值的成员起作用

// 共用体语法结构
// union 共同体类型名
// {
//     成员类型1 成员名1;
// 	   成员类型2 成员名2;
// 	   ... ...
// 	   成员类型n 成员名n;
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
#include <stdio.h>
// 联合是对同一块内存的不同是哟个方式
int main(void){
	// 直接定义联合体变量 mb, 分配四个字节
	union {
		unsigned int u_n;
		unsigned char u_c[4];
	}mb;
	// __   __   __   __
	// 0x78 0x56 0x34 0x12	u_n
	mb.u_n = 0x12345678;	// 向 4个字节内存中写入了数据 0x12345678
	for(int i = 0; i < 4; i++){
		// 这里与主机字节序有关系 -> 大端模式与小端模式
		// 一般来说, 我们的个人计算机都是小端模式
		// mb.u_n = 1;	// 4字节 0x00000001
		//     +====+====+====+====+
		//     |0x01|0x00|0x00|0x00|	小端方式
		//     +====+====+====+====+
		//L -> 0    1    2    3    4 -> H(High)高地址

		printf("%#x ", mb.u_c[i]);		// 0x78 0x56 0x34 0x12	u_c
	}
	printf("\n");

	mb.u_c[2] = 0x43;
	for(int i = 0; i < 4; i++){
		printf("%#x ", mb.u_n);			// 0x12435678	u_n
	}
	printf("\n");
	// 可以看出联合体公用内存空间
	return 0;
}
#endif

#if 0
#include <stdio.h>
/* 联合体到底有什么用 */
// 经典使用场景:
// 数据传输 -> 传统方式
//		unsigned char buf[48];
// A 给 B 发送数据, 数据一共有 48个字节
// 		包含信息:
// 		- 4字节的数据头
// 		- 40字节的数据本身
// 		- 4字节的数据尾

// 联合套结构体 -> A给 B发送数据, B使用联合体解析数据
union msg{
	unsigned char buf[48];
	struct cmd{
		unsigned char head[4];
		unsigned char data[40];
		unsigned char tail[4];
	}cmd_info;
}ms;

// 声明结构体数据类型
typedef struct person{
	char name[32];
	char sex;	// 'm' | 'f'
	char job;	// 's' | 't'
	union{	// 教授和学生杂糅在一起
		int classnum;
		char position[10];
	}category;
}per_t;

int main(void){
	ms.cmd_info.data;	// 直接获取 40字节
	per_t p[2] = {
		// 出现错误, 暂时没有解决方案
		{.name = "XiaoMing", .sex = 'm', .job = 's', .category.classnum = 10},
		{.name = "ZhangSan", .sex = 'f', .job = 't', .category.position = "教授"}
	};
	for(int i = 0; i < 2; i++){
		if(p[i].job == 's'){
			printf("姓名: %s, 性别: %c, 班级: %d\n", p[i].name, p[i].sex, p[i].category.classnum);
		} else {
			printf("姓名: %s, 性别: %c, 职称: %s\n", p[i].name, p[i].sex, p[i].category.position);
		}
	}
	return 0;
}
#endif

#if 1
#include <stdio.h>
int main(void){

	return 0;
}
#endif

#if 0
// 类和对象
// 类的语法结构
// class 类名
// {
// 	public:
// 		公有数据成员;
// 		公有成员函数;
// 	private:
// 		私有数据成员;
// 		私有成员函数;
// 	protected:
// 		保护数据成员;
// 		保护成员函数;
// };
#include <iostream>
using namespace std;
// 和Java C#不同的是: C++中 public, private, protected只能修饰类的成员, 不能修饰类, C++中的类没有共有私有之分
// 类内部没有访问权限的限制, 都可以互相访问
// 在C++中用class定义的类中, 其成员的默认存取权限是private
class Person{
public:
	// 无参构造函数
	Person();
	// 带有默认参数的构造函数
	Person(string sex = "男");
	Person(int year, string name);
	Person(int year, string sex, string name);
	Person(Person &p);
	void show();
	~Person();
private:
	int year;
	string sex;
	string name;
};


Person::Person(){}
Person::Person(int year, string name){
	this->year = year;
	this->name = name;
}
// 带参数初始化表的构造函数
// 类名::构造函数名(参数列表):参数初始化表
// {
// 	函数体;
// }
// 参数初始化列表的一般形式:
// 参数名1(初值1),参数名2(初值2),...,参数名n(初值n)
Person::Person(int year, string sex, string name): year(year), sex(sex), name(name)
{
	cout << year << ' ' << sex << ' ' << name << endl;
	cout << this->year << ' ' << this->sex << ' ' << this->name << endl;
}
Person::~Person(){}
// 栈区: 存放函数的参数值, 局部变量等, 由编译器自动分配和释放, 通常在函数执行完后就释放, 其操作方式类似于数据结构中的栈.
// 栈内存分配运算内置于CPU的指令集, 效率很高, 但是分配的内存量有限, 比如iOS中栈区的大小是 2M.
Person p(123, "yar");//在栈上创建对象

// 堆区: 就是通过new, malloc, realloc分配的内存块, 编译器不会负责它们的释放工作, 需要用程序区释放. 
// 分配方式类似于数据结构中的链表. '内存泄漏' 通常说的就是堆区.
Person *pp = new Person(234,"yar");//在堆上创建对象

Person tp(10, "男", "张三");
void Person::show()
{
	cout << "year = " << this->year << endl;
	cout << "sexx = " << this->sex << endl;
	cout << "name = " << this->name << endl;
}

int main()
{
	tp.show();
    return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;
// 以关键字static开头的成员为静态成员, 多个类共享.
// static 成员变量属于类，不属于某个具体的对象
// 静态成员函数只能访问类中静态数据成员
class TestClass
{
private:
	static int statA;
	int noStat;
public:
	TestClass();
	void visit_1();
	static int visit_2();
	~TestClass();
};

TestClass::TestClass(){}
void TestClass::visit_1(){
	cout << statA << ' ' << noStat << endl;
}

int TestClass::visit_2(){
	// 下列语句报错: 非静态成员引用必须与特定对象相对
	//                           v  
	// cout << statA << ' ' << noStat << endl;
	cout << statA << endl;
}

TestClass::~TestClass(){}

int main()
{
    return 0;
}
#endif

#if 0
// Friend 友元
// Blog: https://blog.csdn.net/weixin_46098577/article/details/116596183
#include <iostream>
using namespace std;
// 全局函数做友元
class Building{
	// 告诉编译器 laoWang 全局函数是 Building类的好朋友, 可以访问 Building对象的私有成员
	friend void laoWang1(Building *building);
	friend void laoWang2(Building &building);
	friend void laoWang3(Building building);
public:
	Building()
	{
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}	
	string m_SittingRoom;	// 客厅
private:
	string m_BedRoom;		// 卧室
};

//全局函数
void laoWang1(Building *building)
{
	cout << "隔壁老王 全局函数 正在访问: (地址传递) " << building->m_SittingRoom << endl;
	// 在未声明友元时, building->m_BedRoom语句报错, [ERROR] 成员 "Building::m_BedRoom"不可访问
	cout << "隔壁老王 全局函数 正在访问: (地址传递) " << building->m_BedRoom << endl;
}

void laoWang2(Building &building)
{
	cout << "隔壁老王 全局函数 正在访问: (引用传递) " << building.m_SittingRoom << endl;
	// 在未声明友元时, building->m_BedRoom语句报错, [ERROR] 成员 "Building::m_BedRoom"不可访问
	cout << "隔壁老王 全局函数 正在访问: (引用传递) " << building.m_BedRoom << endl;
}

void laoWang3(Building building)
{
	cout << "隔壁老王 全局函数 正在访问: (值传递) " << building.m_SittingRoom << endl;
	// 在未声明友元时, building->m_BedRoom语句报错, [ERROR] 成员 "Building::m_BedRoom"不可访问
	cout << "隔壁老王 全局函数 正在访问: (值传递) " << building.m_BedRoom << endl;
}

void test()
{
	Building building;
	laoWang1(&building);
	laoWang2(building);
	laoWang3(building);
}

int main()
{
	test();
    return 0;
}
#endif

#if 0
// 类做友元
#include <iostream>
using namespace std;
#include <iostream>
#include <string>

using namespace std;

// 类作友元
class Building;

class LaoWang{
public:
	LaoWang();
	void visit();	//参观函数  访问Building中的属性
	Building *building;
};

// 房屋类
class Building{
	// 告诉编译器, LaoWang类是 Building类的好朋友, 可以访问 Building类的私有成员
	friend class LaoWang;
	// 成员函数做友元
	// friend void LaoWang::visit1();
public:
	Building();
	string m_SittingRoom;	// 客厅
private:
	string m_BedRoom;		// 卧室
};

// 类外定义成员函数
Building::Building(){
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}

LaoWang::LaoWang(){
	// 创建建筑物对象
	building = new Building;
}

void LaoWang::visit(){
	cout << "隔壁老王LaoWang类正在访问: " << building->m_SittingRoom << endl;
	cout << "隔壁老王LaoWang类正在访问: " << building->m_BedRoom << endl;
}

void test(){
	LaoWang lw;
	lw.visit();
}

int main()
{
	test();
    return 0;
}
#endif


#if 0
#include <iostream>
using namespace std;
// 继承和派生
// 继承和派生是面向对象程序设计的两个重要特性, 继承是从已有的类得到已有的特性
// 已有的类被称为基类或者父亲, 新类被称为派生类或子类
// 继承与派生从不同角度说明类之间的关系, 这种关系包含访问机制, 多态和重载等

// 继承方式为可选项, 默认为 private
// class 派生类名:[继承方式] 基类名{
// 		派生类新增加的成员声明;
// };

// [继承方式]
// Public		基类的 public成员和 protected成员的访问属性保持不变, 私有成员不可见.
// Private		基类的 public成员和 protected成员成为private成员, 只能被派生类的成员函数直接访问, 私有成员不可见.
// Protected	基类的 public成员和 protected成员成为protected成员, 只能被派生类的成员函数直接访问, 私有成员不可见.
class CEmployee{
public:
	int m_ID;
	char m_Name[128];
	char m_Depart[128];
};

class COperator: public CEmployee{
public:
	char m_Password[128];
	bool Login();
};
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

#if 0
#include <iostream>
using namespace std;

int main()
{
    return 0;
}
#endif
