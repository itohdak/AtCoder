#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  string S, T;
  cin >> S >> T;
  int U[26], V[26];
  for(int i=0; i<26; i++) {
    U[i] = -1;
    V[i] = -1;
  }
  bool ans = true;
  for(int i=0; i<S.size(); i++) {
    int tmp_s = (int)S[i]-(int)'a';
    int tmp_t = (int)T[i]-(int)'a';
    if(U[tmp_s] < 0) {
      U[tmp_s] = i;
    } else if(T[U[tmp_s]] != T[i]) {
      ans = false;
      break;
    }
    if(V[tmp_t] < 0) {
      V[tmp_t] = i;
    } else if(S[V[tmp_t]] != S[i]) {
      ans = false;
      break;
    }
  }
  if(ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}

