#include <bits/stdc++.h>
using namespace std;

/*
tc별로 시행
n개의 회전 명령을 받고 명령에 따라 큐브의 면을 회전 시킴

tc만큼 반복
원본큐브를 시물용 큐브로 복사하기
n개만큼 반복
명령 단위 한개 받기
시계방향 회전이면 한번만 회전 아니면 3번 회전 시키기
큐브의 윗면 출력

*/

int cube[6][3][3];
int si[6][3][3];

int n, tc;
const int UP = 0;
const int DOWN = 1;
const int FRONT = 2;
const int BACK = 3;
const int LEFT = 4;
const int RIGHT = 5;

void rotate(int dir)
{
    int tmp[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tmp[i][j] = cube[dir][2 - j][i];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            swap(tmp[i][j], cube[dir][i][j]);
        }
    }
}
void cubing(char a)
{
    if (a == 'U')
    {
        rotate(UP);
        int tmp[3];
        for (int i = 0; i < 3; i++)
            tmp[i] = cube[LEFT][0][i];

        for (int i = 0; i < 3; i++)
            cube[LEFT][0][i] = cube[FRONT][0][i];
        for (int i = 0; i < 3; i++)
            cube[FRONT][0][i] = cube[RIGHT][0][i];
        for (int i = 0; i < 3; i++)
            cube[RIGHT][0][i] = cube[BACK][0][i];
        for (int i = 0; i < 3; i++)
            cube[BACK][0][i] = tmp[i];
    }
    else if (a == 'D')
    {
        rotate(DOWN);
        int tmp[3];
        for (int i = 0; i < 3; i++)
            tmp[i] = cube[RIGHT][2][i];

        for (int i = 0; i < 3; i++)
            cube[RIGHT][2][i] = cube[FRONT][2][i];
        for (int i = 0; i < 3; i++)
            cube[FRONT][2][i] = cube[LEFT][2][i];
        for (int i = 0; i < 3; i++)
            cube[LEFT][2][i] = cube[BACK][2][i];
        for (int i = 0; i < 3; i++)
            cube[BACK][2][i] = tmp[i];
    }
    else if (a == 'F')
    {
        rotate(FRONT);
        int tmp[3];
        for (int i = 0; i < 3; i++)
            tmp[i] = cube[LEFT][i][2];

        for (int i = 0; i < 3; i++)
            cube[LEFT][i][2] = cube[DOWN][0][i];
        for (int i = 0; i < 3; i++)
            cube[DOWN][0][i] = cube[RIGHT][2 - i][0];
        for (int i = 0; i < 3; i++)
            cube[RIGHT][i][0] = cube[UP][2][i];
        for (int i = 0; i < 3; i++)
            cube[UP][2][i] = tmp[2 - i];
    }
    else if (a == 'B')
    {
        rotate(BACK);
        int tmp[3];
        for (int i = 0; i < 3; i++)
            tmp[i] = cube[RIGHT][i][2];

        for (int i = 0; i < 3; i++)
            cube[RIGHT][i][2] = cube[DOWN][2][2 - i];
        for (int i = 0; i < 3; i++)
            cube[DOWN][2][i] = cube[LEFT][i][0];
        for (int i = 0; i < 3; i++)
            cube[LEFT][i][0] = cube[UP][0][2 - i];
        for (int i = 0; i < 3; i++)
            cube[UP][0][i] = tmp[i];
    }
    else if (a == 'L')
    {
        rotate(LEFT);
        int tmp[3];
        for (int i = 0; i < 3; i++)
            tmp[i] = cube[BACK][i][2];

        for (int i = 0; i < 3; i++)
            cube[BACK][i][2] = cube[DOWN][2 - i][0];
        for (int i = 0; i < 3; i++)
            cube[DOWN][i][0] = cube[FRONT][i][0];
        for (int i = 0; i < 3; i++)
            cube[FRONT][i][0] = cube[UP][i][0];
        for (int i = 0; i < 3; i++)
            cube[UP][i][0] = tmp[2 - i];
    }
    else if (a == 'R')
    {
        rotate(RIGHT);
        int tmp[3];
        for (int i = 0; i < 3; i++)
            tmp[i] = cube[FRONT][i][2];

        for (int i = 0; i < 3; i++)
            cube[FRONT][i][2] = cube[DOWN][i][2];
        for (int i = 0; i < 3; i++)
            cube[DOWN][i][2] = cube[BACK][2 - i][0];
        for (int i = 0; i < 3; i++)
            cube[BACK][i][0] = cube[UP][2 - i][2];
        for (int i = 0; i < 3; i++)
            cube[UP][i][2] = tmp[i];
    }
}
// w, y, r, o, g, b
void print_up()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (cube[UP][i][j] == 0)
                cout << 'w';
            else if (cube[UP][i][j] == 1)
                cout << 'y';
            else if (cube[UP][i][j] == 2)
                cout << 'r';
            else if (cube[UP][i][j] == 3)
                cout << 'o';
            else if (cube[UP][i][j] == 4)
                cout << 'g';
            else
                cout << 'b';
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 원본 큐브 색칠
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
                cube[i][j][k] = i;
        }
    }

    cin >> tc;

    while (tc--)
    {
        cin >> n;

        // 시뮬 큐브 초기화
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                    cube[i][j][k] = i;
            }
        }

        while (n--)
        { // n개의 명령 시행
            char a, b;
            cin >> a >> b;

            if (b == '+')
            { // 시계방향
                cubing(a);
            }
            else
            { // 반시계는 3번반복
                for (int i = 0; i < 3; i++)
                    cubing(a);
            }
        }

        // 큐브 윗면 출력
        print_up();
    }
}