#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n; ll d[10000005];


// d[i]=자리수가 i자리인 찐이븐수의 개수
// d[1]=5
// d[2]=16
// d[i]=d[i-1]*4
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;
  d[1]=5;
  d[2]=20;
  for(int i=3; i<=10000001; i++)
  d[i]=(d[i-1]*5)%(1000000000+7);

  while(n--){
    int t;
    cin>>t;
    cout<<d[t]<<'\n';
  }
}