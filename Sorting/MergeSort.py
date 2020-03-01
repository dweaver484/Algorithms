#!/usr/bin/python3

def MergeSort( arr ):
    if len(arr) > 1:
        mid = int(len(arr) / 2)
        l = MergeSort(arr[:mid])
        r = MergeSort(arr[mid:])
        i,j,k = 0,0,0
        while i < len(l) and j < len(r):
            if l[i] <= r[j]:
                arr[k] = l[i]
                k+=1
                i+=1
            else:
                arr[k] = r[j]
                k+=1
                j+=1
        if i >= len(l):
            arr=arr[:k]+r[j:]
        else:
            arr=arr[:k]+l[i:]
    return arr

if __name__ == '__main__':
    import TestSort
    
    TestSort.TestSort(MergeSort)
