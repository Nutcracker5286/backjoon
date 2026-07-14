#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int value : scoville) {
        pq.push(value);
    }

    int count = 0;

    while (!pq.empty()) {
        // 가장 작은 값이 K 이상이라면
        // 나머지 값들도 모두 K 이상이다.
        if (pq.top() >= K) {
            return count;
        }

        // 두 음식을 섞어야 하는데 하나밖에 남지 않은 경우
        if (pq.size() < 2) {
            return -1;
        }

        int first = pq.top();
        pq.pop();

        int second = pq.top();
        pq.pop();

        int mixed = first + second * 2;
        pq.push(mixed);

        count++;
    }

    return -1;
}