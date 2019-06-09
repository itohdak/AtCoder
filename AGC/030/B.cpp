#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

ll X[200000];
ll spin(int i, int j, int tmp, ll ans, ll L) {
  // cout << i << ' ' << j << ' ' << tmp << ' ' << ans << endl;
  if(i > j)
    return ans;
  ll dr;
  if(tmp > i)
    dr = X[i]+L-X[tmp];
  else
    dr = X[i]-X[tmp];
  ll dl;
  if(tmp > j)
    dl = X[tmp]-X[j];
  else
    dl = X[tmp]+L-X[j];
  if(dr < dl) {
    return spin(i, j-1, j, ans+dl, L);
  } else if(dr > dl) {
    return spin(i+1, j, i, ans+dr, L);
  } else {
    // cout << "branch" << endl;
    return max(spin(i, j-1, j, ans+dl, L), spin(i+1, j, i, ans+dr, L));
  }
}

int main(){
  ll L;
  int N;
  cin >> L >> N;
  X[0] = 0L;
  for(int i=0; i<N; i++)
    cin >> X[i+1];
  cout << spin(1, N, 0, 0L, L) << endl;
  return 0;
}

