#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

// 回分の半径を求める
void Manacher(string S, vector<int>& res) {
  int i=0, j=0;
  while(i < S.size()) {
    while(i-j >= 0 && i+j < S.size() && S[i-j] == S[i+j]) ++j;
    res[i] = j;
    int k=1;
    while(i-k >= 0 && i+k < S.size() && k+res[i-k] < j) res[i+k] = res[i-k], ++k;
    i += k; j -= k;
  }
}

// SとS[i:]の最長共有接頭辞の長さを求める
void Zalgorithm(string S, vector<int>& res) {
  res[0] = S.size();
  int i = 1, j = 0;
  while (i < S.size()) {
    while (i+j < S.size() && S[j] == S[i+j]) ++j;
    res[i] = j;
    if (j == 0) { ++i; continue;}
    int k = 1;
    while (i+k < S.size() && k+res[k] < j) res[i+k] = res[k], ++k;
    i += k; j -= k;
  }
}

int main() {
  string S = "abaaababa";
  vector<int> res(S.size());
  Manacher(S, res);
  cout << S << endl;
  rep(i, S.size()) // 121412321
    cout << res[i];
  cout << endl;

  string T = "aaabaaaab";
  Zalgorithm(T, res);
  cout << T << endl;
  rep(i, S.size()) // 921034210
    cout << res[i];
  cout << endl;

  return 0;
}

