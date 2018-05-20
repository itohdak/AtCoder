#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

struct point1{
  int x;
  int y;
  int r;
};
struct point2{
  int x;
  int y;
};

int main(){
  int N, M;
  cin >> N >> M;
  vector<point1> Pn;
  vector<point2> Pm;
  for(int i=0; i<N; i++){
    int x, y, r;
    cin >> x >> y >> r;
    point1 p1 = {x, y, r};
    Pn.push_back(p1);
  }
  for(int i=0; i<M; i++){
    int x, y;
    cin >> x >> y;
    point1 p2 = {x, y};
    Pm.push_back(p2);
  }
  
  return 0;
}

