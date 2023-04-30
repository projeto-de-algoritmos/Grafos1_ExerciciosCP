#include <bits/stdc++.h>
using namespace std;
 
using byte_t = char;
#define all(x) x.begin(), x.end()
 
using ll = long long;
 
void topological_order(const vector<vector<int>> &g, vector<byte_t> &vis, vector<int> &order, int s)
{
  vis[s] = true;
  for (auto x : g[s])
    if (not vis[x])
      topological_order(g, vis, order, x);
  order.push_back(s);
}
 
void mark_components(const vector<vector<int>> &g, vector<int> &component, int s, const int comp_value)
{
  component[s] = comp_value;
  for (auto x : g[s])
    if (component[x] == -1)
      mark_components(g, component, x, comp_value);
}
 
ll max_coins(const vector<set<int>> &g, int s, const vector<ll> &coins, vector<ll> &memo)
{
  if (memo[s]) return memo[s];
 
  ll mx = 0;
  for (auto x : g[s])
    mx = max(mx, max_coins(g, x, coins, memo));
 
  return memo[s] = mx + coins[s];
}
 
void solve()
{
  int n, m;
  cin >> n >> m;
  vector<ll> coins(n);
  for (auto &x : coins) cin >> x;
  vector<vector<int>> g(n), gr(n);
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    gr[b].push_back(a);
  }
 
  vector<int> order;
  vector<byte_t> vis(n);
  for (int i = 0; i < n; i++)
    if (not vis[i])
      topological_order(g, vis, order, i);
 
  reverse(all(order));
 
  vector<int> comp(n, -1);
  for (auto i : order)
    if (comp[i] == -1)
      mark_components(gr, comp, i, i);
 
  vector<set<int>> condensed(n);
  vector<ll> condensed_coins(n);
  for (int i = 0; i < n; i++)
  {
    condensed_coins[comp[i]] += coins[i];
 
    for (auto x : g[i])
      if (comp[i] != comp[x])
        condensed[comp[i]].insert(comp[x]);
  }
 
  vector<ll> memo(n);
  ll ans = 0;
  for (int i = 0; i < n; i++)
    ans = max(ans, max_coins(condensed, i, condensed_coins, memo));
  cout << ans << '\n';
}
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  solve();
 
  return 0;
}
