#!/usr/bin/python3

def InsertionSort( lst ):
    for i in range(len(lst)-1):
        if lst[i+1] < lst[i]:
            tmp = lst[i]
            lst[i] = lst[i+1]
            lst[i+1] = tmp
            j = i
            while j > 0 and lst[j] < lst[j-1]:
                tmp = lst[j]
                lst[j] = lst[j-1]
                lst[j-1] = tmp
                j-=1
    return lst

if __name__ == '__main__':
    import TestSort

    TestSort.TestSort( InsertionSort )


