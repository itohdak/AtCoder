#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

struct data {
  int x, y;
  data(int x_, int y_) : x(x_), y(y_) {}
};

int main() {
  int N;
  cin >> N;
  vector<data> A, B;
  rep(i, 2*N) {
    int x, y;
    cin >> x >> y;
    if(i < N)
      A.push_back(data(x, y));
    else
      B.push_back(data(x, y));
  }
  sort(B.begin(), B.end(), [](data d1, data d2) {return d1.x < d2.x;});
  vector<bool> match(N);
  int cnt = 0;
  rep(i, N) {
    int tmp = -1;
    int tmpY = -1;
    rep(j, N) {
      if(!match[j] && A[j].x < B[i].x && A[j].y < B[i].y && tmpY < A[j].y)
        tmpY = A[j].y, tmp = j;
    }
    if(tmp != -1)
      match[tmp] = true, cnt++;
  }
  cout << cnt << endl;
  return 0;
}

