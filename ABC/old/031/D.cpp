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
  int K, N;
  cin >> K >> N;
  vector<string> V(N), W(N);
  rep(i, N) cin >> V[i] >> W[i];
  vector<int> len;
  auto check = [&]() {
    rep(i, N) {
      int sumLen = 0;
      for(char c: V[i]) {
        sumLen += len[int(c-'1')];
      }
      if(sumLen != (int)W[i].size()) return false;
    }
    // cout << len << endl;
    map<int, string> mp;
    rep(i, N) {
      int tmp = 0;
      for(char c: V[i]) {
        string substr = W[i].substr(tmp, len[int(c-'1')]);
        // cout << substr << endl;
        if(mp.count(int(c-'1')) && mp[int(c-'1')] != substr) return false;
        else mp[int(c-'1')] = substr;
        tmp += len[int(c-'1')];
      }
    }
    for(auto m: mp) cout << m.second << endl;
    return true;
  };
  function<void(int)> dfs = [&](int i) {
    if(i == K) {
      if(check()) exit(0);
    } else {
      for(int l=1; l<=3; l++) {
        len.push_back(l);
        dfs(i+1);
        len.pop_back();
      }
    }
  };
  dfs(0);
  return 0;
}
