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

void InitStack1(SqStack1*& s);							//��ʼ��ջ
void DestroyStack1(SqStack1*& s);							//����ջ
bool StackEmpty1(SqStack1* s);							//�ж�ջ�Ƿ�Ϊ��
bool Push1(SqStack1*& s, ElemType1 e);						//��ջ
bool Pop1(SqStack1*& s, ElemType1& e);						//��ջ
bool GetTop1(SqStack1* s, ElemType1& e);					//ȡջ��Ԫ��

void InitStack1(SqStack1*& s)								//��ʼ��ջ
{
	s = (SqStack1*)malloc(sizeof(SqStack1));			//����һ��˳��ջ�ռ䣬�׵�ַ�����s��
	s->top = -1;									//ջ��ָ����Ϊ-1
}

void DestroyStack1(SqStack1*& s)							//����ջ
{
	free(s);
}

bool StackEmpty1(SqStack1* s)								//�ж�ջ�Ƿ�Ϊ��
{
	return(s->top == -1);
}

bool Push1(SqStack1*& s, ElemType1 e)						//��ջ
{
	if (s->top == MaxSize - 1)						//ջ�����������ջ�����
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}

bool Pop1(SqStack1*& s, ElemType1& e)						//��ջ
{
	if (s->top == -1)								//ջΪ�յ��������ջ�����
		return false;
	e = s->data[s->top];							//ȡջ��Ԫ��
	s->top--;
	return true;
}

bool GetTop1(SqStack1* s, ElemType1& e)					//ȡջ��Ԫ��
{
	if (s->top == -1)								//ջΪ�յ��������ջ�����
		return false;
	e = s->data[s->top];
	return true;
}
