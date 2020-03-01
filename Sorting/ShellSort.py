#!/usr/bin/python3

def ShellSort( lst ):
    h = 1
    while h < len(lst)/3:
        h = 3*h + 1
    while h > 0:
        i = h
        while i < len(lst):
            if lst[i] < lst[i-h]:
                tmp = lst[i]
                lst[i] = lst[i-h]
                lst[i-h] = tmp
                j = i - h
                while j >= h and lst[j] < lst[j-h]:
                    tmp = lst[j]
                    lst[j] = lst[j-h]
                    lst[j-h] = tmp
                    j -= h
            i += 1
        h = int(h/3)
    return lst

if __name__ == '__main__':
    import TestSort

    TestSort.TestSort( ShellSort )


