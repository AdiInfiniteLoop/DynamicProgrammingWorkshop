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



int dp[10001];

/* Design: level, choice, check , move
----Basic Template----
    int rec(int level) {
    for(allchoice) {
        if(checkif valid)
            pick and move
    }
}
*/

int rec(int level, int &n) {    //level == Level
    if(level == n) return 1;    //Check
    else if(level > n) return 0;// Pruning: Removing uneccesaary or unreachable codes
    //Choice + Move together
    return rec(level + 1, n) + rec(level + 2, n) + rec(level + 3, n);
}

int rec2 (int level, int &n, int canJumpMax) {
    //canJumpMax means what is the maximum jump we can make
    if(level == n) return 1;
    else if(level > n) return 0;
    if(dp[level] != -1) return dp[level];
    //Level
    int ans(0);
    fr(i,1,canJumpMax) {
    //Choice: Pick or Not(depends on Check)
        ans += rec2(level + i, n, canJumpMax);     
    }

    return dp[level] = ans;
}


/* dp[level] is enough to give enough data about the state  */

int main() {
    int n;
    cin >> n;
    cout << rec(1, n) << endl;
    cout << rec2(1, n,3);

    memset(dp, 01, sizeof(dp));
}


/* Recursion time comp0lexity is 3^N But wwhen memoizing the recursive calls take O(1) time. Therefore, the dp T.C is O(N )*/