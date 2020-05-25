#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stack>

int n_operator[6] = { 2,1,0,1,0,2 };//* + , - . /：运算符优先级

int main()
{
	char t[100];

	//输入串式
	while (scanf("%s", &t) != EOF)
	{
		strcat(t, ",");

		std::stack<int> OPND;
		std::stack<char> OPTR;
		OPTR.push(',');

		for (int i = 0; t[i] != '\0'; ++i)
		{
			//如果是数字，入OPND栈，以下是字符串数字转换成int型数字
			if (t[i] >= '0'&&t[i] <= '9')
			{
				int temp = 0;
				int times = 1;
				for (; t[i] >= '0'&&t[i] <= '9'; ++i);
				int j = --i;
				for (; t[j] >= '0'&&t[j] <= '9'; --j)
				{
					temp += (t[j] - '0')*times;
					times *= 10;
				}
				OPND.push(temp);
				continue;
			}

			//如果是运算符，且当前运算符的优先级大于OPTR栈顶的运算符
			if (n_operator[t[i] - '*'] > n_operator[OPTR.top() - '*'])
			{
				OPTR.push(t[i]);//入栈
				continue;
			}

			//如果是运算符，且当前运算符的优先级小于OPTR栈顶的运算符或者运算符优先级相等且两者均不等于“,”，后者的条件是实现连加(减、乘或除)的关键
			if (n_operator[t[i] - '*'] < n_operator[OPTR.top() - '*'] || (n_operator[t[i] - '*'] == n_operator[OPTR.top() - '*'] && t[i] != ','&&OPTR.top() != ','))
			{
				//将OPND栈弹出两个数字，注意先后顺序，后弹出的是被加(减、乘或除)数，所以要调换
				int b = OPND.top();
				OPND.pop();
				int a = OPND.top();
				OPND.pop();

				//弹出运算符
				char c = OPTR.top();
				OPTR.pop();

				switch (c)
				{
				case '+':
					OPND.push(a + b);
					break;
				case '-':
					OPND.push(a - b);
					break;
				case '*':
					OPND.push(a * b);
					break;
				case '/':
					OPND.push(a / b);
					break;
				default:
					throw "WTF?!";//此处为抛出错误，一般不可能出现，除非有bug
					break;
				}
				--i;
				continue;
			}

			//此处if条件可以省略，只留下OPTR.pop();
			if (n_operator[t[i] - '*'] == n_operator[OPTR.top() - '*'])
			{
				OPTR.pop();
				continue;
			}
		}

		//输出OPND的栈顶，栈顶值为最终计算后的结果
		printf("%d\n", OPND.top());
	}

	return 0;
}
