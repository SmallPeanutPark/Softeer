#include<iostream>
#include <cmath>
#include <algorithm>

using namespace std;

double arr[1000001];

int main(int argc, char** argv)
{
	int N; cin >> N; // 학생의 수 
    int K; cin >> K; // 구간의 수
    for(int i = 0; i < K; ++i) {
        if(i == 0) {
            // init
            for(int j = 1; j <= N; ++j) {
                cin >> arr[j];
            }
        }
        double a, b; cin >> a >> b;
        double sum = 0; double cnt = 0;
        for(int j = a; j <= b; ++j) {
            // 구간의 성적 평균을 구하라
            cnt += 1;
            sum += arr[j];
        }
        double ref = sum / cnt; // 평균
        // 셋째자리에서 반올림하고 둘째자리까지 출력
        ref *= pow(10, 3);
        ref = round(ref);
        ref /= pow(10, 3);
        cout.precision(2);
        cout.setf(ios::fixed);
        cout << ref << '\n';
    }
    return 0;
}
