#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i=0;i<n-1;i++)
        for (int j=0;j<n-i-1;j++)
            if (arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
}

void insertionSort(int arr[], int n) {
    for (int i=1;i<n;i++) {
        int key=arr[i],j=i-1;
        while(j>=0 && arr[j]>key) arr[j+1]=arr[j--];
        arr[j+1]=key;
    }
}

int partition(int arr[], int low, int high) {
    int pivot=arr[high], i=low-1;
    for(int j=low;j<high;j++)
        if(arr[j]<pivot) swap(arr[++i],arr[j]);
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high) {
    if(low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

void display(int arr[], int n){
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int n,arr[50],ch;
    cout<<"Enter size: ";cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"1.Bubble 2.Insertion 3.Quick Sort: ";
    cin>>ch;
    if(ch==1) bubbleSort(arr,n);
    else if(ch==2) insertionSort(arr,n);
    else quickSort(arr,0,n-1);
    cout<<"Sorted: "; display(arr,n);
}
