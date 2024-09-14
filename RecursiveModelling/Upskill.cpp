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



int taken[1001][1001][1001];

// bool check(int level, vi(p(int, int)) &v, int x, int k) {
//     int time(0);
//     int item(0);
//     fr(i, 0,level) {
//         if(taken[i]) {
//             time += v[i].first;
//             item++;
//         }
//     }

//     time += v[level].first;
//     item++;
//     if(time <= x && item <= k) return 1;
//     return false;
// }

// int rec(int level, vi(p(int, int)) &v, int x, int k) {
//     if(level == sza(v)) {
//         return 0;
//      }

//     //Choice: Taken or Not Take
//     //Don't take
//     int ans = rec(level + 1, v, x, k);
//     //Takecl
    
//     if(check(level, v, x, k)) {
//         //Place
//         taken[level] = 1;
//         //Move
//         rec(level + 1, v,x,k);
//         //Revert
//         taken[level] = 0;
//     }

//     return ans;
// }



int rec(int level, vi(p(int, int))&v, int t, int k ) {
    
    //Base Case
    if(level >= sza(v) || t <= 0 || k <= 0) return 0;
    if(taken[level][t][k] != -1) return taken[level][t][k];

    //Level: means in which index here am I.

    //Choice: can pick or not
    //Check: See if can be picked

     if(v[level].first > t) {
        return taken[level][t][k]  = rec(level + 1, v, t, k);
    }
    //Move
    return taken[level][t][k] = max( v[level].second + rec(level + 1, v, t - v[level].first, k - 1), rec(level + 1, v, t ,k));
}

int main() {
    int n;
    cin >> n;
    vi(p(int, int)) v;
    memset(taken, -1, sizeof(taken));
    fr(i,0,n-1) {
        int x,k;
        cin >> x >> k;
        v.emplace_back(x,k);
    }
    cout<< rec(0, v, 2, 2) <<endl;
}
