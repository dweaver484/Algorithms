import gc
import time
import random
import statistics as stats

NUM_RUNS = 5
TEST_SIZE = 100
VALUE_RANGE = 2 * TEST_SIZE

def VerifySort( lst ):
    for i in range(1,len(lst)):
        if lst[i] < lst[i-1]:
            return False
    return True

def TestSort( sortFunc, numRuns=NUM_RUNS, lst=None ):
    if lst is None:
        lst = random.sample(range(0,VALUE_RANGE),TEST_SIZE)
    print('In:  {}'.format(lst))
    execTimes = []
    for i in range(numRuns):
        arr = lst[:] # Make a fresh copy
        gc.disable()
        ts=time.time()
        result = sortFunc(arr)
        te=time.time()
        gc.enable()
        execTimes.append(te-ts)
        if not VerifySort(result):
            print('Out: {}'.format(result))
            print('******** FAIL *********')
            break;
    else:
        print('Out: {}'.format(result))
        print('PASS')
    timeMax = max(execTimes) * 1000 # ms
    timeMin = min(execTimes) * 1000 # ms
    timeAvg = stats.mean(execTimes) * 1000 # ms
    print('{:<14}: {} run execution time min={:.4} avg={:.4} max={:.4} ms'.format(sortFunc.__name__, numRuns, timeMin, timeAvg, timeMax))
    return result

