#include <iostream>

using namespace std;

/*          value index
3 5 2 1 4     1     3
1 5 2 3 4     2     2
1 2 5 3 4     3     3
1 2 3 5 4     4     4
1 2 3 4 5     end
*/
void print_array(const int arr[], const int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void custom_selection_sort(int array[], int length) {
    for (int i = 0; i < length - 1; i++) {
        int min = array[i];
        int index;
        for (int j = i + 1; j < length; j++) {
            if (min > array[j]) {
                min = array[j];
                index = j;
            }
        }
        int temp = array[i];
        array[i] = min;
        array[index] = temp;
    }
}

int main() {
    const int length = 5;
    int array[length] = {3, 5, 2, 1, 4};
    print_array(array, length);
    custom_selection_sort(array, length);
    print_array(array, length);
}