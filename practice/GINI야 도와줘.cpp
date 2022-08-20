#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

string board[51];
int bumtime[51][51];
int raintime[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(int argc, char** argv)
{
	int R, C; cin >> R >> C;
	int homeX = 0;
	int homeY = 0;
	queue<pair<int, int>> bum;
	queue<pair<int, int>> rain;
	for(int i = 0; i < R; ++i) {
		cin >> board[i];
		fill(bumtime[i], bumtime[i] + 51, -1);
		fill(raintime[i], raintime[i] + 51, -1);
		for(int j = 0; j < C; ++j) {
			if(board[i][j] == 'W') {
				bum.push({i,j});
				bumtime[i][j] = 0;
			}

			if(board[i][j] == '*') {
				rain.push({i, j});
				raintime[i][j] = 0;
			}

			if(board[i][j] == 'H') {
				homeX  = i;
				homeY = j;
			}
		}
	}

	// 소나기 bfs
	while(!rain.empty()) {
		pair<int, int> cur = rain.front();
		rain.pop();
		for(int i = 0; i < 4; ++i) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if(raintime[nx][ny] != -1 || board[nx][ny] == 'X' || board[nx][ny] == 'H') continue;
			rain.push({nx, ny});
			raintime[nx][ny] = raintime[cur.first][cur.second] + 1;
		}
	}

	// 태범 bfs
	while(!bum.empty()) {
		pair<int, int> cur = bum.front();
		bum.pop();
		for(int i = 0; i < 4; ++i) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if(bumtime[nx][ny] != -1 || board[nx][ny] == '*' || board[nx][ny] == 'X') continue;
			if(raintime[nx][ny] != -1 && raintime[nx][ny] <= bumtime[cur.first][cur.second] + 1) continue;
			bum.push({nx, ny});
			bumtime[nx][ny] = bumtime[cur.first][cur.second] + 1;
		}
	}
	if(bumtime[homeX][homeY] != -1) {
		cout << bumtime[homeX][homeY];
	} else {
		cout << "FAIL";
	}
}
