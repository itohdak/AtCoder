#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)
#include <set>

using namespace std;
#define ll long long

void dfs(vector<string> S, set<string>& T, int tmpi, int& ans, set<string>& ansSet) {
  if(tmpi == S.size()) {
    // string tmpSet = "";
    // for(set<string>::iterator itr=T.begin(); itr!=T.end(); itr++)
    //   tmpSet += *itr;
    // if(ansSet.find(tmpSet) == ansSet.end()) { // not found
    //   ans++;
    //   ansSet.insert(tmpSet);
    // }
    ans++;
    return;
  } else {
    int s = S[tmpi].size();
    for(int i=0; i<s; i++) {
      for(int j=i+1; j<s; j++) {
	char c[] = {S[tmpi][i], S[tmpi][j]};
	string cand(c, 2);
	if(T.find(cand) == T.end()) { // not found
	  T.insert(cand);
	  dfs(S, T, tmpi+1, ans, ansSet);
	  T.erase(cand);
	}
      }
    }
  }
}

int main(){
  int N;
  cin >> N;
  vector<string> S(N);
  for(int i=0; i<N; i++)
    cin >> S[i];
  int ans = 0;
  set<string> T, ansSet;
  dfs(S, T, 0, ans, ansSet);
  cout << ans << endl;
  return 0;
}

