#include<bits/stdc++.h>
using namespace std;

int num[15];
int arr[15];
int k;


void solve(int t, int st){
    if(t==6){
        for (int i = 0; i < 6; i++)
        {
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for (int i = st; i < k; i++)
    {
        arr[t]=num[i];
        solve(t+1,i+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        cin>>k;
        if(k==0) 
            break;
        for (int i = 0; i < k; i++)
        {
            cin>>num[i];
        }
        solve(0,0);
        cout<<'\n';
    }
    
}

