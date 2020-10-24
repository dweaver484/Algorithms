#!/usr/bin/python3

class Heap:
    def __init__(self, lst):
        self.pq = [0]
        for i in lst:
            self.insert(i)

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
            t = self.pq[k]
            self.pq[k] = self.pq[j]
            self.pq[j] = t
            k = j
            j = int(k/2)

    def sink(self, k):
        sz = len(self.pq)
        j = 2*k
        while j < sz:
            if j+1 < sz and self.pq[j] < self.pq[j+1]:
                j+=1
            if self.pq[k] < self.pq[j]:
                t = self.pq[k]
                self.pq[k] = self.pk[j]
                self.pq[j] = t
                k = j
            else:
                break

if __name__ == '__main__':
    hp = Heap([1,2,3,4,5,6,7,8,9,10])
    for i in range(10):
        print(hp.pq[i+1])
