#include <iostream>
using namespace std;
long long int t=0,u=0;
void merge(long long int arr[], long long int l, long long int m, long long int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    long long int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0,j=0,k=l;
    while (i < n1 && j < n2) {
        if (L[i] > R[j]) {
            arr[k++] = R[j++];
            t+=n1-i;
        }
        else {
            arr[k++] = L[i++];
        }
    }
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];    }
}
void mergeSort(long long int arr[],long long int l,long long int r){
    if(l>=r){
        return;
    }
    long long int m = (l+r-1)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}
int main()
{
   long long int test, arr_size;
    cin>>test;
    while(test--){
            t=0;
            cin>>arr_size;
            long long int arr[arr_size];
            for (int i = 0; i<arr_size; i++)
                cin>>arr[i];
        mergeSort(arr, 0, arr_size - 1);
        cout<<t<<endl;}
    return 0;
}
