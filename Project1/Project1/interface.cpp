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
		printf("\t\t\t\t\t    #######  ���й���ϵͳ  #######  \n");
		printf("\t\t\t\t\t    -------                -------  \n");
		printf("%70s", "\t\t    ������������������������������\n");
		printf("%66s", "\t    [1.����Ա��½ ]\n");
		printf("%66s", "\t    [2.�ͻ���½   ]\n");
		printf("%70s", "\t\t    ������������������������������\n");
		printf("\t\t\t\t\t    *******                *******  \n");
		printf("\t\t\t\t\t    #######  ���й���ϵͳ  #######  \n");
		printf("\t\t\t\t\t    -------                -------  \n");
		printf("��ѡ��");
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
			printf("����1��2��ѡ��һ��\n");
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
		printf("\t\t\t\t\t    #######  ��ӭ��������  #######  \n");
		printf("\t\t\t\t\t    -------                -------  \n");
		printf("%70s", "\t\t    ������������������������������\n");
		printf("%65s", "[ 1.��½]\n");
		printf("%65s", "[ 2.ע��]\n");
		printf("%68s", "[ 3.�һ�����]\n");
		printf("%68s", "[ 4.�޸�����]\n");
		printf("%70s", "\t\t    ������������������������������\n");
		printf("\t\t\t\t\t    -------                -------  \n");
		printf("\t\t\t\t\t    #######  ��ӭ��������  #######  \n");
		printf("\t\t\t\t\t    *******                *******  \n");
		printf("��ѡ��");
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
			printf("������Ϸ�ѡ��\n");
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
		printf("\t\t\t\t\t    #######  ���й���ϵͳ  #######  \n");
		printf("\t\t\t\t\t    -------                -------  \n");
		printf("%70s", "\t\t    ������������������������������\n");
		printf("%65s", "[ 1.��½]\n");
		printf("%65s", "[ 2.ע��]\n");
		printf("%65s", "[ 3.�һ�����]\n");
		printf("%65s", "[ 4.�޸�����]\n");
		printf("%70s", "\t\t    ������������������������������\n");
		printf("\t\t\t\t\t    -------                -------  \n");
		printf("\t\t\t\t\t    #######  ���й���ϵͳ  #######  \n");
		printf("\t\t\t\t\t    *******                *******  \n");
		printf("��ѡ��");
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
			printf("������Ϸ�ѡ��\n");
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
	printf("\t\t\t\t\t    #######  ���й���ϵͳ  #######  \n");
	printf("\t\t\t\t\t    -------                -------  \n");
	printf("%70s", "\t\t\t    ����������������������������������\n");
	printf("%70s", "[ 1.��Ʒ��Ϣϵͳ]\n");
	printf("%70s", "[ 2.��Ա��Ϣϵͳ]\n");
	printf("%70s", "[ 3.������ͳ��  ]\n");
	printf("%70s", "[ 4.�˳�ϵͳ    ]\n");
	printf("%70s", "\t\t\t    ����������������������������������\n");
	printf("\t\t\t\t\t    -------                -------  \n");
	printf("\t\t\t\t\t    #######  ���й���ϵͳ  #######  \n");
	printf("\t\t\t\t\t    *******                *******  \n");
	printf("��ѡ��");
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
		printf("��л����ʹ�ã�\n");
		system("pause");
		exit(1);
		break;
	default:
		getchar();
		rewind(stdin);
		printf("���������룡\n");
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
		printf("\t\t\t\t\t    #######  ��ӭ��������  #######  \n");
		printf("\t\t\t\t\t    -------                -------  \n");
		printf("%70s", "\t\t\t    ����������������������������������\n");
		printf("%70s", "[ 1.������Ʒ      ]\n");
		printf("%70s", "[ 2.չʾ��Ʒ��Ϣ  ]\n");
		printf("%70s", "[ 3.�˳�ϵͳ      ]\n");
		printf("%70s", "\t\t\t    ����������������������������������\n");
		printf("\t\t\t\t\t    -------                -------  \n");
		printf("\t\t\t\t\t    #######  ��ӭ��������  #######  \n");
		printf("\t\t\t\t\t    *******                *******  \n");
		printf("��ѡ��");
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
			printf("��л����ʹ�ã�\n");
			system("pause");
			exit(1);
		default:
			getchar();
			rewind(stdin);
			printf("���������룡\n");
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
	memset(my_condition.str, 0, sizeof(my_condition.str));//��֤my_condition.str����Ϊ���ַ���������������
	//Condition* pb = (Condition*)malloc(sizeof(Condition));
	//pb = &my_condition;
	if (count != 0)
	{
		printf("�ɹ���ȡ %d ����Ʒ��Ϣ��\n", count);
		print_menu();
		scanf("%d", &choice);
		getchar();
		switch (choice) {
		case 1: {
			printf("�����������ѯͳ�Ƶ���Ʒ��:\n");
			if (scanf("%s", my_condition.str) == 1) {
				printf("������ȡ�ɹ���");
			}
			else {
				printf("����ʧ�ܣ�");
			}
			break;
		}
		case 2: {
			printf("�����������ѯͳ�ƵĽ�������(yyyy-mm-dd)");

			if (scanf("%s", my_condition.str) == 1) {
				if (check_date_format(my_condition.str))
					printf("������ȡ�ɹ���");
				else {
					printf("����ʧ�ܣ���ʽ����\n");
					//return 1;
				}
			}
		}
			  break;
		case 3: {
			printf("�����������ѯͳ�Ƶı�����(���� ��ֵ)");
			if (scanf("%c %s", &my_condition.symbol, my_condition.str) == 2) {
				if (check_num_format(my_condition.str)) {
				}
				else {
					printf("����ʧ�ܣ�\n");
				}
			}
			break;
		}
		case 4: {
			printf("�����������ѯͳ�Ƶ����� ");
			if (scanf("%s", my_condition.str) == 1) {
			}
			else {
				printf("����ʧ�ܣ�\n");
			}
		}
			  break;
		case 5: {
			printf("�����������ѯͳ�Ƶļ۸�(���� ��ֵ)");
			if (scanf("%c %s", &my_condition.symbol, my_condition.str) == 2) {
				if (check_num_format(my_condition.str)) {
				}
				else {
					printf("����ʧ�ܣ�\n");
				}
			}
			break;
		}
		case 6: {
			printf("�����������ѯͳ�Ƶ���Ʒ�������(���� ��ֵ)");
			if (scanf("%c %d", &my_condition.symbol, &int_condition) == 2) {

			}
			else {
				printf("����ʧ�ܣ�\n");
			}
		}
			  break;
		case 7:
			//getchar();
			system("cls");
			Sort_menu();
			break;
		default:
			printf("��Ч��ѡ��\n");
			break;
		}

	}
	else {
		printf("��ȡ��Ʒ��Ϣʧ�ܣ�\n");
	}
	print_statistics(head, choice, my_condition, int_condition);
	free(head);           // �ͷ������ڴ�
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
		printf("\t\t\t\t\t    #######  ��Ʒ��Ϣϵͳ  #######  \n");
		printf("\t\t\t\t\t    -------                -------  \n");
		printf("%70s", "\t\t\t    ����������������������������������\n");
		printf("%70s", "[ 1.��ѯ��Ʒ��Ϣ]\n");
		printf("%70s", "[ 2.�����Ʒ��Ϣ]\n");
		printf("%70s", "[ 3.ɾ����Ʒ��Ϣ]\n");
		printf("%70s", "[ 4.�޸���Ʒ��Ϣ]\n");
		printf("%70s", "[ 5.չʾ��Ʒ��Ϣ]\n");
		printf("%70s", "[ 6.����]\n");
		printf("%70s", "[ 7.�����ļ���Ϣ]\n");
		printf("%70s", "[ 8.չʾ������ϸ]\n");
		printf("%70s", "[ 9.������һ��]\n");
		printf("%70s", "\t\t\t    ����������������������������������\n");
		printf("\t\t\t\t\t    -------                -------  \n");
		printf("\t\t\t\t\t    #######  ��Ʒ��Ϣϵͳ  #######  \n");
		printf("\t\t\t\t\t    *******                *******  \n");
		printf("��ѡ��");
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
			printf("���������룡");
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
		printf("\t\t\t\t\t    #######  �û���Ϣϵͳ  #######  \n");
		printf("\t\t\t\t\t    -------                -------  \n");
		printf("%70s", "\t\t\t    ����������������������������������\n");
		printf("%70s", "[ 1.��ѯ�û���Ϣ]\n");
		printf("%70s", "[ 2.����û���Ϣ]\n");
		printf("%70s", "[ 3.ɾ���û���Ϣ]\n");
		printf("%70s", "[ 4.�޸��û���Ϣ]\n");
		printf("%70s", "[ 5.չʾ�û���Ϣ]\n");
		printf("%70s", "[ 6.�����û���Ϣ]\n");
		printf("%70s", "[ 7.��ʾ������ϸ]\n");
		printf("%70s", "[ 8.������һ��]\n");
		printf("%70s", "\t\t\t    ����������������������������������\n");
		printf("\t\t\t\t\t    -------                -------  \n");
		printf("\t\t\t\t\t    #######  �û���Ϣϵͳ  #######  \n");
		printf("\t\t\t\t\t    *******                *******  \n");
		printf("��ѡ��");
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
			printf("���������룡");
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
		printf("\t\t\t\t\t    #######  ����ͳ��ϵͳ  #######  \n");
		printf("\t\t\t\t\t    -------                -------  \n");
		printf("%70s", "\t\t    ������������������������������\n");
		printf("%65s", "[ 1.����]\n");
		printf("%65s", "[ 2.ͳ��]\n");
		printf("%68s", "[ 3.������һ��]\n");
		printf("%70s", "\t\t    ������������������������������\n");
		printf("\t\t\t\t\t    -------                -------  \n");
		printf("\t\t\t\t\t    #######  ����ͳ��ϵͳ  #######  \n");
		printf("\t\t\t\t\t    *******                *******  \n");
		printf("��ѡ��");
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
			printf("������ѡ��\n");
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
		printf("\t\t\t\t\t    #######    ����ϵͳ    #######  \n");
		printf("\t\t\t\t\t    -------                -------  \n");
		printf("%77s", "\t\t    ��������������������������������\n");
		printf("%68s", "\t   [ 1.���ݴ��������]\n");
		printf("%68s", "\t   [ 2.���ݴ��������]\n");
		printf("%68s", "\t   [ 3.�����ۼ۽�������]\n");
		printf("%68s", "\t   [ 4.�����ۼ���������]\n");
		printf("%68s", "\t\t   [ 5.������Ʒ��Ž�������]\n");
		printf("%68s", "\t\t   [ 6.������Ʒ�����������]\n");
		printf("%69s", "[ 7.���ݽ�������]\n");
		printf("%69s", "[ 8.չʾ������Ϣ]\n");
		printf("%67s", "   [ 9.������һ��]\n");
		printf("%77s", "\t\t    ��������������������������������\n");
		printf("\t\t\t\t\t    -------                -------  \n");
		printf("\t\t\t\t\t    #######    ����ϵͳ    #######  \n");
		printf("\t\t\t\t\t    *******                *******  \n");
		printf("��ѡ��");
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
			printf("������ѡ��\n");
			system("pause");
			system("cls");
			SortGoods_menu();
		}
	}
}