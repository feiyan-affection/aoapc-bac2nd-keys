// UVa1617 Laptop
// 陈锋
#include <bitset>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <valarray>
#include <vector>

using namespace std;
#define _for(i, a, b) for (int i = (a); i < (b); ++i)
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define _zero(D) memset((D), 0, sizeof(D))
#define _init(D, v) memset((D), (v), sizeof(D))
#define _ri1(x) scanf("%d", &(x))
#define _ri2(x, y) scanf("%d%d", &(x), &(y))
#define _ri3(x, y, z) scanf("%d%d%d", &(x), &(y), &(z))
#define _ri4(a, b, c, d) scanf("%d%d%d%d", &(a), &(b), &(c), &(d))
typedef long long LL;
const int MAXN = 1000000 + 4;
struct Seg {
  int l, r;
  bool operator<(const Seg& s) const {
    if (r != s.r) return r < s.r;
    return l < s.l;
  }
};
Seg segs[MAXN];
int N;
int solve() {
  int ans = 0, p = -1;
  _for(i, 0, N) {
    const auto& s = segs[i];
    if (s.r == p) continue; 
    if (s.l > p)
      ++ans, p = s.r;
    else
      ++p;
  }
  return ans - 1;
}

int main() {
  int T;
  _ri1(T);
  while (_ri1(N) == 1 && N) {
    _for(i, 0, N) _ri2(segs[i].l, segs[i].r);
    sort(segs, segs + N);
    int ans = solve();
    printf("%d\n", ans);
  }
  return 0;
}
// 20497014 1617  Laptop  Accepted  C++11 0.000 2017-12-16 11:45:17