#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
typedef pair<pi, pi> pipi;

const int MAX = 1e6 + 7;
const int MOD = 1e9 + 7;
//const int MOD = 998'244'353;
const int INF = 1e9 + 7;
int dx[] = { -1, 1, 0, 0, -1, 1, -1, 1 };
int dy[] = { 0, 0, -1, 1, -1, -1, 1, 1 };
ll mat[4][4] = {{-1, 3, -3, 1}, {9, -24, 21, -6}, \
    {-26, 57, -42, 11}, {24, -36, 24, -6}};
ll coef[4];

ll calc (ll i) {
    ll ret = 0;
    ret += coef[0] * i * i * i;
    ret += coef[1] * i * i;
    ret += coef[2] * i;
    ret += coef[3];
    return ret;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    if (n <= 4) cout << "YES\n";
    else {
        for (int i = 0; i < 4; i++) {
            coef[i] = 0;
            for (int j = 0; j < 4; j++)
                coef[i] += mat[i][j] * x[j];
        }
        bool ans = true;
        for (int i = 4; i < n; i++) {
            if (calc (i + 1) != 6 * x[i]) {
                ans = false;
                break;
            }
        }
        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main (void) {
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
