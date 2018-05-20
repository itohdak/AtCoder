#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>

using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  vector<int> A;
  for(int i=0; i<N; i++)
    A.push_back(0);
  for(int i=0; i<N; i++){
    int in;
    cin >> in;
    A[in-1]++;
  }
  sort(A.begin(), A.end(), greater<int>());
  cout << accumulate(A.begin()+K, A.end(), 0) << endl;
  return 0;
}

