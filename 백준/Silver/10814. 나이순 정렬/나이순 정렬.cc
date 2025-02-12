#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, string> a,pair<int, string> b){

  return a.first< b.first;

}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  vector<pair<int, string>> arr;
  cin>>n;

  for(int i=0; i<n; i++){
    int x; string y;
    cin>>x>>y;
    arr.push_back({x,y});
  }

  stable_sort(arr.begin(),arr.end(),cmp);

  for(int i=0; i<n; i++){
    cout<<arr[i].first<<" "<<arr[i].second<<'\n';
  }
}