#!/usr/bin/python3

def QuickSort( arr, start=0, end=None ):
    if end == None: end = len(arr) - 1
    if start < end:
        piv_val = arr[start]
        i = start + 1
        j = end
        piv_idx = j
        while i <= j:
            if arr[i] >= piv_val:
                piv_idx = i - 1
                while j >= i:
                    if arr[j] <= piv_val:
                        tmp = arr[i]
                        arr[i] = arr[j]
                        arr[j] = tmp
                        piv_idx = i
                        break
                    j -= 1
            i += 1
        tmp = arr[start]
        arr[start] = arr[piv_idx]
        arr[piv_idx] = tmp
        #print('arr: {}'.format(arr))
        QuickSort(arr, start, piv_idx-1)
        QuickSort(arr, piv_idx+1, end)
    return arr

if __name__ == '__main__':
    import TestSort
    
    TestSort.TestSort(QuickSort)
