#include"store.h"
#include"user.h"
#include"interface.h"
#include"sort.h"
void SortGoods_Quantity_Max_to_Low(char* filename)
{
    FILE* fp = fopen(filename, "rb+");
    if (fp == NULL)
    {
        printf("�ļ���ʧ�ܣ�%s!\n", filename);
        AddDetail("�۸�����ʧ�ܣ�¼���ļ���ʧ��");
        return;
    }

    // ͳ�Ƽ�¼����
    fseek(fp, 0L, SEEK_END);
    int num_goods = ftell(fp) / sizeof(Goods);

    // ��̬�����ڴ����洢������Ʒ��¼
    Goods* goods_arr = (Goods*)malloc(num_goods * sizeof(Goods));
    if (goods_arr == NULL)
    {
        printf("�ڴ����ʧ�ܣ�\n");
        fclose(fp);
        AddDetail("�۸�����ʧ�ܣ��ڴ����ʧ��");
        return;
    }

    // ��������Ʒ��¼��ȡ���ڴ���
    rewind(fp);
    fread(goods_arr, sizeof(Goods), num_goods, fp);

    // ����Ʒ���ռ۸��������
    for (int i = 0; i < num_goods - 1; i++)
    {
        for (int j = i + 1; j < num_goods; j++)
        {
            if (goods_arr[i].index == 1 && goods_arr[j].index == 1 && goods_arr[i].quantity < goods_arr[j].quantity)
            {
                Goods temp = goods_arr[i];
                goods_arr[i] = goods_arr[j];
                goods_arr[j] = temp;
            }
        }
    }

    // ����������Ʒ��¼д���ļ���
    rewind(fp);
    fwrite(goods_arr, sizeof(Goods), num_goods, fp);

    // �ͷŶ�̬������ڴ�
    free(goods_arr);

    fclose(fp);
    AddDetail("�۸�����ɹ�");
    printf("����ɹ�!����Ϊ���������\n");
    ShowGoods(POS);
    /*printf("����ɹ����뷵�ز鿴�����\n");
    system("pause");
    system("cls");*/
}

void SortGoods_Quantity_Low_to_Max(char* filename)
{
    FILE* fp = fopen(filename, "rb+");
    if (fp == NULL)
    {
        printf("�ļ���ʧ�ܣ�%s!\n", filename);
        AddDetail("�۸�����ʧ�ܣ�¼���ļ���ʧ��");
        return;
    }

    // ͳ�Ƽ�¼����
    fseek(fp, 0L, SEEK_END);
    int num_goods = ftell(fp) / sizeof(Goods);

    // ��̬�����ڴ����洢������Ʒ��¼
    Goods* goods_arr = (Goods*)malloc(num_goods * sizeof(Goods));
    if (goods_arr == NULL)
    {
        printf("�ڴ����ʧ�ܣ�\n");
        fclose(fp);
        AddDetail("�۸�����ʧ�ܣ��ڴ����ʧ��");
        return;
    }

    // ��������Ʒ��¼��ȡ���ڴ���
    rewind(fp);
    fread(goods_arr, sizeof(Goods), num_goods, fp);

    // ����Ʒ���ռ۸��������
    for (int i = 0; i < num_goods - 1; i++)
    {
        for (int j = i + 1; j < num_goods; j++)
        {
            if (goods_arr[i].index == 1 && goods_arr[j].index == 1 && goods_arr[i].quantity > goods_arr[j].quantity)
            {
                Goods temp = goods_arr[i];
                goods_arr[i] = goods_arr[j];
                goods_arr[j] = temp;
            }
        }
    }

    // ����������Ʒ��¼д���ļ���
    rewind(fp);
    fwrite(goods_arr, sizeof(Goods), num_goods, fp);

    // �ͷŶ�̬������ڴ�
    free(goods_arr);

    fclose(fp);
    AddDetail("�۸�����ɹ�");
    printf("����ɹ�!����Ϊ���������\n");
    ShowGoods(POS);
    /* printf("����ɹ����뷵�ز鿴�����\n");
     system("pause");
     system("cls");
 }*/
}
void SortGoods_Price_Max_to_Low(char* filename)
{
    FILE* fp = fopen(filename, "rb+");
    if (fp == NULL)
    {
        printf("�ļ���ʧ�ܣ�%s!\n", filename);
        AddDetail("�۸�����ʧ�ܣ�¼���ļ���ʧ��");
        return;
    }

    // ͳ�Ƽ�¼����
    fseek(fp, 0L, SEEK_END);
    int num_goods = ftell(fp) / sizeof(Goods); // goods������

    // ��̬�����ڴ����洢������Ʒ��¼
    Goods* goods_arr = (Goods*)malloc(num_goods * sizeof(Goods));
    if (goods_arr == NULL)
    {
        printf("�ڴ����ʧ�ܣ�\n");
        fclose(fp);
        AddDetail("�۸�����ʧ�ܣ��ڴ����ʧ��");
        return;
    }

    // ��������Ʒ��¼��ȡ���ڴ���
    rewind(fp);
    fread(goods_arr, sizeof(Goods), num_goods, fp);

    // ����Ʒ���ռ۸��������
    for (int i = 0; i < num_goods - 1; i++)
    {
        for (int j = i + 1; j < num_goods; j++)
        { ///   1Ϊ�������Ч�Բ�ѯ
            if (goods_arr[i].index == 1 && goods_arr[j].index == 1 && goods_arr[i].price < goods_arr[j].price)
            {
                Goods temp = goods_arr[i];
                goods_arr[i] = goods_arr[j];
                goods_arr[j] = temp;
            }
        }
    }

    // ����������Ʒ��¼д���ļ���
    rewind(fp);
    fwrite(goods_arr, sizeof(Goods), num_goods, fp);

    // �ͷŶ�̬������ڴ�
    free(goods_arr);

    fclose(fp);
    AddDetail("�۸�����ɹ�");
    printf("����ɹ�!����Ϊ���������\n");
    ShowGoods(POS);
    /*printf("����ɹ����뷵�ز鿴�����\n");
    system("pause");
    system("cls");*/
}

void SortGoods_Price_Low_to_Max(char* filename)
{
    FILE* fp = fopen(filename, "rb+");
    if (fp == NULL)
    {
        printf("�ļ���ʧ�ܣ�%s!\n", filename);
        AddDetail("�۸�����ʧ�ܣ�¼���ļ���ʧ��");
        return;
    }

    // ͳ�Ƽ�¼����
    fseek(fp, 0L, SEEK_END);
    int num_goods = ftell(fp) / sizeof(Goods); // goods������

    // ��̬�����ڴ����洢������Ʒ��¼
    Goods* goods_arr = (Goods*)malloc(num_goods * sizeof(Goods));
    if (goods_arr == NULL)
    {
        printf("�ڴ����ʧ�ܣ�\n");
        fclose(fp);
        AddDetail("�۸�����ʧ�ܣ��ڴ����ʧ��");
        return;
    }

    // ��������Ʒ��¼��ȡ���ڴ���
    rewind(fp);
    fread(goods_arr, sizeof(Goods), num_goods, fp);

    // ����Ʒ���ռ۸��������
    for (int i = 0; i < num_goods - 1; i++)
    {
        for (int j = i + 1; j < num_goods; j++)
        { ///   1Ϊ�������Ч�Բ�ѯ
            if (goods_arr[i].index == 1 && goods_arr[j].index == 1 && goods_arr[i].price > goods_arr[j].price)
            {
                Goods temp = goods_arr[i];
                goods_arr[i] = goods_arr[j];
                goods_arr[j] = temp;
            }
        }
    }

    // ����������Ʒ��¼д���ļ���
    rewind(fp);
    fwrite(goods_arr, sizeof(Goods), num_goods, fp);

    // �ͷŶ�̬������ڴ�
    free(goods_arr);

    fclose(fp);
    AddDetail("�۸�����ɹ�");
    printf("����ɹ�!����Ϊ���������\n");
    ShowGoods(POS);
    /*printf("����ɹ����뷵�ز鿴�����\n");
    system("pause");
    system("cls");*/
}

void SortGoods_Date(char* filename)
{ // ���ݽ�������
    FILE* fp = fopen(filename, "rb+");
    if (fp == NULL)
    {
        printf("�ļ���ʧ�ܣ�%s!\n", filename);
        AddDetail("��������ʧ��,�ļ���ʧ��");
        return;
    }
    // ͳ�Ƽ�¼����
    fseek(fp, 0L, SEEK_END);
    int num_goods = ftell(fp) / sizeof(Goods); // ��Ϊ�˴�fpָ�����ļ�ĩβ�����Դ�ʱftell���ص�ֵ/Goods���൱��sizeof�ˡ�

    // ��ȡ������Ʒ��¼���ڴ���
    rewind(fp); // ���ļ�ָ�����õ��ļ���ͷ
    Goods* goods_arr = (Goods*)malloc(num_goods * sizeof(Goods));
    for (int i = 0; i < num_goods; i++)
    {
        fread(&goods_arr[i], sizeof(Goods), 1, fp); // �����ݶ�ȡ���ڴ���  (���Ϊ����)
    }

    // ������Ʒ�������ڴ��絽������
    // ��
    for (int i = 0; i < num_goods - 1; i++)
    {
        for (int j = i + 1; j < num_goods; j++)
        {
            if (goods_arr[i].index == 1 && goods_arr[i].year > goods_arr[j].year)
            {
                Goods temp = goods_arr[i];
                goods_arr[i] = goods_arr[j];
                goods_arr[j] = temp;
            }
        }
    }
    // ����������Ʒ��¼����д���ļ�
    rewind(fp);
    for (int i = 0; i < num_goods; i++)
    {
        fwrite(&goods_arr[i], sizeof(Goods), 1, fp);
    }
    // ��
    for (int i = 0; i < num_goods; i++)
    {
        fread(&goods_arr[i], sizeof(Goods), 1, fp); // �����ݶ�ȡ���ڴ���  (���Ϊ����)
    }

    // ������Ʒ�������ڴ��絽������
    for (int i = 0; i < num_goods - 1; i++)
    {
        for (int j = i + 1; j < num_goods; j++)
        {
            if (goods_arr[i].index == 1 && (goods_arr[i].month > goods_arr[j].month) && (goods_arr[i].year >= goods_arr[j].year))
            {
                Goods temp = goods_arr[i];
                goods_arr[i] = goods_arr[j];
                goods_arr[j] = temp;
            }
        }
    }
    // ����������Ʒ��¼����д���ļ�
    rewind(fp);
    for (int i = 0; i < num_goods; i++)
    {
        fwrite(&goods_arr[i], sizeof(Goods), 1, fp);
    }
    // ��
    for (int i = 0; i < num_goods; i++)
    {
        fread(&goods_arr[i], sizeof(Goods), 1, fp); // �����ݶ�ȡ���ڴ���  (���Ϊ����)
    }

    // ������Ʒ�������ڴ��絽������
    for (int i = 0; i < num_goods - 1; i++)
    {
        for (int j = i + 1; j < num_goods; j++)
        {
            if (goods_arr[i].index == 1 && (goods_arr[i].day > goods_arr[j].day) && (goods_arr[i].month >= goods_arr[j].month) && (goods_arr[i].year >= goods_arr[j].year))
            {
                Goods temp = goods_arr[i];
                goods_arr[i] = goods_arr[j];
                goods_arr[j] = temp;
            }
        }
    }
    // ����������Ʒ��¼����д���ļ�
    rewind(fp);
    for (int i = 0; i < num_goods; i++)
    {
        fwrite(&goods_arr[i], sizeof(Goods), 1, fp);
    }
    fclose(fp);
    AddDetail("��������ɹ�");
    free(goods_arr);
    printf("����ɹ�!����Ϊ���������\n");
    ShowGoods(POS);
    //printf("����ɹ����뷵�ز鿴�����\n");
    //printf("һ��󷵻�\n");
    //Sleep(1000);
    ////("pause");
    //system("cls");
}

void SortGoods_Number_Low_to_Max(char* filename)
{
    FILE* fp = fopen(filename, "rb+");
    if (fp == NULL)
    {
        printf("�ļ���ʧ�ܣ�%s!\n", filename);
        AddDetail("�������ʧ��");
        return;
    }
    // ͳ�Ƽ�¼����
    fseek(fp, 0L, SEEK_END);
    int num_goods = ftell(fp) / sizeof(Goods);

    // ��ȡ������Ʒ��¼���ڴ���
    rewind(fp);
    Goods* goods_arr = (Goods*)malloc(num_goods * sizeof(Goods));
    for (int i = 0; i < num_goods; i++)
    {
        fread(&goods_arr[i], sizeof(Goods), 1, fp);
    }

    // ����Ʒ����num�Ӵ�С����
    for (int i = 0; i < num_goods - 1; i++)
    {
        for (int j = i + 1; j < num_goods; j++)
        {
            // �����ַ������ȱȽ�num��С
            if (strlen(goods_arr[i].num) < strlen(goods_arr[j].num))
            {
                Goods temp = goods_arr[i];
                goods_arr[i] = goods_arr[j];
                goods_arr[j] = temp;
            }
            else if (strlen(goods_arr[i].num) == strlen(goods_arr[j].num))
            {
                // ����ַ���������ͬ��ʹ��strcmp�����Ƚ��ַ�����С
                if (strcmp(goods_arr[i].num, goods_arr[j].num) < 0)
                {
                    Goods temp = goods_arr[i];
                    goods_arr[i] = goods_arr[j];
                    goods_arr[j] = temp;
                }
            }
        }
    }

    // ����������Ʒ��¼����д���ļ�
    rewind(fp);
    for (int i = 0; i < num_goods; i++)
    {
        fwrite(&goods_arr[i], sizeof(Goods), 1, fp);
    }
    fclose(fp);
    free(goods_arr);
    printf("����ɹ�!����Ϊ���������\n");
    ShowGoods(POS);
    /*printf("����ɹ����뷵�ز鿴�����\n");
    system("pause");
    system("cls");*/
}

void SortGoods_Number_Max_to_Low(char* filename)
{
    FILE* fp = fopen(filename, "rb+");
    if (fp == NULL)
    {
        printf("�ļ���ʧ�ܣ�%s!\n", filename);
        AddDetail("�������ʧ��");
        return;
    }
    // ͳ�Ƽ�¼����
    fseek(fp, 0L, SEEK_END);
    int num_goods = ftell(fp) / sizeof(Goods);

    // ��ȡ������Ʒ��¼���ڴ���
    rewind(fp);
    Goods* goods_arr = (Goods*)malloc(num_goods * sizeof(Goods));
    for (int i = 0; i < num_goods; i++)
    {
        fread(&goods_arr[i], sizeof(Goods), 1, fp);
    }

    // ����Ʒ����num�Ӵ�С����
    for (int i = 0; i < num_goods - 1; i++)
    {
        for (int j = i + 1; j < num_goods; j++)
        {
            // �����ַ������ȱȽ�num��С
            if (strlen(goods_arr[i].num) > strlen(goods_arr[j].num))
            {
                Goods temp = goods_arr[i];
                goods_arr[i] = goods_arr[j];
                goods_arr[j] = temp;
            }
            else if (strlen(goods_arr[i].num) == strlen(goods_arr[j].num))
            {
                // ����ַ���������ͬ��ʹ��strcmp�����Ƚ��ַ�����С
                if (strcmp(goods_arr[i].num, goods_arr[j].num) > 0)
                {
                    Goods temp = goods_arr[i];
                    goods_arr[i] = goods_arr[j];
                    goods_arr[j] = temp;
                }
            }
        }
    }

    // ����������Ʒ��¼����д���ļ�
    rewind(fp);
    for (int i = 0; i < num_goods; i++)
    {
        fwrite(&goods_arr[i], sizeof(Goods), 1, fp);
    }
    fclose(fp);
    free(goods_arr);
    printf("����ɹ�!����Ϊ���������\n");
    ShowGoods(POS);
    /*printf("����ɹ����뷵�ز鿴�����\n");
    system("pause");
    system("cls");*/
}