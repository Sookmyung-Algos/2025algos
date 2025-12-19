#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;

__int128_t gcd128(__int128_t a, __int128_t b)
{
    if (b == 0)
        return a;
    return gcd128(b, a % b);
}

__int128_t abs128(__int128_t x)
{
    return x < 0 ? -x : x;
}

string to_string(__int128_t x)
{
    if (x == 0)
        return "0";
    string s;
    bool neg = false;
    if (x < 0)
        neg = true, x = -x;
    while (x > 0)
    {
        s.push_back((x % 10) + '0');
        x /= 10;
    }
    if (neg)
        s.push_back('-');
    reverse(s.begin(), s.end());
    return s;
}

class fraction
{
public:
    __int128_t num, den;

    fraction(__int128_t n = 0, __int128_t d = 1)
    {
        num = n;
        den = d;
        reduce();
    }

    void reduce()
    {
        if (num == 0)
        {
            den = 1;
            return;
        }

        __int128_t g = gcd128(abs128(num), abs128(den));
        num /= g;
        den /= g;
        if (den < 0)
        {
            den = -den;
            num = -num;
        }
    }

    void from_string(string &s)
    {
        int pos = s.find('/');
        if (pos == string::npos)
        {
            num = stoi(s);
            den = 1;
        }
        else
        {
            num = stoi(s.substr(0, pos));
            den = stoi(s.substr(pos + 1));
        }
        reduce();
    }

    string to_str()
    {
        if (num == 0)
            return "0";
        if (den == 1)
            return to_string(num);
        return to_string(num) + "/" + to_string(den);
    }

    fraction operator+(const fraction &rhs) const
    {
        return fraction(num * rhs.den + den * rhs.num, den * rhs.den);
    }

    fraction operator-(const fraction &rhs) const
    {
        return fraction(num * rhs.den - den * rhs.num, den * rhs.den);
    }

    fraction operator*(const fraction &rhs) const
    {
        return fraction(num * rhs.num, den * rhs.den);
    }
};

vector<vector<fraction>> matrix;

void gauss_elimination()
{
    // cout << "before elimination\n";
    for (int i = 0; i < min(n, m); i++)
    {
        int pivot = i;
        while (pivot < n && matrix[pivot][i].num == 0)
            pivot++;

        if (pivot == n)
            break;

        if (i != pivot)
            swap(matrix[i], matrix[pivot]);

        for (int k = i + 1; k < m; k++)
            matrix[i][k] = matrix[i][k] * fraction(matrix[i][i].den, matrix[i][i].num);
        matrix[i][i] = fraction(1, 1);

        for (int j = 0; j < n; j++)
        {
            if (j == i || matrix[j][i].num == 0)
                continue;
            for (int k = i + 1; k < m; k++)
            {
                fraction f = matrix[i][k] * matrix[j][i];
                matrix[j][k] = matrix[j][k] - f;
            }
            matrix[j][i] = fraction(0, 1);
        }
    }
    // cout << "after elimination\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j].num != 0)
            {
                // cout << "here\n";
                if (matrix[i][j].num == 1 && matrix[i][j].den == 1)
                    break;
                for (int k = j + 1; k < m; k++)
                    matrix[i][k] = matrix[i][k] * fraction(matrix[i][j].den, matrix[i][j].num);
                matrix[i][j] = fraction(1, 1);
                break;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        vector<fraction> row(m);
        for (int j = 0; j < m; j++)
        {
            string s;
            cin >> s;
            row[j].from_string(s);
        }
        matrix.push_back(row);
    }
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j].num == 0)
                cnt++;
            else
                break;
        }
        for (int j = i + 1; j < n; j++)
        {
            int cnt2 = 0;
            for (int k = 0; k < m; k++)
            {
                if (matrix[j][k].num == 0)
                    cnt2++;
                else
                    break;
            }
            if (cnt2 < cnt)
                swap(matrix[i], matrix[j]);
        }
    }

    gauss_elimination();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j].to_str() << " ";
        }
        cout << "\n";
    }
    return 0;
}
