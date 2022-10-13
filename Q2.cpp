#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define ll long long int
#define ld long int
#define nl "\n"
#define ss second
#define ff first
using namespace std;

ll MOD = 1000000007;
/*------------------------------------For Debugging-------------------------------------------------------------------------*/
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << nl;
#else
#define debug(x...)
#endif

void _print(ll t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*-------------------------------------------------------------------------------------------------------------------------*/
bool comp(const pair<pair<int, int>,int> &a, const pair<pair<int, int>,int> &b) { return (a.second < b.second); }
bool isPowerOfTwo(int n)   {if (n == 0)       return false;return (ceil(log2(n)) == floor(log2(n)));}
double abaseb(int a, int b)  {return log2(a) / log2(b);}
bool isPowerOfThree(int n)  {if (n == 0) return false; cout << abaseb(n, 3) << nl;int num1 = ceil(abaseb(n, 3));
                  int num2 = floor(abaseb(n, 3));if (num1 == num2)    return true;  else return false;}
ll lcm(ll a, ll b) { return (a / __gcd(a, b)) * b; }
ll countDivisors(ll n)
{ ll cnt = 0;for (ll i = 1; i <= sqrt(n); i++) {
        if (n % i == 0){ if (n / i == i) cnt++;
        else  cnt = cnt + 2; } }
    return cnt;
}
bool isPrime(ll n)
{ if (n <= 1) return false;
  for (int i = 2; i * i <= n; i++)      if (n % i == 0){ return false;}
    return true;
}
string bin(ll n){
    ll i;string val = "0";
    for (i = 1 << 30; i > 0; i = i / 2)
    { if((n & i) != 0) { val+="1"; }
    else { val+="0"; } }
    while(val.front()=='0'){ val.erase(0,1); }
    return val;
}
ll DivOrNot(ll n1, ll n2){ if(n1 % n2 == 0)  return n1/n2; else return (n1/n2)+1;}
ll is_string_palindrome(string b){ string n = b; reverse(all(n)); if(n==b) return 1;return 0;}
/*----------------------------------------Template Ends-----------------------------------------------------------------*/
void todo()
{
    ll n,q  ;
    cin >> n >> q;
    map<ll,vector<ll>> ad;
    
    for(ll i = 0;i<n-1;i++){
        ll x1,x2;
        cin >> x1 >> x2;
        if(x1>x2){swap(x1,x2);}
        // cout << x1 << " " << x2 << nl;
        ad[x1].push_back(x2);
        ad[x2].push_back(x1);
    }
    for(ll i = 0;i<q;i++){
        ll x;
        cin >> x;
    }
    // cout << ad.size() << endl;
    if(ad.size() == 0){
        cout << 1 << nl;
        return;
    }
    // for(auto i:ad){
    //     cout << i.first << " ";
    //     for(auto j:i.second){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    ll rem = q-1;
    ll ans = 1;
    // vector < ll> bfs;
      vector < ll> vis(n+1, 0);
      queue<ll> qt;
      long long k = 1;
      qt.push(k);
      vis[1] = 1;
      while (!qt.empty()) {
        int sz = qt.size();
        int size = 0;
        for(int i = 0;i<sz;i++){
            int node = qt.front();
            qt.pop();
            // bfs.push_back(node);
            // ll size = ad[node].size();
            
            for (auto it: ad[node]) {
                if (!vis[it]) {
                    qt.push(it);
                    size++;
                    vis[it] = 1;
                }
            }
        }
        if(size<=rem){
            rem-=size;
            ans+=size;
        }
        else{
            break;
        }
        if(rem <= 0){
            break;
        }
      }
        cout << ans << nl;;
     


}

int main()
{
    // Fib
    ll fib[10005];
    fib[0] = 0;fib[1] = 1;
    for(ll i = 2; i <= 10005; i++){
       fib[i] = fib[i - 1] + fib[i - 2];}

    // Main Code
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt = 1;
    cin >> tt;
    for (ll i = 1; i <= tt; i++)
    {
        cout << "Case #"<< i <<": ";
        todo();
    }

    return 0;
}