#include <bits/stdc++.h>
using namespace std;

int n;
long long d[1005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;
  d[1]=1; 
  d[2]=2; 
  for(int i=3; i<=n; i++){
    if(d[i-1]+d[i-2]>10007){
      d[i]=(d[i-1]+d[i-2])%10007;
    }
    else
    d[i]=d[i-1]+d[i-2];
  }
  

    cout<<d[n]%10007;
}