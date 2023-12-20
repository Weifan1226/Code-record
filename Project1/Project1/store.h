#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>
#include<time.h>
#include<ctype.h>
#define POS "test.txt"
#define POS_Input "input.txt"
#define POS_Output "output.txt"
#define POS_Customer "customer.txt"
#define POS_DetailG "detailgoods.txt"
#define POS_DetailC "detailcustomers.txt"


#ifdef __cplusplus
extern "C"
{
#endif
    // ��Ʒ��
    typedef struct goods
{
    int index;              // 0Ϊ�գ� 1Ϊ�д��
    char num[20];           // ���
    char name[20];          // ��Ʒ��
    int year, month, day;   // ��������
    char duration[20];      // ������
    char type[20];          // ����
    int quantity;           // ����
    double price;           // �۸�
    struct goods *next;
} Goods;

    //typedef struct node {
    //    Goods data; // ��Ʒ����
    //    struct node* next; // ��һ���ڵ�ָ��
    //} Node, * LinkedList;
    void AddGoods(char* filename);  //������Ʒ      ����ģ��
    void InputGoods(char* filename);  //����       ģ�����
    void ShowGoods(char* filename);  //��ʾ��Ʒ��Ϣ    ����ģ��
    void QueryGoods(char* filename);  //������Ʒ      ģ�����
    void AlterGoods(char* filename);   //�޸���Ʒ��Ϣ   ģ�����
    void DeleteGoods(char* filename);  //ɾ����Ʒ     ģ�����
    void SaleGoods(char* filename);    //��������     ģ�����
    void CleanFile(char* filename);  //����ļ�   
    void UpdateGoodsList(char* input_file, char* goods_file); //���ļ�������Ϣ���ҵ��ļ���  
    void AddDetail(char* operation);   // ��¼������ϸ   
    void AddDetail_Goods(char* operation, Goods goods);   // ��¼������ϸ   
    void ShowDetail();     // ��ʾ������ϸ   
    void BackupGoods(char* filename, char* output_file);   // �����ݱ��ݵ��ļ���
#ifdef __cplusplus
}
#endif
#pragma once
