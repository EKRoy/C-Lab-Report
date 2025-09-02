/*Program to take input of a user name and yearly income and print income 
tax where the taxation criteria is as follows 
i) First 250000 is tax free 
ii) 5% tax for next 250000  
iii) 10% tax for next 500000 
iv) 20% tax for next 4000000  
v) 40% tax for income above 5000000 
Make sure you implement the idea using user-defined function. */
#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;
double incomeTax(double income){
    double tax=0;
    if(income<=250000){
        tax=0;
    }
    else if(income>250000 && income<=500000){
        tax=(income-250000)*0.05;
    }
    else if(income>500000 && income<=1000000){
        tax=250000*0.05+(income-500000)*0.1;
    }
    else if(income>1000000 && income<=5000000){
        tax=250000*0.05+500000*0.1+(income-1000000)*0.2;
    }
    else{
        tax=250000*0.05+500000*0.1+1000000*0.2+(income-5000000)*0.4;
    }
    return tax;
}
int main(){
    int choice=1;
    while(choice==1){
        string first,last;
        cout<<"Enter your name first and last name : ";
        cin>>first>>last;
        double income;
        cout<<"Enter your yearly income: ";
        cin>>income;
        cout<<"Mr./Ms. "<<first<<" "<<last<<endl;
        cout<<fixed<<setprecision(2);
        cout<<"Your income tax is: "<<incomeTax(income)<<"TK."<<endl;
        cout << "Do you want to calculate income tax for a different person? (1=yes, 0=no): ";
       cin>>choice;
    }
   return 0;
}