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
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

template< typename T >
struct BinaryIndexedTree {
  vector< T > data;

  BinaryIndexedTree(int sz) {
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};
int count(vector<int>& P) {
  int n = P.size();
  BinaryIndexedTree<int> bit(n);
  int res = 0;
  rep(i, n) {
    bit.add(P[i], 1);
    res += i+1-bit.sum(P[i]);
  }
  return res;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> A(n), B(n);
  rep(i, n) cin >> A[i];
  rep(i, n) cin >> B[i];
  int ans = inf;
  rep(i, 1<<n) {
    vector<int> v;
    map<int, vector<int>> odd, even;
    rep(j, n) {
      if((i>>j)&1) { // うら
        v.push_back(B[j]);
        if(j%2) { // 奇数 -> 偶数
          even[B[j]].push_back(j);
        } else { // 偶数 -> 奇数
          odd[B[j]].push_back(j);
        }
      } else { // おもて
        v.push_back(A[j]);
        if(j%2) { // 奇数 -> 奇数
          odd[A[j]].push_back(j);
        } else { // 偶数 -> 偶数
          even[A[j]].push_back(j);
        }
      }
    }
    sort(all(v));
    map<int, vector<int>> odd2, even2;
    rep(j, n) {
      if(j%2) {
        odd2[v[j]].push_back(j);
      } else {
        even2[v[j]].push_back(j);
      }
    }
    bool ok = true;
    int tmp = 0;
    vector<int> P(n);
    for(auto ele: odd) {
      if(ele.second.size() != odd2[ele.first].size()) ok = false;
      else {
        rep(k, ele.second.size()) {
          tmp += abs(ele.second[k]-odd2[ele.first][k]);
          P[odd2[ele.first][k]] = ele.second[k];
        }
      }
    }
    for(auto ele: even) {
      if(ele.second.size() != even2[ele.first].size()) ok = false;
      else {
        rep(k, ele.second.size()) {
          tmp += abs(ele.second[k]-even2[ele.first][k]);
          P[even2[ele.first][k]] = ele.second[k];
        }
      }
    }
    if(!ok) continue;
    int cnt = count(P);
    // cout << P << ' ' << cnt << "\n";
    ans = min(cnt, ans);
  }
  cout << (ans == inf ? -1 : ans) << "\n";
  return 0;
}
