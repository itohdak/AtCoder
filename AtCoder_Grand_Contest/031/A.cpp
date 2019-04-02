#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long
#define mod 1000000007

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  vector<int> alph(26, 0);
  for(int i=0; i<S.size(); i++) {
    alph[int(S[i]-'a')]++;
  }
  ll ans = 1;
  for(int i=0; i<26; i++) {
    ans *= (alph[i]+1);
    ans %= mod;
  }
  ans--;
  ans %= mod;
  cout << ans << endl;
  return 0;
}

