#include <bits/stdc++.h>
using namespace std;

int n;
long long d[100];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;

  d[1]=1;
  for(int i=2; i<=n; i++)
  d[i]=d[i-1]+d[i-2];
  cout<<d[n];
}