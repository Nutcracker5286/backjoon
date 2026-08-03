#include <bits/stdc++.h>
using namespace std;

/*
더러운 칸을 모두 깨끗한 칸으로 바꾸는 이동 횟수 최솟값 출력

시작점에서 먼지들까지의 칸, 먼지끼리의 칸의 최솟값 구하기
방문순서를 순열로 정한후 저장된 칸의 값들합

bfs 시행해서 각 칸들 사이의 거리 구하기
칸의 최솟값을 저장
*/

vector<string> split(char op, string str)
{
    vector<string> res;
    int pos = 0;
    while (pos < str.size())
    {
        int nxt = str.find(op, pos);
        if (nxt == -1)
            nxt = str.size();
        if (nxt - pos > 0)
            res.push_back(str.substr(pos, nxt - pos));
        pos = nxt + 1;
    }
    return res;
}

vector<int> sieve(int n)
{
    vector<int> res;
    vector<bool> isP(n + 1, 1);

    for (int i = 2; i <= n; i++)
    {
        if (!isP[i])
            continue;
        res.push_back(i);

        for (int j = i * i; j <= n; j += i)
            isP[j] = 0;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string ans = "가나#다라#마바#";

    auto a = split('#', ans);
    for (auto s : a)
        cout << s << '\n';

    auto pri = sieve(15);
    cout << '\n';
    for (auto s : pri)
        cout << s << ' ';
}
