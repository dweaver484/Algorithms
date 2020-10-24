#!/usr/bin/python3

class Heap:
    def __init__(self, lst):
        self.pq = [0]
        for i in lst:
            self.insert(i)

    def swap(self, i, j):
        t = self.pq[i]
        self.pq[i] = self.pq[j]
        self.pq[j] = t

    def insert(self, x):
        self.pq.append(x)
        self.swim(len(self.pq)-1)

    def delMax(self):
        r = self.pq[1]
        self.pq[1] = self.pq[len(self.pq)-1]
        del self.pq[len(self.pq)-1:]
        self.sink(1)
        return r

    def swim(self, k):
        j = int(k/2)
        while k > 1 and self.pq[k] > self.pq[j]:
            self.swap(k, j)
            k = j
            j = int(k/2)

    def sink(self, k):
        sz = len(self.pq)
        j = 2*k
        while j < sz:
            if j+1 < sz and self.pq[j] < self.pq[j+1]:
                j+=1
            if self.pq[k] < self.pq[j]:
                self.swap(k, j)
                k = j
            else:
                break

    def display(self):
        print(self.pq)
        row = 1
        n = 1
        lst = []
        for i in range(1,len(self.pq)):
            lst.append(self.pq[i])
            if i >= n:
                self.println(lst, row)
                lst.clear()
                row+=1
                n=2**row-1
        self.println(lst, row)

    def println(self, lst, row):
        ns=int(120/(2**(row-1)+1))
        s=''
        for i in lst:
            s += ns*' ' + str(i)
        print(s)

#f(1)=120/2=120/(2**(n-1)+1)
#f(2)=120/3
#f(3)=120/5
#f(4)=120/9
if __name__ == '__main__':
    hp = Heap([1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20])
    hp.display()

