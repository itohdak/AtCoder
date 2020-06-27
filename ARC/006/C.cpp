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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> W(N);
  set<int> se;
  rep(i, N) {
    cin >> W[i];
    auto itr = se.lower_bound(W[i]);
    if(itr == se.end()) {
      se.insert(W[i]);
    } else {
      se.erase(itr);
      se.insert(W[i]);
    }
  }
  cout << se.size() << "\n";
  return 0;
}
