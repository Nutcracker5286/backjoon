#include <string>
#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    //x회전 
    for(int i=0; i<s.size(); i++){
        
        //올바른 괄호인지 체크
        stack<char> st;
        bool isp =1;
        for(auto c : s){
            if(c=='(' || c=='[' || c=='{'){
                st.push(c);
            }
            else{
                if(st.empty()) {
                    isp = 0;
                    break;
                }
                
                if(c=='}' && st.top() =='{') {st.pop(); }
                if(c==')' && st.top() =='(') {st.pop(); }
                if(c==']' && st.top() =='[') {st.pop(); }
            }
        }
        
        if(st.empty() && isp) answer++;
        
        //회전
        rotate(s.begin(), s.begin()+1,s.end());
    }
    return answer;
}