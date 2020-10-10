#include "header.hpp"

/* Copied from ABC151F Enclose All */
#define vec point
struct point {
  ld x, y;
  point(ld x, ld y) : x(x), y(y) {}
  point operator+(const point& rhs) const {
    return point(x+rhs.x, y+rhs.y);
  }
  point operator-(const point& rhs) const {
    return point(x-rhs.x, y-rhs.y);
  }
  point operator*(const ld& d) const {
    return point(x*d, y*d);
  }
  point operator/(const ld& d) const {
    assert(d != 0);
    return point(x/d, y/d);
  }
  ld length() {
    return sqrt(x*x+y*y);
  }
  point perpendicular() {
    ld d = this->length();
    assert(d != 0);
    return point(y, -x) / d;
  }
};
point midpoint(point p1, point p2) {
  return (p1+p2)/2;
}
struct circle {
  point center;
  ld r;
  circle(ld cx=0, ld cy=0, ld r=1) : center(point(cx, cy)), r(r) {}
  circle(point center, ld r) : center(center), r(r) {}
};
vector<point> intersection(circle c1, circle c2) { // c1.r == c2.r
  ld r = c1.r;
  point mid = midpoint(c1.center, c2.center);
  vec dir = c2.center - c1.center;
  ld dh = dir.length();
  vec perp = dir.perpendicular();
  ld dv = sqrt(r*r-(dh/2)*(dh/2));
  vector<point> ret;
  if(dh > r*2+eps) { // no intersection
  } else {
    ret.push_back(mid+perp*dv);
    ret.push_back(mid-perp*dv);
  }
  return ret;
}
