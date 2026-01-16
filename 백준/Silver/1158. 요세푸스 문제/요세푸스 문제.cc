#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> L;
    int N, K,cnt;
    cin >> N >> K;
    cnt=N;

    for (int i = 1; i <= N; i++)
    {
        L.push_back(i);
    }

    auto p = L.begin();
    cout<<"<";
    while (N--)
    {
        for (int j = 0; j < K; j++)
        // k번째 숫자 제거
        {
            if (p != L.end())
                p++;
            else
                {p = L.begin(); p++;}
        }
        p--;
        if(L.size()==1) cout<<*p<<">";
        else cout<<*p<<", ";
        
        cnt--;
        p=L.erase(p);
    }
}