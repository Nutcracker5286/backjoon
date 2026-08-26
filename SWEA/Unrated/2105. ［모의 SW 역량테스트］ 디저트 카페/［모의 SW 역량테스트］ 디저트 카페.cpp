
#include<algorithm>
#include<iostream>

using namespace std;

//시계방향
int dx[4] = { 1,1,-1,-1 };
int dy[4] = { 1,-1,-1,1 };
int n;
int kind[110];
int brd[25][25];
int vis[25][25];

int cnt;
int ans;



bool oob(int x, int y) {
	return x < 0 || y < 0 || x >= n || y >= n;
}

// 카운팅배열에 종류가 겹치면 실패, oob면 실패, 사각형이 안나오면 실패
void make_Rec(int x, int y, int len) {
	int cx, cy;

	//왼쪽변이 1~n인 경우 검사
	bool ismake = 0;
	for (int left = 1; left <= n; left++) {
		fill(&kind[0], &kind[0] + 110, 0);
		fill(&vis[0][0], &vis[0][0] + 25*25, 0);

		kind[brd[x][y]] = 1;
		vis[x][y] = 1;
		cnt = 1;
		cx = x;
		cy = y;


		bool recP = 1;
		for (int d = 0; d < 4; d++) {
			int rbrt = len, lbrt = left;
			if (d % 2 == 0) {
				while (rbrt--) {
					cx += dx[d];
					cy += dy[d];
					if (oob(cx, cy)) return;
					if (kind[brd[cx][cy]]) {
						recP = 0;
						break;
					} 
					kind[brd[cx][cy]] = 1;
					vis[cx][cy] = 1;
					cnt++;
				}

			}
			else {
				while (lbrt--) {
					cx += dx[d];
					cy += dy[d];
					if (oob(cx, cy)) return;
					//마지막 방향이고 돌아왔으면
					if (cx == x && cy == y) {
						break;
					} 
					if (kind[brd[cx][cy]]) {
						recP = 0;
						break;
					}
					kind[brd[cx][cy]] = 1;
					vis[cx][cy] = 1;
					cnt++;
				}

			}
			if (!recP) break;
		}
		if (!recP) continue;
		
		ans = max(ans, cnt);
	}
}












int main(int argc, char** argv)
{
	int test_case;
	int T;
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 이 부분에 여러분의 알고리즘 구현이 들어갑니다.
			 가능한 대각사각형을 그리면서 겹치지 않는 종류만 선택

			 이차원 보드 탐색
				해당 노드에서 약 21까지 길이의 좌우 사각형 그리기
					그리면서 카운팅배열에 종류가 겹치면 실패, oob면 실패, 사각형이 안나오면 실패
					kind와 정답 비교 갱신
		*/


		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> brd[i][j];
			}
		}



		ans = 0;
		//보드탐색
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				//현재 노드에서 사각형 그리기
				for (int l = 1; l <= n; l++) {
					make_Rec(i, j, l);
				}
			}
		}
		ans == 0 ? ans = -1 : ans;
		cout << "#" << test_case << " " << ans << "\n";

		/////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}