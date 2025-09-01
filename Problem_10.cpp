/*Program to take input of a user name and consumed current units and print 
an electric bill which billing criteria is as follows 
i) First 50 units has minimum charge 100tk 
ii) Next 200 units cost 2.50 TK/unit 
iii) Next 250 units cost 3.50 TK/unit 
iv) Units above 500 are charged at a rate 5.00TK/unit 
Make sure you implement the idea using user-defined function. */
#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;
double electricBill(double units){
    double bill=0.0;
    if(units<=50){
        bill=100;
    }
    else if(units>50 && units<=250){
        bill=100+(units-50)*2.5;
    }
    else if(units>250 && units<=500){
        bill=100+(200*2.5)+(units-250)*3.5;
    }
    else bill=100+(200*2.5)+250*3.5+(units-500)*5;
    return bill;
}
int main(){
    int choice=1;
    while(choice==1){
        string name;
        cout<<"Enter your name: ";
        cin.ignore();
        getline(cin,name);
        double units;
        cout<<"Enter your consumed units: ";
        cin>>units;
        cout<<"Mr/ms. "<<name<<endl;
        cout<<fixed<<setprecision(2);
        cout<<"Your Electric Bill is:"<<electricBill(units)<<"Tk."<<endl;
        cout << "Do you want to put new values? (1=yes, 0=no): ";
       cin>>choice;
    }
   return 0;
}