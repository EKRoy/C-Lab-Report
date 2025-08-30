/*Program to find the factorial of any given number.  Write codes for both 
with and with user defined function. */

#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;
void calculateFact(int n){
    long long fact=1;
    for(int i=1;i<=n;i++){
        fact*=i;
    }
    cout<<"Factorial of given number is: "<<fact<<endl;
}
int main(){
    int choice=1;
    while(choice==1){
        int n;
        cout<<"Enter the number: ";
        cin>>n;
        if(n<0){
            cout<<"Factorial does not exists"<<endl;
            cout<<"Please enter the positon number"<<endl;
        }
        else{
            calculateFact(n);
        }
        cout << "Do you want to put new values? (1=yes, 0=no): ";
        cin>>choice;
    }
   return 0;
}