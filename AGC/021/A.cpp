#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  ll N;
  cin >> N;
  int digit = floor(log10l(N)) + 1;
  if((N + 1) % (ll)pow(10, digit-1) == 0)
    cout << 9 * (digit-1) + N / (ll)pow(10, digit-1) << endl;
  else
    cout << 9 * (digit-1) + N / (ll)pow(10, digit-1) - 1 << endl;
  return 0;
}

