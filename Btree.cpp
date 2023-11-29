#include <iostream>
#include "btree_visual_print.h"
using namespace std;
#define MAX_TREE_SIZE 50
#define MAX_FOREST_SIZE 50
/*实现森林和二叉树之间的相互转换

1. 给定一个森林（由大于等于一棵树组成），将其转化成一颗二叉树；  ok

2. 给定一棵二叉树，将其转化成一个森林； ok

提示：1) 森林中的树可以采用双亲孩子表示 ，也可采用邻接表表示； ok
    2) 二叉树采用动态二叉链表表示；  ok
    3) 最好设计可视化界面；  ok
*/

// typedef struct BiNode
// {
//     char data;
//     BiNode *Lchild;
//     BiNode *Rchild;
// } BiNode, *BiTree;


// 孩子兄弟法
typedef struct Tree
{
    char data;         // 数据
    Tree *firstchild;  // 最左孩子
    Tree *nextsibling; // 右兄弟
} Tree;

int getlen(Tree *t[])
{
    int len = 0;
    while (t[len])
    {
        len++;
    }
    return len;
}

// 创建树
Tree *CreateTree()
{
    Tree *cur_root[MAX_TREE_SIZE];
    for (int i = 0; i < MAX_TREE_SIZE; i++)
    {
        cur_root[i] = NULL;
    }
    Tree *t = new Tree;
    if (t == NULL)
    {
        cout << "malloc failed" << endl;
        return NULL;
    }
    cout << "请输入根节点的值" << endl;
    cin >> t->data;
    cur_root[0] = t;
    while (getlen(cur_root) != 0)
    {
        Tree *next_root[MAX_TREE_SIZE];
        for (int i = 0; i < MAX_TREE_SIZE; i++)
        {
            next_root[i] = NULL;
        }
        int flag = 0;
        for (int i = 0; i < getlen(cur_root); i++)
        {
            Tree *root = cur_root[i];
            cout << "请输入" << root->data << "节点的孩子节点的数量" << endl;
            int size = 0;
            cin >> size;
            Tree *tail = NULL;
            for (int j = 0; j < size; j++)
            {
                cout << "请输入" << root->data << "节点的第" << j + 1 << "个孩子节点的值" << endl;
                char data = 0;
                cin >> data;
                if (j == 0)
                {
                    // 第一个元素链接在左孩子上
                    root->firstchild = new Tree;
                    root->firstchild->data = data;
                    tail = root->firstchild;
                }
                else
                {
                    // 其他元素链接在兄弟指针后
                    tail->nextsibling = new Tree;
                    tail->nextsibling->data = data;
                    tail = tail->nextsibling;
                }
                next_root[flag++] = tail;
            }
        }
        for (int i = 0; i < MAX_TREE_SIZE; i++)
        {
            cur_root[i] = next_root[i];
        }
    }
    return t;
}

// 创建二叉树节点
BiNode *CreateNode(char data)
{
    BiNode *node = (BiNode *)malloc(sizeof(BiNode));
    if (NULL == node)
    {
        cout << "malloc failed" << endl;
        return NULL;
    }
    node->data = data;
    node->Lchild = NULL;
    node->Rchild = NULL;
    return node;
}

// 创建二叉树
BiNode *CreateBiTree()
{
    BiTree t = NULL;
    char data;
    cin >> data;
    if (data != '#')
    {
        t = CreateNode(data);
        t->data = data;
        t->Lchild = CreateBiTree();
        t->Rchild = CreateBiTree();
    }
    return t;
}

// 普通树转二叉树
BiTree Tree2BiTree(Tree *t)
{
    BiTree root = NULL;
    if (t)
    {
        root = (BiTree)malloc(sizeof(BiNode));
        root->data = t->data;
        root->Lchild = Tree2BiTree(t->firstchild);
        root->Rchild = Tree2BiTree(t->nextsibling);
    }
    return root;
}

// 二叉树森林转一棵二叉树
BiTree Forest2BiTree(Tree *t[])
{
    BiTree root = NULL;
    if (NULL == t[0])
        return NULL;
    root = Tree2BiTree(t[0]);
    root->Rchild = Forest2BiTree(t + 1);
    return root;
}

// 二叉树分解成小二叉树森林
BiTree* BiTree2SmallBTree(BiTree t)
{
    BiTree* son = new BiTree[MAX_TREE_SIZE];
    for (int i = 0; i < MAX_TREE_SIZE; i++)
        son[i] = NULL;
    int i = 0;
    while (t)
    {
        son[i] = new BiNode; 
        son[i]->data = t->data;
        son[i]->Lchild = t->Lchild;
        son[i]->Rchild = NULL;
        t = t->Rchild;
        i++;

    }
    return son;
}


// 二叉树转树
Tree* BiTree2Forest(BiTree t)
{
    if (t == NULL)
        return NULL;

    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->data = t->data;
    tree->firstchild = BiTree2Forest(t->Lchild);
    tree->nextsibling = BiTree2Forest(t->Rchild);

    return tree;
}

void PreOrder(BiTree t)
{
    if (t == NULL)
        return;
    cout << t->data << " ";
    PreOrder(t->Lchild);
    PreOrder(t->Rchild);
}

void InOrder(BiTree t)
{
    if (t == NULL)
        return;
    InOrder(t->Lchild);
    cout << t->data << " ";
    InOrder(t->Rchild);
}

void PostOrder(BiTree t)
{
    if (t == NULL)
        return;
    PostOrder(t->Lchild);
    PostOrder(t->Rchild);
    cout << t->data << " ";
}

int caucalate_Tree_Depth(BiTree t)
{
    if (t == NULL)
        return 0;
    int left_depth = caucalate_Tree_Depth(t->Lchild);
    int right_depth = caucalate_Tree_Depth(t->Rchild);
    return (left_depth > right_depth) ? (left_depth + 1) : (right_depth + 1);
}

// 求二叉树的节点数
int get_BiTree_Size(BiTree t)
{
    if (!t)
        return 0;
    int leftTreeSize = get_BiTree_Size(t->Lchild);
    int rightTreeSize = get_BiTree_Size(t->Rchild);
    return leftTreeSize + rightTreeSize + 1;
}

// 先序遍历求叶子节点数
int get_BiTreeLeaf_Num(BiTree t)
{
    if (t)
    {
        if (!t->Lchild && !t->Rchild) // 度为零才是叶子结点
            return 1;
        else
        {
            int left = get_BiTreeLeaf_Num(t->Lchild);
            int right = get_BiTreeLeaf_Num(t->Rchild);
            return left + right;
        }
    }
    else
    {
        return 0;
    }
}

//先序遍历展示树 
void PreDisplay(Tree *node)
{
    if (node == nullptr)
        return;
    std::cout << node->data << " ";
    PreDisplay(node->firstchild);
    PreDisplay(node->nextsibling);
}

void solve()
{
    Tree *forest[MAX_FOREST_SIZE];
    for (int i = 0; i < MAX_FOREST_SIZE; i++)
        forest[i] = NULL;
    cout << "请输入森林的树的个数" << endl;
    int size = 0;
    cin >> size;
    if (size == 0)
    {
        cout << "森林为空" << endl;
        return;
    }
    for (int i = 0; i < size; i++)
    {
        cout << "请输入第" << i + 1 << "棵树" << endl;
        forest[i] = CreateTree();
    }
    for (int i = 0; i < size; i++)
    {
        cout << "第" << i + 1 << "棵树转换为二叉树为：" << endl;
        BiTree temp = Tree2BiTree(forest[i]);
        btree_visual_print(temp, "%c", stdout);
    }
    BiTree t = Forest2BiTree(forest);
    cout << "森林转换为二叉树的结果为：" << endl;
    btree_visual_print(t, "%c", stdout);

    cout << "二叉树转换为森林的结果为：" << endl;
    
    BiTree *ret = BiTree2SmallBTree(t);
    for (int i = 0; i < size; i++)
    {
        cout << "第" << i + 1 << "棵二叉树为：" << endl;
        btree_visual_print(ret[i], "%c", stdout);
        Tree *temp = BiTree2Forest(ret[i]);
        cout << "第" << i + 1 << "棵二叉树转换为树为：" << endl;
        PreDisplay(temp);
        cout << endl;
    }
}

int main()
{
    solve();
    return 0;
}
