#include"user.h"
#include"store.h"
#include"interface.h"
#include"sort.h"
#include"static.h"

void Interface() {
	int choose;
	int flag = 1;
	while (flag == 1) {
		printf("\t\t\t\t\t    *******                *******  \n");
		printf("\t\t\t\t\t    #######  超市管理系统  #######  \n");
		printf("\t\t\t\t\t    -------                -------  \n");
		printf("%70s", "\t\t    ┏┅┅┅┅┅┅┅┅┅┅┅┅┅┓\n");
		printf("%66s", "\t    [1.管理员登陆 ]\n");
		printf("%66s", "\t    [2.客户登陆   ]\n");
		printf("%70s", "\t\t    ┗┅┅┅┅┅┅┅┅┅┅┅┅┅┛\n");
		printf("\t\t\t\t\t    *******                *******  \n");
		printf("\t\t\t\t\t    #######  超市管理系统  #######  \n");
		printf("\t\t\t\t\t    -------                -------  \n");
		printf("请选择：");
		scanf("%d", &choose);
		switch (choose) {
		case 1:
			system("pause");
			system("cls");
			set0();
			break;
		case 2:
			system("pause");
			system("cls");
			set1();
			break;
		default:
			printf("请在1与2中选择一项\n");
			system("pause");
			system("cls");
			Interface();
		}
	}
}
void set1() {
	int choose;
	int flag = 1;
	while (flag == 1) {
		printf("\t\t\t\t\t    *******                *******  \n");
		printf("\t\t\t\t\t    #######  欢迎来到超市  #######  \n");
		printf("\t\t\t\t\t    -------                -------  \n");
		printf("%70s", "\t\t    ┏┅┅┅┅┅┅┅┅┅┅┅┅┅┓\n");
		printf("%65s", "[ 1.登陆]\n");
		printf("%65s", "[ 2.注册]\n");
		printf("%68s", "[ 3.找回密码]\n");
		printf("%68s", "[ 4.修改密码]\n");
		printf("%70s", "\t\t    ┗┅┅┅┅┅┅┅┅┅┅┅┅┅┛\n");
		printf("\t\t\t\t\t    -------                -------  \n");
		printf("\t\t\t\t\t    #######  欢迎来到超市  #######  \n");
		printf("\t\t\t\t\t    *******                *******  \n");
		printf("请选择：");
		scanf("%d", &choose);
		switch (choose) {
		case 1:
			system("cls");
			login1();
			getchar();
			flag = 0;
			break;
		case 2:
			getchar();
			system("cls");
			reg1();
			break;
		case 3:
			getchar();
			system("cls");
			Findback1();
			break;
		case 4:
			getchar();
			system("cls");
			Altercode1();
			break;
		default:
			getchar();
			rewind(stdin);
			printf("请输入合法选项\n");
			system("pause");
			system("cls");
			set1();
		}
	}
}
void set0() {
	int choose;
	int flag = 1;
	while (flag == 1) {
		printf("\t\t\t\t\t    *******                *******  \n");
		printf("\t\t\t\t\t    #######  超市管理系统  #######  \n");
		printf("\t\t\t\t\t    -------                -------  \n");
		printf("%70s", "\t\t    ┏┅┅┅┅┅┅┅┅┅┅┅┅┅┓\n");
		printf("%65s", "[ 1.登陆]\n");
		printf("%65s", "[ 2.注册]\n");
		printf("%65s", "[ 3.找回密码]\n");
		printf("%65s", "[ 4.修改密码]\n");
		printf("%70s", "\t\t    ┗┅┅┅┅┅┅┅┅┅┅┅┅┅┛\n");
		printf("\t\t\t\t\t    -------                -------  \n");
		printf("\t\t\t\t\t    #######  超市管理系统  #######  \n");
		printf("\t\t\t\t\t    *******                *******  \n");
		printf("请选择：");
		scanf("%d", &choose);
		switch (choose) {
		case 1:
			system("cls");
			login0();
			getchar();
			flag = 0;
			break;
		case 2:
			getchar();
			system("cls");
			reg0();
			break;
		case 3:
			getchar();
			system("cls");
			Findback0();
			break;
		case 4:
			getchar();
			system("cls");
			Altercode0();
			break;
		default:
			getchar();
			rewind(stdin);
			printf("请输入合法选项\n");
			system("pause");
			system("cls");
			set0();
		}
	}
}

void menu0() {
	int choose;
	int flag = 1;
	//system("color fc");
	printf("\t\t\t\t\t    *******                *******  \n");
	printf("\t\t\t\t\t    #######  超市管理系统  #######  \n");
	printf("\t\t\t\t\t    -------                -------  \n");
	printf("%70s", "\t\t\t    ┏┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┓\n");
	printf("%70s", "[ 1.商品信息系统]\n");
	printf("%70s", "[ 2.会员信息系统]\n");
	printf("%70s", "[ 3.排序与统计  ]\n");
	printf("%70s", "[ 4.退出系统    ]\n");
	printf("%70s", "\t\t\t    ┗┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┛\n");
	printf("\t\t\t\t\t    -------                -------  \n");
	printf("\t\t\t\t\t    #######  超市管理系统  #######  \n");
	printf("\t\t\t\t\t    *******                *******  \n");
	printf("请选择：");
	scanf("%d", &choose);
	system("pause");
	switch (choose) {
	case 1:
		system("cls");
		Goods_menu();
		getchar();
		break;
	case 2:
		getchar();
		system("cls");
		Customer_menu();
		break;
	case 3:
		getchar();
		system("cls");
		Sort_menu();
		break;
	case 4:
		getchar();
		system("cls");
		printf("感谢您的使用！\n");
		system("pause");
		exit(1);
		break;
	default:
		getchar();
		rewind(stdin);
		printf("请重新输入！\n");
		system("cls");
		system("pause");
		menu0();
	}
}
void menu1() {
	int choose;
	int flag = 1;
	//system("color fc");
	while (flag == 1) {
		printf("\t\t\t\t\t    *******                *******  \n");
		printf("\t\t\t\t\t    #######  欢迎来到超市  #######  \n");
		printf("\t\t\t\t\t    -------                -------  \n");
		printf("%70s", "\t\t\t    ┏┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┓\n");
		printf("%70s", "[ 1.查找商品      ]\n");
		printf("%70s", "[ 2.展示商品信息  ]\n");
		printf("%70s", "[ 3.退出系统      ]\n");
		printf("%70s", "\t\t\t    ┗┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┛\n");
		printf("\t\t\t\t\t    -------                -------  \n");
		printf("\t\t\t\t\t    #######  欢迎来到超市  #######  \n");
		printf("\t\t\t\t\t    *******                *******  \n");
		printf("请选择：");
		scanf("%d", &choose);
		system("pause");
		system("cls");
		switch (choose) {
		case 1:
			QueryGoods(POS);
			getchar();
			system("cls");
			break;
		case 2:
			getchar();
			system("cls");
			ShowGoods(POS);
			break;
		case 3:
			getchar();
			system("cls");
			printf("感谢您的使用！\n");
			system("pause");
			exit(1);
		default:
			getchar();
			rewind(stdin);
			printf("请重新输入！\n");
			system("cls");
			system("pause");
			menu1();
		}
		menu1();
	}
}
void static_menu() {
	Goods* head = NULL;
	int count = read_products(&head, POS);
	int choice = 0;
	int int_condition = 0;
	Condition my_condition;
	memset(my_condition.str, 0, sizeof(my_condition.str));//保证my_condition.str内容为空字符，而不会干扰输出
	//Condition* pb = (Condition*)malloc(sizeof(Condition));
	//pb = &my_condition;
	if (count != 0)
	{
		printf("成功读取 %d 条商品信息！\n", count);
		print_menu();
		scanf("%d", &choice);
		getchar();
		switch (choice) {
		case 1: {
			printf("请输入你想查询统计的商品名:\n");
			if (scanf("%s", my_condition.str) == 1) {
				printf("条件获取成功！");
			}
			else {
				printf("输入失败！");
			}
			break;
		}
		case 2: {
			printf("请输入你想查询统计的进货日期(yyyy-mm-dd)");

			if (scanf("%s", my_condition.str) == 1) {
				if (check_date_format(my_condition.str))
					printf("条件获取成功！");
				else {
					printf("输入失败，格式错误！\n");
					//return 1;
				}
			}
		}
			  break;
		case 3: {
			printf("请输入你想查询统计的保质期(符号 数值)");
			if (scanf("%c %s", &my_condition.symbol, my_condition.str) == 2) {
				if (check_num_format(my_condition.str)) {
				}
				else {
					printf("输入失败！\n");
				}
			}
			break;
		}
		case 4: {
			printf("请输入你想查询统计的类型 ");
			if (scanf("%s", my_condition.str) == 1) {
			}
			else {
				printf("输入失败！\n");
			}
		}
			  break;
		case 5: {
			printf("请输入你想查询统计的价格(符号 数值)");
			if (scanf("%c %s", &my_condition.symbol, my_condition.str) == 2) {
				if (check_num_format(my_condition.str)) {
				}
				else {
					printf("输入失败！\n");
				}
			}
			break;
		}
		case 6: {
			printf("请输入你想查询统计的商品库存数量(符号 数值)");
			if (scanf("%c %d", &my_condition.symbol, &int_condition) == 2) {

			}
			else {
				printf("输入失败！\n");
			}
		}
			  break;
		case 7:
			//getchar();
			system("cls");
			Sort_menu();
			break;
		default:
			printf("无效的选择！\n");
			break;
		}

	}
	else {
		printf("读取商品信息失败！\n");
	}
	print_statistics(head, choice, my_condition, int_condition);
	free(head);           // 释放链表内存
	//free(pb);
	system("pause");
	system("cls");
	static_menu();
}
void Goods_menu() {
	int choose;
	int flag = 1;
	while (flag == 1) {
		printf("\t\t\t\t\t    *******                *******  \n");
		printf("\t\t\t\t\t    #######  商品信息系统  #######  \n");
		printf("\t\t\t\t\t    -------                -------  \n");
		printf("%70s", "\t\t\t    ┏┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┓\n");
		printf("%70s", "[ 1.查询商品信息]\n");
		printf("%70s", "[ 2.添加商品信息]\n");
		printf("%70s", "[ 3.删除商品信息]\n");
		printf("%70s", "[ 4.修改商品信息]\n");
		printf("%70s", "[ 5.展示商品信息]\n");
		printf("%70s", "[ 6.进货]\n");
		printf("%70s", "[ 7.备份文件信息]\n");
		printf("%70s", "[ 8.展示操作明细]\n");
		printf("%70s", "[ 9.返回上一级]\n");
		printf("%70s", "\t\t\t    ┗┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┛\n");
		printf("\t\t\t\t\t    -------                -------  \n");
		printf("\t\t\t\t\t    #######  商品信息系统  #######  \n");
		printf("\t\t\t\t\t    *******                *******  \n");
		printf("请选择：");
		scanf("%d", &choose);
		system("pause");
		switch (choose) {
		case 1:
			system("cls");
			QueryGoods(POS);
			getchar();
			break;
		case 2:
			getchar();
			system("cls");
			AddGoods(POS);
			break;
		case 3:
			getchar();
			system("cls");
			DeleteGoods(POS);
			break;
		case 4:
			getchar();
			system("cls");
			AlterGoods(POS);
			break;
		case 5:
			getchar();
			system("cls");
			ShowGoods(POS);
			break;
		case 6:
			getchar();
			system("cls");
			InputGoods(POS);
			break;
		case 7:
			getchar();
			system("cls");
			BackupGoods(POS, "goodsSave.txt");
			break;
		case 8:
			getchar();
			system("cls");
			ShowDetail();
			break;
		case 9:
			getchar();
			system("cls");
			menu0();
			break;
		default:
			getchar();
			rewind(stdin);
			printf("请重新输入！");
			system("cls");
			Goods_menu();
		}
	}
	system("pause");
	system("cls");
	Goods_menu();
}
void Customer_menu() {
	int choose;
	int flag = 1;
	while (flag == 1) {
		printf("\t\t\t\t\t    *******                *******  \n");
		printf("\t\t\t\t\t    #######  用户信息系统  #######  \n");
		printf("\t\t\t\t\t    -------                -------  \n");
		printf("%70s", "\t\t\t    ┏┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┓\n");
		printf("%70s", "[ 1.查询用户信息]\n");
		printf("%70s", "[ 2.添加用户信息]\n");
		printf("%70s", "[ 3.删除用户信息]\n");
		printf("%70s", "[ 4.修改用户信息]\n");
		printf("%70s", "[ 5.展示用户信息]\n");
		printf("%70s", "[ 6.备份用户信息]\n");
		printf("%70s", "[ 7.显示操作明细]\n");
		printf("%70s", "[ 8.返回上一级]\n");
		printf("%70s", "\t\t\t    ┗┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┛\n");
		printf("\t\t\t\t\t    -------                -------  \n");
		printf("\t\t\t\t\t    #######  用户信息系统  #######  \n");
		printf("\t\t\t\t\t    *******                *******  \n");
		printf("请选择：");
		scanf("%d", &choose);
		system("pause");
		switch (choose) {
		case 1:
			system("cls");
			QueryCustomer();
			getchar();
			break;
		case 2:
			getchar();
			system("cls");
			AddCustomer();
			break;
		case 3:
			getchar();
			system("cls");
			DeleteCustomer();
			break;
		case 4:
			getchar();
			system("cls");
			AlterCustomer();
			break;
		case 5:
			getchar();
			system("cls");
			ShowCustomer();
			break;
		case 6:
			getchar();
			system("cls");
			backups();
			break;
		case 7:
			getchar();
			system("cls");
			ShowDetailCus();
			system("pause");
			system("cls");
			break;
		case 8:
			getchar();
			system("cls");
			menu0();
			break;
		default:
			getchar();
			rewind(stdin);
			printf("请重新输入！");
			system("cls");
			Customer_menu();
		}
	}
	system("cls");
	menu0();
}
void Sort_menu() {
	int choose;
	int flag = 1;
	while (flag == 1) {
		printf("\t\t\t\t\t    *******                *******  \n");
		printf("\t\t\t\t\t    #######  排序统计系统  #######  \n");
		printf("\t\t\t\t\t    -------                -------  \n");
		printf("%70s", "\t\t    ┏┅┅┅┅┅┅┅┅┅┅┅┅┅┓\n");
		printf("%65s", "[ 1.排序]\n");
		printf("%65s", "[ 2.统计]\n");
		printf("%68s", "[ 3.返回上一级]\n");
		printf("%70s", "\t\t    ┗┅┅┅┅┅┅┅┅┅┅┅┅┅┛\n");
		printf("\t\t\t\t\t    -------                -------  \n");
		printf("\t\t\t\t\t    #######  排序统计系统  #######  \n");
		printf("\t\t\t\t\t    *******                *******  \n");
		printf("请选择：");
		scanf("%d", &choose);
		switch (choose) {
		case 1:
			system("cls");
			SortGoods_menu();
			getchar();
			break;
		case 2:
			getchar();
			system("cls");
			static_menu();
			break;
		case 3:
			getchar();
			system("pause");
			system("cls");
			menu0();
		default:
			getchar();
			rewind(stdin);
			printf("请重新选择\n");
			system("pause");
			system("cls");
			Sort_menu();
		}
	}
}
void SortGoods_menu() {
	int choose;
	int flag = 1;
	while (flag == 1) {
		printf("\t\t\t\t\t    *******                *******  \n");
		printf("\t\t\t\t\t    #######    排序系统    #######  \n");
		printf("\t\t\t\t\t    -------                -------  \n");
		printf("%77s", "\t\t    ┏┅┅┅┅┅┅┅┅┅┅┅┅┅┅┓\n");
		printf("%68s", "\t   [ 1.根据存货量降序]\n");
		printf("%68s", "\t   [ 2.根据存货量升序]\n");
		printf("%68s", "\t   [ 3.根据售价降序排序]\n");
		printf("%68s", "\t   [ 4.根据售价升序排序]\n");
		printf("%68s", "\t\t   [ 5.根据商品序号降序排序]\n");
		printf("%68s", "\t\t   [ 6.根据商品序号升序排序]\n");
		printf("%69s", "[ 7.根据进货排序]\n");
		printf("%69s", "[ 8.展示货物信息]\n");
		printf("%67s", "   [ 9.返回上一级]\n");
		printf("%77s", "\t\t    ┗┅┅┅┅┅┅┅┅┅┅┅┅┅┅┛\n");
		printf("\t\t\t\t\t    -------                -------  \n");
		printf("\t\t\t\t\t    #######    排序系统    #######  \n");
		printf("\t\t\t\t\t    *******                *******  \n");
		printf("请选择：");
		scanf("%d", &choose);
		switch (choose) {
		case 1:
			system("cls");
			SortGoods_Quantity_Low_to_Max(POS);
			getchar();
			break;
		case 2:
			getchar();
			system("cls");
			SortGoods_Quantity_Max_to_Low(POS);
			break;
		case 3:
			getchar();
			system("cls");
			SortGoods_Price_Low_to_Max(POS);
			break;
		case 4:
			getchar();
			system("cls");
			SortGoods_Price_Max_to_Low(POS);
			break;
		case 5:
			getchar();
			system("cls");
			SortGoods_Number_Max_to_Low(POS);
			break;
		case 6:
			getchar();
			system("cls");
			SortGoods_Number_Low_to_Max(POS);
			break;
		case 7:
			getchar();
			system("cls");
			SortGoods_Date(POS);
			break;
		case 8:
			getchar();
			system("cls");
			ShowGoods(POS);
			break;
		case 9:
			getchar();
			system("pause");
			system("cls");
			Sort_menu();
			break;
		default:
			getchar();
			rewind(stdin);
			printf("请重新选择\n");
			system("pause");
			system("cls");
			SortGoods_menu();
		}
	}
}