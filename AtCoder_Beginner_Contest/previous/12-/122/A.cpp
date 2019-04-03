#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  char b;
  cin >> b;
  if(b == 'A')
    cout << 'T' << endl;
  else if(b == 'T')
    cout << 'A' << endl;
  else if(b == 'C')
    cout << 'G' << endl;
  else if(b == 'G')
    cout << 'C' << endl;
  return 0;
}

