#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int N;
  cin >> N;
  int max_n = floor(sqrt(N));
  cout << max_n * max_n << endl;
  return 0;
}

