#include <iostream>
#include <queue>
using namespace std;

void merge(int *arr, int low, int middle, int high);
void mergesort(int *arr, int low, int high){
    int middle;
    if(low<high)
        {
            middle=(low+high)/2;
            mergesort(arr,low,middle);
            mergesort(arr,middle+1,high);
            merge(arr,low,middle,high);

        }
}
void merge(int *arr, int low, int middle, int high){
    int i;
    queue <int> queue1;
    queue <int> queue2;

    for(i=low; i<=middle; i++) queue1.push(arr[i]);
    for(i=middle+1; i<=high; i++) queue2.push(arr[i]);

    i=low;
    while (!(queue1.empty()|| queue2.empty()))
    {
       if(queue1.front()<=queue2.front()){
        arr[i++] = queue1.front();
        queue1.pop();
       }
       else{
        arr[i++] = queue2.front();
        queue2.pop();
       }

    }

    while (!queue1.empty())
    {
        arr[i++] = queue1.front();
        queue1.pop();
    }

    while (!queue2.empty())
    {
        arr[i++] = queue2.front();
        queue2.pop();
    }
    
    
}


int main (void){

int arr[]={33, 42, 9, 37, 8, 47, 5, 29, 49, 31, 4, 48, 16, 22, 26};
int arr_size= sizeof(arr)/sizeof(arr[0]);
mergesort(arr,0,(arr_size-1));
for (int i=0; i<arr_size;i++){
    cout<<arr[i]<<'\n';
}

}
