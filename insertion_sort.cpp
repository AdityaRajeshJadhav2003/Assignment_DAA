#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  vector<int> v;
  cout<<"Enter the number of elements : ";
  cin>>n;
  cout<<"Enter the elements : ";
  for(int i = 0; i<n; i++){
    int x;
    cin>>x;
    v.push_back(x);
  }

  for(int i = 1; i<n; i++){
    int curr =  v[i];
    int j = i-1;
    while(v[j] > curr && j>=0){
      v[j+1] = v[j];
      j--;
    }
    v[j+1] = curr;
  }
  cout<<"The sorted array is : ";
  for(auto x: v){
    cout<<x<<" ";
  }
  cout<<endl;
  return 0;
}