#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

bool comp(int c1, int c2) {
  return ceil(c1 / 10.0) * 10 - c1 > ceil(c2 / 10.0) * 10 - c2;
}

int main(){
  vector<int> cookTime(5);
  for(int i=0; i<5; i++)
    cin >> cookTime[i];
  sort(cookTime.begin(), cookTime.end(), comp);
  int ans = cookTime[0];
  for(int i=1; i<5; i++)
    ans += ceil(cookTime[i] / 10.0) * 10;
  cout << ans << endl;
  return 0;
}

