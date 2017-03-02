/*
	URL: http://codeforces.com/contest/529/problem/B
*/

#include <bits/stdc++.h>
using namespace std;

#define loop(i,n) for(int i=0; i<n; i++)
#define ll long long
#define pii pair<ll, ll>

const int MXN = 1005;
const int INF = 1e9 + 7;
int n;
int w[MXN], h[MXN];

int try_height(int height) {
	int num_lying = 0;
	int tot_width = 0;
	vector<int> v;
	loop(j, n) {
		if (h[j] > height) {
			if (w[j] <= height) num_lying++;
			else return -1;
			tot_width += h[j];
		}
		else {
			if (w[j] <= height) {
				v.push_back(h[j] - w[j]);
			}
			tot_width += w[j];
		}
	}
	if (num_lying > n / 2) return -1;
	sort(v.begin(), v.end());
	for (int j=0; j<v.size() && num_lying < n / 2 && v[j] < 0; j++) {
		num_lying++;
		tot_width += v[j];
	}
	return tot_width * height;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin>>n;
	loop(i, n) cin>>w[i]>>h[i];
	int res = INF;
	loop(i, MXN) {
		int val = try_height(i+1);
		if (val != -1) {
			if (res > val) {
				res = val;
			}
		}
	}
	cout<<res<<endl;
	return 0;
}