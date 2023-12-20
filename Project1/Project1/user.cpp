#include"user.h"
#include"store.h"
#include"interface.h"
#define _CRT_SECURE_NO_WARNINGS

void login0() {
	user a, b;
	FILE* fp;
	int flag = 1;
	fp = fopen("user.txt", "r");
	fread(&b, sizeof(struct User), 1, fp); //读入一个结构体字符块 写入b
	//system("color fc");
	printf("请输入账号:");
	scanf("%s", &a.id);
	while (flag == 1) {
		if (!strcmp(a.id, b.id)) {
			break;
		}
		else {
			if (fp == NULL) {
				printf("未存在管理员账户，请注册！\n");
				system("pause");
				system("cls");
				set0();
			}
			if (!feof(fp)) {/*若文件没有读完*/
				fread(&b, sizeof(struct User), 1, fp);
				/*读出数据 b 存放的地址位置，内存大小，每次读取一个数据块 1 ，以读的方式打开文件*/
			}
			else {
				printf("未找到用户信息，请重新选择！\n");
				fclose(fp);
				system("pause");
				system("cls");
				getchar();
				set0();
			}
		}
	}
	while (flag == 1) {
		printf("请输入六位密码：");
		int i = 0;
		while ((a.pwd[i] = getch()) != 13)//getch()返回值是一个键值，回车的键值是13
		{	
			if (a.pwd[i] == 8 && i == 0) continue;//对退格情况讨论
			if (a.pwd[i] == 8 && i != 0) {
				i -= 1;
				printf("\b \b");
				continue;
			}//退格删除*号并掩盖空格
								//将输入的密码存储在数组中在屏幕上输出‘* ’代替数字 
			i++;
			printf("*");//隐藏密码
		}
		a.pwd[i] = '\0';//把最后的回车变成结束符（数组） 
		printf("\n");
		if (!strcmp(a.pwd, b.pwd)) {
			fclose(fp);
			printf("登陆成功！一秒后跳转！\n");
			Sleep(1000);
			system("cls");
			menu0();
			break;
		}
		else {
			printf("密码错误，请重新输入！\n");
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
	printf("%70s", "欢迎来到注册页面\n");
	//Sleep(1000);
	fp = fopen("user.txt", "r");
	fread(&b, sizeof(struct User), 1, fp); //读出数据存放的地址 b  
	printf("请输入账号\n");
	scanf("%s", &a.id);
	while (flag)
	{
		if (strcmp(a.id, b.id)) /*如果两串不相等*/
		{
			if (!feof(fp))    /*如果未到文件尾*/
			{
				fread(&b, sizeof(struct User), 1, fp);
			}
			else break;
		}
		else
		{
			printf("此用户名已存在！请重新选择！\n");
			getchar();
			rewind(stdin);
			system("pause");
			system("cls");
			return;
		}
	}
	printf("请输入电话号码\n");
	scanf(" %ld", &a.phone);
	printf("请输入管理员姓名\n");
	scanf(" %s", &a.name);
	printf("请输入六位密码\n");
	while (scanf(" %s", &a.pwd) != EOF) {
		if (strlen(a.pwd) != 6) {
			printf("密码长度错误，请重新输入！\n");
		}
		else break;
	}
	printf("请确认密码\n");
	scanf(" %s", &temp);
	do {
		if (!strcmp(a.pwd, temp))
		{
			fp = fopen("user.txt", "a");//追加一个账号 
			fwrite(&a, sizeof(struct User), 1, fp);/* a 待写入文件的指针 （地址）*/
			printf("账号注册成功!一秒后跳转！\n");
			//printf("登陆成功！一秒后跳转！\n");
			Sleep(1000);
			fclose(fp);
			//system("pause");
			system("cls");
			return;
		}
		else
		{
			printf("两次密码不匹配！请重新输入！\n");
			getchar();
			while (scanf(" %s", &a.pwd) != EOF) {
				if (strlen(a.pwd) != 6) {
					printf("密码长度错误，请重新输入！\n");
				}
				else break;
			}
			printf("请确认密码\n");
			scanf("%s", &temp);
		}
	} while (1);
}
void login1() {
	customer a, b;
	FILE* fp;
	int flag = 1;
	fp = fopen("customer.txt", "r");
	fread(&b, sizeof(struct customer), 1, fp); //读入一个结构体字符块 写入b
	//system("color fc");
	printf("请输入账号:");
	scanf("%s", &a.Id);
	while (flag == 1) {
		if (!strcmp(a.Id, b.Id)&&b.flag==1) {
			break;
		}
		else {
			if (fp == NULL) {
				printf("未存在管理员账户，请注册！\n");
				system("pause");
				system("cls");
				set0();
			}
			if (!feof(fp)) {/*若文件没有读完*/
				fread(&b, sizeof(struct customer), 1, fp);				
			}
			else {
				printf("未找到会员信息，请重新选择！\n");
				fclose(fp);
				system("pause");
				system("cls");
				getchar();
				set0();
			}
		}
	}
	while (flag == 1) {
		printf("请输入六位密码：");
		int i = 0;
		while ((a.Passcode[i] = getch()) != 13)//getch()返回值是一个键值，回车的键值是13
		{		
			if (a.Passcode[i] == 8 && i == 0) continue;//对退格情况讨论
			if (a.Passcode[i] == 8 && i != 0) {
				i -= 1;
				printf("\b \b");
				continue;
			}//退格删除*号并掩盖空格
			//将输入的密码存储在数组中在屏幕上输出‘* ’代替数字 
			i++;
			printf("*");//隐藏密码
		}
		a.Passcode[i] = '\0';//把最后的回车变成结束符（数组） 
		printf("\n");
		if (!strcmp(a.Passcode, b.Passcode)) {
			fclose(fp);
			printf("登陆成功！一秒后跳转！\n");
			Sleep(1000);
			/*printf("登陆成功！\n");
			system("pause");*/
			system("cls");
			menu1();
			break;
		}
		else {
			printf("密码错误，请重新输入！\n");
		}
	}
}
void reg1() {
	customer a, b;
	FILE* fp;
	int cnt = 0;
	int flag = 1;
	char temp[20] = { 0 };
	printf("%70s", "欢迎来到注册页面\n");
	fp = fopen("customer.txt", "r");
	fread(&b, sizeof(struct customer), 1, fp); //读出数据存放的地址 b  
	printf("请输入账号\n");
	scanf("%s", &a.Id);
	while (flag)
	{
		if (strcmp(a.Id, b.Id)||b.flag!=1) /*如果两串不相等*/
		{
			if (!feof(fp))    /*如果未到文件尾*/
			{
				fread(&b, sizeof(struct customer), 1, fp);
			}
			else break;
		}
		else
		{
			printf("此用户名已存在！请重新选择！\n");
			getchar();
			rewind(stdin);
			//Sleep(800);
			system("pause");
			system("cls");
			return;
		}
	}
	printf("请输入姓名\n");//若if条件全通过
	scanf("%s", &a.Name);
	printf("请输入出生日期\n");
	scanf("%d %d %d", &a.year, &a.month, &a.day);
	a.flag = 1;
	a.level = 1;
	a.discount = 1;
	a.money = 0.0;
	printf("请输入六位密码\n");
	while (scanf(" %s", &a.Passcode) != EOF) {
		if (strlen(a.Passcode) != 6) {
			printf("密码长度错误，请重新输入！\n");
		}
		else break;
	}
	printf("请确认密码\n");
	scanf(" %s", &temp);
	do {
		if (!strcmp(a.Passcode, temp))
		{
			fp = fopen("customer.txt", "a");//追加一个账号 
			fwrite(&a, sizeof(struct customer), 1, fp);/* a 待写入文件的指针 （地址）*/
			printf("账号注册成功!一秒后跳转！\n");
			//Sleep(500);
			fclose(fp);
			//printf("登陆成功！一秒后跳转！\n");
			Sleep(1000);
			system("cls");
			return;
		}
		else
		{
			printf("两次密码不匹配！请重新输入！\n");
			getchar();
			while (scanf(" %s", &a.Passcode) != EOF) {
				if (strlen(a.Passcode) != 6) {
					printf("密码长度错误，请重新输入！\n");
				}
				else break;
			}
			printf("请确认密码\n");
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
//    printf("请输入账号\n");
//    scanf("%s", &a.Id);
//	while (flag){
//		if (strcmp(a.Id, b.Id)||b.flag!=1) /*如果两串不相等*/
//		{
//			if (!feof(fp))    /*如果未到文件尾*/
//			{
//				fread(&b, sizeof(struct customer), 1, fp);
//			}
//			else break;
//		}
//		else
//		{
//			printf("此账号已存在！请重新选择！\n");
//			getchar();
//			rewind(stdin);
//			system("cls");
//			return;
//		}
//	}
//	a.flag = 1;
//	printf("请输入姓名\n");
//	scanf("%s", &a.Name);
//	printf("请输入出生日期\n");
//	scanf("%d %d %d", &a.year, &a.month, &a.day);
//	printf("请输入用户等级（1-5）\n");
//	scanf("%d", &a.level);
//	printf("请输入折扣\n");
//	scanf("%f", &a.discount);
//	printf("请输入消费额\n");
//	scanf("%f", &a.money);
//	printf("请输入六位密码\n");
//	scanf(" %s", &a.Passcode);
//	printf("请确认密码\n");
//	scanf(" %s", &temp);
//	do {
//		if (!strcmp(a.Passcode, temp))
//		{
//			fp = fopen("customer.txt", "a");
//			fwrite(&a, sizeof(struct customer), 1, fp);
//			fclose(fp);
//			printf("添加信息成功！\n");
//			system("pause");
//			system("cls");
//			return;
//		}
//		else
//		{
//			printf("两次密码不匹配！请重新输入！\n");
//			getchar();
//			scanf("%s", &a.Passcode);
//			printf("请确认密码\n");
//			scanf("%s", &temp);
//		}
//	} while (1);
//}
void AddCustomer() {
	int cnt = 0;
	FILE* fp = fopen(POS_Customer, "r");
	if (fp == NULL) {
		printf("打开文件失败！\n");
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
		printf("请输入账号\n");
		scanf("%s", pb->Id);
		fseek(fp, 0, SEEK_SET);
		while (fread(&c, sizeof(Customer), 1, fp) == 1) {
			if (!strcmp(pb->Id, c.Id) && c.Id != 0) {
				printf("此账号已存在！请重新选择！\n");
				AddDetail_Customer("添加用户信息失败，账号重复！", c);
				getchar();
				rewind(stdin);
				free(pb);
				system("cls");
				return;
			}
			else continue;
		}
		printf("请输入姓名\n");
		scanf("%s", pb->Name);
		printf("请输入出生年月日(以空格隔开:yyyy mm dd）\n");
		while (scanf("%d %d %d", &pb->year, &pb->month, &pb->day)!=EOF) {
			if (pb->year < 0 || pb->month>12 || pb->month < 0 || pb->day < 0 || pb->day>31) {
				printf("输入错误 请重新输入！\n");
			}
			else break;
		}
		printf("请输入用户等级（1-5）\n");
		scanf("%d", &pb->level);
		printf("请输入折扣(0.x)\n");
		scanf("%f", &pb->discount);
		printf("请输入消费额\n");
		scanf("%f", &pb->money);
		printf("请输入六位密码\n");
		while (scanf(" %s", pb->Passcode) != EOF) {
			if (strlen(pb->Passcode) != 6) {
				printf("密码长度错误，请重新输入！\n");
			}
			else break;
		}
		printf("请确认密码\n");
		scanf(" %s", &temp);
		while (1) {
			if (!strcmp(pb->Passcode, temp)) {
				//fp = fopen("customer.txt", "a");//追加一个账号 
				//fseek(fp, 0, SEEK_END);
				//fwrite(pb, sizeof(struct customer), 1, fp);/* a 待写入文件的指针 （地址）*/
				printf("添加信息成功!\n");
				AddDetail_Customer("添加用户信息成功！", c);
				cnt++;
				//fclose(fp);
				break;
			}
			else
			{
				printf("两次密码不匹配！请重新输入！\n");
				getchar();
				while (scanf(" %s", &pb->Passcode) != EOF) {
					if (strlen(pb->Passcode) != 6) {
						printf("密码长度错误，请重新输入！\n");
					}
					else break;
				}
				printf("请确认密码\n");
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
		printf("输入1以继续录入,输入0以停止录入\n");
		scanf("%d", &choose);
		system("cls");
	}
	Customer* p = head;
	fp = fopen(POS_Customer, "a");
	while (p != NULL) {
		fwrite(p, sizeof(Customer), 1, fp);
		p = p->next;
	}
	printf("本次共录入了%d名客户的信息\n",cnt);
	p = head;
	while (p != NULL) {
		Customer* temp = p->next;
		free(p);
		p = temp;
	}//释放内存
	fclose(fp);
	system("pause");
	system("cls");
	AddDetailCus("添加客户信息成功");
}

void ShowCustomer() {
	printf("\t\t\t   ********************客户信息如下：************************\n");
	printf("\t\t\t   %-10s %-12s %-13s %-12s %-10s\n", "账号", "姓名", "生日", "会员等级", "累计消费");
	FILE* fp = fopen(POS_Customer, "r");
	customer c;
	int cnt = 0;
	if (fp == NULL) {
		printf("打开文件失败！\n");
		Goods_menu();
	}
	if (fp == 0) {
		printf("未存在用户信息！\n");
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
	printf("\t\t\t\t\t   系统中共有%d名会员的信息\n",cnt);
	printf("\t\t\t   ************************************************************\n");
	AddDetailCus("显示会员信息成功");
	system("pause");
	system("cls");
}

//void QueryCustomer() {
//	customer c;
//	int flag = 0;
//	char temp[20]={0};
//	FILE* fp = fopen(POS_Customer, "r");
//	if (fp == NULL) {
//		printf("打开文件失败！\n");
//		exit(1);
//	}
//	else {
//		printf("请输入需要查询的用户姓名或账号\n");
//		scanf("%s", temp);
//		while (fread(&c, sizeof(struct customer), 1, fp) == 1) {
//			if ((strcmp(c.Name, temp) != 0 && strcmp(c.Id, temp) != 0)||c.flag != 1) {
//				continue;
//				//printf("未找到用户信息！\n");
//				//system("pause");
//				//system("cls");
//				//Customer_menu();
//			}
//			else {
//				if (flag == 0) {
//					printf("\t\t\t   ********************客户信息如下：************************\n");
//					printf("\t\t\t   %-10s %-12s %-13s %-12s %-10s\n", "账号", "姓名", "生日", "会员等级", "累计消费");
//					printf("\t\t\t   %-8s %-6s %6d/%d/%d %10d %15f \n", c.Id, c.Name, c.year, c.month, c.day, c.level, c.money);
//					flag = 1;
//				}
//				else printf("\t\t\t   %-8s %-6s %6d/%d/%d %10d %15f \n", c.Id, c.Name, c.year, c.month, c.day, c.level, c.money);				
//			}
//		}
//		if(flag==1)AddDetailCus("查询会员信息成功");
//		if (flag == 0) {
//			printf("未找到用户信息！\n");
//			AddDetailCus("查询会员信息失败，未找到用户信息！");
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
	if ((str[0] >= '0' && str[0] <= '9') || (str[0] >= 'a' && str[0] <= 'z')|| (str[0] >= 'A' && str[0] <= 'Z')) return 0;//判断是否为数字串
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
		printf("打开文件失败！\n");
		exit(1);
	}
	else {
		printf("请输入需要查询的用户姓名或账号\n");
		fseek(fp, 0, SEEK_SET);
		scanf("%s", temp);	
		while (fread(&c, sizeof(struct customer), 1, fp) == 1) {
			
			if ((vagueNum(temp, c.Id) == 0 && vagueChinese(temp, c.Name) == 0 && vagueNum(temp, c.Name) == 0) || c.flag != 1) {
				continue;
				//printf("未找到用户信息！\n");
				//system("pause");
				//system("cls");
				//Customer_menu();
			}
			else {
				if (flag == 0) {
					printf("\t\t\t   ********************客户信息如下：************************\n");
					printf("\t\t\t   %-10s %-12s %-13s %-12s %-10s\n", "账号", "姓名", "生日", "会员等级", "累计消费");
					printf("\t\t\t   %-8s %-6s %6d/%d/%d %10d %15f \n", c.Id, c.Name, c.year, c.month, c.day, c.level, c.money);
					flag = 1;
				}
				else printf("\t\t\t   %-8s %-6s %6d/%d/%d %10d %15f \n", c.Id, c.Name, c.year, c.month, c.day, c.level, c.money);
			}
		}
		if (flag == 1)AddDetailCus("查询会员信息成功");
		if (flag == 0) {
			printf("未找到用户信息！\n");
			AddDetailCus("查询会员信息失败，未找到用户信息！");
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
		printf("打开文件失败！\n");
		exit(1);
	}
	else {
		printf("请输入需要修改信息的账号\n");
		scanf("%s", temp1);
		fseek(fp, 0, SEEK_SET);
		while (fread(&b, sizeof(struct customer), 1, fp) == 1) {
			if (strcmp(b.Id, temp1)||b.flag != 1) {
				continue;
			}
			else {
				flag = 1;
				printf("\t\t\t   ********************客户信息如下：************************\n");
				printf("\t\t\t   %-10s %-12s %-13s %-12s %-10s\n", "账号", "姓名", "生日", "会员等级", "累计消费");
				printf("\t\t\t   %-8s %-6s %6d/%d/%d %10d %15f \n", b.Id, b.Name, b.year, b.month, b.day, b.level, b.money);
				printf("\t\t\t   ************************************************************\n");
				printf("请选择要修改的信息：1姓名 2出生日期 3用户等级 4折扣 5消费密额 6密码(请连续输入)\n");
				scanf("%s", choose);
				for (int i = 0;i < strlen(choose);i++) {
					switch (choose[i]) {
					case '1':
						printf("请输入姓名\n");
						scanf("%s", &b.Name);
						break;
					case '2':
						printf("请输入出生年月日(以空格隔开:yyyy mm dd）\n");
						while (scanf("%d %d %d", b.year, b.month, b.day) != EOF) {
							if (b.year < 0 || b.month>12 || b.month < 0 || b.day < 0 || b.day>31) {
								printf("输入错误 请重新输入！\n");
							}
							else break;
						}
						break;
					case '3':
						printf("请输入用户等级（1-5）\n");
						scanf("%d", &b.level);
						break;
					case '4':
						printf("请输入折扣\n");
						scanf("%f", &b.discount);
						break;
					case '5':
						printf("请输入消费额\n");
						scanf("%f", &b.money);
						break;
					case '6':
						printf("请输入六位密码\n");
						while (scanf(" %s", b.Passcode) != EOF) {
							if (strlen(b.Passcode) != 6) {
								printf("密码长度错误，请重新输入！\n");
							}
							else break;
						}
						printf("请确认密码\n");
						scanf(" %s", &temp2);
						do {
							if (!strcmp(b.Passcode, temp2))
							{
								fp = fopen(POS_Customer, "r+");
								fwrite(&b, sizeof(struct customer), 1, fp);
								fclose(fp);
								printf("修改信息成功！\n");
								AddDetailCus("修改会员信息成功");
								system("pause");
								system("cls");
								Customer_menu();
							}
							else
							{
								printf("两次密码不匹配！请重新输入！\n");
								getchar();
								while (scanf(" %s", b.Passcode) != EOF) {
									if (strlen(b.Passcode) != 6) {
										printf("密码长度错误，请重新输入！\n");
									}
									else break;
								}
								printf("请确认密码\n");
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
				printf("修改信息成功！\n");
				AddDetailCus("修改会员信息成功");
				system("pause");
			}
		}
		if (flag == 0) {
			printf("未找到用户信息！\n");
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
		printf("打开文件失败！\n");
		exit(1);
	}
	else {
		printf("请输入需要删除信息的用户账号\n");
		scanf("%s", temp);
		fseek(fp, 0, SEEK_SET);
		while (fread(&c, sizeof(customer), 1, fp) == 1) {
			if ((!strcmp(temp, c.Id))&&c.flag==1) {
				printf("\t\t\t   ********************客户信息如下：************************\n");
				printf("\t\t\t   %-10s %-12s %-13s %-12s %-10s\n", "账号", "姓名", "生日", "会员等级", "累计消费");
				printf("\t\t\t   %-8s %-6s %6d/%d/%d %10d %15f \n", c.Id, c.Name, c.year, c.month, c.day, c.level, c.money);
				printf("\t\t\t   ************************************************************\n");
				printf("是否确认删除？(键入1以删除)\n");
				scanf("%d", &choose);
				if (choose == 1) {
					fp = fopen(POS_Customer, "r+");
					c.flag = 0; strcpy(c.Id, c.Id);strcpy(c.Name, c.Name);c.year = c.year;c.month = c.month;c.day = c.day;c.level = c.level;c.money = c.money;
					fwrite(&c, sizeof(struct customer), 1, fp);					
					printf("删除成功！\n");
					AddDetailCus("删除会员信息成功");
					fclose(fp);
					system("pause");
					system("cls");
					Customer_menu();
				}
				else AddDetailCus("找到但未进行修改操作");
				mark = 1;
			}
			
		}
	}
	if (mark == 0) {
		printf("未找到会员信息！\n");
		AddDetailCus("删除会员信息失败，未找到会员信息！");
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
		printf("打开文件失败\n");
		set0();
	}
	else {
		printf("请键入需要修改密码的账号\n");
		scanf("%s", id);
		fseek(fp, 0, SEEK_SET);
		while (fread(&u, sizeof(User), 1, fp) == 1) {
			if (strcmp(id, u.id)) {
				//printf("未找到管理员信息\n");
			}
			else {	
				    printf("请输入您的姓名\n");
				    scanf("%s", name);
				    printf("请输入您的电话号码\n");
				    scanf("%ld", &phone);
					if (!strcmp(u.name, name) && phone == u.phone) {
						printf("请输入新六位密码\n");
						while (scanf(" %s", &u.pwd) != EOF) {
							if (strlen(u.pwd) != 6) {
								printf("密码长度错误，请重新输入！\n");
							}
							else break;
						}
						printf("请确认密码\n");
						scanf("%s", temp);
						do {
							if (!strcmp(u.pwd, temp)) {
								fp = fopen("user.txt", "r+");
								fwrite(&u, sizeof(User), 1, fp);
								printf("修改成功！不要再忘记了！\n");
								fclose(fp);
								system("pause");
								system("cls");
								return;
							}
							else {
								printf("两次密码不匹配！请重新输入！\n");
								//getchar();
								while (scanf(" %s", &u.pwd) != EOF) {
									if (strlen(u.pwd) != 6) {
										printf("密码长度错误，请重新输入！\n");
									}
									else break;
								}
								printf("请确认密码\n");
								scanf("%s", &temp);
							}
						} while (1);
					}
					else printf("管理员信息有误，请重新输入！\n");
				mark = 1;
			}
		}
	}
	if (mark == 0)printf("未找到管理员信息\n");
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
		printf("打开文件失败\n");
		set0();
	}
	else {
		fseek(fp, 0, SEEK_SET);
		printf("请键入需要修改密码的账号\n");
		scanf("%s", Id);
		while (fread(&c, sizeof(customer), 1, fp) == 1) {
			if (strcmp(Id, c.Id)) {
				//printf("未找到会员信息\n");
			}
			else {
				printf("请输入您的姓名\n");
				scanf("%s", Name);
				printf("请输入您的生日\n");
				scanf("%d %d %d", &year, &month, &day);
				if ((!strcmp(c.Name, Name)) && year == c.year && month == c.month && day == c.day) {
					printf("请输入新六位密码\n");
					scanf("%s", c.Passcode);
					printf("请确认密码\n");
					scanf("%s", temp);
					do {
						if (!strcmp(c.Passcode, temp)) {
							fp = fopen("user.txt", "r+");
							fwrite(&c, sizeof(User), 1, fp);
							printf("修改成功！不要再忘记了！\n");
							system("pause");
							system("cls");
							fclose(fp);
							return;
						}
						else {
							printf("两次密码不匹配！请重新输入！\n");
							getchar();
							scanf("%s", &c.Passcode);
							printf("请确认密码\n");
							scanf("%s", &temp);
						}
					} while (1);
				}
				else printf("个人信息错误，请重试！\n");
				mark = 1;
			}
		}
	}
	if (mark == 0)printf("未找到会员信息\n");
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
		printf("打开文件失败\n");
		set1();
	}
	else {
		printf("请输入需找回密码的账号\n");
		scanf("%s", id);
		fseek(fp, 0, SEEK_SET);
		while (fread(&u, sizeof(struct User), 1, fp) == 1) {
			if (strcmp(id, u.id)) {
				//printf("未找到管理员信息\n");
			}
			else {
				printf("请输入您的姓名\n");
				scanf("%s", name);
				/*printf("请输入您的工号\n");
				scanf("%s", num);*/
				printf("请输入您的电话号码\n");
				scanf("%ld", &phone);
				if (!strcmp(u.name, name) && phone == u.phone) {
					printf("您的密码是：\n");
					printf("%s\n请别再忘记咯！\n", u.pwd);
				}
				else printf("个人信息有误，请重试！\n");
				mark = 1;
			}
		}
	}
	if(mark==0)printf("未找到管理员信息\n");
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
		printf("打开文件失败\n");
		set1();
	}
	else {
		printf("请输入需找回密码的账号\n");
		scanf("%s", Id);
		fseek(fp, 0, SEEK_SET);
		while (fread(&c, sizeof(customer), 1, fp) == 1) {
			if (strcmp(Id, c.Id)||c.flag!=1) {
				//printf("未找到会员信息\n");
			}
			else {
				printf("请输入您的姓名\n");
				scanf("%s", Name);
				printf("请输入您的生日\n");
				scanf("%d %d %d", &year,&month,&day);
				if ((!strcmp(c.Name, Name)) && year == c.year && month == c.month && day == c.day) {
					printf("您的密码是：\n");
					printf("%s\n请别再忘记咯！\n", c.Passcode);
				}
				else printf("个人信息输入有误，请重试！\n");
				mark = 1;
			}
		}
	}
	if(mark==0)printf("未找到会员信息\n");
	fclose(fp);
	system("pause");
	system("cls");
}
void AddDetailCus(char* operation)
{
	time_t now = time(NULL);
	struct tm* t = localtime(&now);
	int year = t->tm_year + 1900; // 年份需要加上 1900
	int month = t->tm_mon + 1;    // 月份从 0 开始，需要加 1
	int day = t->tm_mday;
	int hour = t->tm_hour;
	int min = t->tm_min;
	int sec = t->tm_sec;

	FILE* pf = fopen(POS_DetailC, "ab+");
	if (pf == NULL)
	{
		printf("文件打开失败：%s!\n", POS_DetailC);
		exit(1);
	}
	fprintf(pf, "%d-%d-%d %d:%d:%d : %s\n", year, month, day, hour, min, sec, operation);
	fclose(pf);
}
void AddDetail_Customer(char* operation, customer c)
{
	time_t now = time(NULL);
	struct tm* t = localtime(&now);
	int year = t->tm_year + 1900; // 年份需要加上 1900
	int month = t->tm_mon + 1;    // 月份从 0 开始，需要加 1
	int day = t->tm_mday;
	int hour = t->tm_hour;
	int min = t->tm_min;
	int sec = t->tm_sec;

	FILE* pf = fopen(POS_DetailC, "ab+");
	if (pf == NULL)
	{
		printf("文件打开失败：%s!\n", POS_DetailC);
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
		printf("文件打开错误！\n");
		exit(1);
	}

	char line[1024];
	while (fgets(line, sizeof(line), pf))
	{
		printf("%s", line);
	}
	fclose(pf);
	AddDetail("查看明细成功");
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
		printf("打开文件失败\n");
		Customer_menu();
	}
	while ((readCount = fread(buffer, 1, bufferLen, fpread)) > 0) {
		fwrite(buffer, readCount, 1, fpwrite);
	}
	free(buffer);
	fclose(fpread);
	fclose(fpwrite);
	printf("备份成功！一秒后返回!\n");
	AddDetailCus("备份会员信息成功！\n");
	Sleep(1000);
	system("cls");
}
