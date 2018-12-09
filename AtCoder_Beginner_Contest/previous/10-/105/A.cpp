#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N, K;
  cin >> N >> K;
  if(N % K == 0)
    cout << 0 << endl;
  else
    cout << 1 << endl;
  return 0;
}

