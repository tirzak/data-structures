using namespace std;

class Seg{
vector<int> sg;

Seg(int n){
int x = (int)(ceil(log2(n))); //Height of segment tree
int max_size = 2*(int)pow(2, x) - 1; //Maximum size of segment tree
sg=vector<int> (max_size);
}

void buildtree(int l, int r , int pos, vector<int> &v){
if(l==r){
  sg[pos]=v[l];
  return;

}

int mid = (l+r)>>1;
buildtree(l,mid,2*pos+1,v);
buildtree(mid+1,r,2*pos+2,v);

sg[pos]=min(sg[2*pos+1],sg[2*pos+2]);
}

int query(int ql, int qh,int l , int h, int pos){
  if(ql<=l and qh>=h){
    return sg[pos];
  }

  if(ql>h or qh<l ){
    return -1;
  }

  int mid = (l+h)>>1;

  return min(query(ql,qh,l,mid,2*pos+1),query(ql,qh,mid+1,h,2*pos+2));


}

};
