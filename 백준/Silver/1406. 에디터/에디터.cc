#include <bits/stdc++.h>
using namespace std;

int main(){
    string a;
    int m;
    
    cin>>a>>m;

    list<char> L;
    for(auto c:a) L.push_back(c);
    auto cursor=L.end();
    
    for (int i = 0; i < m; i++)
    {
        char op;
        cin>>op;
        
        if(op=='P'){
            char q;
            cin>>q;
            L.insert(cursor,q);
        }
        if(op=='L') if(cursor!=L.begin()) cursor--;
        if(op=='D') if(cursor!=L.end()) cursor++;
        if(op=='B') if(cursor!=L.begin()) {cursor--; cursor=L.erase(cursor);}
    }
    for(auto c:L) cout<<c;
    
}