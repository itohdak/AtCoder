#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  string s;
  cin >> s;
  int K;
  cin >> K;
  vector<string> sss;
  for(int i=0; i<(int)s.size(); i++){
    for(int j=i; j<i+K; j++){
      sss.push_back(s.substr(i, j-i+1));
    }
  }
  sort(sss.begin(), sss.end());
  int begin = 0;
  while(begin < (int)sss.size()){
    string stmp = sss[begin];
    int end = begin;
    while(end < (int)sss.size() && sss[end] == stmp)
      end++;
    sss.erase(sss.begin()+begin+1, sss.begin()+end);
    begin++;
  }
  // for(int i=0; i<(int)sss.size(); i++)
  //   cout << sss[i] << ' ';
  // cout << endl;
  cout << sss[K-1] << endl;
  return 0;
}

