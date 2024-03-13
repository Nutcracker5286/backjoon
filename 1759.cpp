#include <bits/stdc++.h>
using namespace std;

int L, C;
int spell[2];
char str[30];
char arr[30];
bool ch_vow(char s){
    if(s=='a') return true;
    else if(s=='e') return true;
    else if(s=='i') return true;
    else if(s=='o') return true;
    else if(s=='u') return true;
    else return false;
}
void solve(int t, int cur){
    if(t==L){
        if(spell[0]>=1 && spell[1]>=2){
            for (int i = 0; i < L; i++)
            {
                cout<<arr[i];
            }
            cout<<'\n'; return;
        }
    }
    for (int i = cur; i < C; i++)
    {
        if(ch_vow(str[i])) spell[0]++;
        else spell[1]++;
        arr[t]=str[i];
        solve(t+1,i+1);
        if(ch_vow(str[i])) spell[0]--;
        else spell[1]--;        
    }
    
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>L>>C;

    for (int i = 0; i < C; i++)
    {
        cin>>str[i];
    }
    sort(str,str+C);
    // for(auto c: str) cout<<c<<" ";
    solve(0,0);
}