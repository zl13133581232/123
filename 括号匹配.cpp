#include<stdio.h>
#include<iostream>


#define MAXSIZE 100
typedef int selemtype;
using namespace std;
typedef struct {      //顺序栈的存储结构
	selemtype* base;
	selemtype* top;
	int stacksize;
}SqStack;
void InitStack(SqStack& s) {     //栈的初始化
	s.base = new selemtype[MAXSIZE];
	if (!s.base)exit(1);
	s.top = s.base;
	s.stacksize = MAXSIZE;
}
void Push(SqStack& s, selemtype e) {    //入栈
	if (s.top - s.base == s.stacksize)return;
	*s.top++ = e;
}
bool StackEmpty(SqStack& s) {     //判断栈空
	if (s.top == s.base)return true;
	else return false;
}
selemtype GetTop(SqStack s) {    //得到栈顶元素
	if (s.top != s.base)
		return *(s.top - 1);
}
void Pop(SqStack& s, selemtype& e) {     //压栈
	if (s.top == s.base)return;
	e = *--s.top;
}
int main() {    //主函数
	SqStack s;     //参数的定义
	selemtype e;
	char ch;
	int x;
	InitStack(s);
	int flag = 1;
	cout << "请输入算数表达式，以#结束" << endl;
	cin >> ch;
	while (ch != '#' && flag)       //具体的判断函数
	{
		switch (ch) {
		case'[':
		case'(':
			Push(s, ch);
			break;
		case')':
			if (!StackEmpty(s) && GetTop(s) == '(')
				Pop(s, x);
			else flag = 0;
			break;
		case']':
			if (!StackEmpty(s) && GetTop(s) == '[')
				Pop(s, x);
			else flag = 0;
			break;
		}
		cin >> ch;
	}
	if (StackEmpty(s) && flag)cout << "匹配成功";
	else 
cout << "匹配失败";
	return 0;
}
