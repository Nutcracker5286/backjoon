#include <bits/stdc++.h>
using namespace std;

/*
    90도 시계 방향 회전

    기존 좌표 (i, j)
    -> 회전 후 (j, m - 1 - i)
*/
vector<vector<int>> rotate(const vector<vector<int>>& key) {
    int m = key.size();

    vector<vector<int>> ret(m, vector<int>(m));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            ret[j][m - 1 - i] = key[i][j];
        }
    }

    return ret;
}

/*
    현재 board 상태에서
    lock 영역이 전부 정확히 1인지 확인

    가능한 경우
    lock 0 + key 1 = 1
    lock 1 + key 0 = 1

    불가능한 경우
    lock 0 + key 0 = 0  -> 홈이 안 채워짐
    lock 1 + key 1 = 2  -> 돌기 충돌
*/
bool check(const vector<vector<int>>& board, int m, int n) {

    int offset = m - 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            // lock이 놓여있는 실제 board 좌표
            int x = i + offset;
            int y = j + offset;

            if (board[x][y] != 1)
                return false;
        }
    }

    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {

    int m = key.size();
    int n = lock.size();

    /*
        key는 lock 바깥으로 삐져나갈 수 있음

        lock 주변에 m-1 만큼 공간을 확보하면
        key가 lock에 한 칸이라도 걸치는 모든 경우를 표현 가능

        전체 보드 크기
        = (m - 1) + n + (m - 1)
        = n + 2 * (m - 1)
    */
    int sz = n + 2 * (m - 1);

    vector<vector<int>> board(sz, vector<int>(sz, 0));

    /*
        lock을 board 중앙에 배치

        시작 좌표는 (m-1, m-1)
    */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i + m - 1][j + m - 1] = lock[i][j];
        }
    }

    /*
        완전탐색

        1. key를 4방향 회전
        2. 각 회전 상태에서 가능한 모든 위치에 배치
        3. lock 영역이 전부 1이면 성공

        key의 왼쪽 위 좌표를 (x, y)라고 할 때
        board 안에 완전히 들어오기 위한 범위:

        0 <= x <= sz - m
        0 <= y <= sz - m
    */
    for (int rot = 0; rot < 4; rot++) {

        for (int x = 0; x <= sz - m; x++) {
            for (int y = 0; y <= sz - m; y++) {

                /*
                    key를 board 위에 올림

                    덧셈으로 처리하면
                    lock + key 상태를 바로 확인 가능
                */
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < m; j++) {
                        board[x + i][y + j] += key[i][j];
                    }
                }

                /*
                    lock 영역이 전부 1이면
                    홈은 전부 채워졌고 돌기 충돌도 없음
                */
                if (check(board, m, n))
                    return true;

                /*
                    다음 위치 탐색을 위해
                    방금 올린 key를 원상복구
                */
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < m; j++) {
                        board[x + i][y + j] -= key[i][j];
                    }
                }
            }
        }

        /*
            현재 방향 탐색이 끝났으면
            key를 90도 회전
        */
        key = rotate(key);
    }

    return false;
}