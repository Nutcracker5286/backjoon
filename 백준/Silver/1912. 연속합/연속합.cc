#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100005];
int d[100005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;

  for(int i=1; i<=n; i++)
  cin>>arr[i];

  for(int i=1; i<=n; i++){
    d[i]=max(d[i-1]+arr[i],arr[i]);
  }

  cout<<*max_element(d+1,d+1+n);
}