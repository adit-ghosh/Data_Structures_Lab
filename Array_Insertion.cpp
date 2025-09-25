//Array Insertion by Adit Ghosh 2401350016
//Date: 13 August 2025

#include<iostream>
#include<String>

using namespace std;

void printArray(const int arr[], int size) {
    cout << "Current Array: {";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << (i == size - 1 ? "" : ", ");
    }
    cout << "}" << endl;
}

int createInitialArray(int arr[]) {
    int initialSize;
    cout << "How many elements do you want to add initially?: ";
    cin >> initialSize;

    if (initialSize > 100 || initialSize < 0) {
        cout << "Invalid number of elements. Using 0." << endl;
        return 0;
    }

    cout << "Enter " << initialSize << " elements:" << endl;
    for (int i = 0; i < initialSize; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    return initialSize;
}

void insertElements(int arr[], int& size) {
    int element;
    char continue_inserting;

    do {
        cout << "\nDo you want to insert another element? (Y/N): ";
        cin >> continue_inserting;

        if (continue_inserting == 'Y' || continue_inserting == 'y') {
            if (size >= 100) {
                cout << "Array is full. Cannot insert more elements." << endl;
                break;
            }

            cout << "Enter the element to insert: ";
            cin >> element;
            arr[size] = element;
            size++;
            printArray(arr, size);
        }

    } while (continue_inserting == 'Y' || continue_inserting == 'y');
}

int main() {
    int arr[100];
    int currentSize = createInitialArray(arr);
    
    printArray(arr, currentSize);
    
    insertElements(arr, currentSize);

    cout << "\nFinal Array: {";
    for (int i = 0; i < currentSize; i++) {
        cout << arr[i] << (i == currentSize - 1 ? "" : ", ");
    }
    cout << "}" << endl;

    return 0;
}

