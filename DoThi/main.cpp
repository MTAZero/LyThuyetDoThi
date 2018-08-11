#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <conio.h>

using namespace std;

const int maxn = 5555;

int a[maxn][maxn];
int n;
int _next[maxn], _prev[maxn];
bool fl[maxn];

void NhapDoThi() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
}

void visit(int k) {
	fl[k] = false;
	for(int j=1; j<=n; j++)
		if (j != k && fl[j]) {
			_next[k] = j;
			_prev[j] = k;
			visit(j);
		}
}

void XuLy() {
	// kiem tra do thi day du
	int dem = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j && a[i][j] == 1) dem++;
	if (dem != n*(n - 1))
		cout << "Day khong phai la do thi day du" << endl;
	else
		cout << "Day la do thi day du K" << n << endl;

	// kiem tra do thi chinh quy
	int i1 = 0;
	for (int j = 1; j <= n; j++)
		if (j != 1 && a[1][j] == 1) i1++;
	bool ok = true;
	for (int i = 2; i <= n; i++) {
		int demj;
		demj = 0;
		for (int j = 1; j <= n; j++)
			if (i != j && a[i][j] == 1)
				demj++;
		if (demj != i1) {
			ok = false;
			break;
		}
	}
	if (ok)
		cout << "Day la do thi " << i1 << "-chinh quy" << endl;
	else
		cout << "Day khong phai la do thi chinh quy" << endl;

	// kiem tra do thi vong
	ok = true;
	for (int i = 1; i <= n; i++) {
		int demj;
		demj = 0;
		for (int j = 1; j <= n; j++)
			if (i != j && a[i][j] == 1)
				demj++;
		if (demj != 2) {
			ok = false;
			break;
		}
	}
	if (!ok) {
		cout << "Day khong phai la do thi vong" << endl;
		return;
	}

	memset(fl, true, sizeof(fl));
	visit(1);
	int z = 1;
	while (_next[z] != 0) z = _next[z];
	if (a[z][1])
		cout << "Day la do thi vong C" << n << endl;
	else
		cout << "Day khong phai la do thi vong" << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	NhapDoThi();
	XuLy();

	getch();
	return 0;
}