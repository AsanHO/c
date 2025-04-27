/*
19.multiple_ptr_dynamic_n_dimension_arr
*/
#include <iostream>

using namespace std;

int main() {
    int *ptr = nullptr;
    int **ptrptr = nullptr;
    int ***ptr3 = nullptr;
    int ****ptr4 = nullptr;
    int *****ptr5 = nullptr;
    int ******ptr6 = nullptr;
    // ?????

    int value = 5;

    ptr = &value;
    ptrptr = &ptr;

    cout << ptr << " " << *ptr << " " << &ptr << endl;
    cout << ptrptr << " " << *ptrptr << " " << &ptrptr << endl;
    cout << **ptrptr << endl;

    // 언제 쓰는가? 교과서적인 2차원 행렬을 구현할 때 자주 사용한다.

    const int row = 3;
    const int col = 5;

    const int arr[row][col] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
    };

    int *r1 = new int[col]{1, 2, 3, 4, 5};
    int *r2 = new int[col]{6, 7, 8, 9, 10};
    int *r3 = new int[col]{11, 12, 13, 14, 15};

    int **matrix = new int *[row] { r1, r2, r3 };

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    delete[] matrix;
    delete[] r1;
    delete[] r2;
    delete[] r3;

    int *matrix2 =
        new int[row * col]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << i << " " << col << " " << j << " ";
            cout << i * col + j << " ";
            cout << matrix2[i * col + j] << " ";
            cout << endl;
        }
    }
}