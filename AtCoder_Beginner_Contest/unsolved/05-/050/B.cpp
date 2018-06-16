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
  cin >> N;
  vector<int> T;
  int sumT = 0;
  for(int i=0; i<N; i++){
    int t;
    cin >> t;
    T.push_back(t);
    sumT += t;
  }
  int M;
  cin >> M;
  for(int i=0; i<M; i++){
    int p, x;
    cin >> p >> x;
    cout << sumT - T[p-1] + x << endl;
  }
  return 0;
}

