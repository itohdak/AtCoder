#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int N, A, B;
  cin >> N >> A >> B;
  cout << min(N * A, B) << endl;
  return 0;
}

