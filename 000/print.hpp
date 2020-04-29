#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
using namespace std;

template<class t, class u>
ostream& operator<<(ostream& os, const pair<t, u>& p) {
  return os << "{" << p.first << ", " << p.second << "}";
}
template<class t> ostream& operator<<(ostream& os, const vector<t>& v) {
  os << "{";
  for(int i=0; i<v.size(); i++) { if(i) os << ", "; os << v[i]; }
  return os << "}";
}
template<class t> ostream& operator<<(ostream& os, const set<t>& se) {
  os << "{";
  auto itr = se.begin();
  for(int i=0; i<se.size(); i++) { if(i) os << ", "; os << *itr; itr++; }
  return os << "}";
}
template<class t> ostream& operator<<(ostream& os, const unordered_set<t>& se) {
  os << "{";
  auto itr = se.begin();
  for(int i=0; i<se.size(); i++) { if(i) os << ", "; os << *itr; itr++; }
  return os << "}";
}
template<class t, class u>
ostream& operator<<(ostream& os, const map<t, u>& mp) {
  os << "{";
  auto itr = mp.begin();
  for(int i=0; i<mp.size(); i++) { if(i) os << ", "; os << *itr; itr++; }
  return os << "}";
}
