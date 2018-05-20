#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int X, t;
  cin >> X >> t;
  cout << max(X-t, 0) << endl;
  return 0;
}

