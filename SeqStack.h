#pragma once
#include <iostream>

using namespace std;

typedef char ElemType;
const int MaxSize = 50;

typedef struct
{
	ElemType data[MaxSize];
	int top;
} SqStack;

void InitStack(SqStack*& s);							//初始化栈
void DestroyStack(SqStack*& s);							//销毁栈
bool StackEmpty(SqStack* s);							//判断栈是否为空
bool Push(SqStack*& s, ElemType e);						//进栈
bool Pop(SqStack*& s, ElemType& e);						//出栈
bool GetTop(SqStack* s, ElemType& e);					//取栈顶元素

void InitStack(SqStack*& s)								//初始化栈
{
	s = (SqStack*)malloc(sizeof(SqStack));			//分配一个顺序栈空间，首地址存放在s中
	s->top = -1;									//栈顶指针置为-1
}

void DestroyStack(SqStack*& s)							//销毁栈
{
	free(s);
}

bool StackEmpty(SqStack* s)								//判断栈是否为空
{
	return(s->top == -1);
}

bool Push(SqStack*& s, ElemType e)						//进栈
{
	if (s->top == MaxSize - 1)						//栈满的情况，即栈上溢出
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}

bool Pop(SqStack*& s, ElemType& e)						//出栈
{
	if (s->top == -1)								//栈为空的情况，即栈下溢出
		return false;
	e = s->data[s->top];							//取栈顶元素
	s->top--;
	return true;
}

bool GetTop(SqStack* s, ElemType& e)					//取栈顶元素
{
	if (s->top == -1)								//栈为空的情况，即栈下溢出
		return false;
	e = s->data[s->top];
	return true;
}
