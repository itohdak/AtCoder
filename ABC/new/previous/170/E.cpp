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
  int N, Q;
  cin >> N >> Q;
  vector<ll> A(N), B(N), C(Q), D(Q);
  vector<multiset<ll>> vse(200005);
  rep(i, N) {
    cin >> A[i] >> B[i];
    vse[B[i]].insert(A[i]);
  }
  multiset<ll> se;
  rep(i, 200005) {
    if(vse[i].empty()) continue;
    se.insert(*(--vse[i].end()));
  }
  rep(i, Q) {
    cin >> C[i] >> D[i];
    C[i]--;
  }
  // cout << se << endl;
  rep(i, Q) {
    ll a = A[C[i]];
    ll b = B[C[i]];
    ll d = D[i];
    auto itr = vse[b].find(a);
    bool flag = false;
    if(itr == --vse[b].end()) flag = true;
    vse[b].erase(itr);
    if(flag) {
      se.erase(se.find(a));
      if(!vse[b].empty()) se.insert(*(--vse[b].end()));
    }
    if(vse[d].empty()) {
      se.insert(a);
    } else if(a > *(--vse[d].end())) {
      se.erase(se.find(*(--vse[d].end())));
      se.insert(a);
    }
    vse[d].insert(a);
    B[C[i]] = d;
    // cout << se << endl;
    cout << *se.begin() << endl;
  }
  return 0;
}
