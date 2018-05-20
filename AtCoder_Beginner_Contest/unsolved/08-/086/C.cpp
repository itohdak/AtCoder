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
  int t, x, y;
  int tp = 0, xp = 0, yp = 0;
  bool ok = true;
  for(int i=0; i<N; i++){
    cin >> t >> x >> y;
    if(ok){
      int d = (t - tp) - (abs(x - xp) + abs(y - yp));
      if(!(d >= 0 && d % 2 == 0)){
	ok = false;
      } else {
	tp = t;
	xp = x;
	yp = y;
      }
    }
  }
  if(ok)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}

