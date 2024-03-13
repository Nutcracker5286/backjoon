#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[10];
int num[10];
bool issused[10];

void solve(int t, int before_num){
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
        if(!issused[i] && before_case !=num[i] && before_num<=num[i]){ 
            issused[i]=1;
            before_case=arr[t]=num[i];
            solve(t+1,arr[t]);
            issused[i]=0;
        }
    }
    
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;

    for (int i = 0; i < n; i++)
    {
        cin>>num[i];
    }
    sort(num, num+n);
    solve(0,0);
    
}