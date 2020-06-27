#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

const ll MAX_N = 1e9+7;
class Doubling {
public:
  int N;
  int logN = ceil(log2(MAX_N));
  vector<vector<int>> next;

  Doubling(int N, vector<int>& ini) {
    next = vector<vector<int>>(logN+1, vector<int>(N));
    rep(i, N) next[0][i] = ini[i];
    rep(k, logN) {
      rep(i, N) {
        next[k+1][i] = (next[k][i] == -1 ? -1 : next[k][next[k][i]]);
      }
    }
  }

  int query(int p, ll q) {
    for(int k=logN-1; k>=0; k--) {
      if(p == -1) break;
      if((q>>k)&1) p = next[k][p];
    }
    return p;
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M;
  ll D;
  cin >> N >> M >> D;
  vector<int> A(M);
  rep(i, M) {
    cin >> A[i];
    A[i]--;
  }
  vector<int> B(N);
  rep(i, N) B[i] = i;
  rep(i, M) swap(B[A[i]], B[A[i]+1]);
  vector<int> to(N);
  rep(i, N) to[B[i]] = i;
  Doubling db(N, to);
  rep(i, N) {
    cout << db.query(i, D)+1 << endl;
  }
  return 0;
}
