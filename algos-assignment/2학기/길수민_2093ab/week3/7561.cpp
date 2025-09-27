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
int a[3][3], b[3];

ll det () {
    ll ret = 0;
    ret += a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]);
    ret -= a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]);
    ret += a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
    return ret;
}

void solve() {
    for (int i = 0; i < 3; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> b[i];
    ll detA = det();

    for (int i = 0; i < 3; i++) swap (a[i][0], b[i]);
    ll detA1 = det();
    for (int i = 0; i < 3; i++) swap (a[i][0], b[i]);

    for (int i = 0; i < 3; i++) swap (a[i][1], b[i]);
    ll detA2 = det();
    for (int i = 0; i < 3; i++) swap (a[i][1], b[i]);

    for (int i = 0; i < 3; i++) swap (a[i][2], b[i]);
    ll detA3 = det();
    for (int i = 0; i < 3; i++) swap (a[i][2], b[i]);
    cout << detA1 << " " << detA2 << " " << detA3 << " " << detA << "\n";
    if (detA == 0) cout << "No unique solution\n";
    else {
        cout << "Unique solution: ";
        ld ans1 = (ld)detA1 / detA;
        ld ans2 = (ld)detA2 / detA;
        ld ans3 = (ld)detA3 / detA;
        if (ans1 > -0.0005 && ans1 < 0.0005) cout << "0.000 ";
        else cout << ans1 << " ";
        if (ans2 > -0.0005 && ans2 < 0.0005) cout << "0.000 ";
        else cout << ans2 << " ";
        if (ans3 > -0.0005 && ans3 < 0.0005) cout << "0.000\n";
        else cout << ans3 << "\n";
    }
    cout << "\n";
}

int main (void) {
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int T;
    cin >> T;
    cout << fixed;
    cout.precision (3);
    while (T--) solve();
    return 0;
}
