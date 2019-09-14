#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

struct stc{
  int s;
  int t;
  int c;
};

bool compare1(const stc& stc1, const stc& stc2){
  return stc1.c < stc2.c;
}
bool compare2(const stc& stc1, const stc& stc2){
  return stc1.s < stc2.s;
}
bool compare(const stc& stc1, const stc& stc2){
  if(stc1.c == stc2.c){
    return stc1.s < stc2.s;
  } else {
    return stc1.c < stc2.c;
  }
}

int main(){
  int N, C;
  cin >> N >> C;
  vector<stc> STC;
  int max_t = 0;
  for(int i=0; i<N; i++){
    int in1, in2, in3;
    cin >> in1 >> in2 >> in3;
    stc tmp = {in1, in2, in3};
    STC.push_back(tmp);
    max_t = max(max_t, in2);
  }
  sort(STC.begin(), STC.end(), compare);
  // for(int i=0; i<STC.size(); i++)
  //   cout << STC[i].s << ' ' << STC[i].t << ' ' << STC[i].c << endl;

  vector<stc> STC_new;
  int now = 0;
  while(now < STC.size()){
    int start = now, end = now;
    while(end < STC.size()){
      if(end == STC.size()-1)
	break;
      else if(STC[end].c == STC[end+1].c && STC[end].t == STC[end+1].s)
	end++;
      else
	break;
    }
    stc tmp = {STC[start].s, STC[end].t, STC[start].c};
    STC_new.push_back(tmp);
    now = end + 1;
  }
  // for(int i=0; i<STC_new.size(); i++)
  //   cout << STC_new[i].s << ' ' << STC_new[i].t << ' ' << STC_new[i].c << endl;

  int need[max_t];
  for(int i=0; i<max_t; i++)
    need[i] = 0;
  for(int i=0; i<STC_new.size(); i++){
    for(int j=STC_new[i].s-1; j<STC_new[i].t; j++){
      need[j]++;
    }
  }
  int ret = 0;
  for(int i=0; i<max_t; i++){
    ret = max(ret, need[i]);
  }
  cout << ret << endl;
  return 0;
}

