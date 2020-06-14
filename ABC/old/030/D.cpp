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
  int N, a;
  string K;
  cin >> N >> a >> K; a--;
  int l = K.size();
  vector<int> B(N);
  rep(i, N) {
    cin >> B[i];
    B[i]--;
  }
  set<int> se;
  vector<int> path;
  while(!se.count(a)) {
    path.push_back(a);
    se.insert(a);
    a = B[a];
  }
  // cout << path << endl;
  int begin = find(all(path), a) - path.begin();
  int nLoop = path.size() - begin;
  int rem = 0;
  rep(i, l) {
    (rem *= 10) %= nLoop;
    (rem += int(K[i]-'0')) %= nLoop;
  }
  if(l <= 6 && atoi(K.c_str()) < begin) {
    cout << path[atoi(K.c_str())]+1 << endl;
  } else {
    rem = (rem+(N+nLoop-1)/nLoop*nLoop-begin) % nLoop;
    cout << path[begin+rem]+1 << endl;
  }
  return 0;
}
