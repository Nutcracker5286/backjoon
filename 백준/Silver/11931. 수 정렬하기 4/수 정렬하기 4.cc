#include<bits/stdc++.h>
using namespace std;

int arr[1000005];
int tmp[1000005];
int n;

void merge(int st, int en){
  int mid=(st+en)/2;

  int leftIdx=st;
  int rightIdx=mid;
  for(int i=st; i<en; i++){
    if(leftIdx==mid) tmp[i]=arr[rightIdx++];
    else if(rightIdx==en) tmp[i]=arr[leftIdx++];
    else if(arr[leftIdx]>=arr[rightIdx]) tmp[i]=arr[leftIdx++];
    else tmp[i]=arr[rightIdx++];
  }
  for(int i=st; i<en; i++) arr[i]=tmp[i];
}


void merge_sort(int st, int en){
  if(en==st+1) return;
  int mid=(st+en)/2;

  merge_sort(st,mid);
  merge_sort(mid,en);
  merge(st,en);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;
  for(int i=0; i<n; i++) cin>>arr[i];

  merge_sort(0,n);
  for(int i=0; i<n; i++) cout<<arr[i]<<'\n';
}