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


int dp[1001];

//BAD DP(or could be better)
// bool rec(int level, int tar, vi(int)& v) {
    
//     //Pruning
//     if(tar == 0) return true;

//     //Level + Base Case
//     if(level >= sza(v) || tar < 0) return 0;
//     if(dp[level] != -1) return dp[level];


//     //Choice: pick or not
//     //Check
//     if(tar >= v[level]) {
//         //Move
//         return dp[level] = rec(level + 1, tar - v[level], v) || rec(level + 1, tar, v);
//     }
//     else {
//         return dp[level] = rec(level + 1, tar, v);
//     }
//     return dp[level];
// }


//NICE DP: as Recursive dependence is on two States.
int t[1001][1001];
bool rec(int level, int sum,int &target, vi(int)& v) {
    if(level >= sza(v) || sum > target) return 0;
    if(target == sum) return true;
    if(t[level][sum] != -1) return t[level][sum];
    cout << sum << " ";
    return t[level][sum]  = rec(level + 1, sum + v[level], target, v) || rec(level + 1,sum, target, v);

}


int main() {
    int n;
    cin >> n;
    int tar;
    cin >> tar;
    vi(int) v(n);
    memset(dp, -1, sizeof(dp));
    memset(t, -1, sizeof(dp));
    fr(i, 0, n - 1) cin >> v[i];
    cout << rec(0, 0,tar, v);

}
