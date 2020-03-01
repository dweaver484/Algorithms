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

if __name__ == '__main__':
    import SelectSort as ss
    import InsertionSort as ins
    import ShellSort as shs
    import MergeSort as ms

    CompareSorts([ss.SelectSort, ins.InsertionSort, shs.ShellSort, ms.MergeSort], 50)

