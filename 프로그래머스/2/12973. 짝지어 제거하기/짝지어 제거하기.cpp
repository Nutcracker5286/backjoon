#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int solution(string s)
{
    int answer = -1;

    stack<char> st;
    
    for(auto c:s){
        if(!st.empty() && st.top()==c){
            st.pop();
            continue;
        }
        st.push(c);
    }
    

    return st.empty();
}