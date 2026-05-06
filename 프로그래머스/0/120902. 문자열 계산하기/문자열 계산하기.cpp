#include <string>
#include <bits/stdc++.h>

using namespace std;

int solution(string a) {
    int answer = 0;
    int tmp=0, sign =1;
    for(int i=0; i<a.size(); i++ ){
        if(isdigit(a[i])){
            tmp=tmp*10+a[i]-'0';
        }else{
            if(a[i]==' ') continue;
            answer+=tmp*sign;
            tmp=0;
            if(a[i]=='+'){
                sign=1;
            }
            else{
                sign=-1;
            }
        }
    }
    
    return answer+tmp*sign;
}