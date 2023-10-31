#include <iostream>
using namespace std;

typedef struct node // 双向设计。便于访问
{
    int data;
    node *next;
    node *pre;
    int minus = 0; // 用于表示正负 0为正 ，1为负
} Node;

Node *createNode(int data) // 创建单个接点，每个节点存储一个数位
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->pre = NULL;
    return node;
}

Node *insertNode(Node *head, int data) // 尾插法
{
    if (head == NULL)
        head = createNode(data);
    else
    {
        Node *p = head;
        while (p->next != NULL)
            p = p->next;
        p->next = createNode(data);
        p->next->pre = p;
    }
    return head;
}

Node *reverse(Node *head) // 链表逆转用于链表加法之后将结果反过来，不然整个就被颠倒了
{
    Node *p = head;
    Node *q = NULL;
    while (p != NULL)
    {
        q = p->pre;
        p->pre = p->next;
        p->next = q;
        p = p->pre;
    }
    if (q != NULL)
        head = q->pre;
    return head;
}

Node *Str2Node(char *string) // 将输入的字符串存储在可计算的链表形式之中，方便操作
{
    Node *head = NULL;
    int i = 0;
    while (string[i] != '\0')
    {
        if (string[i] == '-')
        {
            head->minus = 1;
            i++;
        }
        head = insertNode(head, string[i] - '0');
        i++;
    }
    return head;
}

Node *end(Node *head) // 返回链表的最后一个节点，用于减法比较。因为我们是正着存的，所以最后一个节点就是最高位
{
    Node *p = head;
    while (p->next != NULL)
        p = p->next;
    return p;
}

void print(Node *head) // 显示表达
{
    Node *p = head; // 正序输出

    if (head->minus == 1)
        cout << '-';

    while (p != NULL && p->data == 0 && p->next != NULL) // 前导0不输出,此处直接跳过。
    {
        p = p->next;
    }
    while (p != NULL)
    {
        cout << p->data;
        p = p->next;
    }
    cout << endl;
}

Node *add(Node *num1, Node *num2) // 每一位够了就进位，不够直接加入链表 （尾插法所以会颠倒结果，需要和reverse一起使用）
{
    Node *p1 = end(num1);
    Node *p2 = end(num2);
    Node *head = NULL;
    int carry = 0;                   // 进位
    while (p1 != NULL && p2 != NULL) // 两个链表一起从末尾往前走，谁空了就不用读了
    {
        int sum = p1->data + p2->data + carry;
        carry = sum / 10;
        head = insertNode(head, sum % 10);
        p1 = p1->pre;
        p2 = p2->pre;
    }
    while (p1 != NULL)
    {
        int sum = p1->data + carry;
        carry = sum / 10;
        head = insertNode(head, sum % 10);
        p1 = p1->pre;
    }
    while (p2 != NULL)
    {
        int sum = p2->data + carry;
        carry = sum / 10;
        head = insertNode(head, sum % 10);
        p2 = p2->pre;
    }
    if (carry != 0)
        head = insertNode(head, carry);
    return head;
}

Node *sub(Node *num1, Node *num2) // 道理同加法，只不过需要考虑一下符号问题
{
    Node *p1 = end(num1);
    Node *p2 = end(num2);
    Node *head = NULL;
    int borrow = 0;
    while (p1 != NULL && p2 != NULL)
    {
        int sum = p1->data - p2->data + borrow;
        borrow = 0; // 每一次都要重置borrow 否则会出现输出莫名其妙前面多了个 -1 的情况
        if (sum < 0 && p1->pre != NULL)
        {
            sum += 10;
            borrow = -1;
        }
        else if (sum < 0 && p1->pre == NULL)
        {
            sum = -sum;
            borrow = 0;
        }
        head = insertNode(head, sum % 10);
        p1 = p1->pre;
        p2 = p2->pre;
    }
    while (p1 != NULL)
    {
        int sum = p1->data + borrow;
        borrow = 0;
        if (sum < 0)
        {
            sum += 10;
            borrow = -1;
        }
        head = insertNode(head, sum % 10);
        p1 = p1->pre;
    }
    while (p2 != NULL)
    {
        int sum = p2->data + borrow;
        borrow = 0;
        if (sum < 0 && p2->pre != NULL)
        {
            sum += 10;
            borrow = -1;
        }
        else if (sum < 0 && p2->pre == NULL)
        {
            sum = -sum;
            borrow = 0;
        }
        head = insertNode(head, sum % 10);
        p2 = p2->pre;
    }
    if (borrow != 0)
    {
        head->minus = 1; // 状态更新为负数
        borrow = 0;
    }

    return head;
}

Node *changeNodeData(Node *head, int index, int data)
{
    Node *p = head; // 结果是正序存放的，所以从头遍历就行了
    for (int i = 1; i < index; i++)
        p = p->next;
    p->data = data;
    return head;
}

void deleteList(Node *head) // 释放链表
{
    Node *p = head;
    while (p != NULL)
    {
        Node *temp = p;
        p = p->next;
        free(temp);
    }
}

Node *clearList(Node *head) // 清空链表，但感觉没啥用
{
    deleteList(head);
    Node *p = NULL;
    return p;
}

Node *mutil(Node *num1, Node *num2)
{
    // 转换为num2 个 num1 相加
    Node *temp = createNode(0);
    int carry = 0;
    long long flag = 1;
    while (num2 != NULL)
    {
        for (long long i = 0; i < num2->data * flag; i++)
        {
            temp = add(temp, num1);
        }
        num2 = num2->next;
        flag *= 10;
    }
    return temp;
}

int main()
{
    Node *num1 = NULL;
    Node *num2 = NULL;
    Node *sum = NULL;

    cout << "欢迎使用计算器系统" << endl;
    cout << "本系统支持连续相加减操作，Q退出系统，R重置系统，C改变数字" << endl;
    char *string;

    while (1)
    {
        cin >> string; // 首先读入第一个数字
        if (string[0] == 'q' || string[0] == 'Q')
        {
            cout << "计算器系统成功退出" << endl;
            return 0;
        }
        else if (string[0] == 'r' || string[0] == 'R')
            cout << "计算器系统重置成功,请输入第一个数字:";
        else if (string[0] == 'c' || string[0] == 'C')
            cout << "系统内无需修改数字，请重新输入第一个数字:";
        else if (string[0] == '-') // 判断是不是负数，如果是，则从第二个位置开始记录数字
        {
            num1 = Str2Node(string + 1);
            num1->minus = 1;
            break;
        }
        else
        {
            num1 = Str2Node(string);
            break;
        }
    }

    while (1) // 主运算程序
    {
        cin >> string;
        if (string[0] == '+')
        {
            cin >> string;
            num2 = Str2Node(string);
            if (num1->minus == 0 && num2->minus == 0)
            {
                num1 = reverse(add(num1, num2)); // 我们是正着存数字，但是add后的结果是反着的，所以要反过来
                clearList(num2);                 // 重置num2方便我们连续相加 , 结果就在num1里，所以可以一直刷新num2实现多个操作符，数字一起读入
            }
            else if (num1->minus == 1 && num2->minus == 1) // 此处是判断两个数字的正负号，来判断真正执行的操作是加还是减。 如果是减法都转换为大减小，用minus存储负号信息。
            {
                num1 = reverse(add(num1, num2));
                num1->minus = 1;
                num2->minus = 0;
                clearList(num2);
            }
            else if (num1->minus == 0 && num2->minus == 1)
            {
                int len1 = 0;
                int len2 = 0;
                Node *p1 = num1;
                Node *p2 = num2;
                while (p1 != NULL)
                {
                    len1++;
                    p1 = p1->next;
                }
                while (p2 != NULL)
                {
                    len2++;
                    p2 = p2->next;
                }

                if (len1 > len2)
                {
                    num1 = reverse(sub(num1, num2));
                    num1->minus = 0;
                    num2->minus = 0;
                    clearList(num2);
                }
                else if (len1 < len2)
                {
                    num1 = reverse(sub(num2, num1));
                    num1->minus = 1;
                    num2->minus = 0;
                    clearList(num2);
                }
                else
                {
                    Node *p1 = num1;
                    Node *p2 = num2;
                    while (p1 != NULL)
                    {
                        if (p1->data > p2->data)
                        {
                            num1 = reverse(sub(num1, num2));
                            num1->minus = 0;
                            num2->minus = 0;
                            clearList(num2);
                            break;
                        }
                        else if (p1->data < p2->data)
                        {
                            num1 = reverse(sub(num2, num1));
                            num1->minus = 1;
                            num2->minus = 0;
                            clearList(num2);
                            break;
                        }
                        p1 = p1->next;
                        p2 = p2->next;
                        if (p1 == NULL && p2 == NULL) // 这就是遍历到末尾了，那就是两个数字相同
                        {
                            clearList(num2);
                            clearList(num1);
                            num1 = createNode(0);
                            num1->minus = 0;
                            num2->minus = 0;
                            break;
                        }
                    }
                }
            }
            else if (num1->minus == 1 && num2->minus == 0)
            {
                int len1 = 0;
                int len2 = 0;
                Node *p1 = num1;
                Node *p2 = num2;
                while (p1 != NULL)
                {
                    len1++;
                    p1 = p1->next;
                }
                while (p2 != NULL)
                {
                    len2++;
                    p2 = p2->next;
                }
                if (len1 > len2) // 减法就是先比较长度，长的大，如果一样长，就比较第一个数字大小，如果一样就后推。
                {
                    num1 = reverse(sub(num1, num2));
                    num1->minus = 1;
                    num2->minus = 0;
                    clearList(num2);
                }
                else if (len1 < len2)
                {
                    num1 = reverse(sub(num2, num1));
                    num2->minus = 0;
                    clearList(num2);
                }
                else
                {
                    Node *p1 = num1;
                    Node *p2 = num2;
                    while (p1 != NULL)
                    {
                        if (p1->data > p2->data)
                        {
                            num1 = reverse(sub(num1, num2));
                            num1->minus = 1;
                            num2->minus = 0;
                            clearList(num2);
                            break;
                        }
                        else if (p1->data < p2->data)
                        {
                            num1 = reverse(sub(num2, num1));
                            num1->minus = 0;
                            num2->minus = 0;
                            clearList(num2);
                            break;
                        }
                        p1 = p1->next;
                        p2 = p2->next;
                        if (p1 == NULL && p2 == NULL) // 这就是遍历到末尾了，那就是两个数字相同
                        {
                            clearList(num2);
                            clearList(num1);
                            num1 = createNode(0);
                            num1->minus = 0;
                            num2->minus = 0;
                            break;
                        }
                    }
                }
            }
        }
        else if (string[0] == '-' && string[1] >= '0' && string[0] <= '9') // 此处是在分别 ‘-’是运算符，还是负号
        {
            num2 = Str2Node(string + 1);
            num2->minus = 1;
        }
        else if (string[0] == '-') // 此处是在分别 ‘-’是运算符，还是负号
        {
            cin >> string;
            num2 = Str2Node(string);
            if (num1->minus == 0 && num2->minus == 1)
            {
                num1 = reverse(add(num1, num2));
                num2->minus = 0;
                num1->minus = 1;
                clearList(num2);
            }
            else if (num1->minus == 1 && num2->minus == 0)
            {
                num1 = reverse(add(num2, num1));
                num1->minus = 1;
                num2->minus = 0;
                clearList(num2);
            }
            else if (num1->minus == 1 && num2->minus == 1)
            {
                int len1 = 0;
                int len2 = 0;
                Node *p1 = num1;
                Node *p2 = num2;
                while (p1 != NULL)
                {
                    len1++;
                    p1 = p1->next;
                }
                while (p2 != NULL)
                {
                    len2++;
                    p2 = p2->next;
                }
                if (len1 > len2)
                {
                    num1 = reverse(sub(num1, num2));
                    num1->minus = 1;
                    num2->minus = 0;
                    clearList(num2);
                }
                else if (len1 < len2)
                {
                    num1 = reverse(sub(num2, num1));
                    num2->minus = 0;
                    clearList(num2);
                }
                else
                {
                    Node *p1 = num1;
                    Node *p2 = num2;
                    while (p1 != NULL)
                    {
                        if (p1->data > p2->data)
                        {
                            num1 = reverse(sub(num1, num2));
                            num1->minus = 1;
                            num2->minus = 0;
                            clearList(num2);
                            break;
                        }
                        else if (p1->data < p2->data)
                        {
                            num1 = reverse(sub(num2, num1));
                            num1->minus = 0;
                            num2->minus = 0;
                            clearList(num2);
                            break;
                        }
                        p1 = p1->next;
                        p2 = p2->next;
                        if (p1 == NULL && p2 == NULL) // 这就是遍历到末尾了，那就是两个数字相同
                        {
                            clearList(num2);
                            clearList(num1);
                            num1 = createNode(0);
                            num1->minus = 0;
                            num2->minus = 0;
                            break;
                        }
                    }
                }
            }
            else if (num1->minus == 0 && num2->minus == 0)
            {
                int len1 = 0;
                int len2 = 0;
                Node *p1 = num1;
                Node *p2 = num2;
                while (p1 != NULL)
                {
                    len1++;
                    p1 = p1->next;
                }
                while (p2 != NULL)
                {
                    len2++;
                    p2 = p2->next;
                }

                if (len1 > len2)
                {
                    num1 = reverse(sub(num1, num2));
                    num1->minus = 0;
                    num2->minus = 0;
                    clearList(num2);
                }
                else if (len1 < len2)
                {
                    num1 = reverse(sub(num2, num1));
                    num1->minus = 1;
                    num2->minus = 0;
                    clearList(num2);
                }
                else
                {
                    Node *p1 = num1;
                    Node *p2 = num2;
                    while (p1 != NULL)
                    {
                        if (p1->data > p2->data)
                        {
                            num1 = reverse(sub(num1, num2));
                            num1->minus = 0;
                            num2->minus = 0;
                            clearList(num2);
                            break;
                        }
                        else if (p1->data < p2->data)
                        {
                            num1 = reverse(sub(num2, num1));
                            num1->minus = 1;
                            num2->minus = 0;
                            clearList(num2);
                            break;
                        }
                        p1 = p1->next;
                        p2 = p2->next;
                        if (p1 == NULL && p2 == NULL) // 这就是遍历到末尾了，那就是两个数字相同
                        {
                            clearList(num2);
                            clearList(num1);
                            num1 = createNode(0);
                            num1->minus = 0;
                            num2->minus = 0;
                            break;
                        }
                    }
                }
            }
        }

        else if (string[0] == '=')
        {
            print(num1);
        }
        else if (string[0] == 'q' || string[0] == 'Q')
        {
            if (num1 != NULL)

                deleteList(num1);
            // if (num2 != NULL)        //此处为bug 如果不注释那么num2区域会被释放两遍导致错误
            //     deleteList(num2);
            cout << "计算器系统成功退出" << endl;
            break;
        }
        else if (string[0] == 'r' || string[0] == 'R')
        {
            if (num1 != NULL)
                num1 = clearList(num1);
            // if (num2 != NULL)
            //     num2 = clearList(num2);
            cout << "计算器系统重置成功" << endl;
            while (1)
            {
                cin >> string;

                if (string[0] == '-')
                {
                    num1 = Str2Node(string + 1);
                    num1->minus = 1;
                    break;
                }
                else if (string[0] == 'q' || string[0] == 'Q')
                {
                    cout << "计算器系统成功退出" << endl;
                    return 0;
                }
                else if (string[0] == 'r' || string[0] == 'R')
                    cout << "计算器系统不可重复重置,请输入第一个数字:";
                else if (string[0] == 'c' || string[0] == 'C')
                    cout << "系统内无需修改数字，请重新输入第一个数字:";
                else if (string[0] >= '0' && string[0] <= '9')
                {
                    num1 = Str2Node(string);
                    break;
                }
                else
                {
                    cout << "错误输入" << endl;
                }
            }
        }
        else if (string[0] == 'c' || string[0] == 'C')
        {
            int len = 0;
            Node *p = num1;
            while (p != NULL)
            {
                len++;
                p = p->next;
            }
            int index;
            int data;
            cout << "目前数据为:";
            print(num1);
            printf("请输入你要求改的位置(1-%d)和数字(个位数):", len);
            while (1)
            {
                cin >> index >> data;
                if (index > len || index < 0)
                {
                    cout << "index越界输入" << endl;
                    printf("请输入你要求改的位置(1-%d)和数字(个位数):", len);
                    continue;
                }
                else if (data >= 10 || data < 0)
                {
                    cout << "data错误输入" << endl;
                    printf("请输入你要求改的位置(1-%d)和数字(个位数):", len);
                    continue;
                }

                else
                {
                    num1 = changeNodeData(num1, index, data);
                    cout << "修改成功" << endl;
                    cout << "修改后的结果为:";
                    print(num1);
                    break;
                }
            }
        }
        else if (string[0] == '*')
        {
            cin >> string;
            num2 = Str2Node(string);
            if (num1->minus == num2->minus)
            {
                num1 = reverse(mutil(num1, num2));
                num1->minus = 0;
                num2->minus = 0;
                clearList(num2);
            }
            else if (num1->minus != num2->minus)
            {
                num1 = reverse(mutil(num1, num2));
                num1->minus = 1;
                num2->minus = 0;
                clearList(num2);
            }
        }
        else
        {
            cout << "错误输入" << endl;
        }
    }
    return 0;
}