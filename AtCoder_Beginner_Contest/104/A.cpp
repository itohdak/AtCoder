#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int R;
  cin >> R;
  if(R < 1200)
    cout << "ABC" << endl;
  else if(R < 2800)
    cout << "ARC" << endl;
  else
    cout << "AGC" << endl;
  return 0;
}

