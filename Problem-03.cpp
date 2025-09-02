/*Calculate the value of sinx  using its series for some 
   given 𝑥 using WHILE or DO WHILE condition. */
#include<iostream>
#define _USE_MATH_DEFINES
#include<cmath>
#include <iomanip>
using namespace std;
void coseFunction(double x,int n){
    n--;
    x=x*(M_PI/180);
    double fact=1,sum=x;
    int i=1;
    while(i<=n){
        fact=fact*(2*i+1)*(2*i);
        sum+=pow(-1,i)*pow(x,2*i+1)/fact;
        i++;
    }
    cout << fixed << setprecision(10);
    cout<<"The value of sin("<<x<<") is:"<<sum<<endl;
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