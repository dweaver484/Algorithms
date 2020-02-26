import time
import random

def TestSort( sortFunc, lst=None ):
    if not lst:
        lst = random.sample(range(0,50),20)
    print('In:  {}'.format(lst))
    ts=time.time()
    result = sortFunc(lst)
    te=time.time()
    print('Out: {}'.format(result))
    print('{} Execution Time: {} ms'.format(sortFunc.__name__, (te-ts)*1000))
    for i in range(1,len(result)):
        if result[i] < result[i-1]:
            print('FAIL')
            return result
    print('PASS')
    return result

