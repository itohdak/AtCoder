#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int in;
  cin >> in;
  int a, b, c, d;
  a = (in / 1000) % 10;
  b = (in / 100) % 10;
  c = (in / 10) % 10;
  d = (in / 1) % 10;

  if((a == b && b == c) || (b == c && c == d)) cout << "Yes";
  else cout << "No";
  cout << endl;

  return 0;
}

