#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll arr[100005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;

  for(int i=0; i<n; i++)
  cin>>arr[i];

  sort(arr,arr+n);


  int curCnt=1;
  int maxCnt=1;
  ll maxNum=arr[0];
  for(int i=1; i<n; i++){
    if(arr[i-1]==arr[i]){
        curCnt++;
    }
    else{
      curCnt=1;
    }

    if(curCnt> maxCnt || (curCnt==maxCnt&& arr[i]<= maxNum)){
      maxCnt=curCnt;
      maxNum=arr[i];
    }
  }

  cout<<maxNum;
}