// d[i]= i항이 마지막 항인 가장 긴 증부수의 길이
// for(0:n) i 결정
//  for(0:i) 테이블을 채우기 위해 탐색하는 인자
#include <bits/stdc++.h>
using namespace std;

int n;
int a[1005];
int d[1005];
int pre[1005];
int arr[1005];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;

  for(int i=0; i<n; i++){
    cin>>a[i];
    d[i]=1;
  }


  for(int i=0; i<n; i++){
    for(int j=0; j<i; j++){
      if(a[i]>a[j]){ //i항이 마지막 항이니까
        if(d[i]<d[j]+1){ //탐색길이가 더 길때
          d[i]=d[j]+1; pre[i]=j;
        }
      }
    }
  }

  int ans=0; int ans_idx;
  for(int i=0; i<n; i++){
    if(d[i]>ans){
      ans=d[i];
      ans_idx=i;
    }
  }
  cout<<ans<<'\n';

  int idx=0;
  for(int i=ans_idx; idx<ans; i=pre[i]){
    arr[idx++]=a[i];
  }
  sort(arr,arr+ans);

  for(int i=0; i<ans; i++)
  cout<<arr[i]<<" ";
  
}