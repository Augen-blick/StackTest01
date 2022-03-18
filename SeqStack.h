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

void InitStack(SqStack*& s);							//��ʼ��ջ
void DestroyStack(SqStack*& s);							//����ջ
bool StackEmpty(SqStack* s);							//�ж�ջ�Ƿ�Ϊ��
bool Push(SqStack*& s, ElemType e);						//��ջ
bool Pop(SqStack*& s, ElemType& e);						//��ջ
bool GetTop(SqStack* s, ElemType& e);					//ȡջ��Ԫ��

void InitStack(SqStack*& s)								//��ʼ��ջ
{
	s = (SqStack*)malloc(sizeof(SqStack));			//����һ��˳��ջ�ռ䣬�׵�ַ�����s��
	s->top = -1;									//ջ��ָ����Ϊ-1
}

void DestroyStack(SqStack*& s)							//����ջ
{
	free(s);
}

bool StackEmpty(SqStack* s)								//�ж�ջ�Ƿ�Ϊ��
{
	return(s->top == -1);
}

bool Push(SqStack*& s, ElemType e)						//��ջ
{
	if (s->top == MaxSize - 1)						//ջ�����������ջ�����
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}

bool Pop(SqStack*& s, ElemType& e)						//��ջ
{
	if (s->top == -1)								//ջΪ�յ��������ջ�����
		return false;
	e = s->data[s->top];							//ȡջ��Ԫ��
	s->top--;
	return true;
}

bool GetTop(SqStack* s, ElemType& e)					//ȡջ��Ԫ��
{
	if (s->top == -1)								//ջΪ�յ��������ջ�����
		return false;
	e = s->data[s->top];
	return true;
}
