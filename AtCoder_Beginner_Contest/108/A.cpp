#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int K;
  cin >> K;
  cout << K/2 * (K-K/2) << endl;
  return 0;
}

