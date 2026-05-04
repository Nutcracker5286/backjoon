#include <string>
#include <vector>

using namespace std;
bool aeiou(char c)
{
    return c=='a' || c=='e' || c=='i' ||c=='o'||c=='u' ;
}

string solution(string my_string) {
    string answer = "";
    for(auto c : my_string){
        if(aeiou(c)) continue;
        answer +=c;
    }
    return answer;
}