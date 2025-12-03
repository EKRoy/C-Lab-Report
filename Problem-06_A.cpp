/*Program to check whether any given number is prime or not.
 Write codes for both with user defined function*/
#include <iostream>
using namespace std;
int main()
{
	int n;
	cout << "Enter the value of n:" << endl;
	cin >> n;
	bool flag = true;
	for (int i = 2; i < n; i = i + 1)
	{
		if (n % i == 0)
		{
			flag = false;
		}
	}
	if (flag == true)
	{
		cout << "is prime number" << endl;
	}
	else
		cout << "is not prime number" << endl;

	return 0;
}
