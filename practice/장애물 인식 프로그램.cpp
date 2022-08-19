#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int board[26][26];
bool visited[26][26];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(int argc, char** argv)
{
	int N; cin >> N;
	for(int i = 0; i < N; ++i) {
		fill(visited[i], visited[i] + 26, false);
		for(int j = 0; j < N; ++j) {
			char c; cin >> c;
			if(c == '1') {
				board[i][j] = 1; // 1을 1로 표시
			} else {
				board[i][j] = 0; // 0을 0으로 표시
			}
		}
	}

	// bfs
	queue<pair<int, int>> q;
	int blocktotal = 0;
	vector<int> ans;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			if((board[i][j] == 0) || (visited[i][j])) continue;
			// 시작 위치를 찾는다.
			q.push({i, j});
			visited[i][j] = true;
			blocktotal += 1;
			int cnt = 0;
			while(!q.empty()) {
				pair<int, int> cur = q.front();
				q.pop();
				cnt += 1;
				for(int k = 0; k < 4; ++k) {
					int nx = cur.first + dx[k];
					int ny = cur.second + dy[k];
					if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if(board[nx][ny] == 0 || visited[nx][ny]) continue;
					q.push({nx, ny});
					visited[nx][ny] = true;
				}
			}
			ans.emplace_back(cnt);
		}
	}

	cout << blocktotal << '\n';
	sort(ans.begin(), ans.end());
	for(int element : ans) {
		cout << element << '\n';
	}
	return 0;
}
