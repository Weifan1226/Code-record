#define POS_Customer "C:\Users\��ԭ��ϣ\Desktop\���\Project1\Project1\customer.txt"
typedef struct customer
{
    int flag;
    char Name[30];          // ����
    char Id[30];            // �û��˺�
    char Passcode[30];      //����
    double discount;        //�ۿ� 
    int year, month, day;   //����  ���յ�����л��
    int level;              // �û���Ա�ȼ�
    float money;              //�ۼ�����
    /*
        1:GreenMan : ԭ�۹���, ���յ����Żݲ���
        2:Jonior ������
        3:Senior �� ����
        4:Honred �� ����
        5:Superior : ����
    */
    //int age; // ����
    struct customer* next;
} Customer;

typedef struct User {
    char id[11]; //�˺� 
    char pwd[20]; //���� 
    char name[15];//����Ϊ�ַ��� 
    long phone; //�绰����Ϊ������ 
    //int num;//����
}user;


void login0();  //����Ա��½ ����������ʵ��
void login1();  //��Ա��½ ����������ʵ��
void reg0();  //����Աע��
void reg1();  //�û�ע��
void AddCustomer();  //���¿ͻ�  
void ShowCustomer();  //��ʾ�ͻ���Ϣ  
void QueryCustomer();  //���ҿͻ�  ģ����ѯ��ʵ��   
void AlterCustomer();   //�޸Ŀͻ���Ϣ  
void DeleteCustomer();  //ɾ���ͻ�  
void Altercode0();  //�޸Ĺ���Ա���� ��λ����
void Altercode1();  //�޸Ļ�Ա���� ��λ����
void Findback0();  //�һع���Ա����
void Findback1();  //�һ��û�����
void AddDetailCus(char* operation);  //��Ӳ�����ϸ
void AddDetail_Customer(char* operation, customer c);
void ShowDetailCus();  //��ʾ������ϸ
int vagueChinese(char* str, char* target);  //����ģ����ѯ
int vagueNum(char* str, char* target);  //���ģ����ѯ
void backups();
#pragma once
