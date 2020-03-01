#!/usr/bin/python3

def SelectSort( lst ):
    i=0
    while i < len(lst)-1:
        minIdx=i
        j=i+1
        while j < len(lst):
            if lst[j] < lst[minIdx]:
                minIdx=j
            j+=1
        if minIdx != i:
            tmp=lst[i]
            lst[i]=lst[minIdx]
            lst[minIdx]=tmp
        i+=1
    return lst

if __name__ == '__main__':
    import TestSort
    
    TestSort.TestSort(SelectSort)
