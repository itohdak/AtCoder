#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  ll N, M;
  cin >> N >> M;
  if(N == 1 && M == 1)
    cout << 1 << endl;
  else if(N == 1 || M == 1)
    cout << N * M - 2 << endl;
  else
    cout << N * M - (2 * (N + M) - 4) << endl;
  return 0;
}

