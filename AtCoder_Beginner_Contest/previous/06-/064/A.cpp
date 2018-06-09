#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int r, g, b;
  cin >> r >> g >> b;
  if((g * 10 + b) % 4 == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}

