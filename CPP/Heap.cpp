#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Heap {
    public:
        Heap( vector<int> v = {} ) {
           for( auto & i : v ) {
               insert(i);
           }
        }

        void insert( int i ) {
            pq.push_back(i);
            swim(pq.size()-1);
        }

        int delMax() {
            int r = pq[1];
            pq[1] = pq.back();
            pq.pop_back();
            sink(1);
            return r;
        }

        void swim( size_t i ) {
            size_t j = i/2;
            while( i > 1 && pq[i] > pq[j] ) {
                swap(pq[i], pq[j]);
                i = j;
                j = i/2;
            }
        }

        void sink( size_t i ) {
            size_t j = 2*i;
            while( j < pq.size() ) {
                if( j + 1 < pq.size() && pq[j] < pq[j+1] ) {
                    ++j;
                }
                if( pq[i] < pq[j] ) {
                    swap(pq[i], pq[j]);
                    i=j;
                    j=2*i;
                }
                else {
                    break;
                }
            }
        }

        // 1->1  2**1-1 | 120/2 120/(2**(n-1)+1)
        // 2->3  2**2-1 | 120/3
        // 3->7  2**3-1 | 120/5
        // 4->15 2**4-1 | 120/9
        void display() {
            int row=1;
            int n=2;
            int i=1;
            vector<int> line;
            for( int i=1; i < pq.size(); ++i ) {
                if( i>n-1 ) {
                    println(line,120/(n/2+1));
                    line.clear();
                    n=2*n;
                }
                line.push_back(pq[i]);
            }
            println(line, 120/(n/2+1));
        }

        void println( vector<int> line, int num_spaces) {
            string sp(num_spaces, ' ');
            for( auto &i : line ) {
                cout << sp << i;
            }
            cout << endl;
        }

    private:
        vector<int> pq = {0};
};

int main(void)
{
    Heap hp({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20});
    hp.display();
}
