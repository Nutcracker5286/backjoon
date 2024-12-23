#include<bits/stdc++.h>
using namespace std;

int n, m;
bool flag[10];
int arr[10];
void solve(int t){
    if(t==m){
        for (int i = 0; i < m; i++)
        {
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if(!flag[i]){
            arr[t]=i;
            flag[i]=true;
            solve(t+1);
            flag[i]=false;

        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    solve(0);
}
