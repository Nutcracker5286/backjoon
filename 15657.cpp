#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[10];
vector<int> a;

void solve(int t, int bef){
    if(t==m){
        for (int i = 0; i < m; i++)
        {
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(auto c: a){
        if(bef>c) 
            continue;
        arr[t]=c;
        solve(t+1, c);
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        int tmp; cin>>tmp; a.push_back(tmp);
    }
    sort(a.begin(), a.end());
    
    solve(0,0);
}