#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N;
  int T, A;
  cin >> N >> T >> A;
  vector<int> H(N);
  double min = 1000;
  int ind = -1;
  for(int i=0; i<N; i++) {
    cin >> H[i];
    if(abs(T - H[i] * 0.006 - A) < min) {
      min = abs(T - H[i] * 0.006 - A);
      ind = i + 1;
    }
  }
  cout << ind << endl;
  return 0;
}

