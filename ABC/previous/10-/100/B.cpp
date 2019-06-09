#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int D, N;
  cin >> D >> N;
  cout << (ll)pow(100, D) * (N + N/100) << endl;
  return 0;
}

