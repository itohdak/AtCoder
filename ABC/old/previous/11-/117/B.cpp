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
  vector<int> L(N);
  for(int i=0; i<N; i++)
    cin >> L[i];
  sort(L.begin(), L.end());
  if(accumulate(L.begin(), L.end(), 0) > 2 * L[N-1])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}

