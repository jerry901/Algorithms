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

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

bool is_prime(int n) {
  if (n == 1) {
    return false;
  }

  for (int i = 2; i * 2 <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);

  int M, N;
  cin >> M >> N;
  vector<int> primes;
  for (int i = M; i <= N; ++i) {
    if (is_prime(i)) {
      primes.push_back(i);
    }
  }

  if (primes.size()) {
    cout << accumulate(primes.begin(), primes.end(), 0) << endl;
    cout << primes[0] << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}
