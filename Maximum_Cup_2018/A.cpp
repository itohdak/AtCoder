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
  ll ret = 0;
  for(int i=0; i<N; i++){
    int t, d, m;
    cin >> t >> d >> m;
    if(t + 10 <= d) ret += m;
  }
  cout << ret << endl;
  return 0;
}

