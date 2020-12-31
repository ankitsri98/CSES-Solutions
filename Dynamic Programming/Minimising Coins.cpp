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
//lower_bound returns an iterator pointing to the first ele. which has a value not less than ‘val
#define LB(arr,n) ll c=0;it=lower_bound(arr.begin(),arr.end(),n);if(it==arr.end()){c=1;}
//define it and if c==1 means not found
#define LB1(arr,n) ll idx=it-arr.begin();if(arr[idx]==n){ idx=idx;}else{idx=idx-1;}
// here idx holds the index( 0 based) of found element
//-----------------------------------------------------------------------------------------
//upper_bound returns an iterator pointing to the first ele. which has a value greater than ‘val’.
#define UB(arr,n) ll c=0;it=upper_bound(arr.begin(),arr.end(),n);if(it==arr.end()){c=1;}
#define UB1(arr,n) ll idx=it-arr.begin();
//-----------------------------------------------------------------------------------------
 
ll power(ll a,ll b,ll m) { ll ans=1; while(b) { if(b&1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans; }
 
ll lcm(ll a, ll b) { return (a*b)/__gcd(a, b); }
 
ll modInverse(ll a, ll m) { ll g = __gcd(a, m); return power(a, m-2, m); } 
 
bool cmp(pair<int ,int > &a,pair<int ,int > & b){
    if(a.second!=b.second){
        return a.first<b.first;
    }
    else{
        return a.second<b.second;
    }
}
//--------------------------------------------------------------------------------------------
 
ll countways(ll x,ll dp[],ll arr[],ll n){
    if(x==0)return 0;
    
    if(dp[x]!=-1)return dp[x];
    ll c=INT_MAX;
    REP(i,0,n){
        if(x-arr[i]>=0){
            ll p=countways(x-arr[i],dp,arr,n);
            c=min(c,p+1);
        }
    }
    return dp[x]=c;
}
 
void solve(){
    ll n,x,y;
    cin>>n>>x;
    ll dp[x+1];
    memset(dp,-1,sizeof(dp));
    ll arr[n+1];
    REP(i,0,n)cin>>arr[i];
    ll ans=countways(x,dp,arr,n);
    if(ans==INT_MAX)cout<<-1<<endl;
    else {
        cout<<ans<<endl;
    }
 
}
 
int32_t main()
{
    fastIO;
	int t=1;
	//cin>>t;
	while(t--)
	{
	    solve();
	}
	return 0;
}
