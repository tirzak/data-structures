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
#include <array>

using namespace std;

#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define all_(x) x.rbegin(), x.rend()
#define containsKey(x, key) (x.find(key) != x.end())
#define ppc  __builtin_popcount
#define ppcll __builtin_popcountll
#define len(x) (int)x.size()

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
using vpll=vector<pll>;
class Seg{
vector<ll> sg;
vector<ll> lazy;

int sz;

public:

Seg(int v){
  sz=v;
  int x = (int)(ceil(log2(v))); //Height of segment tree
  int max_size = 2*(int)pow(2, x) - 1;
  v--;
  v |= v >> 1;
  v |= v >> 2;
  v |= v >> 4;
  v |= v >> 8;
  v |= v >> 16;


  v++;
  v*=2;
  sg=vector<ll> (v-1,0);
  lazy=vector<ll>(v-1);
}

void buildtree(int l, int r , int pos, vector<ll> &v){
  if(l==r){
    sg[pos]=v[l];
    return;

  }

  int mid = (l+r)>>1;
  buildtree(l,mid,2*pos+1,v);
  buildtree(mid+1,r,2*pos+2,v);

  sg[pos]=min(sg[2*pos+1],sg[2*pos+2]);
}


ll query(int ql, int qh,int l , int h, int pos){
  if(ql<=l and qh>=h){
    return sg[pos];
  }

  if(ql>h or qh<l ){
    return LLONG_MAX;
  }

  int mid = (l+h)>>1;

  return min(query(ql,qh,l,mid,2*pos+1),query(ql,qh,mid+1,h,2*pos+2));


}




ll queryLazy(int ql, int qh,int l , int h, int pos){
      if(l>h){
    return LLONG_MAX;
  }
 
    if(lazy[pos]!=0){
    sg[pos]+=lazy[pos];
    if(l!=h){
      lazy[2*pos+1]+=lazy[pos];
      lazy[2*pos+2]+=lazy[pos];

    }
    lazy[pos]=0;
  }
   if(ql<=l and qh>=h){
    return sg[pos];
  }
      if(ql>h or qh<l ){
    return LLONG_MAX;
  }


  int mid = (l+h)>>1;

  return min(queryLazy(ql,qh,l,mid,2*pos+1),queryLazy(ql,qh,mid+1,h,2*pos+2));


}
ll queryLazyUtil(int ql, int qh){
  return queryLazy(ql,qh,0,sz-1,0);
}


void lazyUpdate(int ql, int qh,int l , int h, int pos, ll delta){
  if(l>h){
    return;
  }

  if(lazy[pos]!=0){
    sg[pos]+=lazy[pos];
    if(l!=h){
      lazy[2*pos+1]+=lazy[pos];
      lazy[2*pos+2]+=lazy[pos];

    }
    lazy[pos]=0;
  }

    if(ql>h or qh<l ){
    return;
    }

  if(ql<=l and qh>=h){
     sg[pos]+=delta;
      if(l!=h){
      lazy[2*pos+1]+=delta;
      lazy[2*pos+2]+=delta;

    }
    return;

  }

    int mid = (l+h)>>1;

  lazyUpdate(ql,qh,l,mid,2*pos+1,delta);
  lazyUpdate(ql,qh,mid+1,h,2*pos+2,delta);
  sg[pos]=min(sg[2*pos+1],sg[2*pos+2]);


  
}

void lazyUpdateUtil(int ql, int qh,ll delta){
   lazyUpdate(ql,qh,0,sz-1,0,delta);
}


};
