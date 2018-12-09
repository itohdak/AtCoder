#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N, M;
  cin >> N >> M;
  vector<int> C(N, 0);
  for(int i=0; i<M; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    C[a]++;
    C[b]++;
  }
  for(int i=0; i<N; i++)
    cout << C[i] << endl;
  return 0;
}

