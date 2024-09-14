#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define vi(t) vector<t>
#define p(a,b) pair<a,b>
#define fr(i,a,b) for(int i = a; i <= b; i++)


const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int n;
int t;
int dp[101][1001];
ar<int, 101> x;
ar<int, 10> q;

bool rec(int level, int s) {
    if(s > t) return false;
    if(level == n) {
        if(t == s) {
            return true;
        }
        else return false;
    }
    //Cache Check
    if(dp[level][s] != -1) return dp[level][s];
    int ans(0);
    if(rec(level + 1, s)) ans = 1;//Possible without picking
    else if(rec(level + 1, s + x[level])) ans = 1;//Possible when picking

    return dp[level][s] = ans;
}

int main() {
    cin >> n;
    fr(i, 0, n - 1) cin >> x[i];
    memset(dp, -1, sizeof(dp));
    cout << rec(0, t) << endl;

    /* In order to trace the transitions that leads to final value we can use two methods:
    1.Recheck
    2.Backpointer(or Backptr)
     */


}
