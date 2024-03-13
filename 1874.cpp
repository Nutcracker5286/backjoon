#include <bits/stdc++.h>
using namespace std;
// 크기 n의 임의 수열 입력 받고
// 스택을 이용 1~n까지 push pop 반복시 생성 할 수 있는 가 확인
// n의 임의 수열 받을 저장 공간 생성
// 1부터 n까지 저장하는 공간 생성
// 가능시 연산 횟수 보여줄 공간 생성

int main(){
    int n;
   cin>>n;

   stack<int> s;
   int cnt =1;
   string ans;
   while (n--)
   {
    int t;
    cin>>t;
    while(cnt<=t)
    {
        s.push(cnt++);
        ans+="+\n";
    }

    if(s.top()!=t){
        cout<<"NO\n";
        return 0;
    }

    s.pop();
    ans+="-\n";
   }
   cout<<ans;
   
}