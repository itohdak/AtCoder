#include "header.hpp"

vector<vector<int> > E; // edges
void dfs(int tmp, int par, int value){
  int next_val = 0;
  /*
    implement here
    ex) update next_val
  */
  for(int c: E[tmp])
    if(c != par)
      dfs(c, tmp, next_val);
}
// dfs(0, -1, 0)

