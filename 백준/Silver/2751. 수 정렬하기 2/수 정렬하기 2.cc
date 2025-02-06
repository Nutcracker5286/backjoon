#include <bits/stdc++.h>
using namespace std;

int n;
int ans[1000005];
int tmp[1000005];


void merge(int st, int en){
  int mid = (st+en)/2;

  int leftIdx=st;
  int rightIdx=mid;

  for(int i=st; i<en; i++){
    if(leftIdx==mid) tmp[i]=ans[rightIdx++];
    else if(rightIdx==en) tmp[i]=ans[leftIdx++];
    else if(ans[leftIdx]<= ans[rightIdx]) tmp[i]=ans[leftIdx++];
    else tmp[i]=ans[rightIdx++];
  }
  for(int i=st; i<en; i++)
    ans[i]=tmp[i];

}


void merge_sort(int st, int en){
  if(st+1==en) return;
  int mid=(st+en)/2;
  merge_sort(st,mid);
  merge_sort(mid, en);
  merge(st,en);
}


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  
  for(int i=0; i<n; i++)
  cin>>ans[i];
  
  merge_sort(0,n);
  
  for(int i=0; i<n; i++)
  cout<<ans[i]<<'\n';
}