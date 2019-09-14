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
  ll X;
  cin >> N >> X;
  vector<int> M;
  for(int i=0; i<N; i++){
    int in;
    cin >> in;
    X -= in;
    M.push_back(in);
  }
  sort(M.begin(), M.end());
  cout << N + X / M[0] << endl;
  return 0;
}

