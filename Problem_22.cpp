/*Write an OOP to find the inverse of an 𝑛 × 𝑛 square matrix */

#include <iostream>
#include <iomanip>
using namespace std;

class Matrix {
    int n;                           // Size of the matrix (n x n)
    double mat[10][10];              // Fixed-size matrix (for simplicity)
    double inv[10][10];              // Fixed-size matrix to store the inverse

public:
    // Constructor to initialize the size
     void setSize(int size) {
           n = size;
        }
    void inputMatrix() {
        cout << "Enter the elements of the matrix (row-wise):\n";
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> mat[i][j];
    }

    void displayMatrix(){
        cout<<"Orginal Matrix: "<<endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }
    void displayInverseMatrix(){
        cout<<"Inverse Matrix: "<<endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout <<setprecision(4)<< inv[i][j] << " ";
            cout << endl;
        }
    }

    bool calculateInverse() {
        // Initialize the inverse matrix as the identity matrix
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) inv[i][j]=1;
                else inv[i][j]=0;
            }
        }
        // Perform Gaussian elimination
        for (int i = 0; i < n; ++i) {
            double diag = mat[i][i];
            if (diag == 0) {
                cout << "Matrix is singular and cannot be inverted.\n";
                return false;
            }

            // Normalize the current row
            for (int j = 0; j < n; ++j) {
                mat[i][j] /= diag;
                inv[i][j] /= diag;
            }

            // Eliminate other rows
            for (int k = 0; k < n; ++k) {
                if (k != i) {
                    double factor = mat[k][i];
                    for (int j = 0; j < n; ++j) {
                        mat[k][j] -= factor * mat[i][j];
                        inv[k][j] -= factor * inv[i][j];
                    }
                }
            }
        }

        return true;
    }
};
int main() {
    int n;
    cout << "Enter the size of the square matrix (max 10): ";
    cin >> n;
    
    if (n < 0 || n > 10) {
        cout << "\nInvalid matrix size.\n";
        cout<<"(Please enter 0<=n<=10)"<<endl;
        return 0;
    }
    
    Matrix matrix;
    matrix.setSize(n);
    matrix.inputMatrix();
    matrix.displayMatrix();
    if (matrix.calculateInverse()) {
        matrix.displayInverseMatrix();
    }

    return 0;
}
