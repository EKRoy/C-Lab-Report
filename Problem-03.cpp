#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;
#define pi 3.1416
void sineFunction(double x,int n){
    n--;
    x=x*(pi/180);
    double fact=1,sum=x;
    int i=1;
    while(i<=n){
        fact=fact*(2*i+1)*(2*i);
        sum+=pow(-1,i)*pow(x,2*i+1)/fact;
        i++;
    }
    cout << fixed << setprecision(10);
    cout<<"The value of sinx is:"<<sum<<endl;
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
        sineFunction(x,n);
        cout << "Do you want to put new values? (1=yes, 0=no): ";
        cin>>y;
    }
   return 0;
}