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
  vector<int> wines(n);
  vector<int> dp(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> wines[i];
  }

  dp[0] = wines[0];
  dp[1] = dp[0] + wines[1];
  dp[2] = max({ wines[0] + wines[2], wines[1] + wines[2], wines[0] + wines[1] });

  for (int i = 3; i < dp.size(); ++i) {
    dp[i] = max({ dp[i - 2] + wines[i], dp[i - 3] + wines[i - 1] + wines[i], dp[i - 1] });
  }

  cout << dp.back() << endl;

  return 0;
}
