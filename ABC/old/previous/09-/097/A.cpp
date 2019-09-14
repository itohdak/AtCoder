#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if(abs(a - c) <= d || (abs(a - b) <= d && abs(b - c) <= d))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}

