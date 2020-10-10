#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

/* Trie 木： 文字の種類(char_size)、int型で0に対応する文字(base)
   insert(word): 単語 word を Trie 木に挿入する
   search(word): 単語 word が Trie 木にあるか判定する
   start_with(prefix):  prefix が一致する単語が Trie 木にあるか判定する
   count(): 挿入した単語の数を返す
   size(): Trie 木の頂点数を返す
   計算量：insert, search ともに O(M)（Mは単語の長さ）
*/
template <int char_size, int base>
struct Trie {
  struct Node {            // 頂点を表す構造体
    vector<int> next;    // 子の頂点番号を格納。存在しなければ-1
    vector<int> accept;  // 末端がこの頂点になる単語の word_id を保存
    int c;               // base からの間隔をint型で表現したもの
    int common;          // いくつの単語がこの頂点を共有しているか
    Node(int c_) : c(c_), common(0) {
      next.assign(char_size, -1);
    }
  };

  vector<Node> nodes;  // trie 木本体
  int root;
  Trie() : root(0) {
    nodes.push_back(Node(root));
  }

  // 単語の挿入
  void insert(const string &word, int word_id) {
    int node_id = 0;
    for (int i = 0; i < (int)word.size(); i++) {
      int c = (int)(word[i] - base);
      int &next_id = nodes[node_id].next[c];
      if (next_id == -1) {  // 次の頂点が存在しなければ追加
        next_id = (int)nodes.size();
        nodes.push_back(Node(c));
      }
      ++nodes[node_id].common;
      node_id = next_id;
    }
    ++nodes[node_id].common;
    nodes[node_id].accept.push_back(word_id);
  }
  void insert(const string &word) {
    insert(word, nodes[0].common);
  }

  // 単語とprefixの検索
  bool search(const string &word, bool prefix = false) {
    int node_id = 0;
    for (int i = 0; i < (int)word.size(); i++) {
      int c = (int)(word[i] - base);
      int &next_id = nodes[node_id].next[c];
      if (next_id == -1) {  // 次の頂点が存在しなければ終了
        return false;
      }
      node_id = next_id;
    }
    return (prefix) ? true : nodes[node_id].accept.size() > 0;
  }

  // prefix を持つ単語が存在するかの検索
  bool start_with(const string &prefix) {
    return search(prefix, true);
  }

  // 挿入した単語の数
  int count() const {
    return (nodes[0].common);
  }
  // Trie木のノード数
  int size() const {
    return ((int)nodes.size());
  }
};
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<string> S(n);
  Trie<26, 'a'> trie;
  rep(i, n) {
    cin >> S[i];
    reverse(all(S[i]));
    trie.insert(S[i]);
    // cout << trie.size() << endk;
  }
  ll ans = 0;
  rep(i, n) {
    vector<vector<int>> alpha(S[i].size(), vector<int>(26));
    rrep(j, S[i].size()) {
      alpha[j][S[i][j]-'a']++;
      if(j) rep(k, 26) alpha[j-1][k] += alpha[j][k];
    }
    // rep(j, S[i].size()) cout << alpha[j] << endk;
    auto node = trie.nodes[0];
    rep(j, S[i].size()) {
      rep(k, 26) {
        if(alpha[j][k]) {
          int next_id = node.next[k];
          if(next_id != -1) ans += trie.nodes[next_id].accept.size();
        }
      }
      // cout << S[i][j] << endk;
      int next_id = node.next[S[i][j]-'a'];
      if(next_id == -1) break;
      node = trie.nodes[next_id];
      // cout << char(node.c+'a') << endk;
    }
  }
  ans -= n;
  cout << ans << endk;
  return 0;
}
