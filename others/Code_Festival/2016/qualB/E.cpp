#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

template<int char_size, int base>
struct Trie {
  struct Node {
    vector<int> next;
    vector<int> accept;
    int c;
    int common;
    Node(int c_) : c(c_), common(0) {
      next.assign(char_size, -1);
    }
  };
  vector<Node> nodes;
  int root;
  Trie() : root(0) {
    nodes.push_back(Node(root));
  }

  void insert(const string& word, int word_id) {
    int node_id = 0;
    for(int i=0; i<(int)word.size(); i++) {
      int c = (int)(word[i] - base);
      int& next_id = nodes[node_id].next[c];
      if(next_id == -1) {
        next_id = (int)nodes.size();
        nodes.push_back(Node(c));
      }
      ++nodes[node_id].common;
      node_id = next_id;
    }
    ++nodes[node_id].common;
    nodes[node_id].accept.push_back(word_id);
  }
  void insert(const string& word) {
    insert(word, nodes[0].common);
  }

  bool search(const string& word, bool prefix=false) {
    int node_id = 0;
    for(int i=0; i<(int)word.size(); i++) {
      int c = (int)(word[i] - base);
      int& next_id = nodes[node_id].next[c];
      if(next_id == -1) return false;
      node_id = next_id;
    }
    return (prefix ? true : nodes[node_id].accept.size() > 0);
  }
  bool start_with(const string& word) {
    return search(word, true);
  }

  int count_prefix(const string& word) {
    int res = 0, node_id = 0;
    for(int i=0; i<(int)word.size(); i++) {
      int c = (int)(word[i] - base);
      int& next_id = nodes[node_id].next[c];
      if(next_id == -1) return res;
      node_id = next_id;
      res += nodes[node_id].accept.size();
    }
    return res;
  }

  // count the number of word which is lexicographically smaller than `word`
  // when `c1` < `c2`
  int count_branch(const string& word, const char& c1, const char& c2) {
    if(c1 == c2) return 0;
    int res = 0, node_id = 0;
    for(int i=0; i<(int)word.size(); i++) {
      int c = (int)(word[i] - base);
      int& next_id = nodes[node_id].next[c];
      if(next_id == -1) return res;
      if(c == (int)(c2 - base)) {
        int& next_id_other = nodes[node_id].next[(int)(c1 - base)];
        if(next_id_other != -1) res += nodes[next_id_other].common;
      }
      node_id = next_id;
    }
    return res;
  }

  int count() const {
    return (nodes[0].common);
  }
  int size () const {
    return ((int)nodes.size());
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  Trie<26, 'a'> trie;
  vector<string> S(n);
  rep(i, n) {
    cin >> S[i];
    trie.insert(S[i]);
  }
  // vector<int> cntPrefix(n);
  // rep(i, n) cntPrefix[i] = trie.count_prefix(S[i]);
  // int cntBranch[n][26][26];
  // rep(i, n) rep(j, 26) rep(k, 26) {
  //   cntBranch[i][j][k] = trie.count_branch(S[i], char('a'+j), char('a'+k));
  // }
  vector<int> cntPrefix(n);
  vector<vector<vector<int>>> cntBranch(n, vector<vector<int>>(26, vector<int>(26)));
  rep(k, n) {
    const string& word = S[k];
    char base = 'a';
    int node_id = 0;
    for(int i=0; i<(int)word.size(); i++) {
      int c = (int)(word[i] - base);
      int& next_id = trie.nodes[node_id].next[c];
      if(next_id == -1) break;
      rep(j, 26) {
        if(j == c) continue;
        int id = trie.nodes[node_id].next[j];
        if(id != -1) cntBranch[k][j][c] += trie.nodes[id].common;
      }
      node_id = next_id;
      cntPrefix[k] += trie.nodes[node_id].accept.size();
    }
  }
  // cout << cntPrefix << endk;
  // rep(i, n) {
  //   rep(j, 26) {
  //     rep(k, 26) cout << cntBranch[i][j][k] << ' ';
  //     cout << endk;
  //   }
  //   cout << endk;
  // }
  int q; cin >> q;
  rep(_, q) {
    int i; cin >> i;
    i--;
    string s; cin >> s;
    int res = cntPrefix[i];
    rep(j, 26) REP(k, j+1, 26) {
      res += cntBranch[i][s[j]-'a'][s[k]-'a'];
    }
    cout << res << endk;
  }
  return 0;
}
