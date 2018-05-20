#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>

using namespace std;

bool dp(int i, int x, const vector<int> xs, char x_or_y){// i回目にxにいられるかどうか
  if(i == 0){
    if(x == 0) return true;
    else return false;
  }

  int sum = 8000;
  int memo_size = 2 * sum + 1;
  bool memo[i][memo_size];
  for(int a=0; a<i; a++)
    for(int b=0; b<memo_size; b++)
      memo[a][b] = false;

  // 境界条件
  if(x_or_y == 'x')
    memo[0][sum+xs[0]] = true;
  else if(x_or_y == 'y'){
    memo[0][sum+xs[0]] = true;
    memo[0][sum-xs[0]] = true;
  }

  for(int a=1; a<i; a++){
    for(int b=0; b<memo_size; b++){
      if(memo[a-1][b]){
	memo[a][b+xs[a]] = true;
	memo[a][b-xs[a]] = true;
      }
    }
  }

  return memo[i-1][sum+x];
}

int main(){
  string s;
  int x, y;
  cin >> s >> x >> y;
  int i = 0;
  vector<int> iter_xs, iter_ys;
  while(i < s.size()){
    int iter_x = 0, iter_y = 0;
    while(s[i] != 'T' && i < s.size()){
      iter_x++; i++;
    }
    iter_xs.push_back(iter_x);
    i++;
    while(s[i] != 'T' && i < s.size()){
      iter_y++; i++;
    }
    iter_ys.push_back(iter_y);
    i++;
  }
  if(dp(iter_xs.size(), x, iter_xs, 'x') && dp(iter_ys.size(), y, iter_ys, 'y'))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
