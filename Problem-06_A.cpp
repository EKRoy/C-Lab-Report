/*06.Program to check whether any given number is prime or not.
 Write codes for both without user defined function*/

#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;
int main(){
    int choice=1;
    while(choice==1){
        int n;
        cout<<"Enter the number you check: ";
        cin>>n;
        bool isPrime=true;
        if(n==1) isPrime=false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                isPrime=false;
                break;
            }
        }
        if(isPrime){
            cout<<"The Number("<<n<<") is Prime"<<endl; 
        }
        else cout<<"The Number("<<n<<") is not Prime"<<endl;

         cout << "Do you want to put new values? (1=yes, 0=no): ";
        cin>>choice;
    }
   return 0;
}