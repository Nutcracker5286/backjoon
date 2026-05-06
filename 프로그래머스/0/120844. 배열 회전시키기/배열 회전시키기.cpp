#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    vector<int> answer;
    int n = numbers.size();
    
    if(direction =="right"){
        answer.push_back(numbers[n-1]);
        for(int i=0; i<n-1; i++){
            answer.push_back(numbers[i]);
        }
    }else{
        for(int i=1; i<n; i++){
            answer.push_back(numbers[i]);
        }
                answer.push_back(numbers[0]);

    }
    return answer;
}