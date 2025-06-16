#include <bits/stdc++.h>
using namespace std;

int L,C;
char arr[16],ans[16];
bool isUsed[16];

bool findMo(){
    for (int i = 0; i < L; i++)
        if(ans[i] == 'a'|| ans[i] == 'i'|| ans[i] == 'o'|| ans[i] == 'u' || ans[i] == 'e')
            return true;
    return false;
     
}

bool findJa(){
    int cnt=0;
    for (int i = 0; i < L; i++)
        if(ans[i] != 'a'&& ans[i] != 'i'&& ans[i] != 'o'&& ans[i] != 'u' && ans[i] != 'e')
            cnt++;
    return cnt>=2 ? 1 : 0;
}

void solve(int k, char prev){
    if(k==L){

        if(!findMo() || !findJa()) return;
        for (int i = 0; i < L; i++)
            cout<<ans[i];
        cout<<'\n';
        return ;            
             
    }
    for(int i=0 ; i<C; i++){
        if(isUsed[i] || prev > arr[i]) continue;
        isUsed[i]=1;
        ans[k]=arr[i];
        solve(k+1, ans[k]);
        isUsed[i]=0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>L>>C;

    for(int i=0; i<C; i++)
        cin>>arr[i];
    sort(arr,arr+C);
    solve(0,'a'-1);

}



