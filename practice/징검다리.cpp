#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> LIS;

int main(int argc, char** argv)
{
	int stonecount; cin >> stonecount;
	for(int i = 0; i < stonecount; ++i) {
		int n; cin >> n;
		if(LIS.empty()) {
			LIS.emplace_back(n);
		} else {
			if(LIS.back() < n) {
				LIS.emplace_back(n);
			} else {
				auto location = lower_bound(LIS.begin(), LIS.end(), n);
				*location = n;
			}
		}
	}
	cout << LIS.size();
	return 0;
}
