#include <bits/stdc++.h>
using namespace std;

int L,C;
char arr[20];
char str[20];
bool check;
int cnt;
bool str_check(char target){
    if(target=='a')
    return true;
    else if(target=='i')
    return true;
    else if(target=='o')
    return true;
    else if(target=='u')
    return true;
    else if(target=='e')
    return true;
    else return false;
}
void solve(int t, int st){
    if(t==L){
        if(check && cnt>=2){
        for (int i = 0; i < L; i++)
        {
            cout<<arr[i];
        }
        cout<<'\n';
        
        return;}
        
    }
    char st_alp='a'-1;
    for (int i = st; i <= C; i++)
    {
        
        if(st_alp<str[i])
        {
            st_alp=str[i];
            if(str_check(str[i])) check=true;
            else cnt++;
            arr[t]=str[i];
            solve(t+1,i+1);
            check=false;
            if(str_check(str[i])) check=false;
            else cnt--;
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>L>>C;
    for (int i = 0; i < C; i++)
    {
        cin>>str[i];
    }
    sort(str,str+C);
    solve(0,0);
    
}