#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
//you can use greater and lee_equal on the place of less
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

#define fastio()       ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M              1000000007
#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define max_heap       priority_queue <int>
#define min_heap       priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}
//*******************************************************************************************************
// ceil(log2(k)) //if k=15 then output will be 4 which is 2 ka power 4 = 16(15 ke uper wala power of 2)
// floor(log2(k)) //if k=15 then output will be 3 which is 2 ka power3 = 8 (15 ke niche wala power of 2)
//find index of largest element in vector -> int itr = max_element(a.begin(), a.end()) - a.begin();
int lcm(int a , int b){int ans = (a * b)/__gcd(a,b);return ans;}
int setBitNumber(int n){int k = (int)(log2(n));return 1 << k;} //input 15,20 output 8,16
int mostsignificantsetbit(int n){int k = (int)(log2(n));return k;}
int getFirstSetBitPos(int n){return log2(n & -n) + 1;}//Right most set bit
int countSetBits(int n){int count = 0;while (n) {count += n & 1;n >>= 1;}return count;}
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
int powerwithmod(int a, int b) {int result = 1;while (b) {if (b & 1) {result = result * a;result = result % M;}a = a * a;a = a % M;b = b >> 1;}return result;}
bool isPerfectSquare(int x){if (x >= 0) {int sr = sqrt(x);return (sr * sr == x);}return false;}
void print2d(vector<vector<int>> v){int n = v.size();int m = v[0].size();for(int i=0; i<n; i++){for(int j=0; j<m; j++){cout<<v[i][j]<<" ";}cout<<endl;}}  
int XorTillN(int n){if(n%4 == 0)return n;if(n%4 == 1)return 1;if(n%4 == 2)return n+1;if(n%4 == 3)return 0;return 0;}
int get_hash2(string s){
    int hash_val = 0;
    int p_power = 1;
    int p = 31;
    for (char c : s){
        hash_val = (hash_val + (c - 'a' + 1) * p_power) % M;
        p_power = (p_power * p) % M;
    }
    return hash_val;
}
// *********************************************************************************************

class Manacher{
private:
    vector<int> p;
    void run_Manacher(string t){
        int n = t.size();
        p.resize(n,1);
        int l=1,r=1;
        for(int i=1; i<n; i++){
            p[i] = max((int)0, min(r - i, (l + r - i >= 0 ? p[l + r - i] : 0)));// take the mirror if possible
            //expand p[i] as much as possible
            while(i+p[i] < n and i-p[i] >= 0 and t[i+p[i]] == t[i-p[i]]){
                p[i]++;
            }
            if(i+p[i] > r){
                l = i-p[i];
                r = i+p[i];
            }
        }
    }
public:
    Manacher(string s){
        int n = s.size();
        string t;
        for(auto it: s){
            t += string("#") + it;
        }
        t += string("#");
        run_Manacher(t);
    }
    int getLongestPalindrome(int centre, bool odd){
        //boolean tells which to pick odd or even center 
        int pos = 2*centre+1+(!odd); // finds the position for p vector
        return p[pos]-1;//returns the largest palindrome at this center
    }
    bool checkPalindrome(int l, int r){
        if((r-l+1) <= getLongestPalindrome((r+l)/2 , l%2 == r%2)){
            return true;
        }
        return false;
    }
};


void solveit(){
    //#b#a#b#b#a#b#b#a#b#c#
    string s = "babbabbabc";
    Manacher m(s);
    
    bug(m.checkPalindrome(3,5)); // gives true
}

int32_t main()
{
    // createSieve();
    // calculate_factorial();
#ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio();
    clock_t z = clock();
    int t = 1;
    cin >> t;
    while (t--) solveit();
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
    return 0;
}
