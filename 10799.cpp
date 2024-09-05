#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int star=0;
    stack<pair<char, int>> st;
    int ans=0;


    cin>>s;
    for (int i = 0; i < s.size(); i++)
    {
       if(s[i]=='('){
        st.push({s[i],i});
       }
       else{ // ')'일때
        if(i-st.top().second==1){
            // 레이져일때
            st.pop();
            ans+=st.size();
        }
        else{
            //레이져가 아닐때
            ans++;
            st.pop();
        }
       }
    }
    
    cout<<ans;
}