#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;
bool isused[10001];
int arr[10];

void solve(int t,int bef){
    if(t==m){
        for (int i = 0; i < m; i++)
        {
            cout<<arr[i]<<' ';
        }
        cout<<'\n'; return;        
    }
    for(auto c: a){
            isused[c]=1;
            arr[t]=c;
            solve(t+1,c);
            isused[c]=0;
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