#include <bits/stdc++.h>
#include<iostream>

using namespace std;

int dx[4] = { -1,0,1,0 }; // 상 좌 하 우
int dy[4] = { 0,-1,0,1 };

bool pipedir[8][4] = { // 상 좌 하 우
	{0,0,0,0},
	{1,1,1,1},
	{1,0,1,0},
	{0,1,0,1},
	{1,0,0,1},
	{0,0,1,1},
	{0,1,1,0},
	{1,1,0,0},
};



vector<vector<int>> brd;
vector<vector<int>> vis;
int n, m, r, c, l,cnt;

bool oob(int x, int y) {
	return x < 0 || y < 0 || x >= n || y >= m;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 이 부분에 여러분의 알고리즘 구현이 들어갑니다
			 시물레이션문제
			 0은 갈수 없는곳
			 1~7 정해진 방향으로만 진행 가능
			 주어진 맨홀 위치로부터 전파 시작하고  단계가 l 초과이면 종료

			  맨홀마다 호환 되는 경우가 다름 
			  
			 2차 풀이 - 개선 버전
			 불 배열로 해당 모드 별로 상하좌우 가능한지 설정
			 
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////
		cin >> n >> m >> r >> c >> l;


		brd.assign(n, vector<int>(m, 0));
		vis.assign(n, vector<int>(m, -1));

		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> brd[i][j];
			}
		}
		
		//시뮬레이션 시작
		queue<pair<int, int>> q;
		vis[r][c] = 1;
		q.push({ r,c });
		cnt = 1;



		while (!q.empty()) {
			int x, y; tie(x, y) = q.front(); q.pop();

			if (vis[x][y] >= l) break; // l시간 후에는 고려 x

			int mod = brd[x][y];
			
			// 방향마다 해당모드가 열려 있는지 체크
			for (int d = 0; d < 4; d++) {
				if (!pipedir[mod][d]) continue; //열려 있지 않으면 못감

				int nx = x + dx[d], ny = y + dy[d];

				if (oob(nx, ny)) continue;
				if (vis[nx][ny] != -1 || brd[nx][ny]==0) continue;
				// 이동가능한 노드의 반대 방향이 열려있는지 체크 
				int nxtdir = (d + 2) % 4; //상 좌 하 우
				int nxtmod = brd[nx][ny];
				if (!pipedir[nxtmod][nxtdir]) continue; 
				q.push({ nx,ny });
				vis[nx][ny] = vis[x][y] + 1;
				cnt++;


			}



		}

	
		cout << "#" << test_case << " " << cnt << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}