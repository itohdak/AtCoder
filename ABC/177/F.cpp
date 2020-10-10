#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int h, w; cin >> h >> w;
  vector<int> A(h), B(h);
  rep(i, h) cin >> A[i] >> B[i]; // 1-indexed
  map<int, int> mp; // (end, begin)
  multiset<int> st;
  rep(i, w) {
    mp[i+1] = i+1;
    st.insert(0);
  }
  rep(i, h) {
    auto itr = mp.lower_bound(A[i]);
    while(itr != mp.end()) {
      if(itr->first > B[i]) break;
      st.erase(st.find(itr->first-itr->second));
      if(B[i] < w) {
        if(mp[B[i]+1] < itr->second) {
          if(mp[B[i]+1] != 0) st.erase(st.find(B[i]+1-mp[B[i]+1]));
          mp[B[i]+1] = itr->second;
          st.insert(B[i]+1-mp[B[i]+1]);
        }
      }
      itr = mp.erase(itr);
    }
    assert(!(mp.empty()^st.empty()));
    if(mp.empty()) {
      cout << -1 << endl;
    } else {
      cout << *st.begin() + i + 1 << endl;
    }
    // cout << mp << endl;
    // cout << st << endl;
  }
  return 0;
}
