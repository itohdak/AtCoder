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
  if(N % 2 == 0)
    cout << N << endl;
  else
    cout << 2 * N << endl;
  return 0;
}

