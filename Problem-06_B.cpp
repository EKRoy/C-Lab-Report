/*Program to check whether any given number is prime or not.
 Write codes for both with user defined function*/
#include <iostream>
using namespace std;
void isPrime(int n)
{
	if(n<=1){
		cout << " It is not prime number" << endl;
		return;
	}
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
		cout << " It is prime number" << endl;
	}
	else
		cout << " It is not prime number" << endl;
}
int main()
{
	int n;
	cout << "Enter the value of n:" << endl;
	cin >> n;
	isPrime(n);

	return 0;
}
