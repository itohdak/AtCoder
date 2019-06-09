#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int a, b, c, d, e, k;
  cin >> a >> b >> c >> d >> e >> k;
  if(e - a > k)
    cout << ":(" << endl;
  else
    cout << "Yay!" << endl;
  return 0;
}

