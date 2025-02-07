#include<bits/stdc++.h>
using namespace std;

int n;
int arr[10005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>t;
    arr[t]++;
  }

  for(int i=0; i<=10000; i++) {
    for(int j=0; j<arr[i]; j++){
      cout<<i<<'\n';
    }
  }
}