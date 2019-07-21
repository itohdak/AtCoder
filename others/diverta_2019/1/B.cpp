#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main() {
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  ll ans = 0;
  for(int r=0; r<=N/R; r++) {
    for(int g=0; g<=(N-R*r)/G; g++) {
      if((N-R*r-G*g) % B == 0)
	ans++;
    }
  }
  cout << ans << endl;
  return 0;
}

