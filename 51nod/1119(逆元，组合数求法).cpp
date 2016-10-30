#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;

//  ����d = gcd(a,b); �Ͷ�Ӧ�ڵ�ʽax + by = d�е�x,y
ll extend_gcd(ll a, ll b, ll &x, ll &y)
{
    if (a == 0 && b == 0)
    {
        return -1;  //  �����Լ��
    }
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extend_gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

//  ����Ԫ��
//  ax = 1(mod n)
ll mod_reverse(ll a, ll n)
{
    ll x, y;
    ll d = extend_gcd(a, n, x, y);
    if (d == 1)
    {
        return (x % n + n) % n;
    }
    else
    {
        return -1;
    }
}

ll c(ll m, ll n)
{
    ll i, t_1, t_2;
    t_1 = t_2 = 1;
    for (i = n; i >= n - m + 1; i--)
    {
        t_1 = t_1 * i % mod;
    }
    for (i = 1; i <= m; i++)
    {
        t_2 = t_2 * i % mod;
    }
    return  t_1 * mod_reverse(t_2, mod) % mod;  //  ת��Ϊ��Ԫ
}

int main()
{
    ll n, m, ans;
    cin >> m >> n;
    ans = c(min(m - 1, n - 1), m + n - 2);
    cout << ans << endl;
    return 0;
}
