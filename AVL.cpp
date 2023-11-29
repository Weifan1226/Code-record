// AVL树

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef struct AVLNode
{
    int data;
    int balance; // 平衡因子 = 左子树高度 - 右子树高度
    struct AVLNode *leftchild;
    struct AVLNode *rightchild;
    struct AVLNode *parent;
} AVLNode, *AVLTree;

// 可视化部分
typedef struct _node_print_info
{
    AVLTree address;
    int str_len;
    int depth;
    int left_margin;
} _Info;

// 可视化函数
void avl_visual_print(const AVLTree root, const char *elem_fmt, FILE *fp)
{
    if (root == NULL)
        return;

    const int _MAX_STR_LEN = 128;
    const int _MAX_NODE_NUM = 1024;
    const char horiz_conj_char = '_';
    const char vert_conj_char = '|';
    const char left_bracket_char = '(';
    const char right_bracket_char = ')';

    AVLTree tree_deque[_MAX_NODE_NUM];
    int depth_queue[_MAX_NODE_NUM];
    _Info *info_p_arr[_MAX_NODE_NUM];
    int node_count = 0;
    int front = -1, rear = -1;
    AVLTree p;
    _Info *info_p;
    char temp_str[_MAX_STR_LEN];

    tree_deque[++rear] = root;
    depth_queue[rear] = 1;

    while (front < rear)
    {
        p = tree_deque[++front];
        info_p = (_Info *)calloc(1, sizeof(_Info));
        info_p->address = p;
        memset(temp_str, 0, _MAX_STR_LEN);
        snprintf(temp_str, _MAX_STR_LEN, elem_fmt, p->data);
        info_p->str_len = strlen(temp_str) + 2;
        info_p->depth = depth_queue[front];
        info_p_arr[node_count++] = info_p;

        if (p->leftchild != NULL)
        {
            tree_deque[++rear] = p->leftchild;
            depth_queue[rear] = depth_queue[front] + 1;
        }
        if (p->rightchild != NULL)
        {
            tree_deque[++rear] = p->rightchild;
            depth_queue[rear] = depth_queue[front] + 1;
        }
    }

    p = root;
    int top = -1, i;
    int horizontal_accumu_cache = 0;

    do
    {
        while (p != NULL)
        {
            tree_deque[++top] = p;
            p = p->leftchild;
        }
        p = tree_deque[top--];

        for (i = 0; i < node_count; ++i)
        {
            if (info_p_arr[i]->address == p)
            {
                info_p_arr[i]->left_margin = horizontal_accumu_cache;
                horizontal_accumu_cache += info_p_arr[i]->str_len - 1;
            }
        }

        p = p->rightchild;
    } while (!(p == NULL && top == -1));

    int horiz_left_start, horiz_right_end, cursor, j, k, cur_depth = 1, end_flag = 0;
    int vert_index_arr[_MAX_NODE_NUM];
    i = 0;

    while (i < node_count)
    {
        k = -1;
        cursor = 0;

        while (info_p_arr[i]->depth == cur_depth)
        {
            p = info_p_arr[i]->address;

            if (p->leftchild != NULL)
            {
                for (j = 0; j < node_count; ++j)
                {
                    if (info_p_arr[j]->address == p->leftchild)
                    {
                        horiz_left_start = info_p_arr[j]->left_margin + info_p_arr[j]->str_len / 2;
                        vert_index_arr[++k] = horiz_left_start;
                        break;
                    }
                }

                for (; cursor < horiz_left_start; ++cursor)
                    fprintf(fp, " ");

                for (; cursor < info_p_arr[i]->left_margin; ++cursor)
                    fprintf(fp, "%c", horiz_conj_char);
            }
            else
            {
                for (; cursor < info_p_arr[i]->left_margin; ++cursor)
                    fprintf(fp, " ");
            }

            fprintf(fp, "%c", left_bracket_char);
            fprintf(fp, elem_fmt, p->data);
            fprintf(fp, "%c", right_bracket_char);
            cursor += info_p_arr[i]->str_len;

            if (p->rightchild != NULL)
            {
                for (j = 0; j < node_count; ++j)
                {
                    if (info_p_arr[j]->address == p->rightchild)
                    {
                        horiz_right_end = info_p_arr[j]->left_margin + info_p_arr[j]->str_len / 2;
                        vert_index_arr[++k] = horiz_right_end;
                        break;
                    }
                }

                for (; cursor < horiz_right_end; ++cursor)
                    fprintf(fp, "%c", horiz_conj_char);
            }

            if (++i >= node_count)
            {
                end_flag = 1;
                break;
            }
        }

        fprintf(fp, "\n");

        if (!end_flag)
        {
            cursor = 0;

            for (j = 0; j <= k; ++j)
            {
                for (; cursor < vert_index_arr[j]; ++cursor)
                    fprintf(fp, " ");

                fprintf(fp, "%c", vert_conj_char);
                cursor++;
            }

            fprintf(fp, "\n");
        }

        cur_depth++;
    }

    for (i = 0; i < node_count; ++i)
        free(info_p_arr[i]);

    return;
}

int getHeight(AVLTree root)
{
    if (root == NULL)
        return 0;
    int left = getHeight(root->leftchild);
    int right = getHeight(root->rightchild);
    return left > right ? left + 1 : right + 1;
}

// 更新每一个节点的平衡因子
void UpdateBalance(AVLTree root)
{
    if (root == NULL)
        return;
    root->balance = getHeight(root->leftchild) - getHeight(root->rightchild);
    UpdateBalance(root->leftchild);
    UpdateBalance(root->rightchild);
}

// 创建AVL树节点
AVLNode *CreateNode(int data)
{
    AVLNode *p = new AVLNode;
    if (p == NULL)
        exit(1);
    memset(p, 0, sizeof(AVLNode));
    p->data = data;
    p->balance = 0;
    return p;
}

// 左单旋转 p右子树高于左子树时（新节点插入右子树的右侧后）
AVLTree RotateL(AVLTree &root, AVLNode *p)
{
    AVLNode *newroot = p->rightchild;
    p->rightchild = newroot->leftchild;
    if (newroot->leftchild != NULL)
    {
        newroot->leftchild->parent = p;
    }
    newroot->leftchild = p;
    newroot->parent = p->parent;
    if (p->parent == NULL)
    {
        root = newroot;
    }
    else
    {
        if (p->parent->leftchild == p)
        {
            p->parent->leftchild = newroot;
        }
        else
        {
            p->parent->rightchild = newroot;
        }
    }

    p->parent = newroot;
    return root;
}

// 右单旋转 p左子树高于右子树时 （新节点插入左子树的左侧后）
AVLTree RotateR(AVLTree &root, AVLNode *p)
{
    AVLNode *newroot = p->leftchild;
    p->leftchild = newroot->rightchild;
    if (newroot->rightchild != NULL)
    {
        newroot->rightchild->parent = p;
    }
    newroot->rightchild = p;
    newroot->parent = p->parent;
    if (p->parent == NULL)
    {
        root = newroot;
    }
    else
    {
        if (p->parent->rightchild == p)
        {
            p->parent->rightchild = newroot;
        }
        else
        {
            p->parent->leftchild = newroot;
        }
    }

    p->parent = newroot;
    return root;
}

// 左右双旋转 p右子树高于左子树时（新节点插入右子树的左侧后）
AVLTree RotateLR(AVLTree &root, AVLNode *p)
{
    RotateR(root, p->leftchild);
    return RotateL(root, p);
}

// 右左双旋转 p左子树高于右子树时（新节点插入左子树的右侧后）
AVLTree RotateRL(AVLTree &root, AVLNode *p)
{
    RotateL(root, p->rightchild);
    return RotateR(root, p);
}

// 左子树的不平衡情况，需要进行右旋转，或者右左双旋转
AVLTree LeftBalance(AVLTree &root, AVLNode *p)
{
    AVLNode *subL = p->leftchild;

    switch (subL->balance)
    {
    case 0:
        break;
    case 1:
        p->balance = 0;
        subL->balance = 0;
        root = RotateR(root, p);
        break;
    case -1:
        AVLNode *subLR = subL->rightchild;

        switch (subLR->balance)
        {
        case 0:
            p->balance = 0;
            subL->balance = 0;
            break;
        case 1:
            p->balance = -1;
            subL->balance = 0;
            break;
        case -1:
            p->balance = 0;
            subL->balance = 1;
            break;
        }

        subLR->balance = 0;
        root = RotateL(root, subL);
        root = RotateR(root, p);
        break;
    }

    return root;
}

// 右子树的不平衡情况，需要进行左旋转，或者左右双旋转
AVLTree RightBalance(AVLTree &root, AVLNode *p)
{
    AVLNode *subR = p->rightchild;

    switch (subR->balance)
    {
    case 0:
        break;
    case -1:
        p->balance = 0;
        subR->balance = 0;
        root = RotateL(root, p);
        break;
    case 1:
        AVLNode *subRL = subR->leftchild;

        switch (subRL->balance)
        {
        case 0:
            p->balance = 0;
            subR->balance = 0;
            break;
        case -1:
            p->balance = 1;
            subR->balance = 0;
            break;
        case 1:
            p->balance = 0;
            subR->balance = -1;
            break;
        }

        subRL->balance = 0;
        root = RotateR(root, subR);
        root = RotateL(root, p);
        break;
    }

    return root;
}

void Balance(AVLTree &root, AVLNode *p)
{
    if (p == NULL)
        return;

    if (p->balance == 2)
    {
        root = LeftBalance(root, p);
    }
    else if (p->balance == -2)
    {
        root = RightBalance(root, p);
    }

    Balance(root, p->parent);
}

// 插入节点 返回最新创建的叶子结点 并更新AVL
AVLTree InsertNode(AVLTree &root, int data)
{
    AVLNode *node = CreateNode(data);

    if (root == NULL)
    {
        root = node;
        return root;
    }
    else
    {
        AVLNode *p = root;
        AVLNode *parent = NULL;

        while (p != NULL) // 找到插入位置
        {
            parent = p;

            if (data < p->data)
            {
                p = p->leftchild;
            }
            else if (data > p->data)
            {
                p = p->rightchild;
            }
            else
            {
                delete node;
                return root;
            }
        }

        if (data < parent->data)
        {
            parent->leftchild = node;
        }
        else
        {
            parent->rightchild = node;
        }

        node->parent = parent;
        UpdateBalance(root);
        Balance(root, node);
        return node;
    }
}

// 输出函数。 要求：输出两列，第一列为数据，第二列为数据的父亲节点的下标，如果没有父亲节点，则输出-1
void output(AVLTree root, int n, int index[])
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    if (root->parent == NULL)
        cout << -1 << endl;
    else
        for (int i = 0; i < n; i++)
        {
            if (index[i] == root->parent->data)
            {
                cout << i << endl;
                break;
            }
        }
    output(root->leftchild, n, index);
    output(root->rightchild, n, index);
}

void test()
{
    AVLTree root = NULL;
    AVLNode *node = NULL;
    int n;
    cout << "请输入节点个数" << endl;
    cin >> n;
    int data;
    cout << "请依次输入节点值" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> data;
        node = InsertNode(root, data);
        avl_visual_print(root, "%d", stdout);
    }
}

void solve()
{
    AVLTree root = NULL;
    cout << "请输入节点个数" << endl;
    int n;
    cin >> n;
    cout << "请依次输入节点值" << endl;
    int data;
    int index[n];
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        index[i] = data;
        InsertNode(root, data);
        // avl_visual_print(root, "%d", stdout);
    }
    output(root, n, index);
    //avl_visual_print(root, "%d", stdout);
}

int main()
{
    solve();
    return 0;
}