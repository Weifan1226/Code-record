#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include<windows.h>
#include<stdbool.h>
#include<stdio.h>
#include <stdio.h>
#define POS "test.txt"
typedef struct condition {
    char str[20];     // 条件字符串const char* str
    char symbol;             // 比较符号，可选值为 '>'，'<'，'='.
} Condition;

int read_products(Goods** head, const char* filename); // 从文件中读取商品信息
void print_menu(); // 打印菜单
void print_statistics(const Goods* head, int choice, const Condition condition, int int_condition);  // 根据选择的条件进行统计
void print_product(const Goods* product); // 打印商品信息，嵌在“print_products”&“print_statistics”函数中
void print_products(const Goods* head); // 打印所有商品信息
int contains(const char* str1, const char* str2); // 判断str1是否包含str2，嵌在“print_statistics”函数中
bool compare(int a, int b, char symbol);
const char* compare_symbol(char symbol);
int check_date_format(char* str);// 检查日期格式是否正确，格式为yyyy-mm-dd
int check_num_format(char* str);// 检查数值格式是否正确，只能包含数字和小数点
