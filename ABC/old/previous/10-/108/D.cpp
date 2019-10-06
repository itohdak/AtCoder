#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

struct data {
  int from, to;
  int cost;
  data(int from, int to, int cost): from(from), to(to), cost(cost) {}
};

int main() {
  int L;
  cin >> L;
  int r = floor(log2(L));
  int N = r+1;
  vector<data> ans;
  REP(i, 1, r+1) {
    ans.push_back(data(i, i+1, 0));
    ans.push_back(data(i, i+1, pow(2, i-1)));
  }
  for(int i=N-1; i>=1; i--)
    if(L - pow(2, i-1) >= pow(2, r)) {
      ans.push_back(data(i, N, L-pow(2, i-1)));
      L -= pow(2, i-1);
    }
  cout << N << ' ' << ans.size() << endl;
  for(auto a: ans)
    cout << a.from << ' ' << a.to << ' ' << a.cost << endl;
  return 0;
}

