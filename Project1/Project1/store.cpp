#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "store.h"
#include"user.h"
#include"interface.h"
#include"sort.h"

void AddDetail(char* operation)
{
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    int year = t->tm_year + 1900; // �����Ҫ���� 1900
    int month = t->tm_mon + 1;    // �·ݴ� 0 ��ʼ����Ҫ�� 1
    int day = t->tm_mday;
    int hour = t->tm_hour;
    int min = t->tm_min;
    int sec = t->tm_sec;

    FILE* pf = fopen(POS_DetailG, "ab+");
    if (pf == NULL)
    {
        printf("�ļ���ʧ�ܣ�%s!\n", POS_DetailG);
        exit(1);
    }
    fprintf(pf, "%d-%d-%d %d:%d:%d : %s\n", year, month, day, hour, min, sec, operation);
    fclose(pf);
}

void AddDetail_Goods(char* operation, Goods goods)
{
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    int year = t->tm_year + 1900; // �����Ҫ���� 1900
    int month = t->tm_mon + 1;    // �·ݴ� 0 ��ʼ����Ҫ�� 1
    int day = t->tm_mday;
    int hour = t->tm_hour;
    int min = t->tm_min;
    int sec = t->tm_sec;

    FILE* pf = fopen(POS_DetailG, "ab+");
    if (pf == NULL)
    {
        printf("�ļ���ʧ�ܣ�%s!\n", POS_DetailG);
        exit(1);
    }
    fprintf(pf, "%d-%d-%d %d:%d:%d : %s\n", year, month, day, hour, min, sec, operation);
    fclose(pf);
}


void ShowDetail()
{
    FILE* pf = fopen(POS_DetailG, "r");
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

void CleanFile(char* filename)
{
    FILE* fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("�ļ��򿪴���\n");
        AddDetail("����ĵ�ʧ�ܣ�(�ļ���ʧ��)");
        exit(1);
    }
    fclose(fp);
    AddDetail("����ĵ��ɹ�");
    system("pause");
    system("cls");
}

void AddGoods(char* filename)
{
    FILE* fp = fopen(filename, "ab+");
    if (fp == NULL)
    {
        printf("�ļ���ʧ�ܣ�%s!\n", filename);
        AddDetail("��ӻ�����Ϣʧ�ܣ�(�ļ���ʧ��,��ȷ���ļ���ȷ����ڡ�)");
        return; // ��ʾ�û����������ļ����򴴽����ļ�
    }

    int fail = 0;
    int success = 0;
    char ch;
    Goods* head = NULL;
    Goods* tail = NULL;
    Goods goods;
    int cnt = 0;
    printf("¼����Ʒ��Ϣ(y/n): ");
    scanf("%c", &ch);

    while (ch == 'y' || ch == 'Y')
    {
        Goods* pb = (Goods*)malloc(sizeof(Goods));
        pb->index = 1;

        printf("��������Ʒ��ţ�");
        scanf("%s", pb->num);
        fseek(fp, 0, SEEK_SET);
        while (fread(&goods, sizeof(goods), 1, fp) == 1)
        {
            if (strcmp(goods.num, pb->num) == 0 && goods.index == 1)
            {
                printf("ϵͳ���󣺱���ظ�\n");
                AddDetail_Goods("��ӻ�����Ϣʧ�ܡ�����ظ�", goods);
                fail++;
                free(pb); // �ͷ��ѷ�����ڴ�
                pb = NULL;
                break;
            }
        }
        if (pb != NULL)
        {
            printf("��������Ʒ���ƣ�");
            scanf("%s", pb->name);
            fseek(fp, 0, SEEK_SET);
            while (fread(&goods, sizeof(goods), 1, fp) == 1)
            {
                if (strcmp(goods.name, pb->name) == 0 && goods.index == 1)
                {
                    printf("ϵͳ������Ʒ���ظ�\n");
                    AddDetail_Goods("��ӻ�����Ϣʧ�ܡ���Ʒ���ظ�", goods);
                    fail++;
                    free(pb); // �ͷ��ѷ�����ڴ�
                    pb = NULL;
                    break;
                }
            }
        }
        if (pb != NULL)
        {
            printf("�������������(����:2022-01-30):");
            scanf("%d-%d-%d", &pb->year, &pb->month, &pb->day);

            // ��֤�·ݺ������Ƿ�Ϸ�
            while (pb->month > 12 || pb->month <= 0)
            {
                printf("���������һ�������ϴ��ڵ��·��� �����������·ݣ�");
                cnt++;
                AddDetail_Goods("��ӻ�����Ϣʧ�ܡ��·ݴ���", goods);
                scanf("%d", &pb->month);
            }

            while (pb->day > 31 || pb->day <= 0)
            {
                printf("�����������ϵ���������������������:");
                cnt++;
                AddDetail_Goods("��ӻ�����Ϣʧ�ܡ����ڴ���", goods);
                scanf("%d", &pb->day);
            }

            printf("�����뱣���� ������������+�����ʽ����");
            scanf("%s", pb->duration);

            printf("��������Ʒ���ͣ�");
            scanf("%s", pb->type);

            printf("�������½���Ʒ������");
            scanf("%d", &pb->quantity);

            // ��֤�����ͼ۸��Ƿ�Ϊ�Ǹ���
            while (pb->quantity == 0)
            {
                printf("���ţ������С������ȻҪ��0����������������� :( \n");
                printf("�������䣡:");
                cnt++;
                scanf("%d", &pb->quantity);
            }
            while (pb->quantity < 0)
            {
                printf("�½���Ʒ��������С���㣡");
                cnt++;
                scanf("%d", &pb->quantity);
            }

            printf("��������Ʒ���ۣ�");
            scanf("%lf", &pb->price);

            while (pb->price < 0)
            {
                cnt++;
                printf("�½���Ʒ��������С���㣡");
                scanf("%d", &pb->quantity);
            }

            pb->next = NULL;

            if (head == NULL) // ����
            {
                head = pb;
                tail = pb;
            }
            else
            {
                tail->next = pb;
                tail = pb;
            }

            success++;
            if (success % 10 == 0) // ���ڵ��Ƿ񳬹�10���������ݻ��浽�ڴ棬һ����д���ļ���������ܡ�
            {
                Goods* p = head;
                while (p != NULL)
                {
                    fwrite(p, sizeof(Goods), 1, fp);
                    p = p->next;
                }
                head = NULL;
                tail = NULL;
            }
        }

        printf("�Ƿ���Ҫ����¼��(y/n): ");
        getchar();
        scanf("%c", &ch);
    }

    // ��ʣ��ļ�¼д���ļ���
    Goods* p = head;
    while (p != NULL)
    {
        fwrite(p, sizeof(Goods), 1, fp);
        p = p->next;
    }

    printf("��һ��¼����%d����Ʒ\n", success);

    double rate = (double)success + 0.1 / (success + fail + 0.1); // ��0.1��ֹ��ĸΪ��
    if (rate < 0.3 && cnt >= 10)
    {
        printf("ϵͳ���ѣ�������������ϵͳ̫���������Ѿ����ϰ巢�Ͷ��ţ����Ѿ�����������  :( \n");

        int k;
        printf("\n���ŷ�����:\n");
        for (k = 0; k <= 50; k++)
        {
            int l;
            printf("%3.0f%%[", (float)k / 50 * 100);
            for (l = 0; l < k; l++)
            {
                printf("*");
            }
            for (; l <= 50; l++)
            {
                printf(".");
            }
            printf("]\r");
            fflush(stdout);
            Sleep(20); // ��ʱ20����
        }
        printf("\n���ŷ��ͳɹ��� ɽ��·Զ�������ټ���(��֮ǰ�ǵð��ҹص�Ŷ��\n");
    }
    else if (rate < 0.5 && cnt >= 7)
    {
        printf("���Ĳ����е�����Ŷ��������ϰ  :)  \n");
    }
    else if (rate < 0.8 && cnt >= 3)
    {
        printf("������Ǹ�С��������ϸ��һ��Ŷ :) \n ");
    }
    else if (cnt == 0)
    {
        printf("��ȷ����Ĳ�����:) \n");
    }

    fclose(fp);
    // �ͷ��ѷ�����ڴ�
    p = head;
    while (p != NULL) // ����ͷ�ڴ�
    {
        Goods* temp = p->next;
        free(p);
        p = temp;
    }
    AddDetail("��ӻ�����Ϣ�ɹ�");
    printf("һ��󷵻�\n");
    Sleep(1000);
    //system("pause");
    system("cls");
}


void ShowGoods(char* filename)
{
    printf("\n");
    printf("********************** �����Ϣ **********************\n");
    printf("|���      |��Ʒ����       |��������    |������       |��Ʒ����|��Ʒ����|��Ʒ�۸�     |\n");
    printf("-------------------------------------------------------------------\n");

    // ��ʼ��ͷ���
    Goods* head = (Goods*)malloc(sizeof(Goods));
    head->next = NULL;

    Goods* pb;
    FILE* pf = fopen(filename, "rb");

    if (pf == NULL)
    {
        printf("�ļ���ʧ�ܣ�%s!\n", filename);
        AddDetail("�����ļ���ʧ��,��ȷ���ļ���ȷ�����");
        exit(1);
    }

    fseek(pf, 0, SEEK_SET);

    while ((pb = (Goods*)malloc(sizeof(Goods))) && fread(pb, sizeof(Goods), 1, pf) == 1)
    {
        if (pb->index == 1)     //��ѯ�����Ƿ���Ч
        {
            pb->next = head->next;  //������head֮����ӽڵ�
            head->next = pb;
        }
        else
        {
            free(pb); // ���������Ч��¼�����ͷŸýڵ���ڴ�ռ�
        }
    }

    Goods* p = head->next; // ��ͷ������һ���ڵ㿪ʼ����������Ϊ�˴�ͷ�ڵ�ֻ�洢��ַ�����洢����
    while (p != NULL)
    {
        printf("|%-10s|%-15s|%4d/%02d/%02d|%12s|%8s|%8d|%12.2lf|\n",
            p->num, p->name, p->year, p->month, p->day,
            p->duration, p->type, p->quantity, p->price);

        p = p->next;
    }

    printf("-------------------------------------------------------------------\n");
    fclose(pf);
    AddDetail("��ʾ���ɹ�");

    // �ͷŶ�̬������ڴ�
    p = head;
    while (p != NULL)
    {
        pb = p->next;
        free(p);
        p = pb;
    }
    system("pause");
    system("cls");
}
//void ShowGoods(char* filename) {
//    FILE* fp = fopen(filename, "r");
//    Goods g;
//    printf("********************** �����Ϣ **********************\n");
//        printf("|���      |��Ʒ����       |��������    |������       |��Ʒ����|��Ʒ����|��Ʒ�۸�     |\n");
//        printf("-------------------------------------------------------------------\n");
//    if (fp == NULL) {
//        printf("error\n");
//        menu0();
//    }
//    while (fread(&g, sizeof(Goods), 1, fp) == 1) {
//        if (g.index == 1) // �д���Ĳ���ʾ��
//        {
//            printf("|%-10s|%-15s|%4d/%02d/%02d|%12s|%8s|%8d|%12.2lf|\n",
//                g.num, g.name , g.year, g.month,g.day,
//                g.duration,g.type, g.quantity, g.price);
//        }
//    }
//    fclose(fp);
//    system("pause");
//}
void AlterGoods(char* filename)
{
    char ch[50] = { 0 };
    char* pc = ch;
    int found = 0;
    Goods goods;
    FILE* pf = fopen(filename, "rb+");
    if (pf == NULL)
    {
        printf("�ļ���ʧ�ܣ�%s!\n", filename);
        AddDetail("�޸���Ʒ��Ϣ���ļ��򿪴���");
        return;
    }
    int choice = 0;
    char fixstr[20];
    printf("��������Ҫ�޸ĵ���Ʒ��Ż�����:");
    scanf("%s", fixstr);

    // ģ����ѯƥ����
    int match_count = 0;
    long match_indices[1024]; // ��һ��ģ����ѯ�� ͨ��match�����¼����ͷ��ַ����ʵ�����ݴ�С�������ձ�����������ַ����
    while (fread(&goods, sizeof(goods), 1, pf) == 1)
    {
        if (goods.index == 1 && (strstr(goods.num, fixstr) != NULL || strstr(goods.name, fixstr) != NULL))
        {
            match_indices[match_count++] = ftell(pf) - sizeof(Goods); // ��¼ÿ����ϲ�ѯ����������ͷ��ַ��
        }
    }

    if (match_count >= 1)
    {
        printf("�ҵ����� %d ��ƥ�����ѡ��Ҫ�޸ĵ���Ʒ��ţ�\n", match_count);
        printf("| ��� | ���     | ��Ʒ����      | ��������  | ������   | ��Ʒ���� | ��Ʒ���� | ��Ʒ�۸�   |\n");
        printf("--------------------------------------------------------------------------------------------\n");
        for (int i = 0; i < match_count; i++)
        {
            fseek(pf, match_indices[i], SEEK_SET);
            fread(&goods, sizeof(Goods), 1, pf);

            printf("|%-6d|%-10s|%-15s|%4d/%02d/%02d|%10s|%11s|%11d|%13.2lf|\n",
                i + 1, goods.num, goods.name, goods.year, goods.month, goods.day,
                goods.duration, goods.type, goods.quantity, goods.price);
            printf("----------------------------------------------------------------------------------------\n");
        }
        choice = 0;
        printf("��ѡ��Ҫ�޸ĵ���Ʒ��ţ���������1-%d����", match_count);
        scanf("%d", &choice);

        while (choice < 1 || choice > match_count)
        {
            printf("������Ч��\n");
            AddDetail("�޸���Ʒ��Ϣ��������Ч");
            printf("����������Ҫ�޸ĵ���Ʒ��ţ���������1-%d��(�����Ҫ�˳�������-1)��", match_count);
            scanf("%d", &choice);
            if (choice == -1)
            {
                printf("�˳��ɹ�\n");
                AddDetail("ϵͳ�˳��ɹ�");
                return;
            }
        }

        fseek(pf, match_indices[choice - 1], SEEK_SET);
        fread(&goods, sizeof(Goods), 1, pf);
    }
    else
    { //----------------------------------
        printf("δ�ҵ���Ʒ��Ϣ\n");
        AddDetail("δ�ҵ���Ʒ��Ϣ");
        return;
        // fseek(pf, match_indices[0], SEEK_SET);
        // fread(&goods, sizeof(Goods), 1, pf);
    }

    printf("| ��� | ���     | ��Ʒ����      | ��������  | ������   | ��Ʒ���� | ��Ʒ���� | ��Ʒ�۸�   |\n");
    printf("|%-10s|%-15s|%4d/%02d/%02d|%10s|%11s|%11d|%13.2lf|\n",
        goods.num, goods.name, goods.year, goods.month, goods.day,
        goods.duration, goods.type, goods.quantity, goods.price);
    printf("�ҵ�������Ʒ����������Ҫ�޸ĵ���Ϣ��ţ�����-1�� ����-2������-3�� �۸�-4��: ");
    getchar();
    scanf("%s", ch);
    while (*pc != '\0')
    {
        if (*pc == '1')
        {
            printf("�������µ���Ʒ���ƣ�");
            scanf("%s", goods.name);
            AddDetail_Goods("�޸������Ƴɹ�", goods);
        }

        else if (*pc == '2')
        {
            printf("�������µ���Ʒ���ͣ�");
            scanf("%s", goods.type);
            AddDetail_Goods("�޸���Ʒ���ͳɹ�", goods);
        }
        else if (*pc == '3')
        {
            printf("�������µ���Ʒ������");
            scanf("%d", &goods.quantity);
            while (goods.quantity < 0)
            {
                printf("�����������������:");
                scanf("%d", &goods.quantity);
            }
            AddDetail_Goods("�޸���Ʒ�����ɹ�", goods);
        }
        else if (*pc == '4')
        {
            printf("�������µ���Ʒ�۸�");
            scanf("%lf", &goods.price);
            while (goods.price < 0)
            {
                printf("�����������������:");
                scanf("%lf", &goods.price);
            }
            AddDetail_Goods("�޸���Ʒ�۸�ɹ�", goods);
        }
        pc++;
    }
    fseek(pf, -((long)sizeof(goods)), SEEK_CUR);
    if (fwrite(&goods, sizeof(goods), 1, pf) == 1)
    {
        found = 1;
        printf("�޸ĳɹ���\n");
    }
    else
    {
        printf("�޸�ʧ�ܣ�\n");
        AddDetail("�޸���Ʒ��Ϣʧ�� ");
    }

    if (match_count == 0)
    {
        printf("û���ҵ�ƥ����\n");
        AddDetail("δ���ҵ�ƥ����");
    }

    fclose(pf);
}

void QueryGoods(char* filename)
{
    Goods* head = (Goods*)malloc(sizeof(Goods)); // ����ͷ�ڵ�
    head->index = -1;                             // ��ͷ�ڵ��index����Ϊ-1��������������Ʒ��Ϣ
    Goods* node = head;                           // ����ָ��
    Goods* pb;
    FILE* pf = fopen(filename, "rb");
    char querystr[20];
    int found = 0;

    if (NULL == pf)
    {
        printf("�ļ���ʧ��\n");
        AddDetail("��ѯ��Ʒ���ļ���ʧ��");
        exit(1);
    }

    printf("��������Ҫ��ѯ����Ʒ���ƻ���:");
    scanf("%s", querystr);

    fseek(pf, 0, SEEK_SET);

    pb = (Goods*)malloc(sizeof(Goods));
    pb->next = NULL;

    // ��ȡ���ݣ������档
    while (fread(pb, sizeof(Goods), 1, pf) == 1)
    {
        node->next = pb;
        node = node->next;
        pb = (Goods*)malloc(sizeof(Goods)); // �����ڴ�
        pb->next = NULL;                     // �½ڵ�Ϊ��
    }

    for (node = head->next; node != NULL; node = node->next)
    {
        if (node->index == 1 && (strstr(node->name, querystr) != NULL || strstr(node->num, querystr) != NULL))
        {
            if (found == 0)
            {
                printf("|���      |��Ʒ����       |��������    |������       |��Ʒ����|��Ʒ����|��Ʒ�۸�     |\n");
                printf("-------------------------------------------------------------------------------\n");
            }
            printf("|%-10s|%-15s|%4d/%02d/%02d|%12s|%8s|%8d|%12.2lf|\n",
                node->num, node->name, node->year, node->month, node->day,
                node->duration, node->type, node->quantity, node->price);
            found = 1;
        }
    }

    if (!found)
    {
        printf("δ��ѯ����Ӧ��Ʒ\n");
    }

    fclose(pf);
    AddDetail("��ѯ��Ʒ�ɹ�");
    system("pause");
    system("cls");
}

void InputGoods(char* filename)
{
    FILE* pf = fopen(filename, "rb+");
    Goods goods;
    char input[20];
    int inputnum;
    int found = 0;
    char ch;

    if (pf == NULL)
    {
        printf("���ļ�ʧ��\n");
        AddDetail("�����������ļ���ʧ��");
        exit(1);
    }

    printf("��������������Ż�����:");
    scanf("%s", input);

    fseek(pf, 0, SEEK_SET);

    int num_matches = 0;
    long match_indices[1024];
    while (fread(&goods, sizeof(goods), 1, pf) == 1)
    {
        if (goods.index == 1 && (strstr(goods.name, input) != NULL || strstr(goods.num, input) != NULL))
        {
            match_indices[num_matches] = ftell(pf) - sizeof(goods); // ��¼ƥ������ļ�λ������
            num_matches++;
            found = 1; // �ҵ���ƥ������Ϊ��
        }
    }

    if (found)
    {
        printf("�ҵ�����ƥ���\n");
        printf("| ��� | ���     | ��Ʒ����      | ��������  | ������   | ��Ʒ���� | ��Ʒ���� | ��Ʒ�۸�   |\n");
        printf("--------------------------------------------------------------------------\n");

        for (int i = 0; i < num_matches; i++)
        {
            fseek(pf, match_indices[i], SEEK_SET);
            fread(&goods, sizeof(goods), 1, pf);

            printf("|%-6d|%-10s|%-15s|%4d/%02d/%02d|%10s|%11s|%11d|%13.2lf|\n",
                i + 1, goods.num, goods.name, goods.year, goods.month, goods.day,
                goods.duration, goods.type, goods.quantity, goods.price);
            printf("--------------------------------------------------------------------------\n");
        }

        printf("������Ҫ������������Ʒ���(1-%d):", num_matches);
        scanf("%d", &inputnum);

        if (inputnum > 0 && inputnum <= num_matches)
        {
            fseek(pf, match_indices[inputnum - 1], SEEK_SET);
            fread(&goods, sizeof(goods), 1, pf);
            printf("| ���     | ��Ʒ����      | ��������  | ������   | ��Ʒ���� | ��Ʒ���� | ��Ʒ�۸�   |\n");
            printf("------------------------------------------------------------------------\n");
            printf("|%-10s|%-15s|%4d/%02d/%02d|%10s|%11s|%11d|%13.2lf|\n",
                goods.num, goods.name, goods.year, goods.month, goods.day,
                goods.duration, goods.type, goods.quantity, goods.price);
            printf("------------------------------------------------------------------------\n");

            printf("��ѡ���Ƿ���Ҫ���Ӹ���Ʒ��������y/n��:");
            scanf(" %c", &ch);
            if (ch == 'y' || ch == 'Y')
            {
                printf("���������������");
                scanf("%d", &inputnum);

                fseek(pf, (long)(ftell(pf) - sizeof(Goods)), SEEK_SET);
                goods.quantity += inputnum;

                if (fwrite(&goods, sizeof(Goods), 1, pf) == 1)
                {
                    printf("�����ɹ���\n");
                    found = 1;
                }
                else
                {
                    printf("����ʧ�ܣ�\n");
                    AddDetail("��������ʧ��");
                }
            }
            else
            {
                printf("�ѷ�����������\n");
                AddDetail("�ѷ�����������");
            }
        }
        else
        {
            printf("��Ч�����\n");
        }
    }
    else
    {
        printf("û���ҵ�ƥ����\n");
        AddDetail("δ���ҵ�ƥ����");
    }

    fclose(pf);
    system("pause");
    system("cls");
}

void DeleteGoods(char* filename)
{
    Goods goods;
    FILE* pf = fopen(filename, "rb+");

    if (pf == NULL)
    {
        printf("���ļ�ʧ��\n");
        AddDetail("ɾ����Ʒ���ļ���ʧ��");
        exit(1);
    }

    char fixstr[20];
    printf("��������Ҫɾ������Ʒ��Ż�����:");
    scanf("%s", fixstr);

    fseek(pf, 0, SEEK_SET);

    int found = 0;
    int num_matches = 0;
    int match_indices[1024];
    while (fread(&goods, sizeof(goods), 1, pf) == 1)
    {
        if (goods.index == 1 && (strstr(goods.name, fixstr) != NULL || strstr(goods.num, fixstr) != NULL))
        {
            match_indices[num_matches] = ftell(pf) - sizeof(goods); // ��¼ƥ������ļ�λ������
            num_matches++;
            found = 1; // �ҵ���ƥ������Ϊ��
        }
    }

    if (found)
    {
        printf("�ҵ�����%dƥ���\n", num_matches);
        printf("| ��� | ���     | ��Ʒ����      | ��������  | ������   | ��Ʒ���� | ��Ʒ���� | ��Ʒ�۸�   |\n");
        printf("--------------------------------------------------------------------------\n");

        for (int i = 0; i < num_matches; i++)
        {
            fseek(pf, match_indices[i], SEEK_SET);
            fread(&goods, sizeof(goods), 1, pf);

            printf("|%-6d|%-10s|%-15s|%4d/%02d/%02d|%10s|%11s|%11d|%13.2lf|\n",
                i + 1, goods.num, goods.name, goods.year, goods.month, goods.day,
                goods.duration, goods.type, goods.quantity, goods.price);
            printf("--------------------------------------------------------------------------\n");
        }

        int delete_index;
        printf("������Ҫɾ������Ʒ��� (1-%d)(-1ȡ������):", num_matches);
        scanf("%d", &delete_index);
        if (delete_index == -1)
        {
            printf("ȡ���ɹ�\n");
            return;
        }
        if (delete_index > 0 && delete_index <= num_matches)
        {
            fseek(pf, match_indices[delete_index - 1], SEEK_SET);
            goods.index = 0;
            if (fwrite(&goods, sizeof(Goods), 1, pf) == 1)
            {
                printf("ɾ���ɹ���\n");
            }
            else
            {
                printf("ɾ��ʧ�ܣ�\n");
                AddDetail_Goods("ɾ��ʧ��", goods);
            }
        }
        else
        {
            printf("��Ч�����\n");
        }
    }
    else
    {
        printf("δ�ҵ��κ�ƥ����\n");
    }

    fclose(pf);
    AddDetail_Goods("ɾ���������", goods);
    system("pause");
    system("cls");
}


void SaleGoods(char* filename)
{
    FILE* pf = fopen(filename, "rb+");
    Goods goods;
    char input[20];
    int soldnum = 0;
    int num_matches = 0;
    int found = 0;
    if (pf == NULL)
    {
        printf("���ļ�ʧ��\n");
        AddDetail("��������ļ���ʧ��");
        exit(1);
    }

    printf("���������������Ż�����:");
    scanf("%s", input);

    fseek(pf, 0, SEEK_SET);
    int match_count = 0;
    long match_indices[1024];
    found = 0;
    while (fread(&goods, sizeof(goods), 1, pf) == 1)
    {
        if (goods.index == 1 && (strstr(goods.name, input) != NULL || strstr(goods.num, input) != NULL))
        {
            match_indices[num_matches] = ftell(pf) - sizeof(goods); // ��¼ƥ������ļ�λ������
            num_matches++;
            found = 1; // �ҵ���ƥ������Ϊ��
        }
    }
    if (found)
    {
        printf("�ҵ����� %d ��ƥ�����ѡ��Ҫ��������Ʒ��ţ�\n", match_count);
        printf("| ��� | ���     | ��Ʒ����      | ��������  | ������   | ��Ʒ���� | ��Ʒ���� | ��Ʒ�۸�   |\n");
        printf("--------------------------------------------------------------------------------------------\n");
        for (int i = 0; i < num_matches; i++)
        {
            fseek(pf, match_indices[i], SEEK_SET);
            fread(&goods, sizeof(Goods), 1, pf);

            printf("|%-6d|%-10s|%-15s|%4d/%02d/%02d|%10s|%11s|%11d|%13.2lf|\n",
                i + 1, goods.num, goods.name, goods.year, goods.month, goods.day,
                goods.duration, goods.type, goods.quantity, goods.price);
            printf("----------------------------------------------------------------------------------------\n");
        }
        int choice = 0;
        printf("��ѡ��Ҫ��������Ʒ��ţ���������1-%d��(-1ȡ������)��", num_matches);
        scanf("%d", &choice);
        if (choice == -1)
        {
            printf("ȡ���ɹ�\n");
            return;
        }
        if (choice < 1 || choice > num_matches)
        {
            printf("������Ч��\n");
            AddDetail("������Ʒ��Ϣ��������Ч");
            return;
        }

        fseek(pf, match_indices[choice - 1], SEEK_SET);
        fread(&goods, sizeof(Goods), 1, pf);
    }
    else
    { //-----------------------------------------
        printf("δ�ҵ���Ʒ��Ϣ\n");
        AddDetail("δ�ҵ���Ʒ��Ϣ");
        return;
    }

    printf("| ��� | ���     | ��Ʒ����      | ��������  | ������   | ��Ʒ���� | ��Ʒ���� | ��Ʒ�۸�   |\n");

    printf("|%-6d|%-10s|%-15s|%4d/%02d/%02d|%10s|%11s|%11d|%13.2lf|\n",
        1, goods.num, goods.name, goods.year, goods.month, goods.day,
        goods.duration, goods.type, goods.quantity, goods.price);

    printf("�ҵ�������Ʒ����������������: ");
    getchar();
    scanf("%d", &soldnum);

    while (soldnum <= 0 || goods.quantity < soldnum)
    {
        if (soldnum <= 0)
        {
            printf("��������Ӧ��������\n");
            AddDetail("������Ʒ����������Ӧ��Ϊ����");
        }
        else if (goods.quantity < soldnum)
        {
            printf("������������,��ʣ%d����\n", goods.quantity);
            AddDetail("��治�㣬����ʧ��");
        }
        scanf("%d", &soldnum);
    }

    if (goods.quantity >= soldnum)
    {
        goods.quantity -= soldnum;
        printf("�����ɹ���\n");

        if (goods.quantity >= 10)
        {
            printf("%s���ʣ��%d����\n", goods.name, goods.quantity);
        }
        else if (goods.quantity > 0 && goods.quantity < 10)
        {
            printf("%s�����ţ��뼰ʱ������\n", goods.name);
        }
        else if (goods.quantity == 0)
        {
            printf("%s��ȫ������������״̬���㣬�����½�����\n", goods.name);
            goods.index = 0;
        }

        fseek(pf, (long)(ftell(pf) - sizeof(Goods)), SEEK_SET);

        if (fwrite(&goods, sizeof(Goods), 1, pf) == 1)
        {
            found = 1;
            AddDetail_Goods("���������ɹ�", goods);
        }
        else
        {
            printf("����ʧ�ܣ�\n");
            AddDetail_Goods("����ʧ��", goods);
        }
    }
    else
    {
        printf("����ʣ%d�����޷�������\n", goods.quantity);
        found = 1;
    }

    fclose(pf);
    system("pause");
    system("cls");
}

void UpdateGoodsList(char* input_file, char* goods_file)
{
    char ch;
    int index = 1;
    FILE* fp_input = fopen(input_file, "rb");
    if (fp_input == NULL)
    {
        printf("��¼���ļ�ʧ�ܣ�\n");
        AddDetail("�������ʧ�ܣ�¼���ļ���ʧ��");
        exit(1);
    }

    FILE* fp_goods = fopen(goods_file, "rb+");
    if (fp_goods == NULL)
    {
        printf("�򿪴���ļ�ʧ�ܣ�\n");
        AddDetail("�������ʧ�ܣ�����ļ���ʧ��");
        exit(1);
    }

    Goods new_goods;
    while (fread(&new_goods, sizeof(Goods), 1, fp_input))
    {
        // ������Ʒ�Ƿ��Ѿ������ڴ���ļ���
        fseek(fp_goods, 0, SEEK_SET);
        int exist = 0;
        Goods goods;

        while (fread(&goods, sizeof(Goods), 1, fp_goods) == 1)
        {
            if (strcmp(new_goods.num, goods.num) == 0)
            {
                exist = 1;
                // ���´���ļ��и���Ʒ������
                goods.quantity += new_goods.quantity;
                goods.year = new_goods.year; // ���½�������
                goods.month = new_goods.month;
                goods.day = new_goods.day;
                // �����º����Ʒд�ش���ļ���
                fseek(fp_goods, -sizeof(Goods), SEEK_CUR);
                if (fwrite(&goods, sizeof(Goods), 1, fp_goods) != 1)
                {
                    index = 0;
                    printf("д�����ļ�ʧ�ܣ�\n");
                    AddDetail("�������ʧ�ܣ�����ļ�д��ʧ��");
                    break;
                }
                break;
            }
        }

        // �����Ʒ�����ڣ�������ӵ�����ļ���
        if (!exist)
        {
            new_goods.index = 1;
            if (fwrite(&new_goods, sizeof(Goods), 1, fp_goods) != 1)
            {
                index = 0;
                printf("д�����ļ�ʧ�ܣ�\n");
                AddDetail("�������ʧ�ܣ�����ļ�д��ʧ��");
            }
        }
    }
    fclose(fp_input);
    fclose(fp_goods);
    if (index == 1)
    {
        printf("����������\n");
    }
    AddDetail("������³ɹ�");
}
// ����Ʒ��Ϣ���ݵ��ļ���
void BackupGoods(char* filename, char* output_file)
{
    FILE* fp_input = fopen(filename, "rb");
    if (fp_input == NULL)
    {
        printf("��¼���ļ�ʧ�ܣ�\n");
        AddDetail("�������ʧ�ܣ�¼���ļ���ʧ��");
        exit(1);
    }

    FILE* fp_goods = fopen(output_file, "rb+");
    if (fp_goods == NULL)
    {
        printf("�򿪴汸���ļ�ʧ�ܣ�\n");
        AddDetail("���ﱸ��ʧ�ܣ������ļ���ʧ��");
        exit(1);
    }

    Goods new_goods;
    while (fread(&new_goods, sizeof(Goods), 1, fp_input))
    {
        // ������Ʒ�Ƿ��Ѿ������ڴ���ļ���
        fseek(fp_goods, 0, SEEK_SET);
        int exist = 0;
        Goods goods;

        while (fread(&goods, sizeof(Goods), 1, fp_goods) == 1)
        {
            if (strcmp(new_goods.num, goods.num) == 0)
            {
                exist = 1;
                // �����º����Ʒд�ش���ļ���
                fseek(fp_goods, -sizeof(Goods), SEEK_CUR);
                if (fwrite(&goods, sizeof(Goods), 1, fp_goods) != 1)
                {
                    printf("д�����ļ�ʧ�ܣ�\n");
                    AddDetail("�������ʧ�ܣ�����ļ�д��ʧ��");
                }
                break;
            }
        }

        // �����Ʒ�����ڣ�������ӵ�����ļ���
        if (!exist)
        {
            new_goods.index = 1;
            if (fwrite(&new_goods, sizeof(Goods), 1, fp_goods) != 1)
            {
                printf("д�����ļ�ʧ�ܣ�\n");
                AddDetail("�������ʧ�ܣ�����ļ�д��ʧ��");
            }
        }
    }
    fclose(fp_input);
    fclose(fp_goods);
    AddDetail("������³ɹ�");
}
