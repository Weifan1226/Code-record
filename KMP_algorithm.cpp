// 20226460 魏凡峻铎 人工智能未来班 第二次作业-KMP

#include <iostream>
#define MAX 10000
int dp[MAX][256];
// 等同于next数组
// dp[i][j] i表示状态机中有多少个状态，j表示字符，用DFA去理解KMP
// dp[4]['A'] = 3 表示：
// 当前是状态 4，如果遇到字符 A，
// pat 应该转移到状态 3

void _KMP(char *txt, char *pat)
{
    int txt_len = strlen(txt);
    int pat_len = strlen(pat);
    dp[0][pat[0]] = 1;
    int x = 0; // 记录前缀后缀相同长度.
    for (int j = 1; j < pat_len; j++)
    {
        for (int c = 0; c < 256; c++)  //通过遍历ASC确保所有特殊字符都会被考虑到并且 256不会影响时间复杂度
        {
            if (pat[j] == c)
                dp[j][c] = j + 1; // 如果读入字符符合转移，那么转移
            else
                dp[j][c] = dp[x][c]; // 如果不符合转移，那么就跳转到前缀后缀相同长度的状态
        }
        x = dp[x][pat[j]];
    }
}

int _search(char *txt, char *pat)
{
    int txt_len = strlen(txt);
    int pat_len = strlen(pat);
    int j = 0;
    for (int i = 0; i < txt_len; i++)
    {
        j = dp[j][txt[i]];          // 此处模拟自动机读入字符然后状态跳转
        if (j == pat_len)           // 如果跳转到了末尾那么就是匹配成功。
            return i - pat_len + 1; // 返回符合字符串头位置
    }

    return -1; // 没有匹配到终止状态返回-1
}

int KMP(char *txt, char *pat)
{
    _KMP(txt, pat);
    return _search(txt, pat);
}

int main()
{
    char txt[MAX];
    char pat[MAX];
    scanf("%s", txt);
    scanf("%s", pat);

    printf("KMP匹配位置在%d\n", KMP(txt, pat));

    return 0;
}
