#include <iostream>

using namespace std;

// Function prototypes
void displayMenu();
void transposeMatrix();
void inverseMatrix();
void sumOrSubtractMatrix(bool isSum);
void multiplyOrDivideMatrix(bool isMultiply);

int main()
{
    int num;
    do
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> num;

        switch (num)
        {
        case 1:
            transposeMatrix();
            break;
        case 2:
            inverseMatrix();
            break;
        case 3:
            sumOrSubtractMatrix(true);
            break;
        case 4:
            sumOrSubtractMatrix(false);
            break;
        case 5:
            multiplyOrDivideMatrix(true);
            break;
        case 6:
            multiplyOrDivideMatrix(false);
            break;
        case 0:
            cout << " --------------- " << endl;
            cout << "|   Thank you   |" << endl;
            cout << " --------------- " << endl;
            break;
        default:
            cout << " ----------------" << endl;
            cout << "| Invalid choice |" << endl;
            cout << " ----------------" << endl;
        }
    } while (num != 0);

    return 0;
}

void displayMenu()
{
    cout << " --------------------------------" << endl;
    cout << "| 1. Transpose for square matrix |" << endl;
    cout << "| 2. Inverse                     |" << endl;
    cout << "| 3. Sum                         |" << endl;
    cout << "| 4. Subtract                    |" << endl;
    cout << "| 5. Multiplication              |" << endl;
    cout << "| 6. Division                    |" << endl;
    cout << "| 0. Exit                        |" << endl;
    cout << " --------------------------------" << endl;
    cout << endl;
}

void transposeMatrix()
{
    int n;
    cout << "Enter Matrix size (only one number): ";
    cin >> n;
    int arr[n][n];
    cout << "Enter the elements of the " << n << "x" << n << " matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "Transpose Matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
}

void inverseMatrix()
{
    int num2;
    do
    {
        cout << " ---------------" << endl;
        cout << "| 1. 2x2 Matrix |" << endl;
        cout << "| 2. 3x3 Matrix |" << endl;
        cout << " ---------------" << endl;
        cout << "Enter your choice: ";
        cin >> num2;
        cout << endl;
        if (num2 == 1)
        {
            // Identify variables
            double m[2][2];
            double determinant = 0;
            cout << "Enter the elements of the 2x2 matrix:" << endl;
            // Input matrix elements
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    cin >> m[i][j];
                }
            }
            // Calculating determinant
            determinant = (m[0][0] * m[1][1]) - (m[0][1] * m[1][0]);

            if (determinant == 0)
            {
                cout << "Inverse does not exist. Determinant is zero.";
                return;
            }
            // Finding adj of matrix & transpose adj
            double temp = m[0][0];
            m[0][0] = m[1][1];
            m[1][1] = temp;
            m[0][1] = -1 * m[0][1];
            m[1][0] = -1 * m[1][0];
            // Output inverse
            cout << "Inverse of the matrix is:" << endl;
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    cout << (m[i][j] / determinant) << " ";
                }
                cout << endl;
            }
        }
        else if (num2 == 2)
        {
            // Identify variables
            double m[3][3];
            double A_c[3][3];
            double determinant = 0;
            cout << "Enter the elements of the 3x3 matrix:" << endl;
            // Input matrix elements
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cin >> m[i][j];
                }
            }
            // Calculating determinant
            determinant = (m[0][0] * ((m[1][1] * m[2][2]) - (m[1][2] * m[2][1]))) -
                          (m[0][1] * ((m[1][0] * m[2][2]) - (m[1][2] * m[2][0]))) +
                          (m[0][2] * ((m[1][0] * m[2][1]) - (m[1][1] * m[2][0])));

            if (determinant == 0)
            {
                cout << "Inverse does not exist. Determinant is zero.";
                return;
            }
            // Finding A_c of matrix & transpose A_c
            A_c[0][0] = (m[1][1] * m[2][2]) - (m[1][2] * m[2][1]);
            A_c[0][1] = (m[0][2] * m[2][1]) - (m[0][1] * m[2][2]);
            A_c[0][2] = (m[0][1] * m[1][2]) - (m[0][2] * m[1][1]);

            A_c[1][0] = (m[1][2] * m[2][0]) - (m[1][0] * m[2][2]);
            A_c[1][1] = (m[0][0] * m[2][2]) - (m[0][2] * m[2][0]);
            A_c[1][2] = (m[0][2] * m[1][0]) - (m[0][0] * m[1][2]);

            A_c[2][0] = (m[1][0] * m[2][1]) - (m[1][1] * m[2][0]);
            A_c[2][1] = (m[0][1] * m[2][0]) - (m[0][0] * m[2][1]);
            A_c[2][2] = (m[0][0] * m[1][1]) - (m[0][1] * m[1][0]);
            // Output inverse
            cout << "Inverse of the matrix is:" << endl;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cout << (A_c[i][j] / determinant) << " ";
                }
                cout << endl;
            }
        }
        else
        {
            cout << " ----------------" << endl;
            cout << "| Invalid choice |" << endl;
            cout << " ----------------" << endl;
        }
    } while (num2 != 1 && num2 != 2);
}

void sumOrSubtractMatrix(bool isSum)
{
    cout << endl;
    if (isSum == 1)
    {
        int r1, c1;
        int r2, c2;
        cout << "Enter Size of first matrix: ";
        cin >> r1 >> c1;
        cout << "Enter Size of second matrix: ";
        cin >> r2 >> c2;
        if (r1 != r2 || c1 != c2)
        {
            cout << "The summation does not exist. Two matrix have different size" << endl;
            return;
        }
        double arr1[r1][c1];
        double arr2[r2][c2];
        cout << "Enter the elements of first matrix " << r1 << "x" << c1 << " : " << endl;
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                cin >> arr1[i][j];
            }
        }
        cout << "Enter the elements of second matrix " << r2 << "x" << c2 << " : " << endl;
        for (int i = 0; i < r2; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                cin >> arr2[i][j];
            }
        }
        cout << "The summation of two matrices: " << endl;
        for (int i = 0; i < r2; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                cout << arr1[i][j] + arr2[i][j] << " ";
            }
            cout << endl;
        }
    }
    if (isSum == 0)
    {
        int r1, c1;
        int r2, c2;
        cout << "Enter Size of first matrix: ";
        cin >> r1 >> c1;
        cout << "Enter Size of second matrix: ";
        cin >> r2 >> c2;
        if (r1 != r2 || c1 != c2)
        {
            cout << "The subtraction does not exist. Two matrix have different size" << endl;
            return;
        }
        double arr1[r1][c1];
        double arr2[r2][c2];
        cout << "Enter the elements of first matrix " << r1 << "x" << c1 << " : " << endl;
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                cin >> arr1[i][j];
            }
        }
        cout << "Enter the elements of second matrix " << r2 << "x" << c2 << " : " << endl;
        for (int i = 0; i < r2; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                cin >> arr2[i][j];
            }
        }
        cout << "The subtraction of two matrices: " << endl;
        for (int i = 0; i < r2; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                cout << arr1[i][j] - arr2[i][j] << " ";
            }
            cout << endl;
        }
    }
}

void multiplyOrDivideMatrix(bool isMultiply)
{
    if (isMultiply == 1)
    {
        int r1, c1;
        cout << "Enter Size of first matrix: ";
        cin >> r1 >> c1;
        int r2, c2;
        cout << "Enter Size of second matrix: ";
        cin >> r2 >> c2;
        if (c1 != r2)
        {
            cout << "The multiplication does not exist. colum(1) not equal row(2) " << endl;
            return;
        }
        int A[r1][c1];
        int B[r2][c2];
        int C[r1][c2] = {0};
        cout << "Enter the elements of first matrix " << r1 << "x" << c1 << " : " << endl;
        for (int j = 0; j < r1; j++)
        {
            for (int k = 0; k < c1; k++)
            {
                cin >> A[j][k];
            }
        }
        cout << "Enter the elements of second matrix " << r2 << "x" << c2 << " : " << endl;
        for (int j = 0; j < r2; j++)
        {
            for (int k = 0; k < c2; k++)
            {
                cin >> B[j][k];
            }
        }
        // Perform matrix multiplication
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                for (int k = 0; k < r2; k++)
                {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        // The result
        cout << "The multiplication of two matrices: " << endl;
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                cout << C[i][j] << " ";
            }
            cout << endl;
        }
    }
    if (isMultiply == 0)
    {
        int r1, c1;
        cout << "Enter Size of first matrix: ";
        cin >> r1 >> c1;
        int r2, c2;
        cout << "Enter Size of second matrix: ";
        cin >> r2 >> c2;
        if (c1 != r2)
        {
            cout << "The divided does not exist. colum(1) not equal row(2)" << endl;
            return;
        }
        double A[r1][c1];
        double B[r2][c2];
        double C[r1][c2] = {0};
        cout << "Enter the elements of first matrix " << r1 << "x" << c1 << " : " << endl;
        for (int j = 0; j < r1; j++)
        {
            for (int k = 0; k < c1; k++)
            {
                cin >> A[j][k];
            }
        }
        cout << "Enter the elements of second matrix " << r2 << "x" << c2 << " : " << endl;
        for (int j = 0; j < r2; j++)
        {
            for (int k = 0; k < c2; k++)
            {
                cin >> B[j][k];
            }
        }
        // Perform matrix divided
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                for (int k = 0; k < r2; k++)
                {
                    C[i][j] += A[i][k] / B[k][j];
                }
            }
        }
        // The result
        cout << "The divided of two matrices: " << endl;
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                cout << C[i][j] << " ";
            }
            cout << endl;
        }
    }
}