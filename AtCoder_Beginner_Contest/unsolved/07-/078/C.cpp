#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int N, M;
  cin >> N >> M;

  int time_once = 100 * (N - M) + 1900 * M;
  double p_ok = pow(0.5, M);
  double p_ng = 1.0 - p_ok;

  cout << p_ok * time_once * (p_ng / p_ok + 1) / p_ok << endl;

  return 0;
}

