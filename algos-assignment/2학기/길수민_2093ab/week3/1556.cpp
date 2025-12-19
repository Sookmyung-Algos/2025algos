#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll MOD = 121547;
ll matrix[101][101];

ll pow(ll a, ll n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return a % MOD;
    if (n & 1)
        return a * pow(a, n - 1) % MOD;
    ll half = pow(a, n / 2);
    return half * half % MOD;
}

ll gauss_elimination(int n)
{
    ll det = 1;
    for (int i = 0; i < n; i++)
    {
        int pivot = i;
        while (pivot < n && matrix[pivot][i] == 0)
            pivot++;

        if (pivot == n)
            return 0;

        if (i != pivot)
        {
            swap(matrix[i], matrix[pivot]);
            det = MOD - det;
        }

        det = det * matrix[i][i] % MOD;

        ll inv = pow(matrix[i][i], MOD - 2);
        for (int j = i + 1; j < n; j++)
        {
            ll factor = matrix[j][i] * inv % MOD;
            for (int k = i; k < n; k++)
            {
                matrix[j][k] = (matrix[j][k] - matrix[i][k] * factor % MOD + MOD) % MOD;
            }
        }
    }
    return det;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<string> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] >= '0' && arr[i][j] <= '9')
                matrix[i][j] = arr[i][j] - '0';
            else
                matrix[i][j] = arr[i][j] - 'A' + 1, matrix[i][j] = MOD - matrix[i][j];
        }
    }
    ll ans = gauss_elimination(n);
    if (n % 2 == 0)
        ans = (MOD - ans) % MOD;
    cout << ans << "\n";
    return 0;
}
