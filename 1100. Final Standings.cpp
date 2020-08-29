#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct node {
	int id, m;
};

//归并排序
void divi_sort(vector<node>& arr, int start, int end) {
	if (end - start <= 0) return;
	int mid = (start + end) / 2;
	divi_sort(arr, start, mid);
	divi_sort(arr, mid + 1, end);
	vector<node> tem;
	for (int i = start, j = mid + 1; i <= mid || j <= end; ) {
		if (i > mid) {
			tem.push_back(arr[j]);
			j++;
		}
		else if (j > end) {
			tem.push_back(arr[i]);
			i++;
		}
		else {
			if (arr[i].m >= arr[j].m) {
				tem.push_back(arr[i]);
				i++;
			}
			else {
				tem.push_back(arr[j]);
				j++;
			}
		}
	}
	for (int i = 0; i < tem.size(); i++) {
		arr[i + start] = tem[i];
	}
}


int main() {
	int n;
	scanf_s("%d", &n);
	vector<node> ans;
	for (int i = 0; i < n; i++) {
		int id, m;
		scanf_s("%d %d", &id, &m);
		ans.push_back({ id,m });
	}
	//divi_sort(ans, 0, ans.size() - 1);
    
	for (auto&&t : ans) {
		printf("%d %d\n", t.id, t.m);
	}
}

