#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
	int T; cin >> T;
	for(int i = 1; i <= T; ++i) {
		int a, b; cin >> a >> b;
		cout << "Case #" << i << ": " << a+b << '\n';
	}
	return 0;
}
