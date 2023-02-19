#include<bits/stdc++.h>
#define ll long long
using namespace std;
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0,j = 0,k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void sort(int arr[], int l, int r){
    if (l < r) {
        int m = l + (r - l) / 2;
        sort(arr, l, m);
        sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int main(){
    int n,m;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int nums[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    sort(nums,0,n-1);
    cout<<"Sorted Array is : ";
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }

return 0;
}

/* Output:
Enter the size of the array: 10
Enter the elements of the array: 98 23 68 12 45 89 10 5 36 2
Sorted Array is : 2 5 10 12 23 36 45 68 89 98 

*/