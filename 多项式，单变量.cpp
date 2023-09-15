#include <iostream>

using namespace std;
// 人工智能2201（未来实验班） 20226460 魏凡峻铎  数据结构课-李发明老师  第一次作业 
//本设计的程序是针对 系数和指数都是整数的以x为变量的一员多项式的加减乘法。
//主要功能有创造多项式，检查整理多项式，加减乘法，以及显示表达。
//还完善了一些try-catch检查错误输入，用symbol去判断符号，enum使代码更可读。
//还有一些功能没有实现，比如除法，还有一些问题没有解决，比如输入字符会无限循环

typedef struct polynomial
{
    char symbol; // 符号 (同于判断正负)
    float coef; // 系数
    float exp;  // 指数  此处用float是为了方便后期异常处理区分int和float
    struct polynomial *next;
} poly;

enum type_of_error
{
    right_int,   // 正确
    error_float, // 小数错误
    error_minus, // 负数错误
};

// 检验系数指数是否合格
int num_valid(float num)
{
    if (num != (int)num)
    {
        return error_float;
    }
    // else if (num <= 0)
    // {
    //     return error_minus;
    // }
    else
    {
        return right_int;
    }
}
// 打印多项式（需要判断系数，指数是不是正数负数，负数需要输出负号）
void show_poly(poly *p)
{
    if (p == NULL)
    {
        cout << "多项式为空" << endl;
        return;
    }
    else
    {
        cout << "多项式为：" << endl;
        for (p = p->next; p != NULL; p = p->next)
        {
            if(p->coef == 1)
            {
                if (p->exp == 0)
                    cout << p->coef;
                else if (p->exp == 1)
                    cout << "x ";
                else
                    cout << "x^" << p->exp << ' ';
            }
            else if(p->coef == -1)
            {
                if (p->exp == 0)
                    cout << p->coef;
                else if (p->exp == 1)
                    cout << "-x ";
                else
                    cout << "-x^" << p->exp << ' ';
            }
            if (p->coef > 0 && p->coef != 1)
            {
                if (p->exp == 0)
                    cout << p->coef;
                else if (p->exp == 1)
                    cout << p->coef << "x ";
                else
                    cout << p->coef << "x^" << p->exp << ' ';
            }
            else if (p->coef < 0)
            {
                if (p->exp == 0)
                    cout << p->coef;
                else if (p->exp == 1)
                    cout << p->coef << "x ";
                else
                    cout << p->coef << "x^" << p->exp << ' ';
            }
            if (p->next != NULL)
            {
                if (p->next->coef > 0) //如果下一项是正数，则补充加号
                    cout << " +";

            }
        }
        cout << endl;
    }
}
// 多项式内部按次数降序排列
poly *sort_poly(poly *p)
{
    poly *head = p;
    poly *p1 = p;
    if (head == NULL)
    {
        cout << "多项式为空" << endl;
        return NULL;
    }
    if (p->next != NULL && p->next->next != NULL)
    {
        //空
    }
    else
    {
        cout << "多项式只有一项无需排序" << endl;
        return head;
    }
    for (p = head->next; p->next != NULL; p = p->next)  //排序
    {
        poly *minNode = p;
        for (p1 = p->next; p1 != NULL; p1 = p1->next)
        {
            if (p1->exp > minNode->exp)
            {
                minNode = p1;
            }
        }
        if (minNode != p)
        {
            int tmp_exp = p->exp;
            int tmp_coef = p->coef;
            p->exp = minNode->exp;
            p->coef = minNode->coef;
            minNode->exp = tmp_exp;
            minNode->coef = tmp_coef;
        }
    }

    return head;
}

// 整理多项式(合并同类项，排序)
poly *arrange_poly(poly *p)
{
    poly *head = p;
    poly *p1 = p;
    if (head == NULL)
    {
        cout << "多项式为空" << endl;
        return NULL;
    }
    else if (p->next != NULL)
        p1 = p->next;
    else
    {
        cout << "多项式只有一项无需整理" << endl;
        return head;
    }
    for (poly *p2 = head->next; p2 != NULL; p2 = p2->next)
    {
        for (poly *p3 = p2->next; p3 != NULL; p3 = p3->next)
        {
            if (p2->exp == p3->exp)
            {
                p2->coef += p3->coef;
                p2->next = p3->next;
                free(p3);
            }
        }
    }
    sort_poly(head);
    return head;
}

poly *create_poly(int num /*项数*/)
{
    printf("本多项式一共%d项\n", num);
    poly *head = (poly *)malloc(sizeof(poly));
    poly *p = head;
    for (int i = 0; i < num; i++)
    {
        poly *temp = (poly *)malloc(sizeof(poly));
        cout << "请输入第" << i + 1 << "项的系数" << endl;
        // 检查输整数数字
        try
        {
            cin >> temp->symbol;
            if (temp->symbol == '-')    //此处判断正负
            {
                cin >> temp->coef;
                temp->coef = -temp->coef;
            }
            else if(temp->symbol == int(temp->symbol)) //因为char类型在电脑中存储的是ASC码，所以可以通过判断是否为整数来判断是否输入了字符。
                temp->coef = (int)temp->symbol - '0'; //减去0字符就是对应的数字 
            else
                throw runtime_error("系数输入错误");  
            if (num_valid(temp->coef) == right_int) //目前没有解决输入字符的问题。输入字符会无限循环。
            {
                cout << "请输入第" << i + 1 << "项的指数" << endl;
                cin >> temp->symbol;
                if (temp->symbol == '-')
                {
                    cin >> temp->exp;
                    temp->exp = -temp->exp;
                }
                else if(temp->symbol == int(temp->symbol))
                    temp->exp = (int)temp->symbol - '0';
                else
                    throw runtime_error("指数输入错误");
                if (num_valid(temp->exp) == error_float)
                    throw runtime_error("指数输入了浮点数");
               
            }
            else if (num_valid(temp->coef) == error_float)
                throw runtime_error("系数输入了浮点数");
        }
        catch (const runtime_error &err)
        {
            cout << "发生错误：" << err.what() << endl;
            free(temp);
            i--; // 回到上一项
            continue;
        }
        p->next = temp; // 从第二项开始存数据 head不存有效数据
        p = p->next;
    }
    p->next = NULL;
    arrange_poly(head);
    // sort_poly(head);
    return head;
}

//通过新节点，判断指数来进行加法运算。
poly *add_poly(poly *p1, poly *p2)
{
    poly *head = (poly *)malloc(sizeof(poly)); 
    poly *p = head;
    poly *p3 = p1->next;
    poly *p4 = p2->next;
    while (p3 != NULL && p4 != NULL)
    {
        poly *temp = (poly *)malloc(sizeof(poly));
        if (p3->exp > p4->exp)
        {
            temp->coef = p3->coef;
            temp->exp = p3->exp;
            poly * free_p = p3; //释放已经使用的节点
            p3 = p3->next;
            free(free_p);
        }
        else if (p3->exp < p4->exp)
        {
            temp->coef = p4->coef;
            temp->exp = p4->exp;
            poly * free_p = p4;
            free(free_p);
            p4 = p4->next;
        }
        else
        {
            temp->coef = p3->coef + p4->coef;
            temp->exp = p3->exp;
            poly * free_p1 = p3;
            poly * free_p2 = p4;
            p3 = p3->next;
            p4 = p4->next;
            free(free_p1);
            free(free_p2);
        }
        p->next = temp;
        p = p->next;
    }
    if (p3 != NULL)
    {
        p->next = p3;
    }
    else if (p4 != NULL)
    {
        p->next = p4;
    }
    else
    {
        p->next = NULL;
    }
    arrange_poly(head);
    return head;
}

//通减法运算 (p1-p2)
poly *sub_poly(poly *p1, poly *p2)
{
    poly *head = (poly *)malloc(sizeof(poly));
    poly *p = head;
    poly *p3 = p1->next;
    poly *p4 = p2->next;
    while (p3 != NULL && p4 != NULL)
    {
        poly *temp = (poly *)malloc(sizeof(poly));
        if (p3->exp > p4->exp)
        {
            temp->coef = p3->coef;
            temp->exp = p3->exp;
            poly * free_p = p3;
            p3 = p3->next;
            free(free_p);
        }
        else if (p3->exp < p4->exp)
        {
            temp->coef = -p4->coef;
            temp->exp = p4->exp;
            poly * free_p = p4;
            p4 = p4->next;
            free(free_p);
        }
        else
        {
            temp->coef = p3->coef - p4->coef;
            temp->exp = p3->exp;
            poly * free_p1 = p3;
            poly * free_p2 = p4;
            p3 = p3->next;
            p4 = p4->next;
            free(free_p1);
            free(free_p2);
        }
        p->next = temp;
        p = p->next;
    }
    if (p3 != NULL)
    {
        p->next = p3;
    }
    else if (p4 != NULL)
    {
        p->next = p4;
    }
    else
    {
        p->next = NULL;
    }
    arrange_poly(head);
    return head;
}

//乘法运算
poly *mul_poly(poly *p1, poly *p2)
{
    poly *head = (poly *)malloc(sizeof(poly));
    poly *p = head;
    poly *p3 = p1->next;
    poly *p4 = p2->next;
    while (p3 != NULL) //循环遍历
    {
        while (p4 != NULL)
        {
            poly *temp = (poly *)malloc(sizeof(poly));
            temp->coef = p3->coef * p4->coef;
            temp->exp = p3->exp + p4->exp;
            p->next = temp;
            p = p->next;
            p4 = p4->next;
        }
        p3 = p3->next;
        p4 = p2->next;
    }
    p->next = NULL;
    arrange_poly(head);
    return head;
}

//除法真不会。。。。。。

//多变量多项式的结构体定义
/*
    思路是将原来的 symbol exp coef 换成数组，这样就可以存储多个变量了。
    但是这样的话，就不能用上面的函数了，需要重新写一遍s。

typedef struct polynomial
{
    char symbol[10]; 
    float coef[10];
    float exp[10];    
    struct polynomial *next;
} poly;
   
*/



int main()
{
    // 测试数据： 1 2 4 5 2 3 6 7 1 2 3 4 5 6
    poly *p = create_poly(3);
    poly *p1 = create_poly(4);
    poly *ret = add_poly(p, p1);
    show_poly(ret);

    poly *p2 = create_poly(3);
    poly *p3 = create_poly(4);
    poly *ret1 = sub_poly(p2, p3);
    show_poly(ret1);

    poly *p4 = create_poly(3);
    poly *p5 = create_poly(4);
    poly *ret2 = mul_poly(p4, p5);
    show_poly(ret2);
    return 0;
}