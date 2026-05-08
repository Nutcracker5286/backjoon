#include <string>
#include <vector>

using namespace std;

bool parallel(vector<vector<int>>& dots, int a, int b, int c, int d) {
    int x1 = dots[a][0], y1 = dots[a][1];
    int x2 = dots[b][0], y2 = dots[b][1];
    int x3 = dots[c][0], y3 = dots[c][1];
    int x4 = dots[d][0], y4 = dots[d][1];

    int dy1 = y2 - y1;
    int dx1 = x2 - x1;
    int dy2 = y4 - y3;
    int dx2 = x4 - x3;

    return dy1 * dx2 == dy2 * dx1;
}

int solution(vector<vector<int>> dots) {
    if (parallel(dots, 0, 1, 2, 3)) return 1;
    if (parallel(dots, 0, 2, 1, 3)) return 1;
    if (parallel(dots, 0, 3, 1, 2)) return 1;

    return 0;
}