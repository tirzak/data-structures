from collections import deque


def mergesort(arr,low,high):
    if low >= high:
        return
    middle = (low+high)//2
    mergesort(arr,low,middle)
    mergesort(arr,middle+1,high)
    merge(arr,low,middle,high)

def merge(arr,low,middle,high):
    queue1=deque()
    queue2= deque()
    for x in range(low,(middle+1)):
        queue1.append(arr[x])
    for z in range(middle+1,(high+1)):
        queue2.append(arr[z])    


    i=low
    
    while not (not queue1 or not queue2):
        left=queue1[0]
        right=queue2[0]
 
        
        if((left<=right)):
            arr[i] = queue1.popleft()
            i+=1

        else:
            arr[i] =  queue2.popleft()
            i+=1


    while queue1:
        arr[i] = queue1.popleft()
        i+=1

                    
    while queue2:
        arr[i] = queue2.popleft()
        i+=1




l=[33, 42, 9, 37, 8, 47, 5, 29, 49, 31, 4, 48, 16, 22, 26]

mergesort(l,0,len(l)-1)

print(l)