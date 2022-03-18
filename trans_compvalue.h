#pragma once
#include <iostream>
#include "SeqStack.h"
#include "SeqStack1.h"
using namespace std;

void trans(char* exp, char postexp[]);				//���������ʽexpת���ɺ�׺���ʽpostexp
double compvalue(char* postexp[]);					//�����׺���ʽ��ֵ

void trans(char* exp, char postexp[])				//���������ʽexpת���ɺ�׺���ʽpostexp
{
	char e;
	SqStack* Optr;								//���������ջָ��
	InitStack(Optr);								//��ʼ�������ջ
	int i = 0;										//i��Ϊpostexp����ջ
	while (*exp != '\0')							//exp���ʽδɨ����ʱѭ��
	{
		switch (*exp)
		{
		case'(':									//�ж�Ϊ������
			Push(Optr, '(');						//�����Ž�ջ
			exp++;
			break;
		case')':									//�ж�Ϊ������
			Pop(Optr, e);							//��ջԪ��e
			while (e != '(')						//��Ϊ'('ʱѭ��
			{
				postexp[i++] = e;					//��e��ŵ�postexp��
				Pop(Optr, e);						//������ջe
			}
			exp++;
			break;
		case'+':									//�ж�Ϊ�ӻ����
		case'-':
			while (!StackEmpty(Optr))				//ջ����ѭ��
			{
				GetTop(Optr, e);					//ȡջ��Ԫ��e
				if (e != '(')						//e����'('
				{
					postexp[i++] = e;				//��e��ŵ�postexp��
					Pop(Optr, e);					//��ջԪ��e
				}
				else
					break;
			}
			Push(Optr, *exp);						//��'+'��'-'��ջ
			exp++;									//����ɨ�������ַ�
			break;
		case'*':									//�ж�Ϊ'*'��'/'��
		case'/':
			while (!StackEmpty(Optr))				//ջ����ѭ��
			{
				GetTop(Optr, e);					//ȡջ��Ԫ��e
				if (e == '*' || e == '/')			//��ջ��'*'��'/'�������ջ����ŵ�opstexp��
				{
					postexp[i++] = e;				//��e��ŵ�postexp��
					Pop(Optr, e);					//��ջԪ��e
				}
				else								//eΪ��'*'��'/'�����ʱ�˳�ѭ��
					break;
			}
			Push(Optr, *exp);						//��'*'��'/'��ջ
			exp++;									//����ɨ�������ַ�
			break;
		default:									//���������ַ�
			while (*exp >= '0' && *exp <= '9')		//�ж�Ϊ�����ַ�
			{
				postexp[i++] = *exp;
				exp++;
			}
			postexp[i++] = '#';						//��#��ʶһ�����ִ�����
		}
	}
	while (!StackEmpty(Optr))						//��ʱexpɨ����ϣ�ջ����ʱѭ��
	{
		Pop(Optr, e);								//��ջԪ��e
		postexp[i++] = e;							//��e��ŵ�postexp��
	}
	postexp[i] = '\0';								//��postexp���ʽ��ӽ�����ʶ
	DestroyStack(Optr);								//����ջ
}

double compvalue(char *postexp)						//�����׺���ʽ��ֵ
{
	double a, b, c, d, e;
	SqStack1* Opnd;								//���������ջ
	InitStack1(Opnd);								//��ʼ��������ջ
	while (*postexp != '\0')						//postexp�ַ���δɨ����ʱѭ��
	{
		switch (*postexp)
		{
		case'+':									//�ж�Ϊ'+'��
			Pop1(Opnd, a);							//��ջԪ��a
			Pop1(Opnd, b);							//��ջԪ��b
			c = b + a;								//����c
			Push1(Opnd, c);							//�����c��ջ
			break;
		case'-':									//�ж�Ϊ'-'��
			Pop1(Opnd, a);							//��ջԪ��a
			Pop1(Opnd, b);							//��ջԪ��b
			c = b - a;
			Push1(Opnd, c);							//��������c��ջ
			break;
		case'*':									//�ж�Ϊ'*'��
			Pop1(Opnd, a);							//��ջԪ��a
			Pop1(Opnd, b);							//��ջԪ��b
			c = b * a;								//����c
			Push1(Opnd, c);							//��������c��ջ
			break;
		case'/':									//�ж�Ϊ'/'��
			Pop1(Opnd, a);							//��ջԪ��a
			Pop1(Opnd, b);							//��ջԪ��b
			if (a != 0)
			{
				c = b / a;							//������c
				Push1(Opnd, c);						//��������c��ջ
				break;
			}
			else
			{
				cout << "\n\t�������" << endl;
				exit(0);
			}
			break;
		default:									//���������ַ�
			d = 0;									//�������������ַ�ת���ɶ�Ӧ����ֵ��ŵ�d��
			while (*postexp >= '0' && *postexp <='9')//�ж�Ϊ�����ַ�
			{
				d = 10 * d + *postexp - '0';
				postexp++;
			}
			Push1(Opnd, d);							//����ֵd��ջ
			break;
		}
		postexp++;									//�������������ַ�
	}
	GetTop1(Opnd, e);								//ȡջ��Ԫ��e
	DestroyStack1(Opnd);							//����ջ
	return e;
}