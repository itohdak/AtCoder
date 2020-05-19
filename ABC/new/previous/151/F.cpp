#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

struct point {
  double x;
  double y;
  point(double x, double y): x(x), y(y) {}
};
double calc_dist(point p1, point p2) {
  double dx = p1.x - p2.x;
  double dy = p1.y - p2.y;
  return sqrt(dx*dx+dy*dy);
}
point operator+(point p1, point p2) {
  return point(p1.x+p2.x, p1.y+p2.y);
}
point operator/(point p, double d) {
  return point(p.x/d, p.y/d);
}
point operator*(point p, double d) {
  return point(d*p.x, d*p.y);
}
point operator*(double d, point p) {
  return point(d*p.x, p.y);
}

int N;
vector<point> P;
vector<point> intersection(point p1, point p2, double r) {
  point mid = (p1+p2)/2.0; // center
  point diff = point((p1.y-p2.y)/2, -(p1.x-p2.x)/2); // slope
  double dist = calc_dist(p1, p2); // distance
  vector<point> ret; // intersection
  if(dist/2 > r) {
  } else if(dist/2 == r) {
    ret.push_back(mid);
  } else {
    double h = sqrt(1-dist*dist/(4*r*r));
    ret.push_back(mid+(h*diff));
    ret.push_back(mid+(-h*diff));
  }
  return ret;
}

bool test(double k) {
  auto intr = intersection(P[0], P[1], k);
  if(intr.size() != 0) {
    for(auto i: intr) {
      bool ret = true;
      rep(j, N) {
        if(calc_dist(i, P[j]) > k) {
          ret = false;
          break;
        }
      }
      if(!ret) continue;
      return true;
    }
  }
  return false;
}

double binary_search(double n) {
  double ng = 0, ok = n;
  rep(i, 50) {
    double mid = (ok + ng) / 2;
    if(test(mid)) ok = mid;
    else ng = mid;
  }
  return ok;
}

int main() {
  cin >> N;
  P = vector<point>();
  rep(i, N) {
    int x, y;
    cin >> x >> y;
    P.push_back(point(x, y));
  }
  double mx = 0;
  rep(i, N) rep(j, N) mx = max(calc_dist(P[i], P[j]), mx);
  double ans = binary_search(mx/2);
  cout << setprecision(20) << ans << endl;
  return 0;
}
