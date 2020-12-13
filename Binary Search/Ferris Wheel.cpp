#include<bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long int lli;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vop;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define REP(i,a,b) for(long long int i=a;i<b;i++)
#define REPR(i,a,b) for(long long int i=a;i>=b;i--)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define endl "\n"
#define mem(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define MAX LLONG_MAX
const int mxn=2e5;
//----------------------------------------------------------------------------------------
#define LB(arr,n) ll c=0;it=lower_bound(arr.begin(),arr.end(),n);if(it==arr.end()){c=1;}
//define it and if c==1 means not found
#define LB1(arr,n) ll idx=it-arr.begin();if(arr[idx]==n){ idx=idx;}else{idx=idx-1;}
// here idx holds the index( 0 based) of found element
//-----------------------------------------------------------------------------------------
#define UB(arr,n) ll c=0;it=upper_bound(arr.begin(),arr.end(),n);if(it==arr.end()){c=1;}
#define UB1(arr,n) ll idx=it-arr.begin();
//-----------------------------------------------------------------------------------------
 
ll power(ll a,ll b,ll m) { ll ans=1; while(b) { if(b&1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans; }
 
ll lcm(ll a, ll b) { return (a*b)/__gcd(a, b); }
 
ll modInverse(ll a, ll m) { ll g = __gcd(a, m); return power(a, m-2, m); } 
 
int n,m,arr[mxn],ans=0;
void solve(){
    cin>>n>>m;
    REP(i,0,n)cin>>arr[i];
    sort(arr,arr+n);
    int i=0,j=n-1,s;
//IN THIS PROBLEM U WILL TRY TO THINK TO APPLY BS DUE TO TAG
    //BUT THINK IT LIKE
    // KI AGR HUMKO GONDOLA MIN. KARNE HAIN TOH 
    // HUMKO ZADA SE BACHON(MAX 2) KO EK GONDOLA ME BAITHANA HOGA
    // APPROACH IS SAME AS 2 POINTER SUM OF A+B=X 
    while(i<=j){
        if(i==j)s=arr[i];
        else s=arr[i]+arr[j];
        if(s<=m){
            
            i++,j--;
        }
        else{
            j--;
        }
        ans++;//incrementing in both cases as s>m then single child is considered
        //in the gondola in other condition it satisfy cond'
    }
    cout<<ans<<endl;
}
 
int main()
{
    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
