//Example problem https://codeforces.com/contest/295/problem/A (greg and array)

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <iomanip>
#include <bitset>
#include <random>
#include <queue>
#include <cstring>
#include <cassert>
#include <stack>
 
using namespace std;
 
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define all_(x) x.rbegin(), x.rend()
#define containsKey(x, key) (x.find(key) != x.end())
#define ppc  __builtin_popcount
#define ppcll __builtin_popcountll
#define len(x) (ll)x.size()


typedef long long ll;
typedef long long lint;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<vector<ll>> vvl;
typedef vector<vector<int>> vvi;
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
using vl = vector<ll>;
using namespace std;

void solve(){
  ll sz; 
  cin >> sz;
  ll m,k;
  cin>>m>>k;
  map<ll,tuple<ll,ll,ll>>mp;

 
  map<ll,ll> cntr;
  vl b(sz+1);

  vector<ll> a(sz);
  for(auto &e : a){
    cin>>e;
  }
 
  b[0]=a[0];

  vl qtr (m);
  vl qtrdiff (m+1);


  for(ll i=1 ; i < sz ;++i){
    b[i]=a[i]-a[i-1];
  }


  for(ll i=1 ; i <= m ;++i){
    ll x,y,d;
    cin>>x>>y>>d;
    mp[i]={x,y,d};
  }


  for(ll i=0 ; i < k ;++i){
    ll x,y;
    cin>>x>>y;
    --x,--y;
    qtrdiff[x]+=1;
    qtrdiff[y+1]-=1;
    
  }

   for(ll i=0 ; i < m ;++i){
    if(i==0){
      qtr[0]=qtrdiff[0];
    }
    else{
      qtr[i]=qtrdiff[i]+qtr[i-1];
    }
    //cout<<a[i]<<" ";
  }

  for(ll i=0 ; i < m ;++i){
    if(qtr[i]==0) continue;
    auto &[x,y,d]=mp[i+1];
    --x, --y;
    b[x]+=(qtr[i]*d);
    b[y+1]-=(qtr[i]*d);
  }



  for(ll i=0 ; i < sz ;++i){
    if(i==0){
      a[0]=b[0];
    }
    else{
      a[i]=b[i]+a[i-1];
    }
    cout<<a[i]<<" ";
  }
  cout<<"\n";





}

signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll t;
  //cin >> t;

 

    solve();

  

  return 0;
}
