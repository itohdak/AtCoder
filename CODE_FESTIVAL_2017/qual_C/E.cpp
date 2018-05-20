#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

#define ndiv 100

int main(){
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  bool occupied[C][A][B];
  bool answer[C][A][B];

  for(int z=0; z<C; z++){
    for(int x=0; x<A; x++){
      for(int y=0; y<B; y++){
	occupied[z][x][y] = false;
	answer[z][x][y] = false;
      }
    }
  }

  for(int z=0; z<C; z++){
    double xs = double(A) * z / C;
    double xe = double(A) * (z+1) / C;
    double ys = double(B) * z / C;
    double ye = double(B) * (z+1) / C;
    for(int i=0; i<ndiv; i++){
      double x = (xe - xs) * i / ndiv + xs;
      double y = (ye - ys) * i / ndiv + ys;
      occupied[z][int(floor(x))][int(floor(y))] = true;
    }
  }

  for(int z=0; z<C; z++){
    for(int x=0; x<A; x++){
      for(int y=0; y<B; y++){
	bool tmp = false;
	for(int xi=x-D; xi<=x+D; xi++){
	  for(int yi=y-D; yi<=y+D; yi++){
	    for(int zi=z-D; zi<=z+D; zi++){
	      if(xi >= 0 && xi < A &&
		 yi >= 0 && yi < B &&
		 zi >= 0 && zi < C &&
		 occupied[zi][xi][yi]){
		tmp = true;
		break;
	      }
	    }
	    if(tmp) break;
	  }
	  if(tmp) break;
	}
	answer[z][x][y] = tmp;
      }
    }
  }

  int ret = 0;
  for(int z=0; z<C; z++)
    for(int x=0; x<A; x++)
      for(int y=0; y<B; y++)
	if(answer[z][x][y])
	  ret++;

  cout << ret << endl;

  return 0;
}

