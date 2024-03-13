#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[10];
int num[10];
void solve(int t){
    if(t==m){
        for (int i = 0; i < m; i++)
        {
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    int before_case=0;
    for (int i = 0; i < n; i++)
    {
        if(before_case!=num[i]){
            arr[t]=num[i];
            before_case=num[i];
            solve(t+1);
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
    solve(0);
}