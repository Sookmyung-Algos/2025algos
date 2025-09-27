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
ld mat[10][10];
int N;

int main (void) {
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) cin >> mat[i][j];
    }
    for (int i = 0; i < N; i++) {
        ld piv = mat[i][i];
        for (int j = i; j <= N; j++) mat[i][j] /= piv;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            piv = -mat[j][i];
            for (int k = 0; k <= N; k++)
                mat[j][k] += mat[i][k] * piv;
        }
    }
    for (int i = 0; i < N; i++) cout << mat[i][N] << " ";
    cout << "\n";
    return 0;
}
