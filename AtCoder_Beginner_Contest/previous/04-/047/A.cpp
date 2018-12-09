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
  if(a + b == c || a + c == b || b + c == a)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}

