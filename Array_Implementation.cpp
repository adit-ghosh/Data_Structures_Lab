//Array Implimentation by Adit Ghosh 2401350016
//Date: 06 August 2025

#include<iostream>
#include<String>
using namespace std;

template <typename T>
void Array(T num){
    (int)num;
    cout<<"Enter the number of elements in the array: ";
    cin>>num;
    T arr[num];

    // Input elements
    for(int i=0; i<num ; i++){
        cout<<"Enter the "<<i<<" index element: ";
        cin>>arr[i];
    };

    //Showing Array
    cout<<"Array {";
    for(int k = 0; k<num; k++){
        cout<<arr[k];
        if(k != num-1){
            cout<<",";
        };
    }
    cout<<"}"<<endl;

    //Sum of element
    T sum = 0;
    cout<<"Sum: ";
    for(int j=0; j<num; j++){
        sum = sum+arr[j];
    };
    cout<<sum<<endl;

    //Average of element
    int avarage = (float)sum / num;
    cout<<"Average: "<<avarage<<endl;

    //Largest element
    T largest = arr[0];
    for(int l=1; l<num; l++){
        if(arr[l] > largest){
            largest = arr[l];
        };
    };
    cout<<"Largest element: "<<largest<<endl;

    //Smallest element
    T smallest = arr[0];
    for(int m=1; m<num; m++){
        if(arr[m] < smallest){
            smallest = arr[m];
        };
    }
    cout<<"Smallest element: "<<smallest<<endl;

    // Reverse the array
    cout<<"Reversed Array {";
    for(int r=num-1; r>=0; r--){
        cout<<arr[r];
        if(r != 0){
            cout<<",";
        };
    }
    cout<<"}"<<endl;

};

int main(){
    Array<int>(5);
    return 0;
};



