#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include<windows.h>
#include<stdbool.h>
#include<stdio.h>
#include <stdio.h>
#define POS "test.txt"
typedef struct condition {
    char str[20];     // �����ַ���const char* str
    char symbol;             // �ȽϷ��ţ���ѡֵΪ '>'��'<'��'='.
} Condition;

int read_products(Goods** head, const char* filename); // ���ļ��ж�ȡ��Ʒ��Ϣ
void print_menu(); // ��ӡ�˵�
void print_statistics(const Goods* head, int choice, const Condition condition, int int_condition);  // ����ѡ�����������ͳ��
void print_product(const Goods* product); // ��ӡ��Ʒ��Ϣ��Ƕ�ڡ�print_products��&��print_statistics��������
void print_products(const Goods* head); // ��ӡ������Ʒ��Ϣ
int contains(const char* str1, const char* str2); // �ж�str1�Ƿ����str2��Ƕ�ڡ�print_statistics��������
bool compare(int a, int b, char symbol);
const char* compare_symbol(char symbol);
int check_date_format(char* str);// ������ڸ�ʽ�Ƿ���ȷ����ʽΪyyyy-mm-dd
int check_num_format(char* str);// �����ֵ��ʽ�Ƿ���ȷ��ֻ�ܰ������ֺ�С����
