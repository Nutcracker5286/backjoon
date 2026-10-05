#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<pair<int, int>> q; // {탈출 시간, 무게}

    int curT = 0; // 마지막 트럭이 진입한 시간
    int curW = 0; // 현재 다리 위 총 무게

    for (int truck : truck_weights) {

        // 다음 트럭은 최소 1초 뒤에 진입 가능
        curT++;

        // 그 사이 가장 앞 트럭이 이미 나갔다면 제거
        if (!q.empty() && q.front().first <= curT) {
            curW -= q.front().second;
            q.pop();
        }

        // 무게 제한 때문에 못 들어가면
        // 들어갈 수 있을 때까지 앞 트럭들을 제거
        while (!q.empty() && curW + truck > weight) {
            curT = q.front().first; // 앞 트럭 탈출 시간까지 점프

            curW -= q.front().second;
            q.pop();
        }

        // 현재 트럭 진입
        curW += truck;
        q.push({curT + bridge_length, truck});
    }

    return curT + bridge_length;
}