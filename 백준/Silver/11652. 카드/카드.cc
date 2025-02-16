#include <bits/stdc++.h>
using namespace std;


long long arr[100005];
int cnt[100005];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  int ans=0;

  cin>>n;
  
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  sort(arr,arr+n);

  long long maxNum=arr[0];
  int maxCnt=1;
  int curCnt=1;

  for(int i = 1; i < n; i++){
    if(arr[i] == arr[i-1]){
        curCnt++;
    } else {
        curCnt = 1;
    }
    
    // 현재 카운트가 최대 카운트보다 크거나
    // 카운트가 같은데 현재 숫자가 더 작은 경우 업데이트
    if(curCnt > maxCnt || (curCnt == maxCnt && arr[i] < maxNum)){
        maxCnt = curCnt;
        maxNum = arr[i];
    }
}

cout << maxNum;
return 0;
}