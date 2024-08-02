#include <bits/stdc++.h>

#ifdef LOCAL
#define IF_LOCAL if constexpr (1)
#else
#define IF_LOCAL if constexpr (0)
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

  int N, temp, cur = 1;
  stack<int> st;

  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> temp, st.push(temp);
    while (!st.empty() && st.top() == cur) {
      st.pop(), cur++;
    }
  }

  cout << (st.empty() ? "Nice" : "Sad");

  return 0;
}
