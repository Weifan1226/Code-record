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
//    if (count == 0) {                        // ��ȡʧ��
//        printf("��ȡ��Ʒ��Ϣʧ�ܣ�\n");
//        return 1;
//    }
//    printf("�ɹ���ȡ %d ����Ʒ��Ϣ��\n", count);
//
//    int choice;
//    int int_condition = 0;
//    Condition my_condition;
//    print_menu();
//    scanf("%d", &choice);
//    switch (choice) {
//    case 1: {
//        printf("�����������ѯͳ�Ƶ���Ʒ��\n");
//        char* str = (char*)malloc(sizeof(char) * 100);
//        if (fgets(str, 100, stdin)) {
//            str[strcspn(str, "\n")] = 0;     // ȥ�����з�
//            strncpy(my_condition.str, str, sizeof(my_condition.str) - 1);
//        }
//        free(str);
//        break;
//    }
//    case 2: {
//        printf("�����������ѯͳ�ƵĽ�������(yyyy/dd)");
//        char* str = (char*)malloc(sizeof(char) * 100);
//        if (fgets(str, 100, stdin)) {
//            str[strcspn(str, "\n")] = 0;     // ȥ�����з�
//            if (check_date_format(str)) {
//                strncpy(my_condition.str, str, sizeof(my_condition.str) - 1);
//            }
//            else {
//                printf("���ڸ�ʽ����ȷ��\n");
//                return 1;
//            }
//        }
//        free(str);
//        break;
//    }
//    case 3: {
//        printf("�����������ѯͳ�Ƶı�����(���� ��ֵ)");
//        char* symbol = (char*)malloc(sizeof(char) * 10);
//        char* str = (char*)malloc(sizeof(char) * 100);
//        if (scanf("%s%s", symbol, str) == 2) {
//            if (check_num_format(str)) {
//                my_condition.symbol = symbol[0];
//                strncpy(my_condition.str, str, sizeof(my_condition.str) - 1);
//            }
//            else {
//                printf("�����ڸ�ʽ����ȷ��\n");
//                return 1;
//            }
//        }
//        free(symbol);
//        free(str);
//        break;
//    }
//    case 4: {
//        printf("�����������ѯͳ�Ƶ�����");
//        char* str = (char*)malloc(sizeof(char) * 100);
//        if (fgets(str, 100, stdin)) {
//            str[strcspn(str, "\n")] = 0;     // ȥ�����з�
//            strncpy(my_condition.str, str, sizeof(my_condition.str) - 1);
//        }
//        free(str);
//        break;
//    }
//    case 5: {
//        printf("�����������ѯͳ�Ƶļ۸�(���� ��ֵ)");
//        char* symbol = (char*)malloc(sizeof(char) * 10);
//        char* str = (char*)malloc(sizeof(char) * 100);
//        if (scanf("%s%s", symbol, str) == 2) {
//            if (check_num_format(str)) {
//                my_condition.symbol = symbol[0];
//                strncpy(my_condition.str, str, sizeof(my_condition.str) - 1);
//            }
//            else {
//                printf("�۸��ʽ����ȷ��\n");
//                return 1;
//            }
//        }
//        free(symbol);
//        free(str);
//        break;
//    }
//    }
//}