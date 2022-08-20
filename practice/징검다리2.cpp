#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> increasedp;
vector<int> decreasedp;
vector<int> increasebacktracking;
vector<int> decreasebacktracking;
vector<int> b;

int main(int argc, char** argv)
{
	int N; cin >> N;
    for(int i = 0; i < N; ++i) {
        int n; cin >> n;
        b.emplace_back(n);
    }

    // 오름 차순
    increasebacktracking.resize(N, 1);
    for(int i = 0; i < N; ++i) {
        if(increasedp.empty()) {
            increasedp.emplace_back(b[i]);
            increasebacktracking[i] = increasedp.size();
        } else {
            if(increasedp.back() < b[i]) {
                increasedp.emplace_back(b[i]);
                increasebacktracking[i] = increasedp.size();
            } else {
                auto location = lower_bound(increasedp.begin(), increasedp.end(), b[i]);
                *location = b[i];
                increasebacktracking[i] = increasebacktracking[location - increasedp.begin()];
            }
        }
    }
    reverse(b.begin(), b.end());
    decreasebacktracking.resize(N, 1);
    for(int i = 0; i < N; ++i) {
        if(decreasedp.empty()) {
            decreasedp.emplace_back(b[i]);
            decreasebacktracking[i] = decreasedp.size();
        } else {
            if(decreasedp.back() < b[i]) {
                decreasedp.emplace_back(b[i]);
                decreasebacktracking[i] = decreasedp.size();
            } else {
                auto location = lower_bound(decreasedp.begin(), decreasedp.end(), b[i]);
                *location = b[i];
                decreasebacktracking[i] = decreasebacktracking[location - decreasedp.begin()];
            }
        }
    }
    reverse(decreasebacktracking.begin(), decreasebacktracking.end());
    int ans = 0;
    for(int i = 0; i < N; ++i) {
        ans = max(ans, decreasebacktracking[i] + increasebacktracking[i]);
    }
    cout << ans - 1;
}
