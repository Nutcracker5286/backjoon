#include <bits/stdc++.h>
using namespace std;

int dist[100002];
int dir[3] = {-1, 1, 2};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    int cnt = 0;
    cin >> n >> k;
    if(n==k) {cout<<0; return 0;}
    fill(dist, dist + 100001, -1);
    queue<int> Q;
    Q.push(n);
    dist[n] = 0;

    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        int diff=100002;
        for(auto c: {cur-1,2*cur,cur+1}){
            if(c<0 || c>= 100001) continue;
            if(dist[c]>=0) continue;
            if(c==k){cout<<dist[cur]+1; return 0;}
            dist[c]=dist[cur]+1;
            Q.push(c);
        }
    }
}