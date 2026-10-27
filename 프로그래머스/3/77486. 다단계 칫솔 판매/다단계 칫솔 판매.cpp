
#include <bits/stdc++.h>
using namespace std;

int p[10010];
int benefit[10010];

int find(int x) {
    if (p[x] == -1) return x;
    return find(p[x]);
}

// 추천인 방향으로 Union
bool uni(int u, int v) {
    if (find(u) == find(v)) return false;

    // v의 직접 부모는 반드시 u
    p[v] = u;
    return true;
}

void go(int curId, int sell) {
    if (curId == -1 || sell == 0) return;

    int upCost = sell / 10;
    int res = sell - upCost;

    benefit[curId] += res;

    go(p[curId], upCost);
}

vector<int> solution(vector<string> enroll,
                     vector<string> referral,
                     vector<string> seller,
                     vector<int> amount) {

    vector<int> answer;
    unordered_map<string, int> mapp;

    int n = enroll.size();

    for (int i = 0; i < n; i++)
        mapp[enroll[i]] = i;

    fill(p, p + 10010, -1);
    fill(benefit, benefit + 10010, 0);

    // 추천인 관계 구성
    for (int i = 0; i < n; i++) {
        if (referral[i] == "-") continue;

        int pidx = mapp[referral[i]];
        uni(pidx, i);
    }

    // 판매 이익 분배
    for (int i = 0; i < seller.size(); i++) {
        go(mapp[seller[i]], amount[i] * 100);
    }

    for (int i = 0; i < n; i++)
        answer.push_back(benefit[i]);

    return answer;
}
