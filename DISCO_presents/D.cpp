#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int h, w, a, b;
int m[200][201];

int do_work(int m[200][201], int h, int w, int a, int b){
  int sym1 = 0; // up_down_symmetry
  int sym2 = 0; // left_right_symmetry
  int sym3 = 0; // both_symmetry
  bool flags[4] = {false, false, false, false};
  for(int i=0; i<h/2; i++){
    for(int j=0; j<w/2; j++){
      int i_ = h-1-i;
      int j_ = j-1-j;
      if(m[i ][j ] == 'S') flags[0] = true;
      if(m[i ][j_] == 'S') flags[1] = true;
      if(m[i_][j ] == 'S') flags[2] = true;
      if(m[i_][j_] == 'S') flags[3] = true;
      if(flags[0] && flags[1] && flags[2] && flags[3]) sym3++;
      else if(flags[0] && flags[2])
	
    }
  }
}

int main(){
  int num_stone = 0;
  cin >> h >> w;
  cin >> a >> b;

  for(int i=0; i<h; i++){
    cin >> m[i];
    for(int j=0; j<w; j++)
      if(m[j] == 'S')
	num_stone++;
  }

  do_work();

  return 0;
}
