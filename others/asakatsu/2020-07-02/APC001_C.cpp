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
  auto bsearch = [&]() {
    string s0;
    bool done = false;
    auto query = [&](int k) {
      cout << k << endl;
      string res; cin >> res;
      done = (res=="Vacant");
      return res;
    };
    auto test = [&](int k) {
      string res = query(k);
      return ((res==s0 && k%2) || (res!=s0 && k%2==0));
    };
    s0 = query(0);
    if(done) return;
    int ok = N, ng = -1;
    while(ok-ng>1) {
      // cout << ok << ' ' << ng << endl;
      int mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
      if(done) return;
    }
  };
  bsearch();
  return 0;
}
