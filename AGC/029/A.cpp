#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  string S;
  cin >> S;
  int N = (int)S.size();
  ll ans = 0;
  int end = N-1;
  for(int i=N-1; i>=0; i--) {
    if(S[i] == 'B') {
      ans += end - i;
      end--;
    }
  }
  cout << ans << endl;
  return 0;
}

