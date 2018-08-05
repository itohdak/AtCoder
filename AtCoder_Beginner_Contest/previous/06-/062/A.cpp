#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int group(int x){
  if(x == 2)
    return 3;
  else if(x == 4 || x == 6 || x == 9 || x == 11)
    return 2;
  else
    return 1;
}

int main(){
  int x, y;
  cin >> x >> y;
  int gx = group(x), gy = group(y);
  if(gx == gy)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}

