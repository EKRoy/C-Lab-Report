/*Program to take input of a user name and consumed current units and print
an electric bill which billing criteria is as follows
i) First 50 units has minimum charge 100tk
ii) Next 200 units cost 2.50 TK/unit
iii) Next 250 units cost 3.50 TK/unit
iv) Units above 500 are charged at a rate 5.00TK/unit
Make sure you implement the idea using user-defined function. */

#include <iostream>
using namespace std;
void currentBill(double units){
    double bill;
    if(units<=50){
        bill=100;
    }
    else if(units<=250){
        bill=100+(units-50)*2.5;
    }
    else if(units<=500){
        bill = 100 + 200* 2.5+(units-250)*3.5;
    }
    else bill=100+200*2.5+250*3.5+(units-500)*5;
    cout<<"Current Bill:"<<bill<<endl;
}
int main()
{
    string first, last;
    cout << "Enter your first name and last name: "<<endl;
    cin >> first >> last;
    cout<<first<<" "<<last<<endl;
    double units;
    cout<<"Enter your consumed units:"<<endl;
    cin>>units;
    currentBill(units);
    return 0;
}
