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

int queen[10];

 

int valid(int prevLevels, int currentColumn) {
    /* Check if two elements in 2D are interacting in O(1)!!!!! */
    fr(row,0, prevLevels) {
        if(queen[row] == currentColumn || abs(row - prevLevels) == abs(currentColumn - queen[row]) ) return false;
    }
    return true;
}
int rec(int level, int &n) {//return-> no of ways to place from level to [0...n - 1]
    //Pruning
    //**Level = Rows till n - 1 idx   L
    // **Choice: Place or Not  C
    //Base Case
    if(n == level) return 1;//successfully reached
     
     //Compute
     int ans(0);
     fr(i, 0, n-1) {
        //Go column wise, to check in which col at that row we can place it.
        //**Check   C
        if(valid(level, i)) {
            //Place the Queen
            queen[level] = i;//i means column here
            //**Move  M
            ans += rec(level + 1, n);
            //Not necessary here, But Backtracking we gotta revert back the common structure to its original value
            queen[level] = -1;

        }
     }
     return ans;

}
int main() {
    int n;
    cin >> n;
    memset(queen, -1 ,sizeof(queen));
    cout << rec(0, n);

}



/*
1.Levels === Rows(Go Downwards)
2.Choice: Whether we can place the queen there or not.
3.Check: Same column + O(1)! Diagonal Check
4.Place and Move: (In exploration Cases of recursion(Backtracking) -> Good practice to revert back to original state)

-------------------------------------------------------
queen[] is used to see in each row at whcih col is the  queen place previously
row - to - column Mapping

 */