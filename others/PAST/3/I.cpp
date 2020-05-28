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
  int N, Q;
  cin >> N >> Q;
  int cntT = 0;
  vector<int> R(N), C(N);
  rep(i, N) R[i] = i, C[i] = i;
  rep(q, Q) {
    int type;
    cin >> type;
    if(type == 1) {
      int a, b;
      cin >> a >> b;
      --a, --b;
      if(cntT%2==0) swap(C[a], C[b]);
      else          swap(R[a], R[b]);
    } else if(type == 2) {
      int a, b;
      cin >> a >> b;
      --a, --b;
      if(cntT%2==0) swap(R[a], R[b]);
      else          swap(C[a], C[b]);
    } else if(type == 3) {
      cntT++;
    } else if(type == 4) {
      int a, b;
      cin >> a >> b;
      --a, --b;
      if(cntT%2==0) cout << (ll)N*C[a]+R[b] << endl;
      else          cout << (ll)N*C[b]+R[a] << endl;
    }
    // rep(i, N) {
    //   rep(j, N) {
    //     if(cntT%2==0) cout << (ll)N*C[i]+R[j] << ' ';
    //     else          cout << (ll)N*C[j]+R[i] << ' ';
    //   }
    //   cout << endl;
    // }
    // cout << "=========================" << endl;
  }
  return 0;
}
