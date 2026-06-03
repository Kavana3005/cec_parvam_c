#include<iostream>
using namespace std;
int main(){
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    int *arr = new int [size];
    for (int i =0; i<size;i++){
        arr[i] = (i+1) *10;
    }
    cout<<"Array elements: ";
    for (int i =0; i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    delete [] arr;
    arr = nullptr;
    return 0;
}


    