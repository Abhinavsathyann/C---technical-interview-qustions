#include <iostream>
using namespace std;

int main() {
    int a[3][3], b[3][3], sum[3][3];
    cout << "Enter 3x3 matrix A:\n";
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            cin >> a[i][j];
    cout << "Enter 3x3 matrix B:\n";
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            cin >> b[i][j];
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            sum[i][j] = a[i][j] + b[i][j];
    cout << "Sum of matrices:\n";
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++)
            cout << sum[i][j] << " ";
        cout << endl;
    }
}
