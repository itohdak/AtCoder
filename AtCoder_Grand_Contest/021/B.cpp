#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

struct point{
  ll x;
  ll y;
  ll r2;
};

struct lparam{
  ll a;
  ll b;
  ll c;
};

int main(){
  int N;
  cin >> N;
  vector<point> P;
  int max_ind = 0;
  ll max_l = 0;
  for(int i=0; i<N; i++){
    int inx, iny;
    cin >> inx >> iny;
    point p = {inx, iny, inx * inx + iny * iny};
    P.push_back(p);
  }
  return 0;
}

