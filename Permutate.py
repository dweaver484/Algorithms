#!/usr/bin/python3.5

def PermutateLoop( lst ):
    deq=[]
    deq.append([lst,0])
    while len(deq) != 0:
        p = deq.pop()
        if p[1] == len(p[0]):
            #yield
            print(p[0])


def Permutate( lst, idx=0):
    if len(lst) == idx:
        print(lst)
    else:
        numRotations = len(lst)-idx
        for i in range(numRotations):
            Permutate(lst, idx+1)
            lst=lst[:idx] + lst[idx+1:] + lst[idx:idx+1] # Rotate

def Generate( lst, idx=0):
    if len(lst) == idx:
        #print(lst)
        yield lst
    else:
        numRotations = len(lst)-idx
        for i in range(numRotations):
            yield from Generate(lst, idx+1)
            lst=lst[:idx] + lst[idx+1:] + lst[idx:idx+1] # Rotate

if __name__ == '__main__':
    l=[x for x in range(1,6)]
    Permutate(l)
    input("******* Press <ENTER> to continue ********")
    i = 0
    for test in Generate(l):
        i+=1
        print('{:3} : {}'.format(i, test))

