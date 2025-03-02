#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n,ans;
pair<int,int> a[100005];
pair<int,int> d[100005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;

// {종료, 시작}
// 입력은 {시작, 종료}
  for(int i=1; i<=n; i++){
    cin>>a[i].Y>>a[i].X;
  }

  sort(a+1,a+1+n);

  int curT=a[1].X; ans++;
  for(int i=2; i<=n; i++){
    if(a[i].Y >= curT){
      ans++;
      curT=a[i].X;
    }
  }
  cout<<ans;
}