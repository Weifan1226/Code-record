#include"user.h"
#include"store.h"
#include"interface.h"
#define _CRT_SECURE_NO_WARNINGS

void login0() {
	user a, b;
	FILE* fp;
	int flag = 1;
	fp = fopen("user.txt", "r");
	fread(&b, sizeof(struct User), 1, fp); //����һ���ṹ���ַ��� д��b
	//system("color fc");
	printf("�������˺�:");
	scanf("%s", &a.id);
	while (flag == 1) {
		if (!strcmp(a.id, b.id)) {
			break;
		}
		else {
			if (fp == NULL) {
				printf("δ���ڹ���Ա�˻�����ע�ᣡ\n");
				system("pause");
				system("cls");
				set0();
			}
			if (!feof(fp)) {/*���ļ�û�ж���*/
				fread(&b, sizeof(struct User), 1, fp);
				/*�������� b ��ŵĵ�ַλ�ã��ڴ��С��ÿ�ζ�ȡһ�����ݿ� 1 ���Զ��ķ�ʽ���ļ�*/
			}
			else {
				printf("δ�ҵ��û���Ϣ��������ѡ��\n");
				fclose(fp);
				system("pause");
				system("cls");
				getchar();
				set0();
			}
		}
	}
	while (flag == 1) {
		printf("��������λ���룺");
		int i = 0;
		while ((a.pwd[i] = getch()) != 13)//getch()����ֵ��һ����ֵ���س��ļ�ֵ��13
		{	
			if (a.pwd[i] == 8 && i == 0) continue;//���˸��������
			if (a.pwd[i] == 8 && i != 0) {
				i -= 1;
				printf("\b \b");
				continue;
			}//�˸�ɾ��*�Ų��ڸǿո�
								//�����������洢������������Ļ�������* ���������� 
			i++;
			printf("*");//��������
		}
		a.pwd[i] = '\0';//�����Ļس���ɽ����������飩 
		printf("\n");
		if (!strcmp(a.pwd, b.pwd)) {
			fclose(fp);
			printf("��½�ɹ���һ�����ת��\n");
			Sleep(1000);
			system("cls");
			menu0();
			break;
		}
		else {
			printf("����������������룡\n");
		}
	}
}

void reg0() {
	user a, b;
	FILE* fp;
	int cnt = 0;
	int flag = 1;
	char temp[20] = { 0 };
	//system("color fc");
	printf("%70s", "��ӭ����ע��ҳ��\n");
	//Sleep(1000);
	fp = fopen("user.txt", "r");
	fread(&b, sizeof(struct User), 1, fp); //�������ݴ�ŵĵ�ַ b  
	printf("�������˺�\n");
	scanf("%s", &a.id);
	while (flag)
	{
		if (strcmp(a.id, b.id)) /*������������*/
		{
			if (!feof(fp))    /*���δ���ļ�β*/
			{
				fread(&b, sizeof(struct User), 1, fp);
			}
			else break;
		}
		else
		{
			printf("���û����Ѵ��ڣ�������ѡ��\n");
			getchar();
			rewind(stdin);
			system("pause");
			system("cls");
			return;
		}
	}
	printf("������绰����\n");
	scanf(" %ld", &a.phone);
	printf("���������Ա����\n");
	scanf(" %s", &a.name);
	printf("��������λ����\n");
	while (scanf(" %s", &a.pwd) != EOF) {
		if (strlen(a.pwd) != 6) {
			printf("���볤�ȴ������������룡\n");
		}
		else break;
	}
	printf("��ȷ������\n");
	scanf(" %s", &temp);
	do {
		if (!strcmp(a.pwd, temp))
		{
			fp = fopen("user.txt", "a");//׷��һ���˺� 
			fwrite(&a, sizeof(struct User), 1, fp);/* a ��д���ļ���ָ�� ����ַ��*/
			printf("�˺�ע��ɹ�!һ�����ת��\n");
			//printf("��½�ɹ���һ�����ת��\n");
			Sleep(1000);
			fclose(fp);
			//system("pause");
			system("cls");
			return;
		}
		else
		{
			printf("�������벻ƥ�䣡���������룡\n");
			getchar();
			while (scanf(" %s", &a.pwd) != EOF) {
				if (strlen(a.pwd) != 6) {
					printf("���볤�ȴ������������룡\n");
				}
				else break;
			}
			printf("��ȷ������\n");
			scanf("%s", &temp);
		}
	} while (1);
}
void login1() {
	customer a, b;
	FILE* fp;
	int flag = 1;
	fp = fopen("customer.txt", "r");
	fread(&b, sizeof(struct customer), 1, fp); //����һ���ṹ���ַ��� д��b
	//system("color fc");
	printf("�������˺�:");
	scanf("%s", &a.Id);
	while (flag == 1) {
		if (!strcmp(a.Id, b.Id)&&b.flag==1) {
			break;
		}
		else {
			if (fp == NULL) {
				printf("δ���ڹ���Ա�˻�����ע�ᣡ\n");
				system("pause");
				system("cls");
				set0();
			}
			if (!feof(fp)) {/*���ļ�û�ж���*/
				fread(&b, sizeof(struct customer), 1, fp);				
			}
			else {
				printf("δ�ҵ���Ա��Ϣ��������ѡ��\n");
				fclose(fp);
				system("pause");
				system("cls");
				getchar();
				set0();
			}
		}
	}
	while (flag == 1) {
		printf("��������λ���룺");
		int i = 0;
		while ((a.Passcode[i] = getch()) != 13)//getch()����ֵ��һ����ֵ���س��ļ�ֵ��13
		{		
			if (a.Passcode[i] == 8 && i == 0) continue;//���˸��������
			if (a.Passcode[i] == 8 && i != 0) {
				i -= 1;
				printf("\b \b");
				continue;
			}//�˸�ɾ��*�Ų��ڸǿո�
			//�����������洢������������Ļ�������* ���������� 
			i++;
			printf("*");//��������
		}
		a.Passcode[i] = '\0';//�����Ļس���ɽ����������飩 
		printf("\n");
		if (!strcmp(a.Passcode, b.Passcode)) {
			fclose(fp);
			printf("��½�ɹ���һ�����ת��\n");
			Sleep(1000);
			/*printf("��½�ɹ���\n");
			system("pause");*/
			system("cls");
			menu1();
			break;
		}
		else {
			printf("����������������룡\n");
		}
	}
}
void reg1() {
	customer a, b;
	FILE* fp;
	int cnt = 0;
	int flag = 1;
	char temp[20] = { 0 };
	printf("%70s", "��ӭ����ע��ҳ��\n");
	fp = fopen("customer.txt", "r");
	fread(&b, sizeof(struct customer), 1, fp); //�������ݴ�ŵĵ�ַ b  
	printf("�������˺�\n");
	scanf("%s", &a.Id);
	while (flag)
	{
		if (strcmp(a.Id, b.Id)||b.flag!=1) /*������������*/
		{
			if (!feof(fp))    /*���δ���ļ�β*/
			{
				fread(&b, sizeof(struct customer), 1, fp);
			}
			else break;
		}
		else
		{
			printf("���û����Ѵ��ڣ�������ѡ��\n");
			getchar();
			rewind(stdin);
			//Sleep(800);
			system("pause");
			system("cls");
			return;
		}
	}
	printf("����������\n");//��if����ȫͨ��
	scanf("%s", &a.Name);
	printf("�������������\n");
	scanf("%d %d %d", &a.year, &a.month, &a.day);
	a.flag = 1;
	a.level = 1;
	a.discount = 1;
	a.money = 0.0;
	printf("��������λ����\n");
	while (scanf(" %s", &a.Passcode) != EOF) {
		if (strlen(a.Passcode) != 6) {
			printf("���볤�ȴ������������룡\n");
		}
		else break;
	}
	printf("��ȷ������\n");
	scanf(" %s", &temp);
	do {
		if (!strcmp(a.Passcode, temp))
		{
			fp = fopen("customer.txt", "a");//׷��һ���˺� 
			fwrite(&a, sizeof(struct customer), 1, fp);/* a ��д���ļ���ָ�� ����ַ��*/
			printf("�˺�ע��ɹ�!һ�����ת��\n");
			//Sleep(500);
			fclose(fp);
			//printf("��½�ɹ���һ�����ת��\n");
			Sleep(1000);
			system("cls");
			return;
		}
		else
		{
			printf("�������벻ƥ�䣡���������룡\n");
			getchar();
			while (scanf(" %s", &a.Passcode) != EOF) {
				if (strlen(a.Passcode) != 6) {
					printf("���볤�ȴ������������룡\n");
				}
				else break;
			}
			printf("��ȷ������\n");
			scanf("%s", &temp);
		}
	} while (1);
}

//void AddCustomer() {
//    customer a, b;
//	int cnt = 0, flag = 1;
//	char temp[20] = { 0 };
//    FILE* fp = fopen("customer.txt", "r");
//    fread(&b, sizeof(struct customer), 1, fp);
//    printf("�������˺�\n");
//    scanf("%s", &a.Id);
//	while (flag){
//		if (strcmp(a.Id, b.Id)||b.flag!=1) /*������������*/
//		{
//			if (!feof(fp))    /*���δ���ļ�β*/
//			{
//				fread(&b, sizeof(struct customer), 1, fp);
//			}
//			else break;
//		}
//		else
//		{
//			printf("���˺��Ѵ��ڣ�������ѡ��\n");
//			getchar();
//			rewind(stdin);
//			system("cls");
//			return;
//		}
//	}
//	a.flag = 1;
//	printf("����������\n");
//	scanf("%s", &a.Name);
//	printf("�������������\n");
//	scanf("%d %d %d", &a.year, &a.month, &a.day);
//	printf("�������û��ȼ���1-5��\n");
//	scanf("%d", &a.level);
//	printf("�������ۿ�\n");
//	scanf("%f", &a.discount);
//	printf("���������Ѷ�\n");
//	scanf("%f", &a.money);
//	printf("��������λ����\n");
//	scanf(" %s", &a.Passcode);
//	printf("��ȷ������\n");
//	scanf(" %s", &temp);
//	do {
//		if (!strcmp(a.Passcode, temp))
//		{
//			fp = fopen("customer.txt", "a");
//			fwrite(&a, sizeof(struct customer), 1, fp);
//			fclose(fp);
//			printf("�����Ϣ�ɹ���\n");
//			system("pause");
//			system("cls");
//			return;
//		}
//		else
//		{
//			printf("�������벻ƥ�䣡���������룡\n");
//			getchar();
//			scanf("%s", &a.Passcode);
//			printf("��ȷ������\n");
//			scanf("%s", &temp);
//		}
//	} while (1);
//}
void AddCustomer() {
	int cnt = 0;
	FILE* fp = fopen(POS_Customer, "r");
	if (fp == NULL) {
		printf("���ļ�ʧ�ܣ�\n");
		Goods_menu();
	}
	char temp[20] = { 0 };
	int fail = 0, success = 0;
	int choose = 1;
	Customer* head = NULL;
	Customer* tail = NULL;
	Customer c;
	while (choose == 1) {
		Customer* pb = (Customer*)malloc(sizeof(Customer));
		pb->flag = 1;
		printf("�������˺�\n");
		scanf("%s", pb->Id);
		fseek(fp, 0, SEEK_SET);
		while (fread(&c, sizeof(Customer), 1, fp) == 1) {
			if (!strcmp(pb->Id, c.Id) && c.Id != 0) {
				printf("���˺��Ѵ��ڣ�������ѡ��\n");
				AddDetail_Customer("����û���Ϣʧ�ܣ��˺��ظ���", c);
				getchar();
				rewind(stdin);
				free(pb);
				system("cls");
				return;
			}
			else continue;
		}
		printf("����������\n");
		scanf("%s", pb->Name);
		printf("���������������(�Կո����:yyyy mm dd��\n");
		while (scanf("%d %d %d", &pb->year, &pb->month, &pb->day)!=EOF) {
			if (pb->year < 0 || pb->month>12 || pb->month < 0 || pb->day < 0 || pb->day>31) {
				printf("������� ���������룡\n");
			}
			else break;
		}
		printf("�������û��ȼ���1-5��\n");
		scanf("%d", &pb->level);
		printf("�������ۿ�(0.x)\n");
		scanf("%f", &pb->discount);
		printf("���������Ѷ�\n");
		scanf("%f", &pb->money);
		printf("��������λ����\n");
		while (scanf(" %s", pb->Passcode) != EOF) {
			if (strlen(pb->Passcode) != 6) {
				printf("���볤�ȴ������������룡\n");
			}
			else break;
		}
		printf("��ȷ������\n");
		scanf(" %s", &temp);
		while (1) {
			if (!strcmp(pb->Passcode, temp)) {
				//fp = fopen("customer.txt", "a");//׷��һ���˺� 
				//fseek(fp, 0, SEEK_END);
				//fwrite(pb, sizeof(struct customer), 1, fp);/* a ��д���ļ���ָ�� ����ַ��*/
				printf("�����Ϣ�ɹ�!\n");
				AddDetail_Customer("����û���Ϣ�ɹ���", c);
				cnt++;
				//fclose(fp);
				break;
			}
			else
			{
				printf("�������벻ƥ�䣡���������룡\n");
				getchar();
				while (scanf(" %s", &pb->Passcode) != EOF) {
					if (strlen(pb->Passcode) != 6) {
						printf("���볤�ȴ������������룡\n");
					}
					else break;
				}
				printf("��ȷ������\n");
				scanf("%s", &temp);
			}
		}
		pb->next = NULL;
		if (head == NULL) {
			head = pb;
			tail = pb;
		}
		else {
			tail->next = pb;
			tail = pb;
		}
		printf("����1�Լ���¼��,����0��ֹͣ¼��\n");
		scanf("%d", &choose);
		system("cls");
	}
	Customer* p = head;
	fp = fopen(POS_Customer, "a");
	while (p != NULL) {
		fwrite(p, sizeof(Customer), 1, fp);
		p = p->next;
	}
	printf("���ι�¼����%d���ͻ�����Ϣ\n",cnt);
	p = head;
	while (p != NULL) {
		Customer* temp = p->next;
		free(p);
		p = temp;
	}//�ͷ��ڴ�
	fclose(fp);
	system("pause");
	system("cls");
	AddDetailCus("��ӿͻ���Ϣ�ɹ�");
}

void ShowCustomer() {
	printf("\t\t\t   ********************�ͻ���Ϣ���£�************************\n");
	printf("\t\t\t   %-10s %-12s %-13s %-12s %-10s\n", "�˺�", "����", "����", "��Ա�ȼ�", "�ۼ�����");
	FILE* fp = fopen(POS_Customer, "r");
	customer c;
	int cnt = 0;
	if (fp == NULL) {
		printf("���ļ�ʧ�ܣ�\n");
		Goods_menu();
	}
	if (fp == 0) {
		printf("δ�����û���Ϣ��\n");
		return;
	}
	fseek(fp, 0, SEEK_SET);
	while (fread(&c, sizeof(struct customer), 1, fp) == 1) {
		if (c.flag == 1) {
			printf("\t\t\t   %-8s %-6s %6d/%d/%d %10d %15f \n", c.Id, c.Name, c.year, c.month, c.day, c.level, c.money);
			cnt++;
		}
	}
	fclose(fp);
	printf("\t\t\t\t\t   ϵͳ�й���%d����Ա����Ϣ\n",cnt);
	printf("\t\t\t   ************************************************************\n");
	AddDetailCus("��ʾ��Ա��Ϣ�ɹ�");
	system("pause");
	system("cls");
}

//void QueryCustomer() {
//	customer c;
//	int flag = 0;
//	char temp[20]={0};
//	FILE* fp = fopen(POS_Customer, "r");
//	if (fp == NULL) {
//		printf("���ļ�ʧ�ܣ�\n");
//		exit(1);
//	}
//	else {
//		printf("��������Ҫ��ѯ���û��������˺�\n");
//		scanf("%s", temp);
//		while (fread(&c, sizeof(struct customer), 1, fp) == 1) {
//			if ((strcmp(c.Name, temp) != 0 && strcmp(c.Id, temp) != 0)||c.flag != 1) {
//				continue;
//				//printf("δ�ҵ��û���Ϣ��\n");
//				//system("pause");
//				//system("cls");
//				//Customer_menu();
//			}
//			else {
//				if (flag == 0) {
//					printf("\t\t\t   ********************�ͻ���Ϣ���£�************************\n");
//					printf("\t\t\t   %-10s %-12s %-13s %-12s %-10s\n", "�˺�", "����", "����", "��Ա�ȼ�", "�ۼ�����");
//					printf("\t\t\t   %-8s %-6s %6d/%d/%d %10d %15f \n", c.Id, c.Name, c.year, c.month, c.day, c.level, c.money);
//					flag = 1;
//				}
//				else printf("\t\t\t   %-8s %-6s %6d/%d/%d %10d %15f \n", c.Id, c.Name, c.year, c.month, c.day, c.level, c.money);				
//			}
//		}
//		if(flag==1)AddDetailCus("��ѯ��Ա��Ϣ�ɹ�");
//		if (flag == 0) {
//			printf("δ�ҵ��û���Ϣ��\n");
//			AddDetailCus("��ѯ��Ա��Ϣʧ�ܣ�δ�ҵ��û���Ϣ��");
//			system("pause");
//			system("cls");
//			fclose(fp);
//			Customer_menu();
//		}
//		else printf("\t\t\t   ************************************************************\n");
//	}
//	fclose(fp);
//	system("pause");
//	system("cls");
//}
int vagueChinese(char* str, char* target) {
	if ((str[0] >= '0' && str[0] <= '9') || (str[0] >= 'a' && str[0] <= 'z')|| (str[0] >= 'A' && str[0] <= 'Z')) return 0;//�ж��Ƿ�Ϊ���ִ�
	int i, j, tag = 0;
	for (i = 0;i < strlen(str);i += 2) {
		for (j = 0;j < strlen(target);j += 2) {
			if (str[i] == target[j] && str[i + 1] == target[j + 1]) {
				tag++;
			}
		}
	}
	return tag == strlen(str) / 2 ? 1 : 0;
}
int vagueNum(char* str, char* target) {
	if (strstr(target, str) == NULL) return 0;
	else return 1;
}
void QueryCustomer() {
	customer c;
	int flag = 0;
	char temp[20] = { 0 };
	FILE* fp = fopen(POS_Customer, "r");
	if (fp == NULL) {
		printf("���ļ�ʧ�ܣ�\n");
		exit(1);
	}
	else {
		printf("��������Ҫ��ѯ���û��������˺�\n");
		fseek(fp, 0, SEEK_SET);
		scanf("%s", temp);	
		while (fread(&c, sizeof(struct customer), 1, fp) == 1) {
			
			if ((vagueNum(temp, c.Id) == 0 && vagueChinese(temp, c.Name) == 0 && vagueNum(temp, c.Name) == 0) || c.flag != 1) {
				continue;
				//printf("δ�ҵ��û���Ϣ��\n");
				//system("pause");
				//system("cls");
				//Customer_menu();
			}
			else {
				if (flag == 0) {
					printf("\t\t\t   ********************�ͻ���Ϣ���£�************************\n");
					printf("\t\t\t   %-10s %-12s %-13s %-12s %-10s\n", "�˺�", "����", "����", "��Ա�ȼ�", "�ۼ�����");
					printf("\t\t\t   %-8s %-6s %6d/%d/%d %10d %15f \n", c.Id, c.Name, c.year, c.month, c.day, c.level, c.money);
					flag = 1;
				}
				else printf("\t\t\t   %-8s %-6s %6d/%d/%d %10d %15f \n", c.Id, c.Name, c.year, c.month, c.day, c.level, c.money);
			}
		}
		if (flag == 1)AddDetailCus("��ѯ��Ա��Ϣ�ɹ�");
		if (flag == 0) {
			printf("δ�ҵ��û���Ϣ��\n");
			AddDetailCus("��ѯ��Ա��Ϣʧ�ܣ�δ�ҵ��û���Ϣ��");
			system("pause");
			system("cls");
			fclose(fp);
			Customer_menu();
		}
		else printf("\t\t\t   ************************************************************\n");
	}
	fclose(fp);
	system("pause");
	system("cls");
}
void AlterCustomer() {
	customer b;
	char choose[8]={0};
	int flag = 0;
	char temp1[20] = { 0 };
	char temp2[20] = { 0 };
	FILE* fp = fopen(POS_Customer, "r");
	if (fp == NULL) {
		printf("���ļ�ʧ�ܣ�\n");
		exit(1);
	}
	else {
		printf("��������Ҫ�޸���Ϣ���˺�\n");
		scanf("%s", temp1);
		fseek(fp, 0, SEEK_SET);
		while (fread(&b, sizeof(struct customer), 1, fp) == 1) {
			if (strcmp(b.Id, temp1)||b.flag != 1) {
				continue;
			}
			else {
				flag = 1;
				printf("\t\t\t   ********************�ͻ���Ϣ���£�************************\n");
				printf("\t\t\t   %-10s %-12s %-13s %-12s %-10s\n", "�˺�", "����", "����", "��Ա�ȼ�", "�ۼ�����");
				printf("\t\t\t   %-8s %-6s %6d/%d/%d %10d %15f \n", b.Id, b.Name, b.year, b.month, b.day, b.level, b.money);
				printf("\t\t\t   ************************************************************\n");
				printf("��ѡ��Ҫ�޸ĵ���Ϣ��1���� 2�������� 3�û��ȼ� 4�ۿ� 5�����ܶ� 6����(����������)\n");
				scanf("%s", choose);
				for (int i = 0;i < strlen(choose);i++) {
					switch (choose[i]) {
					case '1':
						printf("����������\n");
						scanf("%s", &b.Name);
						break;
					case '2':
						printf("���������������(�Կո����:yyyy mm dd��\n");
						while (scanf("%d %d %d", b.year, b.month, b.day) != EOF) {
							if (b.year < 0 || b.month>12 || b.month < 0 || b.day < 0 || b.day>31) {
								printf("������� ���������룡\n");
							}
							else break;
						}
						break;
					case '3':
						printf("�������û��ȼ���1-5��\n");
						scanf("%d", &b.level);
						break;
					case '4':
						printf("�������ۿ�\n");
						scanf("%f", &b.discount);
						break;
					case '5':
						printf("���������Ѷ�\n");
						scanf("%f", &b.money);
						break;
					case '6':
						printf("��������λ����\n");
						while (scanf(" %s", b.Passcode) != EOF) {
							if (strlen(b.Passcode) != 6) {
								printf("���볤�ȴ������������룡\n");
							}
							else break;
						}
						printf("��ȷ������\n");
						scanf(" %s", &temp2);
						do {
							if (!strcmp(b.Passcode, temp2))
							{
								fp = fopen(POS_Customer, "r+");
								fwrite(&b, sizeof(struct customer), 1, fp);
								fclose(fp);
								printf("�޸���Ϣ�ɹ���\n");
								AddDetailCus("�޸Ļ�Ա��Ϣ�ɹ�");
								system("pause");
								system("cls");
								Customer_menu();
							}
							else
							{
								printf("�������벻ƥ�䣡���������룡\n");
								getchar();
								while (scanf(" %s", b.Passcode) != EOF) {
									if (strlen(b.Passcode) != 6) {
										printf("���볤�ȴ������������룡\n");
									}
									else break;
								}
								printf("��ȷ������\n");
								scanf("%s", &temp2);
							}
						} while (1);
						break;
					default:
						break;
					}
				}
				Customer c = b;
				b.flag = 0; strcpy(b.Id, b.Id);strcpy(b.Name, b.Name);b.year = b.year;b.month = b.month;b.day = b.day;b.level = b.level;b.money = b.money;
				fp = fopen(POS_Customer, "r+");
				fwrite(&c, sizeof(struct customer), 1, fp);
				fwrite(&b, sizeof(struct customer), 1, fp);
				fclose(fp);
				printf("�޸���Ϣ�ɹ���\n");
				AddDetailCus("�޸Ļ�Ա��Ϣ�ɹ�");
				system("pause");
			}
		}
		if (flag == 0) {
			printf("δ�ҵ��û���Ϣ��\n");
			system("pause");
			system("cls");
			Customer_menu();
		}
	}
	//system("pause");
	system("cls");
}
void DeleteCustomer() {
	customer c;
	int choose, mark = 0;
	FILE* fp = fopen(POS_Customer, "r");
	char temp[20] = { 0 };
	if (fp == NULL) {
		printf("���ļ�ʧ�ܣ�\n");
		exit(1);
	}
	else {
		printf("��������Ҫɾ����Ϣ���û��˺�\n");
		scanf("%s", temp);
		fseek(fp, 0, SEEK_SET);
		while (fread(&c, sizeof(customer), 1, fp) == 1) {
			if ((!strcmp(temp, c.Id))&&c.flag==1) {
				printf("\t\t\t   ********************�ͻ���Ϣ���£�************************\n");
				printf("\t\t\t   %-10s %-12s %-13s %-12s %-10s\n", "�˺�", "����", "����", "��Ա�ȼ�", "�ۼ�����");
				printf("\t\t\t   %-8s %-6s %6d/%d/%d %10d %15f \n", c.Id, c.Name, c.year, c.month, c.day, c.level, c.money);
				printf("\t\t\t   ************************************************************\n");
				printf("�Ƿ�ȷ��ɾ����(����1��ɾ��)\n");
				scanf("%d", &choose);
				if (choose == 1) {
					fp = fopen(POS_Customer, "r+");
					c.flag = 0; strcpy(c.Id, c.Id);strcpy(c.Name, c.Name);c.year = c.year;c.month = c.month;c.day = c.day;c.level = c.level;c.money = c.money;
					fwrite(&c, sizeof(struct customer), 1, fp);					
					printf("ɾ���ɹ���\n");
					AddDetailCus("ɾ����Ա��Ϣ�ɹ�");
					fclose(fp);
					system("pause");
					system("cls");
					Customer_menu();
				}
				else AddDetailCus("�ҵ���δ�����޸Ĳ���");
				mark = 1;
			}
			
		}
	}
	if (mark == 0) {
		printf("δ�ҵ���Ա��Ϣ��\n");
		AddDetailCus("ɾ����Ա��Ϣʧ�ܣ�δ�ҵ���Ա��Ϣ��");
	}
	fclose(fp);
	system("pause");
	system("cls");

}
void Altercode0() {
	User u;
	char id[20] = { 0 };
	char temp[20] = { 0 };
	int mark = 0;
	long phone;
	char name[20] = { 0 };
	FILE* fp = fopen("user.txt", "r");
	if (fp == NULL) {
		printf("���ļ�ʧ��\n");
		set0();
	}
	else {
		printf("�������Ҫ�޸�������˺�\n");
		scanf("%s", id);
		fseek(fp, 0, SEEK_SET);
		while (fread(&u, sizeof(User), 1, fp) == 1) {
			if (strcmp(id, u.id)) {
				//printf("δ�ҵ�����Ա��Ϣ\n");
			}
			else {	
				    printf("��������������\n");
				    scanf("%s", name);
				    printf("���������ĵ绰����\n");
				    scanf("%ld", &phone);
					if (!strcmp(u.name, name) && phone == u.phone) {
						printf("����������λ����\n");
						while (scanf(" %s", &u.pwd) != EOF) {
							if (strlen(u.pwd) != 6) {
								printf("���볤�ȴ������������룡\n");
							}
							else break;
						}
						printf("��ȷ������\n");
						scanf("%s", temp);
						do {
							if (!strcmp(u.pwd, temp)) {
								fp = fopen("user.txt", "r+");
								fwrite(&u, sizeof(User), 1, fp);
								printf("�޸ĳɹ�����Ҫ�������ˣ�\n");
								fclose(fp);
								system("pause");
								system("cls");
								return;
							}
							else {
								printf("�������벻ƥ�䣡���������룡\n");
								//getchar();
								while (scanf(" %s", &u.pwd) != EOF) {
									if (strlen(u.pwd) != 6) {
										printf("���볤�ȴ������������룡\n");
									}
									else break;
								}
								printf("��ȷ������\n");
								scanf("%s", &temp);
							}
						} while (1);
					}
					else printf("����Ա��Ϣ�������������룡\n");
				mark = 1;
			}
		}
	}
	if (mark == 0)printf("δ�ҵ�����Ա��Ϣ\n");
	fclose(fp);
	system("pause");
	system("cls");
}
void Altercode1() {
	customer c;
	char Id[20] = { 0 };
	char temp[20] = { 0 };
	char Name[20] = { 0 };
	int year, month, day;
	int mark = 0;
	FILE* fp = fopen(POS_Customer, "r");
	if (fp == NULL) {
		printf("���ļ�ʧ��\n");
		set0();
	}
	else {
		fseek(fp, 0, SEEK_SET);
		printf("�������Ҫ�޸�������˺�\n");
		scanf("%s", Id);
		while (fread(&c, sizeof(customer), 1, fp) == 1) {
			if (strcmp(Id, c.Id)) {
				//printf("δ�ҵ���Ա��Ϣ\n");
			}
			else {
				printf("��������������\n");
				scanf("%s", Name);
				printf("��������������\n");
				scanf("%d %d %d", &year, &month, &day);
				if ((!strcmp(c.Name, Name)) && year == c.year && month == c.month && day == c.day) {
					printf("����������λ����\n");
					scanf("%s", c.Passcode);
					printf("��ȷ������\n");
					scanf("%s", temp);
					do {
						if (!strcmp(c.Passcode, temp)) {
							fp = fopen("user.txt", "r+");
							fwrite(&c, sizeof(User), 1, fp);
							printf("�޸ĳɹ�����Ҫ�������ˣ�\n");
							system("pause");
							system("cls");
							fclose(fp);
							return;
						}
						else {
							printf("�������벻ƥ�䣡���������룡\n");
							getchar();
							scanf("%s", &c.Passcode);
							printf("��ȷ������\n");
							scanf("%s", &temp);
						}
					} while (1);
				}
				else printf("������Ϣ���������ԣ�\n");
				mark = 1;
			}
		}
	}
	if (mark == 0)printf("δ�ҵ���Ա��Ϣ\n");
	fclose(fp);
	system("pause");
	system("cls");
}
void Findback0() {
	user u;
	FILE* fp = fopen("user.txt", "r");
	char id[20] = { 0 };
	char name[20] = { 0 };
	long phone;
	//int num;
	int mark = 0;
	if (fp == NULL) {
		printf("���ļ�ʧ��\n");
		set1();
	}
	else {
		printf("���������һ�������˺�\n");
		scanf("%s", id);
		fseek(fp, 0, SEEK_SET);
		while (fread(&u, sizeof(struct User), 1, fp) == 1) {
			if (strcmp(id, u.id)) {
				//printf("δ�ҵ�����Ա��Ϣ\n");
			}
			else {
				printf("��������������\n");
				scanf("%s", name);
				/*printf("���������Ĺ���\n");
				scanf("%s", num);*/
				printf("���������ĵ绰����\n");
				scanf("%ld", &phone);
				if (!strcmp(u.name, name) && phone == u.phone) {
					printf("���������ǣ�\n");
					printf("%s\n��������ǿ���\n", u.pwd);
				}
				else printf("������Ϣ���������ԣ�\n");
				mark = 1;
			}
		}
	}
	if(mark==0)printf("δ�ҵ�����Ա��Ϣ\n");
	fclose(fp);
	system("pause");
	system("cls");
}
void Findback1() {
	customer c;
	FILE* fp = fopen(POS_Customer, "r");
	char Id[20] = { 0 };
	char Name[20] = { 0 };
	int year, month, day;
	int flag = 0;
	int mark = 0;
	if (fp == NULL) {
		printf("���ļ�ʧ��\n");
		set1();
	}
	else {
		printf("���������һ�������˺�\n");
		scanf("%s", Id);
		fseek(fp, 0, SEEK_SET);
		while (fread(&c, sizeof(customer), 1, fp) == 1) {
			if (strcmp(Id, c.Id)||c.flag!=1) {
				//printf("δ�ҵ���Ա��Ϣ\n");
			}
			else {
				printf("��������������\n");
				scanf("%s", Name);
				printf("��������������\n");
				scanf("%d %d %d", &year,&month,&day);
				if ((!strcmp(c.Name, Name)) && year == c.year && month == c.month && day == c.day) {
					printf("���������ǣ�\n");
					printf("%s\n��������ǿ���\n", c.Passcode);
				}
				else printf("������Ϣ�������������ԣ�\n");
				mark = 1;
			}
		}
	}
	if(mark==0)printf("δ�ҵ���Ա��Ϣ\n");
	fclose(fp);
	system("pause");
	system("cls");
}
void AddDetailCus(char* operation)
{
	time_t now = time(NULL);
	struct tm* t = localtime(&now);
	int year = t->tm_year + 1900; // �����Ҫ���� 1900
	int month = t->tm_mon + 1;    // �·ݴ� 0 ��ʼ����Ҫ�� 1
	int day = t->tm_mday;
	int hour = t->tm_hour;
	int min = t->tm_min;
	int sec = t->tm_sec;

	FILE* pf = fopen(POS_DetailC, "ab+");
	if (pf == NULL)
	{
		printf("�ļ���ʧ�ܣ�%s!\n", POS_DetailC);
		exit(1);
	}
	fprintf(pf, "%d-%d-%d %d:%d:%d : %s\n", year, month, day, hour, min, sec, operation);
	fclose(pf);
}
void AddDetail_Customer(char* operation, customer c)
{
	time_t now = time(NULL);
	struct tm* t = localtime(&now);
	int year = t->tm_year + 1900; // �����Ҫ���� 1900
	int month = t->tm_mon + 1;    // �·ݴ� 0 ��ʼ����Ҫ�� 1
	int day = t->tm_mday;
	int hour = t->tm_hour;
	int min = t->tm_min;
	int sec = t->tm_sec;

	FILE* pf = fopen(POS_DetailC, "ab+");
	if (pf == NULL)
	{
		printf("�ļ���ʧ�ܣ�%s!\n", POS_DetailC);
		exit(1);
	}
	fprintf(pf, "%d-%d-%d %d:%d:%d : %s\n", year, month, day, hour, min, sec, operation);
	fclose(pf);
}

void ShowDetailCus()
{
	FILE* pf = fopen(POS_DetailC, "r");
	if (pf == NULL)
	{
		printf("�ļ��򿪴���\n");
		exit(1);
	}

	char line[1024];
	while (fgets(line, sizeof(line), pf))
	{
		printf("%s", line);
	}
	fclose(pf);
	AddDetail("�鿴��ϸ�ɹ�");
	system("pause");
	system("cls");
}
void backups() {
	FILE* fpread = fopen(POS_Customer, "rt");
	FILE* fpwrite = fopen("customerSave.txt", "wt");
	int bufferLen = 1024 * 4;
	char* buffer = (char*)malloc(bufferLen);
	int readCount;
	if (fpread == NULL || fpwrite == NULL) {
		printf("���ļ�ʧ��\n");
		Customer_menu();
	}
	while ((readCount = fread(buffer, 1, bufferLen, fpread)) > 0) {
		fwrite(buffer, readCount, 1, fpwrite);
	}
	free(buffer);
	fclose(fpread);
	fclose(fpwrite);
	printf("���ݳɹ���һ��󷵻�!\n");
	AddDetailCus("���ݻ�Ա��Ϣ�ɹ���\n");
	Sleep(1000);
	system("cls");
}
