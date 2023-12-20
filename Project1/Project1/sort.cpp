#include"store.h"
#include"user.h"
#include"interface.h"
#include"sort.h"
void SortGoods_Quantity_Max_to_Low(char* filename)
{
    FILE* fp = fopen(filename, "rb+");
    if (fp == NULL)
    {
        printf("文件打开失败：%s!\n", filename);
        AddDetail("价格排序失败，录入文件打开失败");
        return;
    }

    // 统计记录总数
    fseek(fp, 0L, SEEK_END);
    int num_goods = ftell(fp) / sizeof(Goods);

    // 动态分配内存来存储所有商品记录
    Goods* goods_arr = (Goods*)malloc(num_goods * sizeof(Goods));
    if (goods_arr == NULL)
    {
        printf("内存分配失败！\n");
        fclose(fp);
        AddDetail("价格排序失败，内存分配失败");
        return;
    }

    // 将所有商品记录读取到内存中
    rewind(fp);
    fread(goods_arr, sizeof(Goods), num_goods, fp);

    // 对商品按照价格进行排序
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

    // 将排序后的商品记录写回文件中
    rewind(fp);
    fwrite(goods_arr, sizeof(Goods), num_goods, fp);

    // 释放动态分配的内存
    free(goods_arr);

    fclose(fp);
    AddDetail("价格排序成功");
    printf("排序成功!以下为排序后结果！\n");
    ShowGoods(POS);
    /*printf("排序成功！请返回查看结果！\n");
    system("pause");
    system("cls");*/
}

void SortGoods_Quantity_Low_to_Max(char* filename)
{
    FILE* fp = fopen(filename, "rb+");
    if (fp == NULL)
    {
        printf("文件打开失败：%s!\n", filename);
        AddDetail("价格排序失败，录入文件打开失败");
        return;
    }

    // 统计记录总数
    fseek(fp, 0L, SEEK_END);
    int num_goods = ftell(fp) / sizeof(Goods);

    // 动态分配内存来存储所有商品记录
    Goods* goods_arr = (Goods*)malloc(num_goods * sizeof(Goods));
    if (goods_arr == NULL)
    {
        printf("内存分配失败！\n");
        fclose(fp);
        AddDetail("价格排序失败，内存分配失败");
        return;
    }

    // 将所有商品记录读取到内存中
    rewind(fp);
    fread(goods_arr, sizeof(Goods), num_goods, fp);

    // 对商品按照价格进行排序
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

    // 将排序后的商品记录写回文件中
    rewind(fp);
    fwrite(goods_arr, sizeof(Goods), num_goods, fp);

    // 释放动态分配的内存
    free(goods_arr);

    fclose(fp);
    AddDetail("价格排序成功");
    printf("排序成功!以下为排序后结果！\n");
    ShowGoods(POS);
    /* printf("排序成功！请返回查看结果！\n");
     system("pause");
     system("cls");
 }*/
}
void SortGoods_Price_Max_to_Low(char* filename)
{
    FILE* fp = fopen(filename, "rb+");
    if (fp == NULL)
    {
        printf("文件打开失败：%s!\n", filename);
        AddDetail("价格排序失败，录入文件打开失败");
        return;
    }

    // 统计记录总数
    fseek(fp, 0L, SEEK_END);
    int num_goods = ftell(fp) / sizeof(Goods); // goods的数量

    // 动态分配内存来存储所有商品记录
    Goods* goods_arr = (Goods*)malloc(num_goods * sizeof(Goods));
    if (goods_arr == NULL)
    {
        printf("内存分配失败！\n");
        fclose(fp);
        AddDetail("价格排序失败，内存分配失败");
        return;
    }

    // 将所有商品记录读取到内存中
    rewind(fp);
    fread(goods_arr, sizeof(Goods), num_goods, fp);

    // 对商品按照价格进行排序
    for (int i = 0; i < num_goods - 1; i++)
    {
        for (int j = i + 1; j < num_goods; j++)
        { ///   1为货物的有效性查询
            if (goods_arr[i].index == 1 && goods_arr[j].index == 1 && goods_arr[i].price < goods_arr[j].price)
            {
                Goods temp = goods_arr[i];
                goods_arr[i] = goods_arr[j];
                goods_arr[j] = temp;
            }
        }
    }

    // 将排序后的商品记录写回文件中
    rewind(fp);
    fwrite(goods_arr, sizeof(Goods), num_goods, fp);

    // 释放动态分配的内存
    free(goods_arr);

    fclose(fp);
    AddDetail("价格排序成功");
    printf("排序成功!以下为排序后结果！\n");
    ShowGoods(POS);
    /*printf("排序成功！请返回查看结果！\n");
    system("pause");
    system("cls");*/
}

void SortGoods_Price_Low_to_Max(char* filename)
{
    FILE* fp = fopen(filename, "rb+");
    if (fp == NULL)
    {
        printf("文件打开失败：%s!\n", filename);
        AddDetail("价格排序失败，录入文件打开失败");
        return;
    }

    // 统计记录总数
    fseek(fp, 0L, SEEK_END);
    int num_goods = ftell(fp) / sizeof(Goods); // goods的数量

    // 动态分配内存来存储所有商品记录
    Goods* goods_arr = (Goods*)malloc(num_goods * sizeof(Goods));
    if (goods_arr == NULL)
    {
        printf("内存分配失败！\n");
        fclose(fp);
        AddDetail("价格排序失败，内存分配失败");
        return;
    }

    // 将所有商品记录读取到内存中
    rewind(fp);
    fread(goods_arr, sizeof(Goods), num_goods, fp);

    // 对商品按照价格进行排序
    for (int i = 0; i < num_goods - 1; i++)
    {
        for (int j = i + 1; j < num_goods; j++)
        { ///   1为货物的有效性查询
            if (goods_arr[i].index == 1 && goods_arr[j].index == 1 && goods_arr[i].price > goods_arr[j].price)
            {
                Goods temp = goods_arr[i];
                goods_arr[i] = goods_arr[j];
                goods_arr[j] = temp;
            }
        }
    }

    // 将排序后的商品记录写回文件中
    rewind(fp);
    fwrite(goods_arr, sizeof(Goods), num_goods, fp);

    // 释放动态分配的内存
    free(goods_arr);

    fclose(fp);
    AddDetail("价格排序成功");
    printf("排序成功!以下为排序后结果！\n");
    ShowGoods(POS);
    /*printf("排序成功！请返回查看结果！\n");
    system("pause");
    system("cls");*/
}

void SortGoods_Date(char* filename)
{ // 根据进货排序
    FILE* fp = fopen(filename, "rb+");
    if (fp == NULL)
    {
        printf("文件打开失败：%s!\n", filename);
        AddDetail("日期排序失败,文件打开失败");
        return;
    }
    // 统计记录总数
    fseek(fp, 0L, SEEK_END);
    int num_goods = ftell(fp) / sizeof(Goods); // 因为此处fp指向了文件末尾，所以此时ftell返回的值/Goods就相当于sizeof了。

    // 读取所有商品记录到内存中
    rewind(fp); // 将文件指针重置到文件开头
    Goods* goods_arr = (Goods*)malloc(num_goods * sizeof(Goods));
    for (int i = 0; i < num_goods; i++)
    {
        fread(&goods_arr[i], sizeof(Goods), 1, fp); // 将数据读取到内存中  (类比为数组)
    }

    // 按照商品进货日期从早到晚排序
    // 年
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
    // 将排序后的商品记录重新写回文件
    rewind(fp);
    for (int i = 0; i < num_goods; i++)
    {
        fwrite(&goods_arr[i], sizeof(Goods), 1, fp);
    }
    // 月
    for (int i = 0; i < num_goods; i++)
    {
        fread(&goods_arr[i], sizeof(Goods), 1, fp); // 将数据读取到内存中  (类比为数组)
    }

    // 按照商品进货日期从早到晚排序
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
    // 将排序后的商品记录重新写回文件
    rewind(fp);
    for (int i = 0; i < num_goods; i++)
    {
        fwrite(&goods_arr[i], sizeof(Goods), 1, fp);
    }
    // 日
    for (int i = 0; i < num_goods; i++)
    {
        fread(&goods_arr[i], sizeof(Goods), 1, fp); // 将数据读取到内存中  (类比为数组)
    }

    // 按照商品进货日期从早到晚排序
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
    // 将排序后的商品记录重新写回文件
    rewind(fp);
    for (int i = 0; i < num_goods; i++)
    {
        fwrite(&goods_arr[i], sizeof(Goods), 1, fp);
    }
    fclose(fp);
    AddDetail("日期排序成功");
    free(goods_arr);
    printf("排序成功!以下为排序后结果！\n");
    ShowGoods(POS);
    //printf("排序成功！请返回查看结果！\n");
    //printf("一秒后返回\n");
    //Sleep(1000);
    ////("pause");
    //system("cls");
}

void SortGoods_Number_Low_to_Max(char* filename)
{
    FILE* fp = fopen(filename, "rb+");
    if (fp == NULL)
    {
        printf("文件打开失败：%s!\n", filename);
        AddDetail("序号排序失败");
        return;
    }
    // 统计记录总数
    fseek(fp, 0L, SEEK_END);
    int num_goods = ftell(fp) / sizeof(Goods);

    // 读取所有商品记录到内存中
    rewind(fp);
    Goods* goods_arr = (Goods*)malloc(num_goods * sizeof(Goods));
    for (int i = 0; i < num_goods; i++)
    {
        fread(&goods_arr[i], sizeof(Goods), 1, fp);
    }

    // 对商品按照num从大到小排序
    for (int i = 0; i < num_goods - 1; i++)
    {
        for (int j = i + 1; j < num_goods; j++)
        {
            // 根据字符串长度比较num大小
            if (strlen(goods_arr[i].num) < strlen(goods_arr[j].num))
            {
                Goods temp = goods_arr[i];
                goods_arr[i] = goods_arr[j];
                goods_arr[j] = temp;
            }
            else if (strlen(goods_arr[i].num) == strlen(goods_arr[j].num))
            {
                // 如果字符串长度相同，使用strcmp函数比较字符串大小
                if (strcmp(goods_arr[i].num, goods_arr[j].num) < 0)
                {
                    Goods temp = goods_arr[i];
                    goods_arr[i] = goods_arr[j];
                    goods_arr[j] = temp;
                }
            }
        }
    }

    // 将排序后的商品记录重新写回文件
    rewind(fp);
    for (int i = 0; i < num_goods; i++)
    {
        fwrite(&goods_arr[i], sizeof(Goods), 1, fp);
    }
    fclose(fp);
    free(goods_arr);
    printf("排序成功!以下为排序后结果！\n");
    ShowGoods(POS);
    /*printf("排序成功！请返回查看结果！\n");
    system("pause");
    system("cls");*/
}

void SortGoods_Number_Max_to_Low(char* filename)
{
    FILE* fp = fopen(filename, "rb+");
    if (fp == NULL)
    {
        printf("文件打开失败：%s!\n", filename);
        AddDetail("序号排序失败");
        return;
    }
    // 统计记录总数
    fseek(fp, 0L, SEEK_END);
    int num_goods = ftell(fp) / sizeof(Goods);

    // 读取所有商品记录到内存中
    rewind(fp);
    Goods* goods_arr = (Goods*)malloc(num_goods * sizeof(Goods));
    for (int i = 0; i < num_goods; i++)
    {
        fread(&goods_arr[i], sizeof(Goods), 1, fp);
    }

    // 对商品按照num从大到小排序
    for (int i = 0; i < num_goods - 1; i++)
    {
        for (int j = i + 1; j < num_goods; j++)
        {
            // 根据字符串长度比较num大小
            if (strlen(goods_arr[i].num) > strlen(goods_arr[j].num))
            {
                Goods temp = goods_arr[i];
                goods_arr[i] = goods_arr[j];
                goods_arr[j] = temp;
            }
            else if (strlen(goods_arr[i].num) == strlen(goods_arr[j].num))
            {
                // 如果字符串长度相同，使用strcmp函数比较字符串大小
                if (strcmp(goods_arr[i].num, goods_arr[j].num) > 0)
                {
                    Goods temp = goods_arr[i];
                    goods_arr[i] = goods_arr[j];
                    goods_arr[j] = temp;
                }
            }
        }
    }

    // 将排序后的商品记录重新写回文件
    rewind(fp);
    for (int i = 0; i < num_goods; i++)
    {
        fwrite(&goods_arr[i], sizeof(Goods), 1, fp);
    }
    fclose(fp);
    free(goods_arr);
    printf("排序成功!以下为排序后结果！\n");
    ShowGoods(POS);
    /*printf("排序成功！请返回查看结果！\n");
    system("pause");
    system("cls");*/
}