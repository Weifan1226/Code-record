#include"user.h"
#include"store.h"
#include"interface.h"
#include"sort.h"
#include"static.h"
void print_menu() {
    printf("\t\t\t\t\t    *******                *******  \n");
    printf("\t\t\t\t\t    #######  ����ͳ��ϵͳ  #######  \n");
    printf("\t\t\t\t\t    -------                -------  \n");
    printf("%70s", "\t\t    ������������������������������\n");
    printf("\t\t\t\t\t\t    ��ѡ��ͳ������\n");
    printf("\t\t\t\t\t\t    1. ����Ʒ��ͳ��\n");
    printf("\t\t\t\t\t\t    2. ����������ͳ��\n");
    printf("\t\t\t\t\t\t    3. *��������ͳ��\n");
    printf("\t\t\t\t\t\t    4. ������ͳ��\n");
    printf("\t\t\t\t\t\t    5. *���۸�ͳ��\n");
    printf("\t\t\t\t\t\t    6. *������ͳ��\n");
    printf("\t\t\t\t\t\t    7. ������һ��\n");
    printf("%77s", "\t\t    ��������������������������������\n");
    printf("\t\t\t\t\t    -------                -------  \n");
    printf("\t\t\t\t\t    #######    ����ϵͳ    #######  \n");
    printf("\t\t\t\t\t    *******                *******  \n");
    printf("������\n");
}
void print_product(const Goods* product) {
    printf("%s %s %04d-%02d-%02d %s %s %d %0.2f\n",
        product->num, product->name, product->year, product->month, product->day,
        product->duration, product->type, product->quantity, product->price);
}
void print_products(const Goods* head) {
    for (const Goods* ptr = head; ptr != NULL; ptr = ptr->next) {
        print_product(ptr);
    }
}
int contains(const char* str1, const char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 < len2) {
        return 0;
    }

    for (int i = 0; i <= len1 - len2; i++) {
        if (strncmp(str1 + i, str2, len2) == 0) {
            return 1;
        }
    }
    return 0;
}
int check_date_format(char* str) {
    if (strlen(str) != 10)
        return 0;
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) {
            if (str[i] != '-')
                return 0;
        }
        else {
            if (str[i] < '0' || str[i] > '9')
                return 0;
        }
    }
    return 1;
}// �����ֵ��ʽ�Ƿ���ȷ��ֻ�ܰ������ֺ�С����
int check_num_format(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] < '0' || str[i] > '9') {
            if (str[i] != '.')
                return 0;
        }
    }
    return 1;
}

int read_products(Goods** head, const char* filename) {
    Goods a;
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        return 0;
    }

    int count = 0;
    Goods* current = NULL;
    while (fread(&a, sizeof(Goods), 1, fp) == 1) {
        count++;
    }
    fseek(fp, 0, SEEK_SET);
    int temp = count;
    while (!feof(fp) && temp--) {
        Goods* new_goods = (Goods*)malloc(sizeof(Goods));
        fread(new_goods, sizeof(Goods), 1, fp);
        new_goods->next = NULL;

        if (*head == NULL) {
            *head = new_goods;
            current = new_goods;
        }
        else {
            current->next = new_goods;
            current = new_goods;
        }

        //count++;
    }
    while (fread(&a, sizeof(Goods), 1, fp) == 1) {
        count++;
    }
    fclose(fp);
    return count;
}
bool compare(int a, int b, char symbol) {
    switch (symbol) {
    case '>':return a > b;
    case '<':return a < b;
    case '=':return a == b;
    default: return false;
    }
}//�Ƚ�����ֵ�Ƿ���������ıȽϷ���
const char* compare_symbol(char symbol) {
    switch (symbol) {
    case '>': return "����";
    case '<': return "С��";
    case '=': return "����";
    default: return "";
    }
}// ���ݱȽϷ����滻Ϊ��Ӧ�������ַ���
void print_statistics(const Goods* head, int choice, Condition condition, int int_condition) {
    int cnt = 0;
    switch (choice) {
    case 1: {
        printf("��Ʒ������ %s ����Ʒ�б�\n", condition.str);
        for (const Goods* ptr = head; ptr != NULL; ptr = ptr->next) {
            if (contains(ptr->name, condition.str)) {
                print_product(ptr);
                //cnt++;
            }
        }
        //printf("")
        break;
    }

    case 2: {
        int a = 0, b = 0, c = 0;
        printf("��������Ϊ %s ����Ʒ�б�\n", condition.str);
        for (const Goods* ptr = head; ptr != NULL; ptr = ptr->next) {
            a = atoi(strtok(condition.str, "-"));
            b = atoi(strtok((condition.str + 5), "-"));
            c = atoi(strtok((condition.str + 8), "-"));
            if (
                ptr->year == atoi(strtok(condition.str, "-")) &&
                ptr->month == atoi(strtok((condition.str+5), "-")) &&
                ptr->day == atoi(strtok((condition.str+8), "-"))
                )
            {
                print_product(ptr);
                cnt++;
            }
        }
        printf("��������Ϊ %d-%d-%d ����Ʒ����%d��\n", a,b,c, cnt);
        break;
    }

    case 3: {
        printf("������%c %s �����Ʒ�б�\n", compare_symbol(condition.symbol), condition.str);
        for (const Goods* ptr = head; ptr != NULL; ptr = ptr->next) {
            if (compare(atoi(ptr->duration), atoi(condition.str), condition.symbol))
            {
                print_product(ptr);
            }
        }
        break;
    }

    case 4: {
        printf("����Ϊ%s����Ʒ�б�\n", condition.str);
        //printf(condition.str);
        //printf("\b����Ʒ�б�\n");
        {
            for (const Goods* ptr = head; ptr != NULL; ptr = ptr->next) {
                if (contains(ptr->type, condition.str)) {
                    print_product(ptr);
                }
            }
            break;
        }
    }

    case 5: {
        printf("�۸�%s %s ����Ʒ�б�\n", compare_symbol(condition.symbol), condition.str);
        for (const Goods* ptr = head; ptr != NULL; ptr = ptr->next) {
            if (compare(ptr->price, atof(condition.str), condition.symbol)) {
                print_product(ptr);
                cnt++;
            }
        }
        printf("�۸�%s %s ����Ʒ����%d��\n",compare_symbol(condition.symbol), condition.str, cnt);
        break;
    }
    case 6: {
        printf("����%s %d ����Ʒ�б�\n", compare_symbol(condition.symbol), int_condition);
        for (const Goods* ptr = head; ptr != NULL; ptr = ptr->next) {
            if (compare(ptr->quantity, int_condition, condition.symbol)) {
                print_product(ptr);
            }
        }
        break;
    }

    default:
        printf("��Ч��ѡ��\n");
        break;
    }
}

