#include <bits/stdc++.h>
using namespace std;


int n;
int a[1005];
int d[1005];
int pre[1005];


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;

  fill(d,d+n,1);
  for(int i=0; i<n; i++)
  cin>>a[i];


  for(int i=0; i<n; i++){
    for(int j=0; j<i; j++){
      if(a[i]<=a[j]) continue;
      if(d[i]>=d[j]+1) continue;
      d[i]=d[j]+1; pre[i]=j;
    }
  }

  int mx=1;
  int ansIdx=0;
  for(int i=0; i<n; i++){
    if(mx > d[i]) continue;
    mx=d[i]; ansIdx=i;
  }

  stack<int> st;
  int idx=0;
  for(int i=ansIdx; idx<mx; i=pre[i]){
    st.push(a[i]); idx++;
  }
  
  cout<<mx<<'\n';
  for(int i=0; i<mx; i++)
  {
    cout<<st.top()<<' '; st.pop();
  }




}