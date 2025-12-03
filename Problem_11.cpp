/*Program to take input of a user name and yearly income and print income
tax where the taxation criteria is as follows
i) First 250000 is tax free
ii) 5% tax for next 250000
iii) 10% tax for next 500000
iv) 20% tax for next 4000000
v) 40% tax for income above 5000000
Make sure you implement the idea using user-defined function. */
#include <iostream>
using namespace std;
void incomeTax(double income)
{
    double tax;
    if (income <= 250000)
    {
        tax = 0;
    }
    else if (income <= 500000)
    {
        tax = 0 + (income - 250000) * 0.05;
    }
    else if (income <= 1000000)
    {
        tax = 0 + 250000 * 0.05 + (income - 500000) * 0.1;
    }
    else if (income <= 5000000)
    {
        tax = 0 + 250000 * 0.05 + 500000 * 0.1 + (income - 1000000) * 0.2;
    }
    else
        tax = 0 + 250000 * 0.05 + 500000 * 0.1 + 40000000 * 0.2 + (income - 5000000) * 0.4;
        
    cout<<"Income tax:"<<tax<<endl;
}
int main()
{
    string first, last;
    cout << "Enter your first name and last name: " << endl;
    cin >> first >> last;
    cout << first << " " << last << endl;
    double income;
    cout << "Enter your consumed income:" << endl;
    cin >> income;
    incomeTax(income);
    return 0;
}

