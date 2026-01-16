#include <iostream>

using namespace std;


struct info{
  int s, y;
};

int main()
{
  int n, k, W, M;
  info gm[1001];
  int m[7]={0};
  int w[7]={0};
  int ans=0;
  cin>>n>>k;
  for(int i=0; i<n; i++)
  {
    cin>>gm[i].s>>gm[i].y;
  }

   for(int i=0; i<n; i++)
  {
    if(gm[i].s==0) w[gm[i].y]++;
    if(gm[i].s==1) m[gm[i].y]++;
  }

   for(int i=1; i<7; i++)
  {
    W=w[i]%k;
    if(W==0) ans=w[i]/k+ans;
    else ans=w[i]/k+1+ans;
  }

   for(int i=1; i<7; i++)
  {
    M=m[i]%k;
    if(M==0) ans=m[i]/k+ans;
    else ans=m[i]/k+1+ans;
  }

  cout<<ans;


}