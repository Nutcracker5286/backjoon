#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int cnt=0;
    cin>>n;

    while(n--){
        string s;
        stack<char> word;
        cin>>s;
        word.push(s[0]);


        for (int i = 1; i < s.size(); i++)
        {
            if(!word.empty() && s[i]==word.top()) word.pop();
            else
                word.push(s[i]);
        }

        if(word.empty()) cnt++;
        
    }

    cout<<cnt;

}