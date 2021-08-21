#define PQ_SIZE 10
#include <iostream>

using namespace std;
typedef struct 
{
    int q[(PQ_SIZE)];
    int n;
} priority_queue;

void pq_swap(priority_queue *q, int i, int j) {
    int temp;			
    temp = q->q[i];
    q->q[i] = q->q[j];
    q->q[j] = temp;
}
int pq_parent(int n){
    if(n==1) return -1;
   
    else {
         int x=n/2;
         return x;
    } 
}

int pq_young_child(int n){
    return 2*n;
}
void bubble_up(priority_queue *q, int p){
    if(pq_parent(p)==-1) return;

    if(q->q[pq_parent(p)]>q->q[p]){
        pq_swap(q,p,pq_parent(p));
        bubble_up(q,pq_parent(p));
    }
}
void pq_insert(priority_queue *q, int x){
    if(q->n >= PQ_SIZE)
        cout<<"Warning"<<endl;
    else{    
    q->n=(q->n) +1;
    q->q[q->n] = x;
    bubble_up(q,q->n);
    }
}
void make_heap(priority_queue *q, int s[], int n) {
    int i;                         

    q->n=0;
    for (i = 0; i < n; i++)
        pq_insert(q, s[i]);
}
void bubble_down(priority_queue *q, int p) {
    int c;				
    int i;				
    int min_index;		        

    c = pq_young_child(p);
    min_index = p;

    for (i = 0; i <= 1; i++)
        if ((c + i) <= q->n) {
            if (q->q[min_index] > q->q[c + i])
                min_index = c+i;
        }

    if (min_index != p) {
        pq_swap(q, p, min_index);
        bubble_down(q, min_index);
    }
}
int extract_min(priority_queue *q) {
    int min = -1;			
    if (q->n <= 0)
        printf("Warning: empty priority queue.\n");
    else {
        min = q->q[1];
        q->q[1] = q->q[ q->n ];
        q->n = q->n - 1;
        bubble_down(q, 1);
    }
    return (min);
}
void heapsort(int s[], int n)
{
    int i; /* counters */
    priority_queue q; /* heap for heapsort */
    make_heap(&q,s,n);
    for (i=0; i<n; i++)
        s[i] = extract_min(&q);
}

int main(){
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    heapsort(arr,n);

    for(auto &it: arr){
        cout<<it<<' ';
    }
    return 0;
    
}