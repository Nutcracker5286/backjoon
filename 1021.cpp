#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    int cnt=0;
    cin>>n>>m;

    deque<int> s;

    for (int i = 1; i <= n; i++)
    {
        s.push_back(i);
    }
    
    while (m--)
    {
        int t;
        cin>>t;
        int idx=find(s.begin(), s.end(), t)-s.begin();
        while (s.front()!=t)
        {//왼쪽이동
            if(idx<=(int)s.size()/2){
                s.push_back(s.front());
                s.pop_front();
            }
        //오른쪽이동
            else{
                s.push_front(s.back());
                s.pop_back();
            }
            cnt++;
        }
        s.pop_front();
        
    }
    cout<<cnt;
}