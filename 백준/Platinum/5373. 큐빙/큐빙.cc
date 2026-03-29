#include <bits/stdc++.h>
using namespace std;

/*
육면을 돌려서 윗면의 색깔 출력

tc 받고
tc 만큼 반복 시작
회전 횟수, 회전면, 회전 방향 받음

기존 다이스 복사해서 시물용 다이스 복사
시뮬용 다이스의 회전 수행
*/

/*
0 ,1, 2, 3,4,5
위, 아래,북, 동 ,남, 서
*/
int cu[6][3][3];
int tmp[6][3][3];

int tc, n, cnt;

void rotSpace(int num)
{
    int ts[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ts[i][j] = tmp[num][3 - 1 - j][i];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tmp[num][i][j] = ts[i][j];
        }
    }
}

void rotate(char space)
{
    // 윗면
    if (space == 'U')
    {
        // 면에 대한 회전 및 위아래 제외 사방의 줄 변경
        rotSpace(0);
        // 북 -> 동 시계방향 2,3,4,5
        int ts[3];
        for (int i = 0; i < 3; i++)
            ts[i] = tmp[5][0][i];

        for (int i = 5; i > 2; i--)
        {
            for (int j = 0; j < 3; j++)
                tmp[i][0][j] = tmp[i - 1][0][j];
        }
        for (int i = 0; i < 3; i++)
            tmp[2][0][i] = ts[i];
    }
    // 아랫면
    else if (space == 'D')
    {
        // 면에 대한 회전 및 위아래 제외 사방의 줄 변경
        rotSpace(1);
        // 북 -> 동 시계방향 2,5,4,3
        int ts[3];
        for (int i = 0; i < 3; i++)
            ts[i] = tmp[3][2][i];

        // 4 -> 3
        for (int i = 0; i < 3; i++)
            tmp[3][2][i] = tmp[4][2][i];

        // 5 ->4
        for (int i = 0; i < 3; i++)
            tmp[4][2][i] = tmp[5][2][i];
        // 2 -> 5
        for (int i = 0; i < 3; i++)
            tmp[5][2][i] = tmp[2][2][i];

        // 3 -> 2
        for (int i = 0; i < 3; i++)
            tmp[2][2][i] = ts[i];
    }
    // 앞
    else if (space == 'F')
    {
        // 면에 대한 회전 및 위아래 제외 사방의 줄 변경
        rotSpace(4);
        // 북 -> 동 시계방향 0,3,1,5
        int ts[3];
        for (int i = 0; i < 3; i++)
            ts[i] = tmp[5][i][2];

        // 1 ->5
        for (int i = 0; i < 3; i++)
            tmp[5][i][2] = tmp[1][0][i];

        // 3 ->1
        for (int i = 0; i < 3; i++)
            tmp[1][0][i] = tmp[3][2 - i][0];
        // 0 ->3
        for (int i = 0; i < 3; i++)
            tmp[3][i][0] = tmp[0][2][i];

        // 5 ->0
        for (int i = 0; i < 3; i++)
            tmp[0][2][i] = ts[2 - i];
    }
    // 뒤
    else if (space == 'B')
    {
        // 면에 대한 회전 및 위아래 제외 사방의 줄 변경
        rotSpace(2);
        // 0,5,1,3
        int ts[3];
        for (int i = 0; i < 3; i++)
            ts[i] = tmp[0][0][i];

        // 3 -> 0
        for (int i = 0; i < 3; i++)
            tmp[0][0][i] = tmp[3][i][2];

        // 1 ->3
        for (int i = 0; i < 3; i++)
            tmp[3][i][2] = tmp[1][2][2 - i];

        // 5 -> 1
        for (int i = 0; i < 3; i++)
            tmp[1][2][i] = tmp[5][i][0];

        // 0 -> 5
        for (int i = 0; i < 3; i++)
            tmp[5][i][0] = ts[2 - i];
    }
    // 왼
    else if (space == 'L')
    {
        // 면에 대한 회전 및 위아래 제외 사방의 줄 변경
        rotSpace(5);
        // 0, 4,1,2
        int ts[3];
        for (int i = 0; i < 3; i++)
            ts[i] = tmp[0][i][0];

        //  2  -> 0
        for (int i = 0; i < 3; i++)
            tmp[0][i][0] = tmp[2][2 - i][2];

        //  1 -> 2
        for (int i = 0; i < 3; i++)
            tmp[2][i][2] = tmp[1][2 - i][0];
        //  4 -> 1
        for (int i = 0; i < 3; i++)
            tmp[1][i][0] = tmp[4][i][0];

        // 0 -> 4
        for (int i = 0; i < 3; i++)
            tmp[4][i][0] = ts[i];
    }

    // 오

    else if (space == 'R')
    {
        // 면에 대한 회전 및 위아래 제외 사방의 줄 변경
        rotSpace(3);
        // 0, 2,1,4
        int ts[3];
        for (int i = 0; i < 3; i++)
            ts[i] = tmp[0][i][2];

        //  4  -> 0
        for (int i = 0; i < 3; i++)
            tmp[0][i][2] = tmp[4][i][2];

        //  1 -> 4
        for (int i = 0; i < 3; i++)
            tmp[4][i][2] = tmp[1][i][2];
        //  2 -> 1
        for (int i = 0; i < 3; i++)
            tmp[1][i][2] = tmp[2][2 - i][0];

        // 0 -> 2
        for (int i = 0; i < 3; i++)
            tmp[2][i][0] = ts[2 - i];
    }
}

vector<char> ans;
void chkColor(int row, int col)
{
    if (tmp[0][row][col] == 0)
    {
        ans.push_back('w');
    }
    else if (tmp[0][row][col] == 1)
    {
        ans.push_back('y');
    }

    else if (tmp[0][row][col] == 2)
    {
        ans.push_back('o');
    }

    else if (tmp[0][row][col] == 3)
    {
        ans.push_back('b');
    }

    else if (tmp[0][row][col] == 4)
    {
        ans.push_back('r');
    }

    else if (tmp[0][row][col] == 5)
    {
        ans.push_back('g');
    }
}

void print_color()
{
    for (int i = 0; i < 3; i++)
    {
        ans.clear();
        for (int j = 0; j < 3; j++)
        {
            chkColor(i, j);
        }
        for (auto c : ans)
            cout << c;
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                cu[i][j][k] = i;
            }
        }
    }

    cin >> tc;

    // tc 시작
    while (tc--)
    {
        // 회전 명령 횟수 시작
        cin >> n;

        // 기존 다이스 복사
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    tmp[i][j][k] = cu[i][j][k];
                }
            }
        }

        while (n--)
        { // 방향 ,횟수 삽입
            char a, b;
            cin >> a >> b;

            // 다이스 회전
            if (b == '+')
            {
                rotate(a);
            }
            else
            {
                for (int i = 0; i < 3; i++)
                    rotate(a);
            }
        }
        // 윗면의 색상 출력
        print_color();
    }
}