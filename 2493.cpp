#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int cnt=0;
    stack<pair<int,int>> s;
    s.push({100000001,0});

// 탑의 개수
    cin>>n;

    for (int i = 1; i <= n; i++)
    {//각 탑마다 스택에 있는 숫자와 비교
        int t;
        //탑의 높이
        cin>>t;
        while (s.top().X<t)
        {
            s.pop();
        }
        cout<<s.top().Y<<" ";
        s.push({t,i});
        
    }



}