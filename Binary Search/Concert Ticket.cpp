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
 
//ll modInverse(ll a, ll m) { ll g = __gcd(a, m); return power(a, m-2, m); } 
 
ll n,m,arr[mxn],ans=0,brr[mxn];
void solve(){
    cin>>n>>m;
    multiset<ll > st;
    REP(i,0,n){cin>>arr[i];st.insert(arr[i]);}
    
    REP(i,0,m)cin>>brr[i];
    vector<ll > v(m,INT_MAX);
    for(int i=0;i<m;i++){
        auto it=st.lower_bound(brr[i]+1);// +1 done coz we need less than or equal to brr[i]
        //and LB gives >= so it returned -1 will always be less than or equal to brr[i]
        if(it==st.begin())cout<<-1<<endl;
        else {
            --it;
            cout<<*it<<endl;
            st.erase(it);
        }
    }
}
 
int32_t main()
{
	int t=1;
	//cin>>t;
	while(t--)
	{
	    solve();
	}
	return 0;
}
