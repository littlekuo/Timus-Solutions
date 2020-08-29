#include<iostream>
#include<vector>

using namespace std;

int main() {
	double num;
	vector<double> ans;
	while (cin >> num) {
		ans.push_back(sqrt(num));
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		printf("%.4llf\n", ans[i]);
	}
}