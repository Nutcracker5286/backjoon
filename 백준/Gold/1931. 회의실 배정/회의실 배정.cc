#include <bits/stdc++.h>
using namespace std;

int n,ans;
pair<int, int> a[100005];
// {종료,시작}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;

  for(int i=0; i<n; i++)
  cin>>a[i].second>>a[i].first;

  sort(a,a+n);

  int curT=0;
  for(int i=0; i<n; i++){
    if(curT <= a[i].second){
      curT=a[i].first;
      ans++;
    }
  }

  cout<<ans;
}