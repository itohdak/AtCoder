#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  vector<int> N(4);
  int tmp[] = {1, 4, 7, 9};
  for(int i=0; i<4; i++) {
    cin >> N[i];
  }
  sort(N.begin(), N.end());
  bool ret = true;
  for(int i=0; i<4; i++) {
    if(N[i] != tmp[i])
      ret = false;
  }
  if(ret)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}

