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
    int year = t->tm_year + 1900; // 年份需要加上 1900
    int month = t->tm_mon + 1;    // 月份从 0 开始，需要加 1
    int day = t->tm_mday;
    int hour = t->tm_hour;
    int min = t->tm_min;
    int sec = t->tm_sec;

    FILE* pf = fopen(POS_DetailG, "ab+");
    if (pf == NULL)
    {
        printf("文件打开失败：%s!\n", POS_DetailG);
        exit(1);
    }
    fprintf(pf, "%d-%d-%d %d:%d:%d : %s\n", year, month, day, hour, min, sec, operation);
    fclose(pf);
}

void AddDetail_Goods(char* operation, Goods goods)
{
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    int year = t->tm_year + 1900; // 年份需要加上 1900
    int month = t->tm_mon + 1;    // 月份从 0 开始，需要加 1
    int day = t->tm_mday;
    int hour = t->tm_hour;
    int min = t->tm_min;
    int sec = t->tm_sec;

    FILE* pf = fopen(POS_DetailG, "ab+");
    if (pf == NULL)
    {
        printf("文件打开失败：%s!\n", POS_DetailG);
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

void CleanFile(char* filename)
{
    FILE* fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("文件打开错误！\n");
        AddDetail("清空文档失败，(文件打开失败)");
        exit(1);
    }
    fclose(fp);
    AddDetail("清空文档成功");
    system("pause");
    system("cls");
}

void AddGoods(char* filename)
{
    FILE* fp = fopen(filename, "ab+");
    if (fp == NULL)
    {
        printf("文件打开失败：%s!\n", filename);
        AddDetail("添加货物信息失败，(文件打开失败,请确认文件正确或存在。)");
        return; // 提示用户重新输入文件名或创建新文件
    }

    int fail = 0;
    int success = 0;
    char ch;
    Goods* head = NULL;
    Goods* tail = NULL;
    Goods goods;
    int cnt = 0;
    printf("录入商品信息(y/n): ");
    scanf("%c", &ch);

    while (ch == 'y' || ch == 'Y')
    {
        Goods* pb = (Goods*)malloc(sizeof(Goods));
        pb->index = 1;

        printf("请输入商品编号：");
        scanf("%s", pb->num);
        fseek(fp, 0, SEEK_SET);
        while (fread(&goods, sizeof(goods), 1, fp) == 1)
        {
            if (strcmp(goods.num, pb->num) == 0 && goods.index == 1)
            {
                printf("系统错误：编号重复\n");
                AddDetail_Goods("添加货物信息失败。编号重复", goods);
                fail++;
                free(pb); // 释放已分配的内存
                pb = NULL;
                break;
            }
        }
        if (pb != NULL)
        {
            printf("请输入商品名称：");
            scanf("%s", pb->name);
            fseek(fp, 0, SEEK_SET);
            while (fread(&goods, sizeof(goods), 1, fp) == 1)
            {
                if (strcmp(goods.name, pb->name) == 0 && goods.index == 1)
                {
                    printf("系统错误：商品名重复\n");
                    AddDetail_Goods("添加货物信息失败。商品名重复", goods);
                    fail++;
                    free(pb); // 释放已分配的内存
                    pb = NULL;
                    break;
                }
            }
        }
        if (pb != NULL)
        {
            printf("请输入进货日期(例如:2022-01-30):");
            scanf("%d-%d-%d", &pb->year, &pb->month, &pb->day);

            // 验证月份和日期是否合法
            while (pb->month > 12 || pb->month <= 0)
            {
                printf("你觉得这是一个地球上存在的月份吗？ 请重新输入月份：");
                cnt++;
                AddDetail_Goods("添加货物信息失败。月份错误", goods);
                scanf("%d", &pb->month);
            }

            while (pb->day > 31 || pb->day <= 0)
            {
                printf("你这是月球上的日期吗，请重新输入日期:");
                cnt++;
                AddDetail_Goods("添加货物信息失败。日期错误", goods);
                scanf("%d", &pb->day);
            }

            printf("请输入保质期 （请输入数字+天的形式）：");
            scanf("%s", pb->duration);

            printf("请输入商品类型：");
            scanf("%s", pb->type);

            printf("请输入新进商品数量：");
            scanf("%d", &pb->quantity);

            // 验证数量和价格是否为非负数
            while (pb->quantity == 0)
            {
                printf("天呐，你这个小笨蛋竟然要进0件货物，真是无语子呢 :( \n");
                printf("给我重输！:");
                cnt++;
                scanf("%d", &pb->quantity);
            }
            while (pb->quantity < 0)
            {
                printf("新进商品数量不能小于零！");
                cnt++;
                scanf("%d", &pb->quantity);
            }

            printf("请输入商品卖价：");
            scanf("%lf", &pb->price);

            while (pb->price < 0)
            {
                cnt++;
                printf("新进商品数量不能小于零！");
                scanf("%d", &pb->quantity);
            }

            pb->next = NULL;

            if (head == NULL) // 链接
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
            if (success % 10 == 0) // 检测节点是否超过10个，将内容缓存到内存，一次性写入文件，提高性能。
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

        printf("是否需要继续录入(y/n): ");
        getchar();
        scanf("%c", &ch);
    }

    // 将剩余的记录写入文件中
    Goods* p = head;
    while (p != NULL)
    {
        fwrite(p, sizeof(Goods), 1, fp);
        p = p->next;
    }

    printf("您一共录入了%d个商品\n", success);

    double rate = (double)success + 0.1 / (success + fail + 0.1); // 用0.1防止分母为零
    if (rate < 0.3 && cnt >= 10)
    {
        printf("系统提醒：由于您操作本系统太过垃圾，已经给老板发送短信，您已经被辞退了捏  :( \n");

        int k;
        printf("\n短信发送中:\n");
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
            Sleep(20); // 延时20毫秒
        }
        printf("\n短信发送成功！ 山高路远，江湖再见！(走之前记得把我关掉哦）\n");
    }
    else if (rate < 0.5 && cnt >= 7)
    {
        printf("您的操作有点生疏哦，请多加练习  :)  \n");
    }
    else if (rate < 0.8 && cnt >= 3)
    {
        printf("你可真是个小笨蛋，再细心一点哦 :) \n ");
    }
    else if (cnt == 0)
    {
        printf("精确无误的操作！:) \n");
    }

    fclose(fp);
    // 释放已分配的内存
    p = head;
    while (p != NULL) // 清理头内存
    {
        Goods* temp = p->next;
        free(p);
        p = temp;
    }
    AddDetail("添加货物信息成功");
    printf("一秒后返回\n");
    Sleep(1000);
    //system("pause");
    system("cls");
}


void ShowGoods(char* filename)
{
    printf("\n");
    printf("********************** 库存信息 **********************\n");
    printf("|编号      |商品名称       |进货日期    |保质期       |商品类型|商品数量|商品价格     |\n");
    printf("-------------------------------------------------------------------\n");

    // 初始化头结点
    Goods* head = (Goods*)malloc(sizeof(Goods));
    head->next = NULL;

    Goods* pb;
    FILE* pf = fopen(filename, "rb");

    if (pf == NULL)
    {
        printf("文件打开失败：%s!\n", filename);
        AddDetail("货物文件打开失败,请确认文件正确或存在");
        exit(1);
    }

    fseek(pf, 0, SEEK_SET);

    while ((pb = (Goods*)malloc(sizeof(Goods))) && fread(pb, sizeof(Goods), 1, pf) == 1)
    {
        if (pb->index == 1)     //查询数据是否有效
        {
            pb->next = head->next;  //依次在head之后添加节点
            head->next = pb;
        }
        else
        {
            free(pb); // 如果不是有效记录，则释放该节点的内存空间
        }
    }

    Goods* p = head->next; // 从头结点的下一个节点开始遍历链表，因为此处头节点只存储地址，不存储数据
    while (p != NULL)
    {
        printf("|%-10s|%-15s|%4d/%02d/%02d|%12s|%8s|%8d|%12.2lf|\n",
            p->num, p->name, p->year, p->month, p->day,
            p->duration, p->type, p->quantity, p->price);

        p = p->next;
    }

    printf("-------------------------------------------------------------------\n");
    fclose(pf);
    AddDetail("显示库存成功");

    // 释放动态分配的内存
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
//    printf("********************** 库存信息 **********************\n");
//        printf("|编号      |商品名称       |生产日期    |保质期       |商品类型|商品数量|商品价格     |\n");
//        printf("-------------------------------------------------------------------\n");
//    if (fp == NULL) {
//        printf("error\n");
//        menu0();
//    }
//    while (fread(&g, sizeof(Goods), 1, fp) == 1) {
//        if (g.index == 1) // 有存货的才显示。
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
        printf("文件打开失败：%s!\n", filename);
        AddDetail("修改商品信息。文件打开错误");
        return;
    }
    int choice = 0;
    char fixstr[20];
    printf("请输入需要修改的商品编号或名称:");
    scanf("%s", fixstr);

    // 模糊查询匹配项
    int match_count = 0;
    long match_indices[1024]; // 第一种模糊查询， 通过match数组记录数据头地址（其实是数据大小，不是普遍意义的物理地址）。
    while (fread(&goods, sizeof(goods), 1, pf) == 1)
    {
        if (goods.index == 1 && (strstr(goods.num, fixstr) != NULL || strstr(goods.name, fixstr) != NULL))
        {
            match_indices[match_count++] = ftell(pf) - sizeof(Goods); // 记录每组符合查询条件的数据头地址。
        }
    }

    if (match_count >= 1)
    {
        printf("找到以下 %d 个匹配项，请选择要修改的商品编号：\n", match_count);
        printf("| 序号 | 编号     | 商品名称      | 进货日期  | 保质期   | 商品类型 | 商品数量 | 商品价格   |\n");
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
        printf("请选择要修改的商品编号（输入数字1-%d）：", match_count);
        scanf("%d", &choice);

        while (choice < 1 || choice > match_count)
        {
            printf("输入无效！\n");
            AddDetail("修改商品信息。输入无效");
            printf("请重新输入要修改的商品编号（输入数字1-%d）(如果需要退出请输入-1)：", match_count);
            scanf("%d", &choice);
            if (choice == -1)
            {
                printf("退出成功\n");
                AddDetail("系统退出成功");
                return;
            }
        }

        fseek(pf, match_indices[choice - 1], SEEK_SET);
        fread(&goods, sizeof(Goods), 1, pf);
    }
    else
    { //----------------------------------
        printf("未找到商品信息\n");
        AddDetail("未找到商品信息");
        return;
        // fseek(pf, match_indices[0], SEEK_SET);
        // fread(&goods, sizeof(Goods), 1, pf);
    }

    printf("| 序号 | 编号     | 商品名称      | 进货日期  | 保质期   | 商品类型 | 商品数量 | 商品价格   |\n");
    printf("|%-10s|%-15s|%4d/%02d/%02d|%10s|%11s|%11d|%13.2lf|\n",
        goods.num, goods.name, goods.year, goods.month, goods.day,
        goods.duration, goods.type, goods.quantity, goods.price);
    printf("找到以上商品，请输入需要修改的信息编号（名称-1， 类型-2，数量-3， 价格-4）: ");
    getchar();
    scanf("%s", ch);
    while (*pc != '\0')
    {
        if (*pc == '1')
        {
            printf("请输入新的商品名称：");
            scanf("%s", goods.name);
            AddDetail_Goods("修改商名称成功", goods);
        }

        else if (*pc == '2')
        {
            printf("请输入新的商品类型：");
            scanf("%s", goods.type);
            AddDetail_Goods("修改商品类型成功", goods);
        }
        else if (*pc == '3')
        {
            printf("请输入新的商品数量：");
            scanf("%d", &goods.quantity);
            while (goods.quantity < 0)
            {
                printf("输入错误，请输入正数:");
                scanf("%d", &goods.quantity);
            }
            AddDetail_Goods("修改商品数量成功", goods);
        }
        else if (*pc == '4')
        {
            printf("请输入新的商品价格：");
            scanf("%lf", &goods.price);
            while (goods.price < 0)
            {
                printf("输入错误，请输入正数:");
                scanf("%lf", &goods.price);
            }
            AddDetail_Goods("修改商品价格成功", goods);
        }
        pc++;
    }
    fseek(pf, -((long)sizeof(goods)), SEEK_CUR);
    if (fwrite(&goods, sizeof(goods), 1, pf) == 1)
    {
        found = 1;
        printf("修改成功！\n");
    }
    else
    {
        printf("修改失败！\n");
        AddDetail("修改商品信息失败 ");
    }

    if (match_count == 0)
    {
        printf("没有找到匹配项\n");
        AddDetail("未能找到匹配项");
    }

    fclose(pf);
}

void QueryGoods(char* filename)
{
    Goods* head = (Goods*)malloc(sizeof(Goods)); // 创建头节点
    head->index = -1;                             // 将头节点的index设置为-1，区别于正常商品信息
    Goods* node = head;                           // 遍历指针
    Goods* pb;
    FILE* pf = fopen(filename, "rb");
    char querystr[20];
    int found = 0;

    if (NULL == pf)
    {
        printf("文件打开失败\n");
        AddDetail("查询商品，文件打开失败");
        exit(1);
    }

    printf("请输入需要查询的商品名称或编号:");
    scanf("%s", querystr);

    fseek(pf, 0, SEEK_SET);

    pb = (Goods*)malloc(sizeof(Goods));
    pb->next = NULL;

    // 读取内容，链表储存。
    while (fread(pb, sizeof(Goods), 1, pf) == 1)
    {
        node->next = pb;
        node = node->next;
        pb = (Goods*)malloc(sizeof(Goods)); // 申请内存
        pb->next = NULL;                     // 新节点为空
    }

    for (node = head->next; node != NULL; node = node->next)
    {
        if (node->index == 1 && (strstr(node->name, querystr) != NULL || strstr(node->num, querystr) != NULL))
        {
            if (found == 0)
            {
                printf("|编号      |商品名称       |生产日期    |保质期       |商品类型|商品数量|商品价格     |\n");
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
        printf("未查询到对应商品\n");
    }

    fclose(pf);
    AddDetail("查询商品成功");
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
        printf("打开文件失败\n");
        AddDetail("进货操作，文件打开失败");
        exit(1);
    }

    printf("请输入进货货物编号或名称:");
    scanf("%s", input);

    fseek(pf, 0, SEEK_SET);

    int num_matches = 0;
    long match_indices[1024];
    while (fread(&goods, sizeof(goods), 1, pf) == 1)
    {
        if (goods.index == 1 && (strstr(goods.name, input) != NULL || strstr(goods.num, input) != NULL))
        {
            match_indices[num_matches] = ftell(pf) - sizeof(goods); // 记录匹配项的文件位置索引
            num_matches++;
            found = 1; // 找到了匹配项，标记为真
        }
    }

    if (found)
    {
        printf("找到以下匹配项：\n");
        printf("| 序号 | 编号     | 商品名称      | 生产日期  | 保质期   | 商品类型 | 商品数量 | 商品价格   |\n");
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

        printf("请输入要增加数量的商品序号(1-%d):", num_matches);
        scanf("%d", &inputnum);

        if (inputnum > 0 && inputnum <= num_matches)
        {
            fseek(pf, match_indices[inputnum - 1], SEEK_SET);
            fread(&goods, sizeof(goods), 1, pf);
            printf("| 编号     | 商品名称      | 生产日期  | 保质期   | 商品类型 | 商品数量 | 商品价格   |\n");
            printf("------------------------------------------------------------------------\n");
            printf("|%-10s|%-15s|%4d/%02d/%02d|%10s|%11s|%11d|%13.2lf|\n",
                goods.num, goods.name, goods.year, goods.month, goods.day,
                goods.duration, goods.type, goods.quantity, goods.price);
            printf("------------------------------------------------------------------------\n");

            printf("请选择是否需要增加该商品的数量（y/n）:");
            scanf(" %c", &ch);
            if (ch == 'y' || ch == 'Y')
            {
                printf("请输入进货数量：");
                scanf("%d", &inputnum);

                fseek(pf, (long)(ftell(pf) - sizeof(Goods)), SEEK_SET);
                goods.quantity += inputnum;

                if (fwrite(&goods, sizeof(Goods), 1, pf) == 1)
                {
                    printf("进货成功！\n");
                    found = 1;
                }
                else
                {
                    printf("进货失败！\n");
                    AddDetail("进货操作失败");
                }
            }
            else
            {
                printf("已放弃进货操作\n");
                AddDetail("已放弃进货操作");
            }
        }
        else
        {
            printf("无效的序号\n");
        }
    }
    else
    {
        printf("没有找到匹配项\n");
        AddDetail("未能找到匹配项");
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
        printf("打开文件失败\n");
        AddDetail("删除商品，文件打开失败");
        exit(1);
    }

    char fixstr[20];
    printf("请输入需要删除的商品编号或名称:");
    scanf("%s", fixstr);

    fseek(pf, 0, SEEK_SET);

    int found = 0;
    int num_matches = 0;
    int match_indices[1024];
    while (fread(&goods, sizeof(goods), 1, pf) == 1)
    {
        if (goods.index == 1 && (strstr(goods.name, fixstr) != NULL || strstr(goods.num, fixstr) != NULL))
        {
            match_indices[num_matches] = ftell(pf) - sizeof(goods); // 记录匹配项的文件位置索引
            num_matches++;
            found = 1; // 找到了匹配项，标记为真
        }
    }

    if (found)
    {
        printf("找到以下%d匹配项：\n", num_matches);
        printf("| 序号 | 编号     | 商品名称      | 生产日期  | 保质期   | 商品类型 | 商品数量 | 商品价格   |\n");
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
        printf("请输入要删除的商品序号 (1-%d)(-1取消操作):", num_matches);
        scanf("%d", &delete_index);
        if (delete_index == -1)
        {
            printf("取消成功\n");
            return;
        }
        if (delete_index > 0 && delete_index <= num_matches)
        {
            fseek(pf, match_indices[delete_index - 1], SEEK_SET);
            goods.index = 0;
            if (fwrite(&goods, sizeof(Goods), 1, pf) == 1)
            {
                printf("删除成功！\n");
            }
            else
            {
                printf("删除失败！\n");
                AddDetail_Goods("删除失败", goods);
            }
        }
        else
        {
            printf("无效的序号\n");
        }
    }
    else
    {
        printf("未找到任何匹配项\n");
    }

    fclose(pf);
    AddDetail_Goods("删除操作完成", goods);
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
        printf("打开文件失败\n");
        AddDetail("卖出货物，文件打开失败");
        exit(1);
    }

    printf("请输入卖出货物编号或名称:");
    scanf("%s", input);

    fseek(pf, 0, SEEK_SET);
    int match_count = 0;
    long match_indices[1024];
    found = 0;
    while (fread(&goods, sizeof(goods), 1, pf) == 1)
    {
        if (goods.index == 1 && (strstr(goods.name, input) != NULL || strstr(goods.num, input) != NULL))
        {
            match_indices[num_matches] = ftell(pf) - sizeof(goods); // 记录匹配项的文件位置索引
            num_matches++;
            found = 1; // 找到了匹配项，标记为真
        }
    }
    if (found)
    {
        printf("找到以下 %d 个匹配项，请选择要卖出的商品编号：\n", match_count);
        printf("| 序号 | 编号     | 商品名称      | 生产日期  | 保质期   | 商品类型 | 商品数量 | 商品价格   |\n");
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
        printf("请选择要卖出的商品编号（输入数字1-%d）(-1取消操作)：", num_matches);
        scanf("%d", &choice);
        if (choice == -1)
        {
            printf("取消成功\n");
            return;
        }
        if (choice < 1 || choice > num_matches)
        {
            printf("输入无效！\n");
            AddDetail("卖出商品信息。输入无效");
            return;
        }

        fseek(pf, match_indices[choice - 1], SEEK_SET);
        fread(&goods, sizeof(Goods), 1, pf);
    }
    else
    { //-----------------------------------------
        printf("未找到商品信息\n");
        AddDetail("未找到商品信息");
        return;
    }

    printf("| 序号 | 编号     | 商品名称      | 生产日期  | 保质期   | 商品类型 | 商品数量 | 商品价格   |\n");

    printf("|%-6d|%-10s|%-15s|%4d/%02d/%02d|%10s|%11s|%11d|%13.2lf|\n",
        1, goods.num, goods.name, goods.year, goods.month, goods.day,
        goods.duration, goods.type, goods.quantity, goods.price);

    printf("找到以上商品，请输入卖出数量: ");
    getchar();
    scanf("%d", &soldnum);

    while (soldnum <= 0 || goods.quantity < soldnum)
    {
        if (soldnum <= 0)
        {
            printf("卖出数量应是正数！\n");
            AddDetail("卖出商品错误。卖货数应该为正数");
        }
        else if (goods.quantity < soldnum)
        {
            printf("卖出数量不足,仅剩%d件！\n", goods.quantity);
            AddDetail("库存不足，卖出失败");
        }
        scanf("%d", &soldnum);
    }

    if (goods.quantity >= soldnum)
    {
        goods.quantity -= soldnum;
        printf("卖出成功！\n");

        if (goods.quantity >= 10)
        {
            printf("%s库存剩余%d件。\n", goods.name, goods.quantity);
        }
        else if (goods.quantity > 0 && goods.quantity < 10)
        {
            printf("%s库存紧张，请及时补货！\n", goods.name);
        }
        else if (goods.quantity == 0)
        {
            printf("%s已全部卖出，货物状态归零，请重新进货！\n", goods.name);
            goods.index = 0;
        }

        fseek(pf, (long)(ftell(pf) - sizeof(Goods)), SEEK_SET);

        if (fwrite(&goods, sizeof(Goods), 1, pf) == 1)
        {
            found = 1;
            AddDetail_Goods("货物卖出成功", goods);
        }
        else
        {
            printf("卖出失败！\n");
            AddDetail_Goods("卖出失败", goods);
        }
    }
    else
    {
        printf("库存仅剩%d件，无法卖出！\n", goods.quantity);
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
        printf("打开录入文件失败！\n");
        AddDetail("货物更新失败，录入文件打开失败");
        exit(1);
    }

    FILE* fp_goods = fopen(goods_file, "rb+");
    if (fp_goods == NULL)
    {
        printf("打开存货文件失败！\n");
        AddDetail("货物更新失败，存货文件打开失败");
        exit(1);
    }

    Goods new_goods;
    while (fread(&new_goods, sizeof(Goods), 1, fp_input))
    {
        // 检查该商品是否已经存在于存货文件中
        fseek(fp_goods, 0, SEEK_SET);
        int exist = 0;
        Goods goods;

        while (fread(&goods, sizeof(Goods), 1, fp_goods) == 1)
        {
            if (strcmp(new_goods.num, goods.num) == 0)
            {
                exist = 1;
                // 更新存货文件中该商品的数量
                goods.quantity += new_goods.quantity;
                goods.year = new_goods.year; // 更新进货日期
                goods.month = new_goods.month;
                goods.day = new_goods.day;
                // 将更新后的商品写回存货文件中
                fseek(fp_goods, -sizeof(Goods), SEEK_CUR);
                if (fwrite(&goods, sizeof(Goods), 1, fp_goods) != 1)
                {
                    index = 0;
                    printf("写入存货文件失败！\n");
                    AddDetail("货物更新失败，存货文件写入失败");
                    break;
                }
                break;
            }
        }

        // 如果商品不存在，则将其添加到存货文件中
        if (!exist)
        {
            new_goods.index = 1;
            if (fwrite(&new_goods, sizeof(Goods), 1, fp_goods) != 1)
            {
                index = 0;
                printf("写入存货文件失败！\n");
                AddDetail("货物更新失败，存货文件写入失败");
            }
        }
    }
    fclose(fp_input);
    fclose(fp_goods);
    if (index == 1)
    {
        printf("货物更新完成\n");
    }
    AddDetail("货物更新成功");
}
// 将商品信息备份到文件中
void BackupGoods(char* filename, char* output_file)
{
    FILE* fp_input = fopen(filename, "rb");
    if (fp_input == NULL)
    {
        printf("打开录入文件失败！\n");
        AddDetail("货物更新失败，录入文件打开失败");
        exit(1);
    }

    FILE* fp_goods = fopen(output_file, "rb+");
    if (fp_goods == NULL)
    {
        printf("打开存备份文件失败！\n");
        AddDetail("货物备份失败，备份文件打开失败");
        exit(1);
    }

    Goods new_goods;
    while (fread(&new_goods, sizeof(Goods), 1, fp_input))
    {
        // 检查该商品是否已经存在于存货文件中
        fseek(fp_goods, 0, SEEK_SET);
        int exist = 0;
        Goods goods;

        while (fread(&goods, sizeof(Goods), 1, fp_goods) == 1)
        {
            if (strcmp(new_goods.num, goods.num) == 0)
            {
                exist = 1;
                // 将更新后的商品写回存货文件中
                fseek(fp_goods, -sizeof(Goods), SEEK_CUR);
                if (fwrite(&goods, sizeof(Goods), 1, fp_goods) != 1)
                {
                    printf("写入存货文件失败！\n");
                    AddDetail("货物更新失败，存货文件写入失败");
                }
                break;
            }
        }

        // 如果商品不存在，则将其添加到存货文件中
        if (!exist)
        {
            new_goods.index = 1;
            if (fwrite(&new_goods, sizeof(Goods), 1, fp_goods) != 1)
            {
                printf("写入存货文件失败！\n");
                AddDetail("货物更新失败，存货文件写入失败");
            }
        }
    }
    fclose(fp_input);
    fclose(fp_goods);
    AddDetail("货物更新成功");
}
