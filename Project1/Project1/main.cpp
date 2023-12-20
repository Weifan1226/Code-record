#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include"store.h"
#include"user.h"
#include"interface.h"
#include"sort.h"
#include"static.h"
//#include"static.h"

int main()
{
    system("color fc");  
    //Sort_menu();
    //print_menu();
    Interface();
    //SortGoods_Date(POS);
    //SortGoods_menu();   
    //AddGoods(POS); 
    //menu1();
    //ShowGoods(POS);
    //AlterCustomer();
    //ShowCustomer();
    //SortGoods_Quantity(POS);
    //system("cls");
    //system("pause");
    //ShowGoods(POS);
    //QueryGoods(POS);
    //AddCustomer();
    //reg0();
    //Altercode0();
    //login0();
    //Customer_menu();
    //QueryCustomer();
    return 0;
}




//int main() {
//    Goods* head = NULL;
//    int count = read_products(&head, POS);
//    if (count == 0) {                        // 读取失败
//        printf("读取商品信息失败！\n");
//        return 1;
//    }
//    printf("成功读取 %d 条商品信息！\n", count);
//
//    int choice;
//    int int_condition = 0;
//    Condition my_condition;
//    print_menu();
//    scanf("%d", &choice);
//    switch (choice) {
//    case 1: {
//        printf("请输入你想查询统计的商品名\n");
//        char* str = (char*)malloc(sizeof(char) * 100);
//        if (fgets(str, 100, stdin)) {
//            str[strcspn(str, "\n")] = 0;     // 去掉换行符
//            strncpy(my_condition.str, str, sizeof(my_condition.str) - 1);
//        }
//        free(str);
//        break;
//    }
//    case 2: {
//        printf("请输入你想查询统计的进货日期(yyyy/dd)");
//        char* str = (char*)malloc(sizeof(char) * 100);
//        if (fgets(str, 100, stdin)) {
//            str[strcspn(str, "\n")] = 0;     // 去掉换行符
//            if (check_date_format(str)) {
//                strncpy(my_condition.str, str, sizeof(my_condition.str) - 1);
//            }
//            else {
//                printf("日期格式不正确！\n");
//                return 1;
//            }
//        }
//        free(str);
//        break;
//    }
//    case 3: {
//        printf("请输入你想查询统计的保质期(符号 数值)");
//        char* symbol = (char*)malloc(sizeof(char) * 10);
//        char* str = (char*)malloc(sizeof(char) * 100);
//        if (scanf("%s%s", symbol, str) == 2) {
//            if (check_num_format(str)) {
//                my_condition.symbol = symbol[0];
//                strncpy(my_condition.str, str, sizeof(my_condition.str) - 1);
//            }
//            else {
//                printf("保质期格式不正确！\n");
//                return 1;
//            }
//        }
//        free(symbol);
//        free(str);
//        break;
//    }
//    case 4: {
//        printf("请输入你想查询统计的类型");
//        char* str = (char*)malloc(sizeof(char) * 100);
//        if (fgets(str, 100, stdin)) {
//            str[strcspn(str, "\n")] = 0;     // 去掉换行符
//            strncpy(my_condition.str, str, sizeof(my_condition.str) - 1);
//        }
//        free(str);
//        break;
//    }
//    case 5: {
//        printf("请输入你想查询统计的价格(符号 数值)");
//        char* symbol = (char*)malloc(sizeof(char) * 10);
//        char* str = (char*)malloc(sizeof(char) * 100);
//        if (scanf("%s%s", symbol, str) == 2) {
//            if (check_num_format(str)) {
//                my_condition.symbol = symbol[0];
//                strncpy(my_condition.str, str, sizeof(my_condition.str) - 1);
//            }
//            else {
//                printf("价格格式不正确！\n");
//                return 1;
//            }
//        }
//        free(symbol);
//        free(str);
//        break;
//    }
//    }
//}