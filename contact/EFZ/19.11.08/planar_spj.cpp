#include <bits/stdc++.h>

using namespace std;

ifstream fin, fout, fans;
ofstream fscore, freport;

double p_x[500*500+10], p_y[500*500+10];
int vis[500*500+10];
int r, c, m;
string out_res, ans_res;

int __isnan(double x) { return x != x; }
int __isinf(double x) { return !__isnan(x) && __isnan(x - x); }

double getDistance(int x, int y) {
	double cx = p_x[x] - p_x[y], cy = p_y[x] - p_y[y];
	return sqrt(cx * cx + cy * cy);
}

bool checkEqual(double a, double b, double c) {
	return a-b <= c && b-a <= c;
}

double Judge() {
	fin >> r >> c >> m;
	fout >> out_res; fans >> ans_res;
	if (out_res != ans_res) {
		freport << "WA1";
		return 0;
	}
	if (out_res == "No") {
		freport << "AC";
		return 1;
	}
	for (int i = 1; i <= m; i++) {
		int p; fin >> p;
		vis[p] = 1;
	}
	for (int i = 1; i <= r*c; i++) {
		fout >> p_x[i] >> p_y[i];
		if (p_x[i] > 1e6 || p_y[i] > 1e6) {
			freport << "WA2";
			return 0.5;
		}
		if (p_x[i] < -1e6 || p_y[i] < -1e6) {
			freport << "WA2";
			return 0.5;
		}
		if (__isnan(p_x[i]) || __isnan(p_y[i])) {
			freport << "WA3";
			return 0.5;
		}
		if (__isinf(p_x[i]) || __isinf(p_y[i])) {
			freport << "WA4";
			return 0.5;
		}
	}
	bool found = false;
	vector<pair<double,double> > vec;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			vec.push_back(make_pair(p_x[c*(i-1)+j], p_y[c*(i-1)+j]));
			if (i < r) {
				if (!checkEqual(getDistance(c*(i-1)+j, c*i+j), 1, 1e-6)) {
					freport << "WA5";
					return 0.5;
				}
			}
			if (j < c) {
				if (!checkEqual(getDistance(c*(i-1)+j, c*(i-1)+j+1), 1, 1e-6)) {
					freport << "WA5";
					return 0.5;
				}
			}
			if (i < r && j < c) {
				if (!checkEqual(getDistance(c*(i-1)+j, c*i+j+1), sqrt(double(2)), 1e-4)) {
					found = true;
				}
				if (vis[c*(i-1)+j] && !checkEqual(getDistance(c*(i-1)+j, c*i+j+1), sqrt(double(2)), 1e-6)) {
					freport << "WA6";
					return 0.5;
				}
			}
		}
	}
	if (!found) {
		freport << "WA7";
		return 0.5;
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i+1 < vec.size(); i++) {
		if (checkEqual(vec[i].first, vec[i+1].first, 1e-6) && checkEqual(vec[i].second, vec[i+1].second, 1e-6)) {
			freport << "WA8";
			return 0.5;
		}
	}
	freport << "AC";
	return 1;
}

int main(int argc, char *argv[]) {
    fin.open(argv[1]);
    fout.open(argv[2]);
    fans.open(argv[3]);
    fscore.open(argv[5]);
    freport.open(argv[6]);
    int score = atoi(argv[4]);
    fscore << score * Judge() << endl;
    fin.close();
    fout.close();
    fans.close();
    fscore.close();
    freport.close();
    return 0;
}
