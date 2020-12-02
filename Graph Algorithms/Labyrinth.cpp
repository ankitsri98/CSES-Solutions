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
 
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
char ch[]={'R','D','L','U'};
ll n,x,y,a,b,m;
char arr[1005][1005];
int fi=0;
string an;
int si,sj,ei,ej;
int point[1005][1005];
//THIS IS USED TO TRACK BACK THE PATH FROM B TO A STORING JUST
//THE INDEX WHICH CHANGES THE INDEXES OF MOVEMENT
bool valid(int i,int j){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    return true;
}
 
void bfs(){
    queue<pair<int ,int > > q;
    q.push({si,sj});
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx=dx[i]+p.F;
            int ny=dy[i]+p.S;
            if(valid(nx,ny) && arr[nx][ny]=='.'){
                arr[nx][ny]='#';//BLOCKING THIS PATH 
                q.push({nx,ny});
                point[nx][ny]=i;//STORING INDEX VALUE THAT MAKE CHANGES
            }
        }
    }
}
 
void solve(){
    
    cin>>n>>m;
    REP(i,0,n){
        REP(j,0,m){
            cin>>arr[i][j];
        }
    }
    mem(point,-1);
    REP(i,0,n){
        REP(j,0,m){
            if(arr[i][j]=='A'){
                arr[i][j]='.';
                si=i,sj=j;
            }
            else if(arr[i][j]=='B'){
                //STORING THE INDEXES AND MARKING THE INDEX TO BE ABLE TO TRAVERSE
                arr[i][j]='.';
                ei=i,ej=j;
            }
        }
    }
    bfs();
    
    if(point[ei][ej]==-1){
    	cout<<"NO"<<endl;
    }
    else{
        pair<int ,int > p={ei,ej};
       // cout<<p.F<<" "<<p.S<<" "<<si<<" "<<sj<<endl;
        while(1){
        	//cout<<"sdfs"<<endl;
            fi++;
            an+=ch[point[p.F][p.S]];
            int k=point[p.F][p.S];
            p.F-=dx[k];
            p.S-=dy[k];
            //cout<<p.F<<" "<<p.S<<endl;
            if(p.F==si && p.S==sj)break;
        }
        reverse(an.begin(),an.end());//COZ WE WERE TRAVELLING B TO A
    	cout<<"YES"<<endl;
    	cout<<fi<<endl;
    	cout<<an<<endl;
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
