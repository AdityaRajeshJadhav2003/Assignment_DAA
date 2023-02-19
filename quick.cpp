#include<bits/stdc++.h>
#define ll long long
using namespace std;
void quicksort(int nums[],int low,int high){
    if(low>=high) return;
    int s = low ,e = high;
    int mid = s + (e-s)/2;
    while(s<=e){
        while(nums[s]<nums[mid]){
            s++;
        }
        while(nums[e]>nums[mid]){
            e--;
        }
        if(s<=e){
            int temp = nums[s];
            nums[s] = nums[e];
            nums[e] = temp;
            s++;
            e--;
        }
    }
    quicksort(nums,low,e);
    quicksort(nums,s,high);
}
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int nums[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    quicksort(nums,0,n-1);
    cout<<"Sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
return 0;
}
/*
Output:
Enter the size of the array: 10
Enter the elements of the array: 100 98 87 65 54 36 25 14 10 1
Sorted array is: 1 10 14 25 36 54 65 87 98 100 
*/