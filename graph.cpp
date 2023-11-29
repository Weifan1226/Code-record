/*最小生成树算法实现

1. 基于邻接链表数据结构实现算法；

2. 实现Prim算法；

3. 实现kruskal算法；*/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 100

// 边
class Arc
{
public:
    Arc *next;   // 指向下一条边
    char adjvex; // 指向的顶点
    int weight;  // 边权值

    Arc(int adjvex, int weight) : adjvex(adjvex), weight(weight), next(NULL) {}
};

// 头表
class VNode
{
public:
    char data; // 顶点信息
    Arc *firstarc;

    VNode(int data) : data(data), firstarc(NULL) {}
};

class closeEdge // Prim算法中的辅助数组，用于存储当前顶点到其他顶点的最小权值
{
public:
    char adjvex;
    int lowcost;
};

// 邻接链表实现图
class Graph
{
public:
    int vexnum, arcnum;
    bool visited[MAX];
    VNode *vex[MAX];

    Graph() : vexnum(0), arcnum(0) {}
    Graph(int vexnum, int arcnum) : vexnum(vexnum), arcnum(arcnum)
    {
        for (int i = 0; i < vexnum; i++)
        {
            vex[i] = NULL;
            visited[i] = false;
        }
    }

    void CreateGraph();
    void DFS(int start);
    void BFS(int start);
    void Prim();
    int **AdjListToAdjMatrix();
    void Kruskal();
};

// 初始化图
void Graph::CreateGraph()
{
    cout << "请输入" << vexnum << "个顶点信息：" << endl;
    char temp;
    for (int i = 0; i < vexnum; i++)
    {
        cin >> temp;
        vex[i] = new VNode(temp); // 创建头表
    }
    for (int i = 0; i < vexnum; i++) // 遍历每一个头节点
    {
        int num;
        cout << "请输入" << vex[i]->data << "顶点的邻接点个数" << endl;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            char adjvex;
            int weight;
            cout << "请输入" << vex[i]->data << "的第" << j + 1 << "邻接节点的信息和路径权重:" << endl;
            cin >> adjvex >> weight;
            if (j == 0) // 第一个节点放在first后面
            {
                vex[i]->firstarc = new Arc(adjvex, weight);
            }
            else // 之后所有的节点放在第一个节点后面
            {
                Arc *p = vex[i]->firstarc;
                while (p->next != NULL)
                    p = p->next;
                p->next = new Arc(adjvex, weight);
            }
        }
    }
}

int getsub(Graph &G, char c)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vex[i]->data == c)
            return i;
    }
    return -1;
}

void Graph::DFS(int i)
{
    Arc *p = this->vex[i]->firstarc;
    // Arc *p = G.vex[i]->firstarc;
    cout << this->vex[i]->data << " ";
    this->visited[i] = true;
    while (p)
    {
        if (!this->visited[getsub(*this, p->adjvex)])
            this->DFS(getsub(*this, p->adjvex));
        p = p->next;
    }
}

void Graph::BFS(int start)
{
    cout << "BFS: ";
    queue<int> q;
    q.push(start);
    this->visited[start] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        cout << this->vex[current]->data << " ";

        Arc *p = this->vex[current]->firstarc;
        while (p)
        {
            if (!this->visited[getsub(*this, p->adjvex)])
            {
                q.push(getsub(*this, p->adjvex));
                this->visited[getsub(*this, p->adjvex)] = true;
            }
            p = p->next;
        }
    }

    cout << endl;
}

void Graph::Prim()
{
    cout << "Prim: " << endl;

    int sum = 0;
    closeEdge closeedge[MAX];                  // 辅助数组，用于存储当前顶点到其他顶点的最小权值
    int k = 0;                                 // 记录最小权值的顶点
    int min = 0;                               // 记录最小权值
    int **matrix = this->AdjListToAdjMatrix(); 

    // 初始化closeedge数组
    for (int i = 1; i < this->vexnum; i++)
    {
        closeedge[i].adjvex = 0;
        closeedge[i].lowcost = matrix[0][i];
    }

    for (int i = 1; i < this->vexnum; i++)
    {
        min = INT_MAX;
        // 找到当前顶点到其他顶点的最小权值
        for (int j = 1; j < this->vexnum; j++)
        {
            if (closeedge[j].lowcost != 0 && closeedge[j].lowcost < min)
            {
                min = closeedge[j].lowcost;
                k = j;
            }
        }

        cout << this->vex[closeedge[k].adjvex]->data << " -> " << this->vex[k]->data << " weight: " << min << endl;
        sum += min;
        closeedge[k].lowcost = 0; // 将当前顶点的权值置为0 表示已经在最小生成树中

        // 更新closeedge数组
        for (int j = 1; j < this->vexnum; j++)
        {
            if (matrix[k][j] != 0 && matrix[k][j] < closeedge[j].lowcost) 
            {
                closeedge[j].adjvex = k;
                closeedge[j].lowcost = matrix[k][j];
            }
        }
    }

    cout << "最小生成树的权值为： " << sum << endl;

}

// 邻接链表转邻接矩阵
int **Graph::AdjListToAdjMatrix()
{
    int **matrix = new int *[this->vexnum];
    for (int i = 0; i < this->vexnum; i++) // 初始化邻接矩阵
    {
        matrix[i] = new int[this->vexnum];
        for (int j = 0; j < this->vexnum; j++)
            matrix[i][j] = 0;
    }
    for (int i = 0; i < this->vexnum; i++) // 将邻接链表转换为邻接矩阵
    {
        Arc *p = this->vex[i]->firstarc;
        while (p)
        {
            matrix[i][getsub(*this, p->adjvex)] = p->weight; // 更新节点之间的权重值
            p = p->next;
        }
    }
    return matrix;
}

// Kruskal算法
void Graph::Kruskal()
{
    cout << "Kruskal: " << endl;
    int sum = 0;
    int **matrix = this->AdjListToAdjMatrix();
    int edges[MAX][3]; // 使用二维数组存储边和权值，每行包含起点、终点和权值

    int edgeCount = 0; // 记录边的数量

    for (int i = 0; i < this->vexnum; i++) // 遍历邻接矩阵，将边存储到edges中
    {
        for (int j = i + 1; j < this->vexnum; j++)
        {
            if (matrix[i][j] != 0) // 有边
            {
                edges[edgeCount][0] = i;
                edges[edgeCount][1] = j;
                edges[edgeCount][2] = matrix[i][j];
                edgeCount++;
            }
        }
    }

    // 对边按权值排序
    for (int i = 0; i < edgeCount - 1; i++)
    {
        for (int j = 0; j < edgeCount - i - 1; j++)
        {
            if (edges[j][2] > edges[j + 1][2])
            {
                // 交换边
                swap(edges[j], edges[j + 1]);
            }
        }
    }

    int *parent = new int[this->vexnum];   // 用于判断边的两个顶点是否在同一个集合中
    for (int i = 0; i < this->vexnum; i++) // 初始化parent
        parent[i] = 0;

    for (int i = 0; i < edgeCount; i++) // 遍历所有边
    {
        int m = edges[i][0];
        int n = edges[i][1];

        while (parent[m] > 0) // 寻找m的根节点
            m = parent[m];

        while (parent[n] > 0)
            n = parent[n];

        if (m != n) // 如果m和n不在同一个集合中，则将m和n合并到一个集合中
        {
            cout << "(" << this->vex[edges[i][0]]->data << "->" << this->vex[edges[i][1]]->data << ")"
                 << " weight: " << edges[i][2] << endl;
            sum += edges[i][2];
            parent[m] = n;
        }
    }

    cout << "最小生成树的权值为：" << sum << endl;
}

void ResetGraph(Graph &G)
{
    for (int i = 0; i < G.vexnum; i++)
        G.visited[i] = false;
}

void TestForDFSandBFS()
{
    cout << "请输入顶点数和边数：" << endl;
    int vexnum, arcnum;
    cin >> vexnum >> arcnum;
    Graph G(vexnum, arcnum);
    G.CreateGraph();
    int start = 0;
    cout << "DFS: ";
    G.DFS(start);
    cout << endl;
    ResetGraph(G);
    G.BFS(start);
    cout << endl;
}

void solve_Prim()
{
    cout << "请输入顶点数和边数：" << endl;
    int vexnum, arcnum;
    cin >> vexnum >> arcnum;
    Graph G(vexnum, arcnum);
    G.CreateGraph();
    G.Prim();
}

void solve_Kruskal()
{
    cout << "请输入顶点数和边数：" << endl;
    int vexnum, arcnum;
    cin >> vexnum >> arcnum;
    Graph G(vexnum, arcnum);
    G.CreateGraph();
    G.Kruskal();
}

void solve()
{
    cout << "请输入顶点数和边数：" << endl;
    int vexnum, arcnum;
    cin >> vexnum >> arcnum;
    Graph G(vexnum, arcnum);
    G.CreateGraph();
    G.Prim();
    ResetGraph(G);
    G.Kruskal();
}   

int main()
{
    // TestForDFSandBFS();
    // solve_Prim();
    // solve_Kruskal();
    solve();
    return 0;
}