#include<bits/stdc++.h>
using namespace std;

int n, m;
int num[10];
int arr[10];

void solve(int t, int bef){
    if(t==m){
        for (int i = 0; i < m; i++)
        {
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return ;
    }
    int befor_case=0;
    for (int i = 0; i < n; i++)
    {
        if(befor_case !=num[i] && bef<=num[i]){
            arr[t]=num[i];
            befor_case=num[i];
            solve(t+1,arr[t]);
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    int max=0;
    for (int i = 0; i < n; i++)
    {
        cin>>num[i];
        

    }
    sort(num,num+n);
    solve(0,0);
}