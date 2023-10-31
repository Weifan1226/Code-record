#include <iostream>
using namespace std;
#define init_size 100
#define in_size 10
#define ll long long
string s;

template <typename T> // 定义栈
class stack
{
public:
	T *base;
	T *top;
	int stacksize;
	stack()
	{
		base = (T *)malloc(init_size * sizeof(T));
		top = base;
		stacksize = init_size;
	}
	bool gettop(T &e) //取栈顶元素
	{
		if (top == base) //栈空
		{
			return false;
		}
		e = *(top - 1);
		return true;
	}
	void push(T k) //入栈
	{
		if (top - base >= stacksize)
		{
			base = (T *)realloc(base, (stacksize + in_size) * sizeof(T)); //满的时候，重新分配，追加空间
			top = base + stacksize;
			stacksize += in_size;
		}
		*top++ = k; //将数据压入栈
	}
	bool pop(T &e) //出栈
	{
		if (top == base)
		{
			return false;
		}
		e = *--top;
		return true;
	}
	bool empty()
	{
		if (top == base)
		{
			return true;
		}
		return false;
	}
};

bool judge(char a, char b) // 定义运算符号优先级
{
	if (a == '+' || a == '-')
	{
		if (b == '*' || b == '/')
		{
			return false;  //后面运算符优先级高，不可弹出
		}
		else
		{
			return true;
		}
	}
	else if (a == '*' || a == '/')
	{
		if (b == '+' || b == '-')
		{
			return true;   //可以弹出 
		}
		else
		{
			return true;
		}
	}
	else if (a == '(' || a == ')')
	{
		return false;
	}
}

ll cal(ll a, ll b, char c) // 计算部分
{
	if (c == '+')
	{
		return a + b;
	}
	else if (c == '-')
	{
		return a - b;
	}
	else if (c == '*')
	{
		return a * b;
	}
	else if (c == '/')
	{
		return a / b;
	}
}

void solve()
{
	stack<char> s1;	 // 操作符栈
	stack<ll> s2;	 // 存数栈
	stack<float> s3; // 输出栈
	ll len = s.length();
	for (ll i = 0; i < len; i++)  //后缀表达式部分 
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			ll a = 0; 
			while (s[i] >= '0' && s[i] <= '9')
			{
				a = a * 10 + s[i] - 48; // 将字符串转换为数字
				i++;
			}
			s2.push(a);
			i--;  // 因为前面有i++，所以这里要减回来1
			cout << a << " ";
		}
		else
		{
			if (s1.empty()) // 空栈的时候直接压入
			{
				s1.push(s[i]);
			}
			else if (s[i] == '(') // 读到左括号直接压入
			{
				s1.push(s[i]);
			}
			else if (s[i] == ')') // 读到右括号，将栈中的操作符弹出，直到遇到左括号
			{
				char c;
				s1.gettop(c);
				while (c != '(') //一直弹
				{
					ll x1, x2;
					s2.pop(x2);
					s2.pop(x1); // 弹出两个数
					s2.push(cal(x1, x2, c));
					cout << c << " ";
					s1.pop(c);
					s1.gettop(c); // 继续判断栈顶元素
				}
				s1.pop(c);  //弹出左括号
			}
			else			//读区操作符的时候
			{
				char c;
				s1.gettop(c);  
				if (!judge(c, s[i]))  //如果栈顶元素优先级高于当前操作符，直接压入
				{
					s1.push(s[i]);
				}
				else
				{
					ll x1, x2;
					while (judge(c, s[i]))
					{
						s2.pop(x2); 		//弹出两个数进行前一个操作符计算
						s2.pop(x1);
						s2.push(cal(x1, x2, c));
						cout << c << " ";
						s1.pop(c);
						if (!s1.gettop(c))
						{
							break;
						}
					}
					s1.push(s[i]);   //将当前操作符压入栈中
				}
			}
		}
	}
	while (!s1.empty())  //最后将栈中剩余的操作符弹出
	{
		char c;
		s1.pop(c);
		cout << c << " ";
		ll x1, x2;
		s2.pop(x2);
		s2.pop(x1);
		s2.push(cal(x1, x2, c));
	}
	cout << endl;

	ll x;  //结果
	s2.pop(x);  //此处栈中只剩下一个x, 把结果弹出来存在x中,最后输出	

	for (ll i = len - 1; i >= 0; i--)  //前缀表达式
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			ll a = 0;
			ll t = 1;
			while (i >= 0 && s[i] >= '0' && s[i] <= '9') //str 2 int
			{
				a = a + (s[i] - 48) * t;
				t *= 10;
				i--;
			}
			s2.push(a); //将数字压入栈中
			i++;
			s3.push(a); //将数字压入输出栈中
			//前缀表达式的输出顺序是从右到左，所以要先压入输出栈s3中
		}
		else
		{
			if (s1.empty())
			{
				s1.push(s[i]);
			}
			else if (s[i] == ')')
			{
				s1.push(s[i]);
			}
			else if (s[i] == '(')
			{
				char c;
				s1.gettop(c);
				while (c != ')')
				{
					ll x1, x2;
					s2.pop(x2);
					s2.pop(x1);
					s2.push(cal(x1, x2, c));
					if (c == '+')
					{
						s3.push(0.1);  //用浮点数的小数部分来判断是哪个运算符
					}
					else if (c == '-')
					{
						s3.push(0.2);
					}
					else if (c == '*')
					{
						s3.push(0.3);
					}
					else
					{
						s3.push(0.4);
					}
					s1.pop(c);
					s1.gettop(c);
				}
				s1.pop(c); //弹出括号
			}
			else
			{
				char c;
				s1.gettop(c);
				if (!judge(c, s[i]))
				{
					s1.push(s[i]);  //如果栈顶元素优先级高于当前操作符，直接压入
				}
				else
				{
					ll x1, x2;
					while (judge(c, s[i]))
					{
						s2.pop(x2);
						s2.pop(x1);
						s2.push(cal(x1, x2, c));
						if (c == '+')
						{
							s3.push(0.1);
						}
						else if (c == '-')
						{
							s3.push(0.2);
						}
						else if (c == '*')
						{
							s3.push(0.3);
						}
						else
						{
							s3.push(0.4);
						}
						s1.pop(c); //读完了就弹出操作符
						if (!s1.gettop(c)) //如果栈空了就退出
						{
							break;
						}
					}
					s1.push(s[i]); //不满足弹出计算的时候当前操作符压入栈中
				}
			}
		}
	}
	while (!s1.empty())   //将栈中剩余的操作符弹出，并用数据记录在S3栈中
	{
		char c;
		s1.pop(c); 
		if (c == '+')
		{
			s3.push(0.1);
		}
		else if (c == '-')
		{
			s3.push(0.2);
		}
		else if (c == '*')
		{
			s3.push(0.3);
		}
		else
		{
			s3.push(0.4);
		}
		ll x1, x2;
		s2.pop(x2);
		s2.pop(x1);
		s2.push(cal(x1, x2, c));
	}
	while (!s3.empty())   //输出栈中的内容
	{ 
		float c;
		s3.pop(c);
		ll x = (ll)c;   //取整数部分 如果是整数则代表是数字，如果是小数则代表是运算符
		if (x == c)  
		{
			cout << x << " "; //直接输出数据
		}
		else   
		{
			if (c < 0.11)  //用浮点数的小数部分来判断是哪个运算符
			{
				cout << "+";
			}
			else if (c < 0.22)
			{
				cout << "-";
			}
			else if (c < 0.33)
			{
				cout << "*";
			}
			else if (c < 0.44)     
			{
				cout << "/";
			}
			cout << " ";
		}
	}
	cout << endl;
	cout << x << endl; //输出结果
}

int main()
{
	cin >> s;
	solve();
}