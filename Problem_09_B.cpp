/*Program to find the largest and smallest number that can be formed using 
digits of a given number. Write codes for with user 
defined function. */
#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;
void largestNumber(string s,int n){
     for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(s[i]<s[j]){
                    int temp=s[i];
                    s[i]=s[j];
                    s[j]=temp;
                }
            }
        }
    cout<<"The largest number is: "<<endl;
    for(int i=0;i<n;i++){
       cout<<s[i];
     }
    cout<<endl;
}
void smallestNumber(string s,int n){
    for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(s[i]>s[j]){
                    int temp=s[i];
                    s[i]=s[j];
                    s[j]=temp;
                }
            }
        }
    cout<<"The smallest number is: "<<endl;
     for(int i=0;i<n;i++){
         cout<<s[i];
     }
     cout<<endl;
}
int main(){
    int choice=1;
    while(choice==1){
        int num;
        cout<<"Enter the number: ";
        cin>>num;
        string s=to_string(num);
        int n=0;
        while(num){
            int x=num%10;
            n++;
            num/=10;
        }
        //largest number:we need descending order of the digits
        largestNumber(s,n);
       // smallest number:we need ascending order of the digits
       smallestNumber(s,n);
        cout << "Do you want to put new values? (1=yes, 0=no): ";
        cin>>choice;
    }
   return 0;

}
