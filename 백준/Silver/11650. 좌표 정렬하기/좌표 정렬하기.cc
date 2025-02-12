#include <bits/stdc++.h>
using namespace std;


bool cmp(pair<int, int> a, pair<int, int> b){
  return a.second<b.second;
}

bool cmp1(pair<int, int> a, pair<int, int> b){
  return a.first<b.first;
}

int n;
pair<int, int> co[100005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;

  for(int i=0; i<n; i++){
    cin>>co[i].first>>co[i].second;
  }

  sort(co,co+n,cmp);
  stable_sort(co,co+n,cmp1);

  for(int i=0; i<n; i++){
   cout<<co[i].first<<' '<<co[i].second<<'\n';
  }
}