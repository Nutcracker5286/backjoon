#include <bits/stdc++.h>
using namespace std;

int n;
int d[45][3];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin>>t;


  d[0][0]=1; d[0][1]=0;
  d[1][0]=0; d[1][1]=1;
  d[2][0]=1; d[2][1]=1;
    for(int i=3; i<=40; i++){
      d[i][0]=d[i-1][0]+d[i-2][0];
      d[i][1]=d[i-1][1]+d[i-2][1];
    }
  while(t--){
    cin>>n;
    cout<<d[n][0]<<" "<<d[n][1]<<'\n';
  }
}