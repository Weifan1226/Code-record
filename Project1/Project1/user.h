#define POS_Customer "C:\Users\南原秋希\Desktop\编程\Project1\Project1\customer.txt"
typedef struct customer
{
    int flag;
    char Name[30];          // 姓名
    char Id[30];            // 用户账号
    char Passcode[30];      //密码
    double discount;        //折扣 
    int year, month, day;   //生日  生日当天会有活动呦
    int level;              // 用户会员等级
    float money;              //累计消费
    /*
        1:GreenMan : 原价购买, 生日当天活动优惠差异
        2:Jonior ：九折
        3:Senior ： 八折
        4:Honred ： 七折
        5:Superior : 五折
    */
    //int age; // 年龄
    struct customer* next;
} Customer;

typedef struct User {
    char id[11]; //账号 
    char pwd[20]; //密码 
    char name[15];//姓名为字符串 
    long phone; //电话号码为长整型 
    //int num;//工号
}user;


void login0();  //管理员登陆 密码隐藏已实现
void login1();  //会员登陆 密码隐藏已实现
void reg0();  //管理员注册
void reg1();  //用户注册
void AddCustomer();  //添新客户  
void ShowCustomer();  //显示客户信息  
void QueryCustomer();  //查找客户  模糊查询已实现   
void AlterCustomer();   //修改客户信息  
void DeleteCustomer();  //删除客户  
void Altercode0();  //修改管理员密码 六位密码
void Altercode1();  //修改会员密码 六位密码
void Findback0();  //找回管理员密码
void Findback1();  //找回用户密码
void AddDetailCus(char* operation);  //添加操作明细
void AddDetail_Customer(char* operation, customer c);
void ShowDetailCus();  //显示操纵明细
int vagueChinese(char* str, char* target);  //中文模糊查询
int vagueNum(char* str, char* target);  //编号模糊查询
void backups();
#pragma once
