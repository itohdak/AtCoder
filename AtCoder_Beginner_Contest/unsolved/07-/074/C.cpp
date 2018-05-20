#include <iostream>
#include <cstdlib>

using namespace std;

bool test_water(int A, int B, int X){
  int max = X / B;
  for(int i=0; i<=max; i++){
    if((X-B*i)%A == 0)
      return true;
  }
  return false;
}

bool test_suger(int C, int D, int Y){
  int max = Y / D;
  for(int i=0; i<=max; i++){
    if((Y-D*i)%C == 0)
      return true;
  }
  return false;
}

int main(){
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  int w_suger_water = 0;
  int w_suger = 0;
  double tmp_concentration = 0;

  for(int x=1; x<=f/100; x++){ // water
    for(int y=0; y<=f-100*x; y++){ // suger
      if(y <= x*e){ // Can suger be dissolved?
	if(test_water(a, b, x) && test_suger(c, d, y)){
	  double concentration;
	  if(x == 0 && y == 0){
	    concentration = 0;
	  } else {
	    concentration = double(y)/(100*x+y);
	  }
	  if(concentration > tmp_concentration){
	    w_suger_water = 100 * x + y;
	    w_suger = y;
	    tmp_concentration = concentration;
	  }
	}
      }
    }
  }

  cout << w_suger_water << ' ' << w_suger << endl;

  return 0;
}

