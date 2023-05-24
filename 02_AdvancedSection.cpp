/**
 * @file 02_AdvancedSection.cpp
 * @author NilEra (nilera0001@gmail.com)
 * @brief 简单提高一下 C++基础, 这些是之前学过的东西, 需要反复加深印象
 * @version 0.1
 * @date 2023-04-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#if 0
// 函数的形式参数和实际参数, 函数的返回值 ---> 基础不做叙述
// 函数部分: 需要注意函数的传递方式 ---> 包括传值, 指针, 引用三个方式
// (* overload) 函数的重载: ---> 注意与[ *重写 ]区分
// 同一个函数名对应不同的函数实现, 每一类实现对应着一个函数体, 名字以及功能相同, 只是参数的类型或参数的个数不同
// (* override) 函数的重写(覆盖):
// 指在派生类中重新对基类中的虚函数(注意是虚函数)重新实现, 即函数名和参数都一样, 只是函数的实现体不一样

/* 虚函数是 C++中很重要的概念, 将重点介绍 */
#include <iostream>
using namespace std;
// 传值
int add_1(int value)
{
	value++;
	return value;
}

// 指针
int add_2(int *pValue)
{
	(*pValue)++;
    cout<<"*pValue = "<< *pValue <<endl;
	return *pValue;
}

// 引用
int add_3(int &value)
{
	value++;
	return value;
}

int main()
{
    int value = 10;
    add_1(value);
    int afterAdd_1 = add_1(value);
    cout<<"value = "<<value<<' '<<afterAdd_1<<endl;

    value = 10;
    add_2(&value);
    int afterAdd_2 = add_2(&value);
    cout<<"value = "<<value<<' '<<afterAdd_2<<endl;

    value = 10;
    add_3(value);
    int afterAdd_3 = add_3(value);
    cout<<"value = "<<value<<' '<<afterAdd_3<<endl;
    return 0;
}
#endif

#if 0
// 函数的调用: 包括 [*函数的嵌套调用*] & [*函数的递归调用*]
#include <iostream>
using namespace std;

// 函数声明 对下文会使用到的函数进行声明
int foo(int x);
int bar(int y);
inline int add(int a, int b);

/* 嵌套调用 */
// 无参数 A()
int A(){
    int num_1 = 10; 
    int num_2 = 20; 
    return num_1 + num_2; 
}

// 有参数 A(int, int)
int A(int num_1, int num_2){ return num_1 + num_2; }
int B(int val){ return val + A(); }
int C(int val){ return val + A(40, 20); }

/* 递归调用 */
// 递归和回归: 原问题 => 子问题 => 子问题的解 => 原问题的解
// 直接递归调用
int sum(int value){
    if (value == 1){
		return 1;
	}
	return value + sum(value - 1);
}

int factorial(int value){
    if (value == 1){
		return 1;
	}
	return value * factorial(value - 1);
}

// 间接递归调用
int foo(int x) {
    if (x <= 0) {
        cout << x<<endl;
        return x;
    }
    return bar(x);
}

int bar(int y) {
    cout << y <<endl;
    return foo(y - 1);
}

// inline 内联函数
// 内联函数语法
// inline 函数类型 函数名(形参列表){ 函数体; }
// C++ 在编译时可以将调用的函数代码嵌入到主调函数中, 这种嵌入到主调函数中的函数称为内联函数, 又称为内嵌函数或内置函数
// · 定义内联函数时, 在函数定义和函数原型声明时都使用 inline, 也可以只在其中一处使用, 其效果一样
// · 内联函数在编译时用内联函数函数的函数体替换, 所以不发生函数调用, 不需要保护现场, 恢复现场, 节省了开销
// · 内联函数增加了目标程序的代码量. 因此, 一般只将函数规模很小且使用频繁的函数声明为内联函数
// · 当内联函数中实现过于复杂时, 编译器会将它作为一个普通函数处理, 所以内联函数内不能包含循环语句和switch语句
inline int add(int a, int b)
{
    return a + b;   // 设置断点1
}

int main()
{
    // 函数的嵌套调用
	cout << B(50) << endl;
    cout << C(50) << endl;

    // 函数的直接递归调用
    cout << "The Sum From 1 to " << 5 << " is ---> "<<sum(5);
    // 函数的间接递归调用
    cout << foo(10) <<endl;

    // Blog: https://blog.csdn.net/qq_33670157/article/details/104455787
    // 内联函数的底层原理: 依靠断点来看
    // 因为内敛函数是直接嵌入主调函数, 所以断点理论上不会执行, 具体可能会与编译器有关
    int result = add(10, 20);
    result = add(10, 30);
    cout << "result = " << result << endl;
	return 0;
}
#endif


#if 0
// 字符串
// C 风格字符串
// 输入字符串长度一定小于已定义的字符数组长度, 最后一位是 "/0" 终止符号; 不然输出时无法知道在哪里结束

// C++ 风格字符串 ---> string
#include <iostream>
using namespace std;
void cStyle();
void cppStyle();

// C 风格字符串相关处理函数
// strcat(char s1[],const char s2[]);//将s2接到s1上
// strcpy(char s1[],const char s2[]);//将s2复制到s1上
// strcmp(const char s1[],const char s2[]);//比较s1,s2 s1>s2返回1 相等返回1，否则返回-1
// strlen(char s[]);//计算字符串s的长度 字符串s的实际长度，不包括\0在内
void cStyle(){
    char a[5];
    // 字符个数不够, 补 0; 字符个数超过报错
    // char str[7] = {'h','e','i','r','e','n'};
    char str[] = {'h','e','i','r','e','n'};
    cin>>str;   //输入 输入字符串长度一定小于已定义的字符数组长度
    cout<<str;  //输出
}

// C++ 风格字符串相关处理函数

void cppStyle(){
    /*======================================================================================================================================================================================================================================================================================================
    string str;             //生成空字符串
    string s(str);          //生成字符串为str的复制品
    string s(str, strbegin, strlen);    //将字符串str中从下标strbegin开始、长度为strlen的部分作为字符串初值
    string s(cstr, char_len);           //以C_string类型cstr的前char_len个字符串作为字符串s的初值
    string s(num ,c);       //生成num个c字符的字符串
    string s(str, stridx);  //将字符串str中从下标stridx开始到字符串结束的位置作为字符串初值
    size()和length();       //返回string对象的字符个数
    max_size();             //返回string对象最多包含的字符数，超出会抛出length_error异常
    capacity();             //重新分配内存之前，string对象能包含的最大字符数
    >,>=,<,<=,==,!=         //支持string与C-string的比较(如 str<”hello”)。  使用>,>=,<,<=这些操作符的时候是根据“当前字符特性”将字符按字典顺序进行逐一得 比较，string (“aaaa”) <string(aaaaa)。    
    compare();              //支持多参数处理, 支持用索引值和长度定位子串来进行比较. 返回一个整数来表示比较结果, 返回值意义如下0 = 相等/ 1 = 大于/ -1 = 小于
    insert( size_type index, size_type count, CharT ch );       //在index位置插入count个字符ch
    insert( size_type index, const CharT* s );                  //index位置插入一个常量字符串
    insert( size_type index, const CharT* s, size_type n);      //index位置插入常量字符串
    insert( size_type index, const basic_string& str );         //index位置插入常量string中的n个字符
    insert( size_type index, const basic_string& str, size_type index_str, size_type n);            //index位置插入常量str的从index_str开始的n个字符
    insert( size_type index, const basic_string& str,size_type index_str, size_type count = npos);  //index位置插入常量str从index_str开始的count个字符，count可以表示的最大值为npos.这个函数不构成重载 npos表示一个常数，表示size_t的最大值，string的find函数如果未找到指定字符，返回的就是一个npos
    iterator insert( iterator pos, CharT ch );
    iterator insert( const_iterator pos, CharT ch );
    void insert( iterator pos, size_type n, CharT ch );                 //迭代器指向的pos位置插入n个字符ch
    iterator insert( const_iterator pos, size_type count, CharT ch );   //迭代器指向的pos位置插入count个字符ch
    void insert( iterator pos, InputIt first, InputIt last );
    iterator insert( const_iterator pos, InputIt first, InputIt last );
    append() 和 + 操作符
    //访问string每个字符串
    string s1("yuanrui"); // 调用一次构造函数
    // 方法一： 下标法
    for( int i = 0; i < s1.size() ; i++ ){cout<<s1[i];}
    // 方法二：正向迭代器
    for( string::iterator iter = s1.begin();; iter < s1.end() ; iter++){cout<<*iter;}
    // 方法三：反向迭代器
    for(string::reverse_iterator riter = s1.rbegin(); ; riter < s1.rend() ; riter++){cout<<*riter;}
    iterator erase(iterator p);                         //删除字符串中p所指的字符
    iterator erase(iterator first, iterator last);      //删除字符串中迭代器区间[first,last)上所有字符
    string& erase(size_t pos = 0, size_t len = npos);   //删除字符串中从索引位置pos开始的len个字符
    void clear();   //删除字符串中所有字符
    string& replace(size_t pos, size_t n, const char *s);       //将当前字符串从pos索引开始的n个字符，替换成字符串s
    string& replace(size_t pos, size_t n, size_t n1, char c);   //将当前字符串从pos索引开始的n个字符，替换成n1个字符c
    string& replace(iterator i1, iterator i2, const char* s);   //将当前字符串[i1,i2)区间中的字符串替换为字符串s
    
    //tolower()和toupper()函数 或者 STL中的transform算法
    string s = "ABCDEFG";
    for( int i = 0; i < s.size(); i++ )
        s[i] = tolower(s[i]);
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    size_t find (constchar* s, size_t pos = 0) const;                   //在当前字符串的pos索引位置开始，查找子串s，返回找到的位置索引，-1表示查找不到子串
    size_t find (charc, size_t pos = 0) const;                          //在当前字符串的pos索引位置开始，查找字符c，返回找到的位置索引，-1表示查找不到字符
    size_t rfind (constchar* s, size_t pos = npos) const;               //在当前字符串的pos索引位置开始，反向查找子串s，返回找到的位置索引，-1表示查找不到子串
    size_t rfind (charc, size_t pos = npos) const;                      //在当前字符串的pos索引位置开始，反向查找字符c，返回找到的位置索引，-1表示查找不到字符
    size_tfind_first_of (const char* s, size_t pos = 0) const;          //在当前字符串的pos索引位置开始，查找子串s的字符，返回找到的位置索引，-1表示查找不到字符
    size_tfind_first_not_of (const char* s, size_t pos = 0) const;      //在当前字符串的pos索引位置开始，查找第一个不位于子串s的字符，返回找到的位置索引，-1表示查找不到字符
    size_t find_last_of(const char* s, size_t pos = npos) const;        //在当前字符串的pos索引位置开始，查找最后一个位于子串s的字符，返回找到的位置索引，-1表示查找不到字符
    size_tfind_last_not_of (const char* s, size_t pos = npos) const;    //在当前字符串的pos索引位置开始，查找最后一个不位于子串s的字符，返回找到的位置索引，-1表示查找不到子串
    sort(s.begin(),s.end());
    substr(pos,n);      //返回字符串从下标pos开始n个字符
    strtok();
    char str[] = "I,am,a,student; hello world!";
    const char *split = ",; !";
    char *p2 = strtok(str,split);
    while( p2 != NULL )
    {
        cout<<p2<<endl;
        p2 = strtok(NULL,split);
    }
    ======================================================================================================================================================================================================================================================================================================*/
}

int main()
{
    cStyle();
    return 0;
}
#endif

#if 0
// 上方 String代码中有 String& function()的用法
// 本部分将对 class& 用法进行叙述 (e.g. string&) 
// 当返回类型为 A& 时, 没有调用拷贝构造函数, 返回的是当前对象本身(即引用), 而不是拷贝出来的副本.
// C++的类相关知识中, 关于函数的返回值为 *this 与 this 的情况
// return *this 返回的是当前对象的克隆或者本身(若返回类型为A, 则是克隆, 若返回类型为 A&, 则是本身).
// return this  返回当前对象的地址(指向当前对象的指针)

// 脑抽了, 以为 class& 是很高端的用法, 忽视了class& function() 和 class &function()这俩东西实际上是没啥区别的
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class A{
public:
	int x;
	A() {x = 0;}
    //这里写了一个拷贝构造函数，所以得再提供一个构造函数
	A(const A &a) {x = a.x; printf("copy constructor is called\n");}

	// * 如果显示的写了一个普通的构造函数，会隐藏默认的无参构造函数
	// * 如果显示的写了一个拷贝构造函数，会隐藏默认的无参构造函数和默认构造函数
	// * 如果显示的写了一个析构函数，会隐藏默认的析构函数
	A& get() {return *this;}
};

int main()
{
	A a;
	a.x = 4;
	if (a.x == a.get().x){cout << a.x << endl;}
    else{cout << "no" << endl;}
	if (&a == &a.get()){cout << "地址" << endl;}
	else{cout << "不是地址" << endl;}
	return 0;
}
#endif

#if 0
// 指针
// & 取地址符 
// * 指针运算符(间接运算符), 其后是指针变量, 表示该指针变量所指向的变量.
// & * 的优先级是相同的. 例如 &*p等价于&(*p).

// 指针运算 (地址运算)
// 算术运算 (移动指针运算): 加减, 自增自减.
// p+n 运算得到的地址是 p + n*sizeof(数据类型)
// 两个相同数据类型的指针可以进行加减运算, 一般用于数组的操作中
// 关系运算: 指针指向同一串连续存储单元才有意义, 比如数组. 与0比较, 判断是不是空指针
// 赋值运算: 变量地址赋值给指针变量, 数组元素地址赋值给指针变量, 指针变量赋值给其他指针变量

// 数组名是数组的首地址, eg: arr为 arr[0]的地址
// 访问数组元素: arr[i], (arr+i), (p+i), p[i]
// 二维数组: arr+i == &arr[i], arr[i] == &arr[i][0], *(arr[i]+j) == arr[i][j]
// 指针访问二维数组: 指向二维数组元素, 指向一维数组
// 数组指针: 数据类型(*指针变量名)[m]
#include <iostream>
using namespace std;
int main()
{
    int x = 3;
    int y;
    int *p;
    p = &x;
    y = *p;     //y = x
    return 0;
}
#endif

// 代码风格进行小调整
#if 0
#include <iostream>
#include <stdio.h>

using namespace std;
int main(void){
    int a[10] = {1, 2, 3, 4, 5};
    printf("sizeof(a) = %lu\n", sizeof(a));
    printf("sizeof(a[0]) = %lu\n", sizeof(a[0]));
    printf("sizeof(a) / sizeof(a[0]) = %lu\n", sizeof(a)/sizeof(a[0]));

    // 不好的代码
    for(int i = 0; i < 5; i++){
        a[i] *= 100;
    }
    for(int i = 0; i < 5; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    // 较好的代码
    int size = sizeof(a)/sizeof(a[0]);
    for(int i = 0; i < size; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    // 关于动态数组
    // C99 支持动态数组, 亦称变长数组, 即在定义数组时通过变量指定数组的长度
    //////// 注意: 动态数组不可初始化 -> 初始化会导致 [E rror]
    // 动态数组的使用会导致一些问题 -> n的值在编译阶段不确定 (gcc x.c -o x)

    int n;
    scanf("%d", &n);
    int b[n];           // C99 动态数组
    for(int i = 0; i < n; i++){
        b[i] = i + 1;
    }

    for(int i = 0; i < n; i++){
        printf("%d ", b[i]);
    }
    printf("\n");
    return 0;
}
#endif

#if 0
/* 指针 Pointer */
#include <iostream>
// 地址: 32位系统中占 4字节; 64位系统中占 8字节
/* 1字节 = 8位 */
/* 1字 = 2字节 */
/* 00000000 00000000 00000000 00000001 -> 1 -> 0x00000001*/
/* 32位 -> int* pa; -> sizeof(pa) = 4 */
/* 64位 -> int* pa; -> sizeof(pa) = 8 */

/* 既然指针类型的大小不是 4字节就是 8字节, 那么指针变量为什么不用相同的数据类型存储 */
// 数据类型的作用是指向的内存数据类型

using namespace std;
int main(void){
    /* 野指针和空指针 */
    /* 野指针: 即指向不可用内存区域的指针 */
    /* 操作野指针将导致未定义的结果, 构成潜在的风险 */
    /* 产生野指针的原因: 指针变量没有初始化; 指针变量所指向的内存已被释放(malloc) */
    
    /* 空指针: 即值为 0的指针, 可用宏 NULL表示 */
    /* 任何情况下, 操作空指针的结果都是确定的 -> 程序崩溃 */
    /* 空指针比野指针跟适合作为指针有效性的判断根据 */
    int* p = NULL;
    printf("%#x\n", *p);    // 程序崩溃
    *p = 100;               // 程序崩溃
    return 0;
}
#endif 

#if 0
#include <iostream>
using namespace std;
/* 指针运算 */
// 指针变量 + n => 指针变量 + n*sizeof(数据类型)
int main(void){
    char ch = 'a';
    char* pch = &ch;
    printf("%p\n", pch);
    pch++;
    printf("%p\n", pch);
}
#endif

#if 0
#include <iostream>
using namespace std;
/* 指针和函数的关系 */
// 1. 指针做函数的参数
//    指针 - 参数 -
//    实参变量的地址 - 直接访问实参变量的值
//    形参变量获取了实参变量的地址 -> 访问实参变量
/* ============================================== */
// 2. 指针做函数的返回值 -> 指针函数(函数返回一个地址)
//    

// 简单交换函数, 无法真正的实现交换
void swap(int x, int y){
    int tmp = x;
    x = y;
    y = tmp;
}

// 指针交换函数, 实现了真正的交换
void swap_p(int* pa, int* pb){
    int tmp = *pa;      // tmp = *pa = a = 10
    *pa = *pb;          // *pa = a = *pb = b = 20
    *pb = tmp;          // *pb = b = tmp = 10
}

int* A(void){
    int a = 100;
    // 无法返回局部变量地址;
    return &a;      // 函数结束, 变量生命周期结束, 分配给 a的内存就被释放了
}

int main(void){
    int a = 10, b = 20;
    swap(a, b);
    printf("a = %d, b = %d\n", a, b);

    int* p = NULL;
    p = A();    // 调用指针函数A并且使用
    return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

int main(void){
    int a[] = {1, 2, 3, 4};
    // 数组名是数组的首地址, 所以不需要加 '&' 引用符
    cout << a << endl;
    int* pa = a;
    cout << a[0] << ' ' << a[1] << ' ' << a[2] << ' ' << a[3] << endl;
    cout << *(a + 0) << ' ' << *(a + 1) << ' ' << *(a + 2) << ' ' << *(a + 3) << endl;
    cout << *(pa + 0) << ' ' << *(pa + 1) << ' ' << *(pa + 2) << ' ' << *(pa + 3) << endl;
    cout << pa[0] << ' ' << pa[1] << ' ' << pa[2] << ' ' << pa[3] << endl;
    return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;
/* void* 泛型指针 */
// 仅存储内存地址, 不指定目标类型
// 例如: void* p = &a; // 通过 p并不能知道 a的类型
// 目标类型不确定, 不能直接解引用
// 使用前必须进行数据类型转换
// 泛型指针做指针计算, 以 1字节为单位
int main(void){
    int a = 100;
    void* p = &a;
    // printf("%d\n", *p);     // [ERROR] 表达式必须是指向完整类型的指针
    int* p1 = (int*) p;
    printf("%d\n", *p1);
    *p1 = 101;
    printf("%d\n", *p1);
    return 0;
}
#endif

#if 0
/* 常量指针和指针常量 */
#include <iostream>
using namespace std;

/* 常量指针 指针该变量保存的地址可以改变, 指向的内存值无法改变 */
// const int* 或 int const*

/* 指针常量, 指针变量保存的地址不能修改, 内存值可以修改 */
// int* const

/* 常量指针常量, 指针变量保存的地址和内存值都不可以进行修改 */
// const int* const

int main(void){
    // 常量指针 
    int a = 10;
    int b = 20;
    const int* p = &a;
    // *p = 20;    // [ERROR] 表达式必须是可修改的左值 -> 指向的内存值无法修改
    p = &b;        // [SUCCESS] -> 指向的地址可以修改

    // 指针常量
    int c = 10;
    int d = 20;
    int* const cp = &c;
    *cp = 20;           // [SUCCSESS] -> 指向的内存值可以修改
    // cp = &b;         // [ERROR] ->表达式必须是可修改的左值 -> 指向的地址无法修改
    return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

int main(void){
    int a = 0x12345678;
    // 指针的强制类型转换
    char* p1 = (char*) &a;
    printf("%#x\n", *p1);       // 0x78
    p1++;
    printf("%#x\n", *p1);       // 0x56
    p1++;
    printf("%#x\n", *p1);       // 0x34
    p1++;
    printf("%#x\n", *p1);       // 0x12

    // 通过类型转换访问其中两个字节的内存
    short* p2 = (short*) &a;
    printf("%#x\n", *p2);       // 0x5678
    p2++;
    printf("%#x\n", *p2);       // 0x1234

    // 获得中间两个字节
    printf("%#x\n", *(short*)((char*) &a + 1));     // 0x3456
    return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

int main(void){
    int a = 0x12345678;
    void* p = (void*) &a;
    // 任意 1字节
    char* p1 = (char*) p;
    printf("%#x\n", *p1);
    p1++;
    printf("%#x\n", *p1);
    p1++;
    printf("%#x\n", *p1);
    p1++;
    printf("%#x\n", *p1);
    cout << "===============" << endl;

    // 任意 1字节, 直接访问
    printf("%#x\n", *(char*)(p + 0));
    printf("%#x\n", *(char*)(p + 1));
    printf("%#x\n", *(char*)(p + 2));
    printf("%#x\n", *(char*)(p + 3));
    cout << "===============" << endl;

    // 任意 2字节
    short* p2 = (short*) p;
    printf("%#x\n", *p2);
    p2++;
    printf("%#x\n", *p2);
    cout << "===============" << endl;

    // 任意 4字节
    int* p3 = (int*) p;
    printf("%#x\n", *p2);
    p3++;
    printf("%#x\n", *p2);
    cout << "===============" << endl;
    return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;
/* 地址 */ 
// 在 32位系统中 -> 4字节
// 在 64位系统中 -> 8字节
// ==============> 因此我们可以使用 unsigned long类型数据存储指针
int main(void){
    int a = 100;
    // unsigned long的变量 p来存储变量 a的地址
    unsigned long p = (unsigned long) &a;
    *(int*) p = 521;
    printf("a = %#x\n", a);
    printf("*(int*) p = %#x\n", *(int*) p);
    return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;
/* 字符串补充 */
// 字符串就是一组字符组成, 用双引号括起来表示, 用字符 '\0' 作为结束符(ASCII码也为0)
int main(void){
    // 下面两句等价
    printf("%s\n", "Hello World!\0");
    printf("%s\n", "Hello World!");
    printf("%s\n", "Hello World!\0[Don't Out]");    // Hello World!
    
    // 数据库 - 语句可以放在多行里, 可以避免太长
    printf("%s\n", "Hello " "World" "!");           // Hello World!

    /* 字符串的表示 */
    // 01. 字符指针方式 char* pstr = "Hello";
    // pstr -> 指针变量 -> 4/8字节 -> 永远存储地址 -> 字符串第一个字符的地址
    // 这种方式不能通过 pstr修改指针指向的字符串, 例如 pstr[1] = 'E';
    char* pstr = "Hello";   // pstr保存字符串的首地址
    cout << *pstr << endl;  // 输出: "H"
    cout << pstr << endl;   // 输入: "Hello World!" -> 打印 pstr指向的字符串
    cout << pstr[0] << pstr[1] << pstr[2] << pstr[3] << pstr[4] <<endl;
    cout << *(pstr + 0) << *(pstr + 1) << *(pstr + 2) << *(pstr + 3) << *(pstr + 4) << endl;
    // pstr[1] = 'E';       // Segmentation Fault 编译器不报错, 执行时报错
    // 原因: 通过字符指针声明的变量指向 "内存的 `常量区` ", 这一部分不允许修改
    
    // 02. 字符数组方式 str[] = {'H', 'e', 'l', 'l', 'o', '\0'}; 或者 str[] = "Hello";
    // 数组名即字符串首地址
    // 有两种初始化方式: 如上
    // 使用 str[] = {'H', 'e', 'l', 'l', 'o'}; 方式初始化时需要手动注明结束符 '\0', 否则就是一个数组
    // 可以任意修改
    char str[] = "Hello World!\n";
    cout << str;

    /* 字符串的输入输出 */
    // scanf("%s", str_name);
    // char* gets(char* s);
    char s_1[100] = {0};
    char s_2[100] = {0};
    scanf("%s", s_1);   // 这里不需要引用符 "&", 因为 s本身就相当于地址了
                        // 遇到空格结束 <- 可以使用 gets() 解决这一问题
    gets(s_2);          // [WARNING] gets 不会限制字符串的读取长度, 过多的读取字符串会导致内存中的其他数据被覆盖
                        // fgets() -> 用于文件操作
                        // gets_s() -> C11标准支持
    printf("=======================\n");
    printf("s_1 is %s\n", s_1);
    printf("s_2 is ");
    puts(s_2);          // 输出到终端上, 并自动追加一个 '\n'
    return 0;
}
#endif 

#if 0
#include <iostream>
#include <string.h>
using namespace std;

extern void reverse(char* pstr);
/* 字符串函数 */
// 字符串长度: 
// · unsigned int strlen(const char* s);    // 记住: char* s存放的一定是一个地址!!!
// 字符串拷贝: 
// · char* strcpy(char* dest, const char* src);
// · char* strncpy(char* dest, const char* src, unsigned int n);
// 字符串连接:
// char* strcat(char* dest, const char* src);   // strcat(数组名, 数组名/字符指针/字符串字面值)
// char* strncat(char* dest, const char* src, unsigned int n);
// 字符串比较:
// int strcmp(const char* s1, const char* s2);
// int strncmo(const char* s1, const char* s2, size_t n);
int main(void){
    char* p1 = "Hello World!";
    char str[100] = "Hello C!";
    printf("%lu, %lu\n", strlen(p1), strlen(str));

    // strcat(数组名, 数组名/字符指针/字符串字面值)
    char str1[20] = "Hello ";
    printf("%s\n", str1);    
    strcat(str1, "XYZ");        // 将字符串 "XYZ" 拼接到字符串 str1后, 并放入 str1数组中
    printf("%s\n", str1);

    // strncat()
    char str2[20] = "Hello ";
    printf("%s\n", str2);    
    strncat(str2, "XYZ", 2);    // 将字符串 "XYZ" 的前 n个字符拼接到字符串 str1后, 并放入 str1数组中
    printf("%s\n", str2);

    // strcpy(数组名, 数组名/字符指针/字符串字面值)
    // 将后面的字符串拷贝到第一个参数指定的内存中
    char str3[20] = "Hello Str3";
    printf("%s\n", str3);
    strcpy(str3, "123456");     // 将字符串拷贝到 str3数组中
                                // 原来存储的字符串 "Hello Str3" 消失
    /* 过程 -> */
    // +=====+=====+=====+=====+=====+=====+=====+=====+=====+=====+=====+=====+
    // |  H  |  E  |  L  |  L  |  O  |     |  S  |  T  |  R  |  3  |  \0 | ... |
    // +=====+=====+=====+=====+=====+=====+=====+=====+=====+=====+=====+=====+
    // "123456" --> "Hello Str3"
    // +=====+=====+=====+=====+=====+=====+=====+=====+=====+=====+=====+=====+
    // |  1  |  2  |  3  |  4  |  5  |  6  |  \0 |  T  |  R  |  3  |  \0 | ... |
    // +=====+=====+=====+=====+=====+=====+=====+=====+=====+=====+=====+=====+
    // 这样会覆盖后, 读到第一个 '\0', 意味着字符串结束
    printf("%s\n", str3);
    // strncpy() 就类似于 strncat()

    // strcmp(字符串, 字符串);
    // 从左边到右边一个字符一个字符比较, 直到不相等或者字符串结束
    // 如果字符串相等, 返回 0; 如果第一个字符串大, 返回 1; 如果第二个字符串大, 返回 -1;
    int ret = 0;
    ret = strcmp("abc", "abc");
    printf("abc : abc = %d\n", ret);
    ret = strcmp("aBc", "abc");
    printf("aBc : abc = %d\n", ret);
    ret = strcmp("abc", "abC");
    printf("abc : abC = %d\n", ret);

    // 定义 reverse()函数实现字符串的反转
    char rstr[20] = "HELLO WORLD!";
    printf("%s\n", rstr);
    reverse(rstr);
    printf("%s\n", rstr);
    return 0;
}

void reverse(char* pstr){
    int len = strlen(pstr);     // 获取有效字符个数
    for(int i = 0; i< len/2; i++){
        char c = pstr[i];
        pstr[i] = pstr[len - i - 1];
        pstr[len - i - 1] = c;
    }
}
#endif

#if 0
#include <iostream>
#include <string.h>
using namespace std;
/* 字符串数组 */
// 二位数组形式的字符串数组
// char sa[4][10] = {"beijing", "tianjin", "shanghai", "chongqing"};
//       +=====+=====+=====+=====+=====+=====+=====+=====+=====+=====+
// sa[0] |  b  |  e  |  i  |  j  |  i  |  n  |  g  |  \0 |  \0 |  \0 |
//       +=====+=====+=====+=====+=====+=====+=====+=====+=====+=====+
// sa[1] |  t  |  i  |  a  |  n  |  j  |  i  |  n  |  \0 |  \0 |  \0 |
//       +=====+=====+=====+=====+=====+=====+=====+=====+=====+=====+
// sa[2] |  s  |  h  |  a  |  n  |  g  |  h  |  a  |  i  |  \0 |  \0 |
//       +=====+=====+=====+=====+=====+=====+=====+=====+=====+=====+
// sa[3] |  c  |  h  |  o  |  n  |  g  |  q  |  i  |  n  |  g  |  \0 |
//       +=====+=====+=====+=====+=====+=====+=====+=====+=====+=====+
// sa[.] | ... | ... | ... | ... | ... | ... | ... | ... | ... | ... |
//       +=====+=====+=====+=====+=====+=====+=====+=====+=====+=====+

// char* ps[4];
// char* ps[4] = {"beijing", "tianjin", "shanghai", "chongqing"};
// ps[0] ~ ps[4] 都是可以修改的, 但是其指向的内容不能够修改
//        +=====+           +=====+=====+=====+=====+=====+=====+=====+=====+=====+=====+
// ps[0]  |  &  | --------> |  b  |  e  |  i  |  j  |  i  |  n  |  g  |  \0 |  \0 |  \0 |
//        +=====+           +=====+=====+=====+=====+=====+=====+=====+=====+=====+=====+
// ps[1]  |  &  | --------> |  t  |  i  |  a  |  n  |  j  |  i  |  n  |  \0 |  \0 |  \0 |
//        +=====+           +=====+=====+=====+=====+=====+=====+=====+=====+=====+=====+
// ps[2]  |  &  | --------> |  s  |  h  |  a  |  n  |  g  |  h  |  a  |  i  |  \0 |  \0 |
//        +=====+           +=====+=====+=====+=====+=====+=====+=====+=====+=====+=====+
// ps[3]  |  &  | --------> |  c  |  h  |  o  |  n  |  g  |  q  |  i  |  n  |  g  |  \0 |
//        +=====+           +=====+=====+=====+=====+=====+=====+=====+=====+=====+=====+
// ps[.]  |  &  | --------> | ... | ... | ... | ... | ... | ... | ... | ... | ... | ... |
//        +=====+           +=====+=====+=====+=====+=====+=====+=====+=====+=====+=====+


int main(void){
    char* psa[4] = {0};     // 定义了一个数组, 数组有4个元素, 每个元素都是 char*类型
    
    // char* ps[4] = {"beijing", "tianjin", "shanghai", "chongqing"};

    // 使用二维数组表示字符串数组
    char str[3][10] = {"beijing", "tianjin", "shanghai"};
    for(int i = 0; i < 3; i++){
        printf("%s ", str[i]);
    }
    printf("\n");
    // str[0] = "hebei";           // [ERROR] 表达式必须是可修改的左值 -> 将字符串 hebei首地址赋值给 str[0], str[0]是数组名, 无法修改
    strcpy(str[0], "hebei");       // [ACCEPT]
    printf("%s\n", str[0]);
    
    // "" 和 '' 有区别
    // str[1][0] = "T";            // [ERROR] 不能将 "const char *"类型的值分配到 "char" 类型的实体
    str[1][0] = 'T';               // [ACCEPT]
    printf(str[1]);

    // 字符指针数组指向字符串 - 这些字符串存储在内存的常量区
    // 因此这些字符指针可以修改, 字符指针存储的字符串无法修改
    char* ps[3] = {"beijing", "tianjin", "hainan"};
    for(int i = 0; i < 3; i++){
        printf("%s ", ps[i]);
    }
    printf("\n");
    ps[0] = "hebei";                // [ACCEPT] -> 将字符串 "hebei"的首地址赋值给 ps[0], ps[0] -> "hebei"
    // strcpy(ps[0], "hebei");      // [ERROR] Segmentation Fault: 将字符串 "hebei"拷贝到 ps[0]指向的内存, 常量区
    printf(str[1]);
    return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;
/* 自己实现字符串比较函数 */
// int my_strcmp(const char* s1, const char* s2){...};
int my_strcmp(const char* s1, const char* s2){
    // s1 > s2 返回值大于 0
    // s1 = s2 返回值等于 0
    // s1 < s2 返回值小于 0
    // while(*s1) -> 得到第一个字符
    while(*s1){
        if(*s1 != *s2)
            return *s1 - *s2;
        s1++;
        s2++;
    }
    return *s1 - *s2;
}
int main(void){

    return 0;
}
#endif

#if 0
// gcc ./filename -o ./outname
// ./outname num_1 num_2
#include <iostream>
#include <string.h>
using namespace std;
/* main 函数的参数 */
// 在终端中所输入的任何内容, 操作系统都会当做字符串处理
// int main(int argc, char* argv[]){...}

int main(int argc, char* argv[]){
    // argc: 记录命令行终端输入的命令和参数的个数 (操作系统自动赋值)
    // ./hello -> argc=1
    // ./hello 100 200 -> argc=3

    // argv: 记录命令行的终端中输入的信息对应的字符串首地址
    // ./hello -> argv[0] -> 存储字符串 "./hello"的首地址
    // ./hello 100 200 -> argv[0] -> 存储字符串 "./hello"的首地址
    //                 -> argv[1] -> 存储字符串 "100"的首地址
    //                 -> argv[2] -> 存储字符串 "200"的首地址
    for(int i = 0; i < argc; i++){
        printf("argc = %d, argv[%d] = %s\n", argc, i, argv[i]);
    }
    if(argc != 3){
        cout << "用法: 数字1 数字2" << endl;
        cout << "例如: 10000 20000" << endl;
        return -1;
    }

    int a=0, b=0;
    // atoi -> ascii to int
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    cout << a << ' ' << b << endl;
    printf("sum = %d\n", a+b);
    return 0;
}
#endif

#if 0
/* 预处理指令和大型程序 */
// 编译程序的四个步骤: 预处理 -> 编译 -> 汇编 -> 链接
// 预处理指令 - 预处理阶段会处理的指令

/* #include<...> 文件包含指令 */
// 将所包含文件的内容粘贴到该指令处
// <...> 尖括号包含 ······················ 先找 `-l` 目录, 再找系统目录 `/usr/include`, 适用于系统头文件
// "..." 双引号包含 ······················ 先找 `-l` 目录, 再找当前目录, 最后找系统目录 `/usr/include`, 适用于自己编写的头文件
// gcc -E -o xxx.i xxx.c

// #define
// 无参宏定义 (常量宏)
#define     PI          3.14
// 有参宏定义 (宏函数)
// 为什么是 (X)*(X)
// 如果是 (X * X)
// printf("%d\n", SQUARE(10));      // (10 * 10)
// printf("%d\n", SQUARE(3+7));     // (3 + 7 * 3 + 7) 
#define     SQUARE(X)   (X)*(X)

#define     MAX(X, Y)   ((X) > (Y) ? (X) : (Y))

// #undef   取消宏定义

// 条件编译指令
#include <iostream>
using namespace std;

int main(void){
    cout << PI << endl;
    cout << SQUARE(PI) << endl;
// #undef MAX          // 从这一行之后所有的宏 MAX都无法使用了, 继续编译会报错
    cout << MAX(10, 20) << endl << endl;
    int* p = NULL;
    if(p == NULL){
        printf("出现了空指针:\n");
        printf("%s %s %s %s %d", 
                __DATE__, __TIME__, __FILE__, __FUNCTION__, __LINE__);
        return -1;
    }
    return 0;
}
#endif

/* 条件编译指令 */
#if 0
// VSCODE 中修改 #define A [值]来查看结果
#define     A       3
#include <iostream>
using namespace std;

int main(void){
#if A == 1
    printf("#if A == 1\n");
#elif A == 2
    printf("#if A == 2\n");
#else
    printf("#if A is Others\n");
#endif
#ifndef C
    printf("C Hasn't Been Defined\n");
#define C 100
#endif

#ifndef C
    printf("C Hasn't Been Defined\n");
#else
    printf("C Has Been Defined\n");
#endif
    return 0;
}
#endif

#if 0
#include <stdio.h>
// 编译出现问题: Redefinition Of 'a'
#include "02_a.h"       // int a = 520
#include "02_b.h"       // #include "02_a.h" -> int a = 520; -> 导致重定义
// 需要使用 
// #ifndef _HEADER_H
// #define _HEADER_H
// 头文件内容
// #endif
int main(void){
    printf("a = %d\n", a);
    return 0;
}
#endif

/* 高级指针 */
#if 0
#include <stdio.h>
/* 函数指针 */
// 一个函数在编译时会被分配一个入口地址, 这个入口地址就称为函数的指针(地址)
// · 函数名就是函数的地址
// · 定义存放函数指针的指针变量, 并用函数名初始化
//      - int add(int a, int b){...}
//      - 返回类型 (*函数指针变量)(形参表) = 函数名;
//      - int (*pfunc)(int, int) = add
// · 可以像通过函数名一样通过函数指针调用函数 -> 怎么使用函数, 就怎么使用函数指针变量
//      - 函数指针变量(实参表);
//      - int ret = pfunc(100, 200);
// · 函数指针可以作为函数的参数
//      - 回调函数

int add(int x, int y){
    return x + y;
}

int sub(int x, int y){
    return x - y;
}

int main(void){
    printf("main(): %p\n", main);
    printf(" add(): %p\n", add);
    printf(" sub(): %p\n", sub);

    // 如何定义一个指针变量存储函数的首地址
    // 如何定义函数指针变量
    int (*pfunc)(int, int) = add;
    // 怎么使用函数, 就怎么使用函数指针变量
    // 函数用法: int ret = add(100, 200);
    // 函数指针用法
    int ret = pfunc(100, 200);
    printf("add 函数的返回值为 %d\n", ret);
    printf("add()的地址为: %p, pfunc的地址为: %p\n", add, pfunc);
    return 0;
}
#endif

#if 0
#include <stdio.h>
// int (*pfunc)(int, int) -> 是什么数据类型 -> int (*)(int, int)型
// 并不是系统本身存在的变量类型, 因此可以起别名
// typedef int (*pfun_t)(int, int); // 起完别名后可以直接以 pfunc_t定义函数指针变量
// 注意: 将新的数据类型卸载 *后
typedef int (*pfunc_t)(int, int);
int add(int x, int y){
    return x + y;
}

int sub(int x, int y){
    return x - y;
}
int main(void){
    pfunc_t pfunc_1 = add;
    pfunc_t pfunc_2 = sub;
    int ret = pfunc_1(100, 200);
    printf("add 函数的返回值为 %d\n", ret);
    ret = pfunc_2(300, 50);
    printf("sub 函数的返回值为 %d\n", ret);
    return 0;
}
#endif

#if 0
#include <stdio.h>
/* 函数指针的使用场景 */
// 经典使用场景: 
// 利用函数指针数组实现遍历调用所有指定函数
// 嵌入式一般系统上电, 做一系列硬件初始化的时候 - CPU, dram, time, net, flash...
int add(int x, int y){
    printf("Enter %s\n", __func__);
    return x + y;
}

int sub(int x, int y){
    printf("Enter %s\n", __func__);
    return x - y;
}

int mul(int x, int y){
    printf("Enter %s\n", __func__);
    return x * y;
}

int div(int x, int y){
    printf("Enter %s\n", __func__);
    return x / y;
}

int mod(int x, int y){
    printf("Enter %s\n", __func__);
    return x % y;
}

// 定义 int (*)(int, int) 为 pfunc_t
typedef int (*pfunc_t)(int, int);
// 定义函数指针数组
pfunc_t a[] = {add, sub, mul, div, mod};
int main(void){
    // 比较麻烦
    add(200, 20);
    sub(200, 20);
    mul(200, 20);
    div(200, 20);
    mod(200, 20);

    // 函数指针数组,
    int len = sizeof(a) / sizeof(a[0]);
    pfunc_t pfunc = NULL;
    int ret = 0;
    for(int i = 0; i < len; i++){
        pfunc = a[i];
        ret = pfunc(200, 20);
        printf("ret = %d\n\n", ret);
    }
    return 0;
}
#endif

#if 0
#include <stdio.h>
/* 函数指针可以作为函数的参数 - 回调函数 - 函数指针彼岸两作为形参 */
// QT的 *信号与槽机制* 就是回调函数的典型使用

// 定义回调函数 add和 sub, 可以将这些函数作为函数的参数传递给其他函数
int add(int x, int y){
    printf("Enter %s\n", __func__);
    return x + y;
}

int sub(int x, int y){
    printf("Enter %s\n", __func__);
    return x - y;
}

// 定义 cal函数, 想要使用 cal函数来调用 add函数和 sub函数
// 将来需要通过函数指针变量来间接调用回调函数
// 如果在某个调用函数中, 将形参设置为另一个函数的首地址, 间接调用对应的函数
typedef int (*pfun_t)(int, int);
int cal(int a, int b, pfun_t pfunc){
    if(pfunc == NULL)   return a * b;
    return pfunc(a, b);
}

int main(void){
    // 第三个参数传递的是 add, 为 add函数的首地址, 此时的 cal函数可以间接的去调用 add函数
    // 可以说回调函数是 QT 信号与槽引以为傲的使用方法
    printf("%d\n", cal(100, 200, add));
    printf("%d\n",cal(100, 200, sub));
    printf("%d\n",cal(100, 200, NULL));    // 执行 pfunc == NULL 的代码

    return 0;
}
#endif

#if 0
#include <stdio.h>
/* 指针数组和数组指针 */
// 指针数组是每个元素都是指针的数组
int a, b, c;
int* ptr_arr[] = { &a, &b, &c};

// 数组指针是指向数组的指针
//      m[0] m[0]+1 m[0]+2
//      +====+====+====+
//  m   |    |    |    |
//      +====+====+====+
// m+1  |    |    |    |
//      +====+====+====+
// m+2  |    |    |    |
//      +====+====+====+
int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
int (*p)[4] = arr;

int main(void){
    // 数组指针演示
    int arr_1[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ", arr_1[i][j]);
        }
        printf("\n");
    }

    // 定义数组指针指向二维数组 - 个人理解: int (*)[4]是一个 **指针数组**
    int (*p)[4] = arr_1;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }

    // 二维数组转化为一维数组 - 二维数组名本质上相当于一个数组指针
    int* p2 = (int *) arr_1;     // 轻质将数组指针类型 arr_1转化为普通的 int类型指针
    for(int i = 0; i < 12; i++){
        printf("%d ", p2[i]);
    }
    printf("\n");

    // 一维数组转化为二维数组
    int arr_2[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int (*p3)[4] = (int (*)[4]) arr_2;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ", p3[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
#endif

#if 1
#include <stdio.h>
/* 二级指针与多级指针 */
// 指针变量的地址即指针的指针
// 将一级指针变量的地址保存在另一个指针变量中即构成二级指针
// 二级指针是指向一级指针的指针
// 常用二级指针的函数形参, 接受一级指针地址形式的实参, 以修改调用者指针的目标, 或将其分配资源
// 对一维数组的数组名取地址, 得到的不是二级指针, 而是数组指针
int main(void){
    int a = 100;
    int* p = &a;    // 一级指针 p
    int** pp = &p;  // 二级指针 pp

    printf("a = %d, &a = %p\n", a, &a);
    printf("p = %p, &p = %p, *p = %d\n", p, &p, *p);
    printf("&pp = %p, pp = %p, *pp = %p, **pp = %d\n", &pp, pp, *pp, **pp);
    /* [Out] 观察下面的输出可以发现, pp正是 &p, 对 pp解引用正是 p */
    // p = 000000874f5ff85c, &p = 000000874f5ff850, *p = 100
    // &pp = 000000874f5ff848, pp = 000000874f5ff850, *pp = 000000874f5ff85c, **pp = 100

    return 0;
}
#endif

