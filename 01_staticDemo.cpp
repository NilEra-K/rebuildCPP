#include <iostream>
int g_a = 10;
static int g_b = 20;

void print_1(void){
    std::cout << g_a << std::endl;
}

static void print_2(void){
    std::cout << g_b << std::endl;
}



