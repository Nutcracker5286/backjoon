#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        string s;
        stack<char> L;
        bool tf=true;
        getline(cin, s);
        if(s==".") break;

        for(auto c:s){
            if(c=='[' || c=='('){
                L.push(c);
            }
            else if(c==']'){
                if(L.empty() || L.top()!='['){
                    tf= false;
                    break;
                }
                L.pop();
            }
            else if(c==')'){
                if(L.empty() || L.top()!='('){
                    tf= false;
                    break;
                }
                L.pop();
            }
        }
        if(!L.empty()) tf=false;
        
        if(tf) cout<<"yes\n";
        else cout<<"no\n";
}
}