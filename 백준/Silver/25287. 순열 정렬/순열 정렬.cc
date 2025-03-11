



#include <bits/stdc++.h>
using namespace std;


int t;
int n;
int a[50005];


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
 
  while(t--){
    cin>>n;
    for(int i=0; i<n; i++){
      cin>>a[i];
    }
    int cur=a[0]> a[1]?n-a[0]+1:a[0];
    
    bool isP=1;
    for(int i=1; i<n; i++){
      if(cur <= a[i]){
        if(cur <= n-a[i]+1)
          cur=min(a[i],n-a[i]+1);
        else
          cur=a[i];
      }
      else{
        if(cur <= n-a[i]+1)
          cur=n-a[i]+1;
        else{
          isP=0;
          break;
        }
          
      }
    }

    if(isP)
      cout<<"YES"<<'\n';
    else
      cout<<"NO"<<'\n';
  }


}