#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class data{
private:
  long long h;
  long long p;
public:
  data(long long _h, long long _p){
    h = _h;
    p = _p;
  }
  ~data(){ }
  long long get_h(){ return h; }
  long long get_p(){ return p; }
};

bool compare(const data& d1, const data& d2){
  return d1.get_h() < d2.get_h();
}

int main(){
  int N;
  cin >> N;
  vector<data> D;
  for(int i=0; i<N; i++){
    long long hin, pin;
    cin >> hin >> pin;
    D.push_back(data(hin, pin));
  }
  sort(D.begin(), D.end(), compare);
  // print data
  for(int i=0; i<N; i++){
    cout << D[i].get_h() << ' ' << D[i].get_p() << endl;
  }
  //
  return 0;
}

