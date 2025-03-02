#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100005];  
int w[100005];  


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;

  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  
  sort(arr,arr+n);
  

  for(int i=1; i<=n; i++){
    w[i]=arr[n-i]*i;
  }

  cout<<*max_element(w+1,w+1+n);
}