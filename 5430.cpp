#include<bits/stdc++.h>
using namespace std;
// R은 순서 뒤집기
// D는 pop_front

void parse(string& tmp, deque<int> &d){
    int cur=0;
    for (int i = 1; i+1 < tmp.size(); i++)
    {
        if(tmp[i]==','){
            d.push_back(cur);
            cur=0;
        }
        else{
            cur=10*cur+(tmp[i]-'0');
        }
    }
    if(cur!=0){
        d.push_back(cur);
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;

    while (t--)
    {
        string a,b;
        deque<int> dq;
        int n;
        bool info=true;
        int rev=0;

        cin>>a>>n>>b;
        parse(b,dq);
        for(auto c:a){
            if(c=='R'){
                rev=1-rev;
            }
            else if(c=='D'){
                if(!dq.empty()){
                    if(!rev)
                        {dq.pop_front();}
                    else
                        {dq.pop_back();}
                }

                else{
                    info=false;
                    break;
                }
            }
        }
        if(info){
            if(rev){
                reverse(dq.begin(),dq.end());
            }
            int cnt=1;
            cout<<"[";
            for(auto z:dq){
                if(cnt==dq.size()){
                    cout<<z<<"";
                }
                else{
                    cout<<z<<",";
                }
                cnt++;
            }
            cout<<"]\n";
        }
        else{
            cout<<"error\n";
        }
    }
    
}