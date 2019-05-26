#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main() {
  int N, K;
  string S;
  cin >> N >> K >> S;
  S[K-1] = 'a' + int(S[K-1] - 'A');
  cout << S << endl;
  return 0;
}

