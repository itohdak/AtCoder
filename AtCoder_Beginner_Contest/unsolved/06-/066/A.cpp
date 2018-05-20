#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  int sum = a + b + c;
  cout << sum - max(a, max(b, c)) << endl;
  return 0;
}

