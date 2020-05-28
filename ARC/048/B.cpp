#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> R(N), H(N), id(N);
  rep(i, N) {
    cin >> R[i] >> H[i];
    H[i]--;
    id[i] = i;
  }
  sort(all(id), [&](int i, int j) { return R[i] < R[j]; });
  int cnt = 0;
  int l = 0, r = 0;
  vector<int> W(N), L(N), D(N);
  while(l < N) {
    int rate = R[id[l]];
    vector<int> cntTmp(3);
    while(r < N && R[id[r]] == rate) {
      cntTmp[H[id[r]]]++;
      r++;
    }
    // cout << l << ' ' << r << ' ' << cntTmp << endl;
    for(int i=l; i<r; i++) {
      W[id[i]] = cnt + cntTmp[(H[id[i]]+1)%3];
      D[id[i]] = cntTmp[H[id[i]]]-1;
      L[id[i]] = N-1 - W[id[i]] - D[id[i]];
    }
    cnt += accumulate(all(cntTmp), 0);
    l = r;
  }
  rep(i, N) cout << W[i] << ' ' << L[i] << ' ' << D[i] << endl;
  return 0;
}
