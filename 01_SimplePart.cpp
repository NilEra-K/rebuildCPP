/**
 * @file 01_SimplePart.cpp
 * @author NilEra (nilera0001@gmail.com)
 * @brief 简单复习一下C++的语法知识, SimplePart是简单的部分, 过于简单的不展开叙述
 * @version 0.1
 * @date 2023-04-08
 * @copyright Copyright (c) 2023
 * 
 */

#if 0
// typedef用法
// typedef 声明, 使用 typedef为一个已有的类型取一个新的名字
// 注意与 template <typename DataType> 区分 
#include <iostream>

using namespace std;
typedef int ZhengXing;
int main()
{
    ZhengXing i = 1000;
    cout << i;          // 正常输出: 结果为1000
    return 0;
}
#endif


#if 0
// 参考相关 Blog:
// https://blog.csdn.net/weixin_49503250/article/details/129978106

// enum 枚举类型: 允许为一组整数赋予有意义的名称
// enum 语法:   
// enum 枚举名{
//      标识符[=整形常数],
//      标识符[=整形常数],
//      ...
//      标识符[=整形常数]
// }枚举变量;

// C++ 11 新特性
// 强枚举类型 
#include <iostream>
#include <string>
using namespace std;

enum Day {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY};

bool isWeekday(Day day) {
    return day >= MONDAY && day <= FRIDAY;
}

bool isWeekend(Day day) {
    return day == SATURDAY || day == SUNDAY;
}

string dayToString(Day day) {
    switch (day) {
        case MONDAY:    return "Monday";
        case TUESDAY:   return "Tuesday";
        case WEDNESDAY: return "Wednesday";
        case THURSDAY:  return "Thursday";
        case FRIDAY:    return "Friday";
        case SATURDAY:  return "Saturday";
        case SUNDAY:    return "Sunday";
        default:        return "Invalid day";
    }
}

int main()
{
    // 默认情况下, 编译器设置第一个枚举量为 0, 下一个为 1, 以此类推
    // 枚举变量可以省略
    //              0      1       2        3         4
    enum course {Chinese, Math, English, Physics, Chemistry} c;
    c = English;
    cout << c << endl;

    //            0    1      1       2      3       4      5
    enum colors {Red, Blue, Black=1, Pink, Yellow, Green, Orange} color;
    color = Blue;
    cout << color << endl;

    color = Black;
    cout << color << endl;

    color = Yellow;
    cout << color << endl;
    int wcolor;
    cin >> wcolor;
    switch (wcolor)
    {
        case Red :
            cout << "The Color is Red" << endl;
            break;
        case Math :     // Math = 1 也就是 Math的开关是1
            cout << "The Course is Math" << endl;
            break;
        case Pink :
            cout << "The Color is Blue" << endl;
            break;
        // Black = 1, 而之前的 Math已经为 1了, switch不允许相同的开关, 因此报错
        // case Black :    
        //     cout << "The Color is Black" << endl;
        //     break;
        default :
            cout << "Invalid selection\n";
    }

    enum Roster {Tom = 1, Sharon, Bill, Teresa, John};
    int who;
    cin >> who;
    switch (who)
    {
        case Tom :
            cout << "Tom's birthday is January 3.\n";
            break;
        case Sharon :
            cout << "Sharon's birthday is April 22.\n";
            break;
        case Bill :
            cout << "Bill's birthday is December 19.\n";
            break;
        case Teresa :
            cout << "Teresa's birthday is February 2.\n";
            break;
        case John :
            cout << "John's birthday is June 17.\n";
            break;
        default :
            cout << "Invalid selection\n";
    }

    Day today = WEDNESDAY;
    cout << "Today is " << dayToString(today) << endl;
    if (isWeekday(today)) {
        cout << "Today is a weekday." << endl;
    } else if (isWeekend(today)) {
        cout << "Today is a weekend." << endl;
    }

    // Using a loop to iterate over the enum values
    for (int i = MONDAY; i <= SUNDAY; i++) {
        Day day = static_cast<Day>(i);
        cout << dayToString(day) << " is " << (isWeekday(day) ? "a weekday" : "a weekend") << endl;
    }
    return 0;
}
#endif

#if 0
// 变量声明
// 普通的变量声明不再阐述
// extern 变量声明语法
// extern 数据类型 变量名 
#include <iostream>

// extern 需要引用外部文件
#include "01_externDemo.cpp"

using namespace std;
int main()
{
    extern int a;
    extern double b;
    cout << a << ' ' << b << endl; 
    return 0;
}
#endif


#if 0
// for循环语法结构
// C++ 有很类似于 Python中的 for语句写法
// 传统 for 循环: for(init; condition; increment){statement(s);}
// 增强 for-each 循环: 用于 STL中
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    // 传统 for 循环, 一种类似于 Python 的写法
    int array[5] = {3, 2, 1};
    for(int x: array){
        cout << x << ' ';
    }
    cout << endl;

    string str[5] = {"a", "b", "c", "d", "e"};
    for(string x: str){
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}
#endif


#if 1
// 字符数组
// 动态创建数组以及指针的一些知识
#include <iostream>

using namespace std;

int main()
{
    char arr_1[] = "hello world";
    char arr_2[10] = "see u";
    cout << arr_1 << ' ' << arr_2 << endl;

    char* pc1 = arr_1;
    char* pc2;
    pc2 = arr_2;

    cout << *pc1 << ' ' << pc2 << endl;
    cout << *(pc1 + 2) << endl;

    // 使用 new动态创建数组
    int* arr_3 = new int[2];
    int* arr_4 = new int[3]{1, 2, 3};
    char* arr_5 = new char[6]{"hello"};
    cout << *arr_3 << ' ' << arr_4 << ' ' << arr_5 << endl;

    // 使用 new动态创建二维数组
    // 01:
    int (*p)[10] = new int[5][10];

    // 02:
    int **q = new int* [5];
    for(int i=0; i<5; i++)
        q[i] = new int[10];
    
    q[1][1] = 10;
    cout<<"q[1][1] = " << q[1][1] <<endl;
    cout<< "sizeof(q) = "<<sizeof(q)<<endl;

    // 使用 new动态创建二维数组
    int size = 0;
    cin >> size;
    int** arr_6 = new int* [size];
    for(int i=0; i<size; i++)
        arr_6[i] = new int[3];
    arr_6[1][1] = 3;
    cout<<"arr_6[1][1] = "<< arr_6[1][1]<<endl;
    cout<< "sizeof(arr_6) = "<< sizeof(arr_6)<<endl;
    cout<< sizeof(arr_6) / sizeof(arr_6[0][0]) << ' ' <<sizeof(arr_6)/sizeof(arr_6[0])<<endl;

    int arr_7[3][5];
    cout<<"sizeof(arr_7) = "<<sizeof(arr_7)<<endl;
    cout<<sizeof(arr_7) / sizeof(arr_7[0][0])<<' '<<sizeof(arr_7)/sizeof(arr_7[0]);
    return 0;
}
#endif


