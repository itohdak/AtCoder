#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int N;
  cin >> N;
  int times[13];
  for(int i=0; i<13; i++)
    times[i] = 0;
  for(int i=0; i<N; i++){
    int in;
    cin >> in;
    times[in]++;
  }
  int ans_times[24];
  for(int i=0; i<24; i++){
    if(i == 0)
      ans_times[i] = 1;
    else
      ans_times[i] = 0;
  }
  int flag = 0;
  int ans = 24;
  for(int i=0; i<13; i++){
    if(times[i] >= 3){
      ans = 0;
      break;
    } else if(times[i] == 2){
      ans_times[i]++;
      ans_times[24-i]++;
    } else if(times[i] == 1){
      if(flag % 2 == 0)
	ans_times[i]++;
      else
	ans_times[24-i]++;
      flag++;
    }
  }
  if(ans != 24){
    vector<int> hoge;
    hoge.push_back(24);
    for(int i=0; i<24; i++){
      if(ans_times[i] == 1)
	hoge.push_back(i);
    }
    for(int i=0; i<hoge.size()-1; i++){
      ans = min(ans, hoge[i+1] - hoge[i]);
    }
  }
  cout << ans << endl;
}

