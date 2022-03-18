#pragma once
#include <iostream>

using namespace std;

typedef double ElemType1;
const int MaxSize1 = 50;

typedef struct
{
	ElemType1 data[MaxSize1];
	int top;
} SqStack1;

void InitStack1(SqStack1*& s);							//初始化栈
void DestroyStack1(SqStack1*& s);							//销毁栈
bool StackEmpty1(SqStack1* s);							//判断栈是否为空
bool Push1(SqStack1*& s, ElemType1 e);						//进栈
bool Pop1(SqStack1*& s, ElemType1& e);						//出栈
bool GetTop1(SqStack1* s, ElemType1& e);					//取栈顶元素

void InitStack1(SqStack1*& s)								//初始化栈
{
	s = (SqStack1*)malloc(sizeof(SqStack1));			//分配一个顺序栈空间，首地址存放在s中
	s->top = -1;									//栈顶指针置为-1
}

void DestroyStack1(SqStack1*& s)							//销毁栈
{
	free(s);
}

bool StackEmpty1(SqStack1* s)								//判断栈是否为空
{
	return(s->top == -1);
}

bool Push1(SqStack1*& s, ElemType1 e)						//进栈
{
	if (s->top == MaxSize - 1)						//栈满的情况，即栈上溢出
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}

bool Pop1(SqStack1*& s, ElemType1& e)						//出栈
{
	if (s->top == -1)								//栈为空的情况，即栈下溢出
		return false;
	e = s->data[s->top];							//取栈顶元素
	s->top--;
	return true;
}

bool GetTop1(SqStack1* s, ElemType1& e)					//取栈顶元素
{
	if (s->top == -1)								//栈为空的情况，即栈下溢出
		return false;
	e = s->data[s->top];
	return true;
}
