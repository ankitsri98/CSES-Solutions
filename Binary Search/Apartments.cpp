#include <bits/stdc++.h>
using namespace std;
#define int long long int 
 
/*int func(int mark[],int arr[],int val,int n,int k){
    int l=0,r=n-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(val>=arr[mid]-k && val<=arr[mid]+k && mark[arr[mid]]>0){
            mark[arr[mid]]--;
            return 1;
        }
        else if(val>arr[mid]+k){
            l=mid+1;
        }
        else if(val<arr[mid]-k){
            r=mid-1;
        }
    }
    return 0;
}*/
int32_t main() {
	int n,m,k;
	cin>>n>>m>>k;
	int arr[n], brr[n];
	//int mark[2*100005]={0};
	for(int i=0;i<n;i++){
	    cin>>arr[i];//appartment
	    //mark[arr[i]]++;
	}
	for(int i=0;i<m;i++){
	    cin>>brr[i];//applicant
	}
	sort(arr,arr+n);
	sort(brr,brr+m);
	int c=0;
	/*for(int i=0;i<m;i++){
	    c+=func(mark,arr,brr[i],n,k);
	}*/
	int i=0,j=0;
	while(i<n && j<m){
	    if(arr[i]>=brr[j]-k  && arr[i]<=brr[j]+k){
	        c++;
	        i++;
	        j++;
	    }
	    else if(arr[i]>brr[j]+k){
	        j++;
	    }
	    else if(arr[i]<brr[j]-k){
	        i++;
	    }
	}
	cout<<c<<endl;
	return 0;
}
