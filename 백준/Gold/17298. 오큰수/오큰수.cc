#include <bits/stdc++.h>
using namespace std;

int n;
int arr[10000005];
stack<pair<int,int>> st;
stack<int> idx;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;
arr[10000004]=-1;
  for(int i=0; i<n; i++)
  cin>>arr[i];

  for(int i=n-1; i>=0; i--){
    int t=arr[i];

    while(!st.empty() && st.top().first <= t) st.pop();

    if(st.empty()){
      idx.push(10000004);
    }
    else{
    idx.push(st.top().second);
    }
    st.push({t,i});

  }

  while(!idx.empty()){
    cout<<arr[idx.top()]<<' '; idx.pop();
  }
}