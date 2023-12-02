#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

int main()
{
	TStack<int> testst(5);
	testst.Push(2);
	testst.Push(4);
	testst.Push(6);
	testst.Push(8);
	cout << testst<<endl;
	cout << "\Top " << testst.GetTop() << endl;
	

	cout << "test 1" << endl;
	int a = testst.Pop();
	cout << testst <<endl;;
	cout << "\nPop was " << a << endl;
	cout << "\nTop " << testst.GetTop() << " empty" << testst.IsEmpty() << endl;

	cout << "test 2" << endl;
	testst.Pop();
	testst.Pop();
	testst.Pop();
	cout << testst << endl;;
	//cout << "\nTop " << testst.GetTop() <<" empty" << testst.IsEmpty() << endl;


	cout << "test 3" << endl;
	TCalculator testclc;
	testclc.SetExpression("1+(9-5)*1");
	cout << testclc.GetExpression();
	testclc.ToPostfix();
	cout << "\n"<<testclc.GetPostfix()<<endl;
	cout << "\n = " << testclc.CalcPostfix() << endl;
	cout << "\n =" << testclc.Calc() << endl;
	 return 0;
}
