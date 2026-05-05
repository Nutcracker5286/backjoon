#include <string>
#include <bits/stdc++.h>

using namespace std;

string solution(int age) {
    string answer = "";
    vector<char> a;
    while(age>0){
        int tmp = age%10;
        age/=10;
        a.push_back(char(tmp+'a'));
    }
    reverse(a.begin(),a.end());
    for(auto c: a) answer+=c;
    return answer;
}