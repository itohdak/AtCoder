#include <bits/stdc++.h>
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
  int N;
  ll A, B, C;
  cin >> N >> A >> B >> C;
  vector<string> S(N+1);
  S[N] = "AB";
  vector<char> ans;
  rep(i, N) cin >> S[i];
  rep(i, N) {
    if(S[i] == "AB") {
      if(A == 0 && B == 0) {
        break;
      } else if(A == 0) {
        A++; B--;
        ans.push_back('A');
      } else if(B == 0) {
        B++; A--;
        ans.push_back('B');
      } else if(A == 1 && B == 1) {
        if(S[i+1] == "AB") {
          A--; B++;
          ans.push_back('B');
        } else if(S[i+1] == "BC") {
          B++; A--;
          ans.push_back('B');
        } else {
          A++; B--;
          ans.push_back('A');
        }
      } else if(A > B) {
        A--; B++;
        ans.push_back('B');
      } else {
        A++; B--;
        ans.push_back('A');
      }
    } else if(S[i] == "BC") {
      if(B == 0 && C == 0) {
        break;
      } else if(B == 0) {
        B++; C--;
        ans.push_back('B');
      } else if(C == 0) {
        C++; B--;
        ans.push_back('C');
      } else if(B == 1 && C == 1) {
        if(S[i+1] == "BC") {
          B--; C++;
          ans.push_back('C');
        } else if(S[i+1] == "AC") {
          C++; B--;
          ans.push_back('C');
        } else {
          B++; C--;
          ans.push_back('B');
        }
      } else if(B > C) {
        B--; C++;
        ans.push_back('C');
      } else {
        B++; C--;
        ans.push_back('B');
      }
    } else {
      if(C == 0 && A == 0) {
        break;
      } else if(C == 0) {
        C++; A--;
        ans.push_back('C');
      } else if(A == 0) {
        A++; C--;
        ans.push_back('A');
      } else if(C == 1 && A == 1) {
        if(S[i+1] == "AC") {
          C--; A++;
          ans.push_back('A');
        } else if(S[i+1] == "AB") {
          A++; C--;
          ans.push_back('A');
        } else {
          C++; A--;
          ans.push_back('C');
        }
      } else if(C > A) {
        C--; A++;
        ans.push_back('A');
      } else {
        C++; A--;
        ans.push_back('C');
      }
    }
  }
  if(ans.size() == N) {
    cout << "Yes" << endl;
    rep(i, N) cout << ans[i] << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}

