#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
vector<pair<int, int>> lesson;

int main(int argc, char** argv)
{
	int N; cin >> N; // 강의 개수
	for(int i = 0; i < N; ++i) {
		int starttime, endtime;
		cin >> starttime >> endtime;
		lesson.emplace_back(make_pair(endtime, starttime));
	}

	sort(lesson.begin(), lesson.end());
	int end = lesson[0].first;
	int ans = 1;
	for(int i = 1; i < N; ++i) {
		if(end <= lesson[i].second) {
			end = lesson[i].first;
			ans += 1;
		}
	}
	cout << ans;
	return 0;
}
