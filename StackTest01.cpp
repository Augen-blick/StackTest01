#include <iostream>
#include "trans_compvalue.h"
using namespace std;

int main()
{
	char exp[20];
	cin >> exp;
	char postexp[20];
	trans(exp, postexp);								//��expת��Ϊpostexp
	cout << "��׺���ʽ��" << exp << endl;				//���exp
	cout << "��׺���ʽ��" << postexp << endl;			//���postexp
	cout << "���ʽ��ֵ��" << compvalue(postexp) << endl;	//��postexp��ֵ�����

	return 1;
}