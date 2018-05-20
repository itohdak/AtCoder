#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  cout << max(0, min(B, D) - max(A, C)) << endl;
  return 0;
}

