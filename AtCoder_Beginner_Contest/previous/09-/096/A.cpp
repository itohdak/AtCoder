#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int a, b;
  cin >> a >> b;
  if(a <= b)
    cout << a << endl;
  else
    cout << a-1 << endl;
  return 0;
}

