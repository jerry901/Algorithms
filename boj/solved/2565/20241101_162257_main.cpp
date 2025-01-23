#include <bits/stdc++.h>

#ifdef LOCAL
#define IF_LOCAL if constexpr (true)
#else
#define IF_LOCAL if constexpr (false)
#endif

#define debug IF_LOCAL std::cout << "[DEBUG]" << ' '
#define endl '\n'
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

template <typename X, typename Y>
ostream& operator<<(ostream& os, const pair<X, Y>& p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}

template <class C, class T, class Container>
basic_ostream<C, T>& operator<<(basic_ostream<C, T>& os, Container const& c) {
  auto it = c.begin();
  os << "{";
  while (it != c.end()) os << *it++ && it != c.end() && os << ", ";
  return os << "}";
}

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

bool compare(pair<int, int> p1, pair<int, int> p2) { return p1.fi < p2.fi; }

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);

  int n;
  cin >> n;

  vector<pair<int, int>> lines(n, { 0, 0 });
  vector<int> dp(n, 1);

  for (int i = 0; i < n; ++i) {
    cin >> lines[i].fi >> lines[i].se;
  }

  sort(all(lines), compare);

  for (int i = 1; i < n; ++i) {
    for (int j = i - 1; j >= 0; --j) {
      if (lines[i].se <= lines[j].se) {
        continue;
      }

      dp[i] = max(dp[i], dp[j] + 1);
    }
  }

  cout << n - *max_element(all(dp)) << endl;

  return 0;
}
