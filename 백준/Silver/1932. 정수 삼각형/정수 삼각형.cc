#include <bits/stdc++.h>
using namespace std;

int n;
int d[505][1005];
int tr[505][1005];


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;
  for(int i=0; i<n; i++){
    int st=n-i-1;
    for(int j=0; j<i+1; j++){
      cin>>tr[i][st];
      st+=2;
    }
  }

  d[0][n-1]=tr[0][n-1];
  for(int i=1; i<n; i++){
    int st=n-i-1;
    for(int j=0; j<i+1; j++){
      d[i][st]=max(d[i-1][st-1], d[i-1][st+1])+tr[i][st];
      st+=2;
    }
  }

  cout<<*max_element(d[n-1],d[n-1]+2*n-1);
}