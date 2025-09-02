/*Write an OOP to read a matrix, display the sum of its diagonal elements, 
lower-diagonal elements and upper-diagonal elements. */
#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;
class Matrix{
    private:
        int mat[100][100];
        int n;

    public:
        void setSize(int size) {
           n = size;
        }
        void inputMatrix(){
            cout<<"Enter the elements of Matrix row_wise: ";
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cin>>mat[i][j];
                }
            }
        }
        void calculateSum(){
                int diagSum=0,lowerSum=0,upperSum=0;
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if(i==j){
                            diagSum+=mat[i][j];
                        }
                        else if(i>j){
                            lowerSum+=mat[i][j];
                        }
                        else upperSum+=mat[i][j];
                    }
                }
             cout << "\nSum of main diagonal elements: " << diagSum << endl;
             cout << "Sum of lower diagonal elements: " << lowerSum << endl;
            cout << "Sum of upper diagonal elements: " << upperSum << endl;
        }
};
int main(){
    int choice=1;
    while(choice==1){
        int n; 
        cout<<"Enter the size of square matrix: ";
        cin>>n;
        Matrix mat;
        mat.setSize(n);
        mat.inputMatrix();
        mat.calculateSum();
        cout << "Do you want to calculate another Matrix? (1=yes, 0=no): ";
        cin>>choice;
    }
   return 0;
}