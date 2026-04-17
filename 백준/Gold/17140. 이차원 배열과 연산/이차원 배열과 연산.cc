#include <bits/stdc++.h>
using namespace std;

/*
a[r][c] 가 k가 되는 시간 구하기
100초 이상이면 -1 출력

1초마다
r연산 => 모든행 단위 정렬 , 행의 개수 >= 열의 개수인 경우만, 행 늘어나면 모든 행 크기 증가
c연산 => 모든열 단위 정렬 , 행의 개수 < 열의 개수, 열 늘어나면 모든 열 크기 증가
가장 큰 행 , 열 기준으로 크기 증가시 0으로 채워짐

연산 후에는
정렬 방식
    정렬시 0은 무시
    수의 등장횟수, 수의 크기 오름차순
    정렬된 결과를 다시 넣어야 함

입력 받기

게임 시작
조건에 따라 행 또는 열 연산 시행
    연산 시행시 사본 벡터로 진행
정렬 결과 배열에 삽입
    배열 즉시 교체
행 또는 열 크기 조정
    나머지 배열의 크기 늘리기
크기가 100을 넘어가면 100을 넘어가는 나머지 제외
*/

int brd[1000][1000];
int r, c, k, rowSize = 3, colSize = 3;

// r연산 시행
void R()
{
    int tmp[101][101] = {0};
    int mxSize = 0;

    // 행별로 시행
    for (int i = 0; i < rowSize; i++)
    {
        pair<int, int> num[101] = {}; // 등장횟수, 수의 크기

        // 정렬를 위한 배열 정리
        for (int j = 0; j < colSize; j++)
        {
            num[brd[i][j]].first++;            // 등장횟수 증가
            num[brd[i][j]].second = brd[i][j]; // 수의 크기 삽입
        }

        sort(num, num + 101); // 횟수, 크기별로 정렬 시행

        // 100까지만 정렬 결과 삽입 및 사이즈 갱신
        int idx = 0;
        for (int j = 0; j < 101; j++)
        {
            // 정렬 시 0은 무시, 등장하지 않은것도 무시
            if (num[j].second == 0 || num[j].first == 0)
                continue;
            if (idx + 2 > 100)
                break; // 100개 이상이면 종료
            // 삽입은 크기, 횟수
            tmp[i][idx++] = num[j].second;
            tmp[i][idx++] = num[j].first;
        }
        mxSize = max(mxSize, idx);
    }

    colSize = mxSize;
    // 원본 부착 및 사이즈 조절
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            if (j >= 100)
                break;
            brd[i][j] = tmp[i][j];
        }
    }
}

// c연산 시행
void C()
{
    int tmp[101][101] = {0};
    int mxSize = 0;

    // 열별로 시행
    for (int i = 0; i < colSize; i++)
    {
        pair<int, int> num[101] = {}; // 등장횟수, 수의 크기

        // 정렬를 위한 배열 정리
        for (int j = 0; j < rowSize; j++)
        {
            num[brd[j][i]].first++;            // 등장횟수 증가
            num[brd[j][i]].second = brd[j][i]; // 수의 크기 삽입
        }

        sort(num, num + 101); // 횟수, 크기별로 정렬 시행

        // 100까지만 정렬 결과 삽입 및 사이즈 갱신
        int idx = 0;
        for (int j = 0; j < 101; j++)
        {
            // 정렬 시 0은 무시, 등장하지 않은것도 무시
            if (num[j].second == 0 || num[j].first == 0)
                continue;
            if (idx + 2 > 100)
                break; // 100개 이상이면 종료
            // 삽입은 크기, 횟수
            tmp[idx++][i] = num[j].second;
            tmp[idx++][i] = num[j].first;
        }
        mxSize = max(mxSize, idx);
    }

    rowSize = mxSize;
    // 원본 부착 및 사이즈 조절
    for (int i = 0; i < colSize; i++)
    {
        for (int j = 0; j < rowSize; j++)
        {
            if (j >= 100)
                break;
            brd[j][i] = tmp[j][i];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> k;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> brd[i][j];
        }
    }

    // 100초 시뮬레이션
    for (int ans = 0; ans <= 100; ans++)
    {
        if (brd[r - 1][c - 1] == k)
        {
            cout << ans;
            return 0;
        }

        if (ans == 100)
            break;

        if (rowSize >= colSize)
            R();
        else
            C();
    }
    cout << -1;
}
