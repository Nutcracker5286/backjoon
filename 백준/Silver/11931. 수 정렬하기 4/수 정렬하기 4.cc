#include <bits/stdc++.h>
using namespace std;


bool cmp(int a, int b){return a>b;}

int arr[10000005];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
    int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  sort(arr,arr+n, cmp);
    
    for(int i = 0; i < n; i++){
    cout<<arr[i]<<'\n';
  }
}