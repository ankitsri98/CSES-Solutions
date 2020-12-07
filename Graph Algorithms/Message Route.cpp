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
 
ll n,m;
vector<int > adj[mxn];
vector<int > mark[mxn];
//IN CASE OF STORING THE PATH IN CASE OF GRID USE WHAT CAUSED YOU TO LAND ON THAT BLOCK(INDEX) THAT IS DIRECTION
//IN CASE ADJ. MATRIX USE ANOTHER ADJ MATRIX TO STORE THE PATH  THEN WHILE LOOP 
int vis[mxn];
int lev[mxn];
void bfs(int u){
    vis[u]=1;
    lev[u]=1;
    queue<int > q;
    q.push(u);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<adj[x].size();i++){
            if(vis[adj[x][i]]==0){
               // cout<<adj[x][i]<<" "<<vis[adj[x][i]]<<endl;
                mark[adj[x][i]].PB(x);
                vis[adj[x][i]]=1;
                q.push(adj[x][i]);
                lev[adj[x][i]]=lev[x]+1;
            }
        }
    }
}
void solve(){
 
    cin>>n>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        adj[a].PB(b);
        adj[b].PB(a);
    }
    mem(vis,0);
    bfs(1);
    //cout<<lev[n]<<endl;
    //cout<<mark[4][0]<<endl;
    if(mark[n].size()==0){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
    vector<int > v;
    int y=n;
    while(y!=1){
        
        v.PB(y);
        y=mark[y][0];
    }
    v.PB(1);
    reverse(v.begin(),v.end());
    cout<<v.size()<<endl;
    for(auto i : v){
        cout<<i<<" ";
    }
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
