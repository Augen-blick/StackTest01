#include <iostream>
#include "trans_compvalue.h"
using namespace std;

int main()
{
	char exp[20];
	cin >> exp;
	char postexp[20];
	trans(exp, postexp);								//将exp转换为postexp
	cout << "中缀表达式：" << exp << endl;				//输出exp
	cout << "后缀表达式：" << postexp << endl;			//输出postexp
	cout << "表达式的值：" << compvalue(postexp) << endl;	//求postexp的值并输出

	return 1;
}