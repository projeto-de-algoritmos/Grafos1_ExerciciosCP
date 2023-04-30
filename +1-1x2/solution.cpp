#include <bits/stdc++.h>
using namespace std;

long long bfs(long long x, long long y)
{
  if (x >= y)
    return x - y;

  set<long long> s;
  queue<pair<long long, long long>> q;
  q.emplace(make_pair(y, 0));
  auto ans = y - x;
  while (not q.empty())
  {
    auto [a, b] = q.front(); q.pop();
    s.emplace(a);

    if (b > ans)
      continue;

    ans = min(ans, abs(a - x) + b);

    if (a == x)
      return min(ans, b);

    if (a & 1)
    {
      if (not s.count(a + 1))
        q.emplace(make_pair(a + 1, b + 1));
      if (not s.count(a - 1))
        q.emplace(make_pair(a - 1, b + 1));
    }
    else if (not s.count(a >> 1))
      q.emplace(make_pair(a >> 1, b + 1));
  }
  return ans;
}

void solve()
{
  long long x, y;
  cin >> x >> y;

  cout << bfs(x, y) << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

	return 0;
}

