#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

struct data{
  long long h;
  long long p;
};

bool compare(const data& d1, const data& d2){
  return d1.h > d2.h;
}

int do_work(vector<data>::iterator begin, vector<data>::iterator end, long long tmp_p, int n){
  if(begin == end){
    cout << "hoge" << endl;
    return n;
  }
  data tmp_data = *begin;
  if(tmp_data.h < tmp_p)
    return do_work(++begin, end, tmp_p, n);
  else
    return do_work(++begin, end, tmp_p+tmp_data.p, n++);
    // return max(do_work(++begin, end, tmp_p+tmp_data.p, n++), do_work(++begin, end, tmp_p, n));
}

int main(){
  int N;
  cin >> N;
  vector<data> D;
  for(int i=0; i<N; i++){
    long long hin, pin;
    cin >> hin >> pin;
    data d = {hin, pin};
    D.push_back(d);
  }
  sort(D.begin(), D.end(), compare);
  cout << do_work(D.begin(), D.end(), (long long)0, 0) << endl;
  // print data
  // for(int i=0; i<N; i++){
  //   cout << D[i].h << ' ' << D[i].p << endl;
  // }
  //
  return 0;
}

