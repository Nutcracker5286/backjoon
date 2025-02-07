#include <bits/stdc++.h>
using namespace std;

int arr[10000];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);


  int t,n;

  cin>>n;

  for(int i=0; i<n; i++) {
    cin>>arr[i];
  }

  sort(arr,arr+n);

  for(int i=0; i<n; i++) {
    cout<<arr[i]<<'\n';
  }
}