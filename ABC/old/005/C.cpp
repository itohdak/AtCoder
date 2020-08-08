#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t, n; cin >> t >> n;
  deque<int> q;
  rep(i, n) {
    int a; cin >> a;
    q.push_back(a);
  }
  int m; cin >> m;
  vector<int> B(m); rep(i, m) cin >> B[i];
  rep(i, m) {
    while(!q.empty() && q.front()+t<B[i]) q.pop_front();
    if(q.empty() || q.front()>B[i]) {
      cout << "no" << endk;
      return 0;
    }
    q.pop_front();
  }
  cout << "yes" << endk;
  return 0;
}
