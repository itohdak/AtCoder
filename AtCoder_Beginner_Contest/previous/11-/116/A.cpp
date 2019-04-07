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
  int maxL = max(a, max(b, c));
  if(maxL == a)
    cout << b * c / 2 << endl;
  else if(maxL == b)
    cout << a * c / 2 << endl;
  else
    cout << a * b / 2 << endl;
  return 0;
}

