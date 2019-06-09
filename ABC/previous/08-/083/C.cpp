#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  long long X, Y;
  cin >> X >> Y;
  cout << floor(log2l(Y/X)) + 1 << endl;
  return 0;
}

