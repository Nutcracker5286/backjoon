#include <bits/stdc++.h>
using namespace std;

int n;
int a[3][100005];
int d[3][100005];


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin>>t;

  while (t--)
  {

   
    cin>>n;

    for(int i=1; i<=2; i++){
      for(int j=1; j<=n; j++){
        a[i][j]=d[i][j]=0;
      }
    }

    for(int i=1; i<=2; i++){
      for(int j=1; j<=n; j++){
        cin>>a[i][j];
      }
    }

    
    d[1][1]=a[1][1];
    d[2][1]=a[2][1];
    d[1][2]=a[2][1]+a[1][2];
    d[2][2]=a[1][1]+a[2][2];


    for(int i=3; i<=n; i++){
     d[1][i]=max({d[1][i-2],d[2][i-2],d[2][i-1]})+a[1][i];
     d[2][i]=max({d[1][i-2],d[2][i-2],d[1][i-1]})+a[2][i];
    }

    int ans=0;
    for(int i=1; i<=2; i++){
      for(int j=1; j<=n; j++){
        ans=max(ans,d[i][j]);
      }
    }

    cout<<ans<<'\n';
  }
  
}