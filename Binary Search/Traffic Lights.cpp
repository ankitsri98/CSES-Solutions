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
 
ll n,x,y;
 
void solve(){
    cin>>x>>n;
    vector<ll > arr(n);
    set<ll > s;
    map<ll , ll > mp;//is used to store the possible range witout traffic lights
    s.insert(0);
    s.insert(x);
    mp[x]=1;//because first time r-l will be = X
    REP(i,0,n){
        cin>>arr[i];
        auto idx=s.lower_bound(arr[i]);//finding the index that is somewhere 
        //middle of end 
        ll r=*idx; //storing the right side value
        --idx;
        ll l=*idx; //storing the left side value
        --mp[r-l]; //now this dist will not be present 
        if(!mp[r-l]){
            mp.erase(r-l);//if count 0 delete it
        }
        s.insert(arr[i]);//insert in set
        mp[r-arr[i]]++;//increment the new ranges arrives without traffic
        mp[arr[i]-l]++;
        cout<<(--mp.end())->first<<" ";//print from end as in sorted order
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
