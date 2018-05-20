#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;
#define it std::vector<int>::iterator

int main(){
  int n, k;
  cin >> n >> k;

  vector<int> x(n), y(n);
  vector<int> x_, y_;

  for(int i=0; i<n; i++){
    cin >> x[i] >> y[i];
    x_.push_back(x[i]);
    y_.push_back(y[i]);
  }
  sort(x_.begin(), x_.end());
  sort(y_.begin(), y_.end());

  long long ans = 1LL * (x_[n-1] - x_[0]) * (y_[n-1] - y_[0]);
  for(int xi=0; xi<n; xi++){
    for(int xj=xi+1; xj<n; xj++){
      for(int yi=0; yi<n; yi++){
	for(int yj=yi+1; yj<n; yj++){
	  int num = 0;
	  long long lx = x_[xi], rx = x_[xj];
	  long long by = y_[yi], uy = y_[yj];
	  for(int i=0; i<n; i++){
	    if(lx <= x[i] and x[i] <= rx and by <= y[i] and y[i] <= uy){
	      num++;
	    }
	  }
	  if(num >= k) ans = min(ans, 1LL * (rx - lx) * (uy - by));
	}
      }
    }
  }

  cout << ans << endl;

  return 0;
}

