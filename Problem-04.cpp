/*Calculate the value of cos(x) using its series for some 
given 𝑥 using WHILE or DO WHILE condition. */

#include<iostream>
#define _USE_MATH_DEFINES
#include<cmath>
#include <iomanip>
using namespace std;
void coseFunction(double x,int n){
    n--;
    x=x*(M_PI/180);
    double fact=1,sum=1;
    int i=1;
    if(n>0){
        do{
            fact*=(2*i)*(2*i-1);
            sum+=pow(-1,i)*pow(x,2*i)/fact;
            i++;
        }
        while(i<=n);
    }

    cout << fixed << setprecision(10);
    cout<<"The value of cos("<<x<<") is:"<<sum<<endl;
}
int main(){
    int n;
    double x;
    int y=1;
    while(y==1){
        cout<<"Enter the number of term(n>0)"<<endl;
        cin>>n;
        cout<<"Enter the value of x in degree."<<endl;
        cin>>x;
        coseFunction(x,n);
        cout << "Do you want to put new values? (1=yes, 0=no): ";
        cin>>y;
    }
   return 0;
}