/*Calculate the value of log⁡(1+𝑥) using its series for some 
given 𝑥 using WHILE or DO WHILE condition. */

#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;
void logFunction(double x,int n){
    double y=1+x;
    double v=(y-1)/(y+1);
    double sum=0.0,p=v;
    sum=p; //first term
    for(int i=3;i<=2*n-1;i+=2){
        p*=v*v;
        sum+=p/i;
    }
    double error = abs(log10(y) - 2 * sum / log(10));
    cout << fixed << setprecision(10);
    cout<<"The actual value of log(1+x) using standard library is: "<<log10(y)<<endl;
    cout<<"Error= "<<error<<endl;
    cout<<"The approximate value of log(1+"<<x<<")= "<<2*sum/log(10)<<endl;
}
int main(){
     int n;
    double x;
    int choice=1;
    while(choice==1){
        cout<<"Enter the number of term(n>0: ";
        cin>>n;
        cout<<"Enter the value of x(x>=0) for log(1+y) series: ";
        cin>>x;
        logFunction(x,n);
        cout << "Do you want to put new values? (1=yes, 0=no): ";
        cin>>choice;
    }
   return 0;
}