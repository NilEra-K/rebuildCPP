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

#if 1
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


