/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;
// float b = 1.0, c = 2.0;
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ansCore, ansEdge;
int oriBrd[200][200];
int brd[200][200];
int mx;
vector<pair<int, int>> core;

void initBrd()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            brd[i][j] = oriBrd[i][j];
}

bool isCon(int x, int y, int d)
{
    if (d == 4)
        return true;
    int nx = x + dx[d], ny = y + dy[d];

    while (nx >= 0 && ny >= 0 && nx < n && ny < n)
    {
        if (brd[nx][ny] || brd[nx][ny] == 2)
        { // 전선 또는 코어 존재
            return false;
        }
        nx += dx[d];
        ny += dy[d];
    }
    return true;
}

int makeCon(int x, int y, int d)
{

    if (d == 4)
        return 0;
    int cnt = 0;
    int nx = x + dx[d], ny = y + dy[d];

    while (nx >= 0 && ny >= 0 && nx < n && ny < n)
    {
        brd[nx][ny] = 2;
        cnt++;
        nx += dx[d];
        ny += dy[d];
    }
    return cnt;
}

void unCon(int x, int y, int d)
{

    if (d == 4)
        return;
    int cnt = 0;
    int nx = x + dx[d], ny = y + dy[d];

    while (nx >= 0 && ny >= 0 && nx < n && ny < n)
    {
        brd[nx][ny] = 0;
        cnt++;
        nx += dx[d];
        ny += dy[d];
    }
    return;
}

/*
현단계에서 전선을 키지 않거나, 특정 방향을 선택하는 함수

종료 조건
    연결이 안되는 경우
    n번째 차례인경우
*/
void solve(int t, int ccnt, int ecnt)
{
    if (t == mx)
    {
        if (ccnt > ansCore)
        {
            ansCore = ccnt;
            ansEdge = ecnt;
        }
        if (ccnt == ansCore)
        {
            ansEdge = min(ansEdge, ecnt);
        }
        return;
    }

    for (int d = 0; d < 4; d++)
    {
        int x = core[t].X, y = core[t].Y;
        if (!isCon(core[t].X, core[t].Y, d)) // 현 방향은 안됨
            continue;

        int curE = makeCon(core[t].X, core[t].Y, d);
        solve(t + 1, ccnt + 1, curE + ecnt);
        unCon(core[t].X, core[t].Y, d);
    }

    // 연결 하지 않은 경우
    solve(t + 1, ccnt, ecnt);
}

int main(int argc, char **argv)
{
    int test_case;
    int T;
    ios::sync_with_stdio(0);
    cin.tie(0);

    /*
       아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
       앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
       //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
       freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
       따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
       freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
       단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
    */
    // freopen("input.txt", "r", stdin);
    cin >> T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for (test_case = 1; test_case <= T; ++test_case)
    {

        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
             이 부분에 여러분의 알고리즘 구현이 들어갑니다.
             cctv와 유사

             가장자리의 코어는 제외, 코어를 백터로 관리

             5진수의 조합으로 방향 결정

             조합으로 시뮬 진행
                보드 초기화
                방향 추출
                    보드에 연결 가능하면
                        연결 및 코어, 전선수 계산
                    불가능하면
                        해당 시뮬 불가 다음 시뮬로 넘어감

                기존 활성 코어 < 현재 활성 코어
                    전선 = 현재 전선
                else
                    전선   = max(전선, 현재 전선)


            진수 진행시 테케는 맞지만 시간 초과
            가지 치기 진행 또는 백트래킹 시행

         */
        /////////////////////////////////////////////////////////////////////////////////////////////
        cin >> n;
        ansCore = 0;
        ansEdge = INT_MAX;
        core.clear();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> oriBrd[i][j];
                brd[i][j] = oriBrd[i][j];
                if (oriBrd[i][j])
                {
                    // 가장자리면 벡터 추가 x
                    if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
                        continue;
                    core.push_back({i, j});
                }
            }
        }

        mx = core.size();

        // 시뮬레이션 시작
        solve(0, 0, 0);
        cout << "#" << test_case << " " << ansEdge << '\n';
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}