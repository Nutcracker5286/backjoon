/*
현재 위치 기준 앞쪽으로 형성되는 슬라이딩 윈도우 내에서 최솟값을 출력하기
각 탐색마다 최소값을 찾으면 n^2이라 실패 따라서 자료구조 자체가 정렬되어
있어서 1로 조회 해야 함

현재 입력값보다 큰 덱에 있는 수는 어차피 최솟값이 불가능 따라서 모두 제거
=> 이러면 deque는 단조 증가 수열로 유지가 됨
입력값을 뒤에 추가
윈도우 범위 밖에 있는 앞부분도 제거
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int arr[5000005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l;
    deque<pair<int, int>> dq; // idx, value

    // input
    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // 탐색 시작
    for (int i = 0; i < n; i++)
    {
        int cur = arr[i]; // 현재 입력값

        // 현재 입력 값보다 덱에 있는 수가 크면 제거 (절대로 최솟값이 될수 없기 때문)
        while (!dq.empty() && dq.back().Y >= cur)
            dq.pop_back();

        // 덱에 있는 수는 현재 값보다 작고 앞에 있음 따라서 뒤에 삽입
        dq.push_back({i, cur});

        // 앞부분의 슬라이딩 범위 밖을 제거 함, 단 윈도우 보다 작으면 패스
        while (i - l + 1 > 0 && !dq.empty() && dq.front().X < i - l + 1)
            dq.pop_front();

        cout << dq.front().Y << ' ';
    }
}