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

  auto split = [&](const string &s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string item;
    while(getline(ss, item, delim)) {
      if(!item.empty()) {
        elems.push_back(item);
      }
    }
    return elems;
  };

  auto isSame = [&](string s, string t) {
    int n = s.size();
    rep(i, n) {
      if(s[i] == t[i] || t[i] == '*') continue;
      return false;
    }
    return true;
  };

  string s;
  getline(cin, s);
  vector<string> word = split(s, ' ');
  int n; cin >> n;
  vector<string> T(n);
  rep(i, n) cin >> T[i];
  rep(k, word.size()) {
    rep(i, n) {
      if(word[k].size() == T[i].size()) {
        if(isSame(word[k], T[i])) {
          rep(j, word[k].size()) word[k][j] = '*';
        }
      }
    }
  }
  rep(k, word.size()) {
    cout << word[k] << (k==word.size()-1 ? "\n" : " ");
  }
  return 0;
}
