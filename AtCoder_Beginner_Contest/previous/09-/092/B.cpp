#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N, D, X;
  cin >> N >> D >> X;
  for(int i=0; i<N; i++){
    int in;
    cin >> in;
    X += (D - 1) / in + 1;
  }
  cout << X << endl;
  return 0;
}

