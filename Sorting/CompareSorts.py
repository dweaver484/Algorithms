#!/usr/bin/python3
import random
import TestSort as ts

def CompareSorts( sortFuncs, numRuns=10, lst=None):
    if lst is None:
        lst = random.sample(range(0,100),50)
    print('='*40)
    for sortFunc in sortFuncs:
        ts.TestSort(sortFunc, numRuns, lst[:])
        print('='*40)

def PythonSort( arr ):
    arr.sort()
    return arr

if __name__ == '__main__':
    import SelectSort as ss
    import InsertionSort as ins
    import ShellSort as shs
    import MergeSort as ms

    arr = [ 20, 1, 19, 2, 18, 3, 17, 4, 16, 5, 15, 6, 14, 7, 13, 8, 12, 9, 11, 10 ]
    CompareSorts([ss.SelectSort, ins.InsertionSort, shs.ShellSort, ms.MergeSort, PythonSort], 50, arr)

