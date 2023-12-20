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
    // 商品体
    typedef struct goods
{
    int index;              // 0为空， 1为有存货
    char num[20];           // 编号
    char name[20];          // 商品名
    int year, month, day;   // 进货日期
    char duration[20];      // 保质期
    char type[20];          // 类型
    int quantity;           // 总数
    double price;           // 价格
    struct goods *next;
} Goods;

    //typedef struct node {
    //    Goods data; // 商品数据
    //    struct node* next; // 下一个节点指针
    //} Node, * LinkedList;
    void AddGoods(char* filename);  //添新商品      无须模糊
    void InputGoods(char* filename);  //进货       模糊完成
    void ShowGoods(char* filename);  //显示商品信息    无须模糊
    void QueryGoods(char* filename);  //查找商品      模糊完成
    void AlterGoods(char* filename);   //修改商品信息   模糊完成
    void DeleteGoods(char* filename);  //删除商品     模糊完成
    void SaleGoods(char* filename);    //卖出货物     模糊完成
    void CleanFile(char* filename);  //清空文件   
    void UpdateGoodsList(char* input_file, char* goods_file); //从文件读入信息到我的文件中  
    void AddDetail(char* operation);   // 记录操作明细   
    void AddDetail_Goods(char* operation, Goods goods);   // 记录操作明细   
    void ShowDetail();     // 显示操作明细   
    void BackupGoods(char* filename, char* output_file);   // 将数据备份到文件中
#ifdef __cplusplus
}
#endif
#pragma once
