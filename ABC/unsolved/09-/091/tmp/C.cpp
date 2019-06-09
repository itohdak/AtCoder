#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

struct point{
  int x;
  int y;
};

bool comp(const point& p1, const point& p2){
  if(p1.x == p2.x)
    return p1.y <= p2.y;
  else
    return p1.x <= p2.x;
}

int main(){
  int N;
  cin >> N;
  vector<point> P, Q;
  for(int i=0; i<N; i++){
    int a, b;
    cin >> a >> b;
    point p = {a, b};
    P.push_back(p);
  }
  sort(P.begin(), P.end(), comp);
  for(int i=0; i<N; i++){
    int c, d;
    cin >> c >> d;
    point q = {c, d};
    Q.push_back(q);
  }
  sort(Q.begin(), Q.end(), comp);

  int ret = 0;
  bool used[N];
  for(int i=0; i<N; i++)
    used[i] = false;

  for(int i=0; i<N; i++){
    point q = Q[i];
    int j = 0;
    while(P[j].x < q.x){
      if(used[j]){
	j++;
      } else {
	if(P[j].y < q.y){
	  used[j] = true;
	  ret++;
	  break;
	} else {
	  j++;
	}
      }
    }
  }
  cout << ret << endl;

  return 0;
}

