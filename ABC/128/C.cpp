#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> S(N);
  vector<int> P(N);
  for(int i=0; i<M; i++) {
    int k;
    cin >> k;
    for(int j=0; j<k; j++) {
      int s;
      cin >> s; s--;
      S[i] += (1 << s);
    }
  }
  for(int i=0; i<M; i++)
    cin >> P[i];
  int ans = 0;
  for(int i=0; i<(1<<N); i++) {
    bool res = true;
    for(int j=0; j<M; j++) {
      bool on_off = P[j] == 0;
      int tmp = i & S[j];
      for(int l=0; l<N; l++) {
	if(tmp % 2 == 1)
	  on_off = !on_off;
	tmp >>= 1;
      }
      if(!on_off) {
	res = false;
	break;
      }
    }
    if(res)
      ans++;
  }
  cout << ans << endl;
  return 0;
}

