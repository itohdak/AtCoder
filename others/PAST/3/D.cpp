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
  vector<string> S(5);
  rep(i, 5) cin >> S[i];
  string num[] = {".###.#.#.#.#.#.#.###", "..#..##...#...#..###",
                  ".###...#.###.#...###", ".###...#.###...#.###",
                  ".#.#.#.#.###...#...#", ".###.#...###...#.###",
                  ".###.#...###.#.#.###", ".###...#...#...#...#",
                  ".###.#.#.###.#.#.###", ".###.#.#.###...#.###"};
  vector<string> T(N, "");
  rep(i, 5) {
    rep(j, N) {
      T[j] += S[i].substr(4*j, 4);
    }
  }
  string ans = "";
  rep(i, N) rep(j, 10){
    if(T[i] == num[j]) {
      ans += char('0'+j);
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
