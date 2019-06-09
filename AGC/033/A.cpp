#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)
#include <queue>

using namespace std;
#define ll long long

bool isAllBlack(vector<vector<char> > A, int H, int W) {
  for(int i=0; i<H; i++)
    for(int j=0; j<W; j++)
      if(A[i][j] == '.')
	return false;
  return true;
}

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char> > A(H, vector<char>(W));
  vector<queue<pair<int, int> > > B(2);
  for(int i=0; i<H; i++)
    for(int j=0; j<W; j++) {
      cin >> A[i][j];
      if(A[i][j] == '#')
	B[0].push(make_pair(i, j));
    }
  int tmp = 0;
  int ans = 0;
  while(!isAllBlack(A, H, W)) {
    int next = (tmp + 1) % 2;
    while(!B[tmp].empty()) {
      pair<int, int> p = B[tmp].front();
      if(p.first-1 >= 0 && A[p.first-1][p.second] == '.') {
	A[p.first-1][p.second] = '#';
	B[next].push(make_pair(p.first-1, p.second));
      }
      if(p.first+1 < H && A[p.first+1][p.second] == '.') {
	A[p.first+1][p.second] = '#';
	B[next].push(make_pair(p.first+1, p.second));
      }
      if(p.second-1 >= 0 && A[p.first][p.second-1] == '.') {
	A[p.first][p.second-1] = '#';
	B[next].push(make_pair(p.first, p.second-1));
      }
      if(p.second+1 < W && A[p.first][p.second+1] == '.') {
	A[p.first][p.second+1] = '#';
	B[next].push(make_pair(p.first, p.second+1));
      }
      B[tmp].pop();
    }
    tmp = next;
    ans++;
  }
  cout << ans << endl;
  return 0;
}
