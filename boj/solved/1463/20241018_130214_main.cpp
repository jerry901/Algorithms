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

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);

  int n;
  cin >> n;

  vector<int> dp(1000001);

  dp[0] = 0;
  dp[1] = 0;
  dp[2] = dp[3] = 1;

  for (int i = 4; i <= 1000000; ++i) {
    int min_prev = 1e9;
    if (i % 2 == 0) {
      min_prev = min(min_prev, dp[i / 2]);
    }

    if (i % 3 == 0) {
      min_prev = min(min_prev, dp[i / 3]);
    }

    dp[i] = min(min_prev, dp[i - 1]) + 1;
  }

  cout << dp[n] << endl;

  return 0;
}
