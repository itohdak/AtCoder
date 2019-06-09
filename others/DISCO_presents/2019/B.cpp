#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

double outer(double x1, double y1, double x2, double y2){
  return x1 * y2 - y1 * x2;
}

bool insidep(double x, double y){
  bool ret = true;
  if(outer(0.5, -0.5, x, y-0.5) < -0.0001) ret = false;
  if(outer(0.5, 0.5, x-0.5, y) < -0.0001) ret = false;
  if(outer(-0.5, 0.5, x-1.0, y-0.5) < -0.0001) ret = false;
  if(outer(-0.5, -0.5, x-0.5, y-1.0) < -0.0001) ret = false;
  return ret;
}

int main(){
  int N;
  cin >> N;
  int res = 0;
  double d = (double)1.0 / N;

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      double x = d * i;
      double y = d * j;
      if(insidep(x, y) && insidep(x+d, y) && insidep(x, y+d) && insidep(x+d, y+d)) {
	res++;
      }
    }
  }
  cout << res << endl;
  return 0;
}

