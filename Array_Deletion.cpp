//Array Deletion by Adit Ghosh 2401350016
//Date: 20 August 2025

#include <iostream>
#include <String>
using namespace std;

int main() {
    int n, pos;

    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[100]; // assuming max size 100 for simplicity

    cout << "Enter " << n << " elements: ";
    cout<<endl;
    for (int i = 0; i < n; i++) {
        cout<<"Element "<<i<<": ";
        cin >> arr[i];
    }

    cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Enter the position (1 to " << n << ") to delete: ";
    cin >> pos;

    if (pos < 1 || pos > n) {
        cout << "Invalid position!" << endl;
    } else {
        // shifting elements left
        for (int i = pos - 1; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--; // reduce array size

        cout << "Array after deletion: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
