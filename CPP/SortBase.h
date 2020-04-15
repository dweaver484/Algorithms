#include <algorithm>
#include <chrono>
#include <vector>

using namespace std;

class SortBase {
    public:
        SortBase( string name = "" ) : m_name(name) {}
        virtual void Sort( vector<long> & v ) = 0;
        void Exchange( long & i, long & j ) { swap( i, j ); }
        bool LessThan( long & i, long & j ) { return i < j; }
        string GetName() { return m_name; }
        void ClearTime() {
            m_min = numeric_limits<long>::max();
            m_max = m_avg = 0; 
            m_sortTimes.clear();
        }
        void AddTime( chrono::nanoseconds t ) {
            m_sortTimes.push_back(t.count());
            m_max = max(m_max,t.count());
            m_min = min(m_min,t.count());
            long sum = 0;
            for( auto v : m_sortTimes ) {
                sum += v;
            }
            m_avg = sum / m_sortTimes.size();
        }
        long GetMin() { return m_min; }
        long GetMax() { return m_max; }
        long GetAvg() { return m_avg; }
    private:
        string m_name;
        vector<long> m_sortTimes;
        long m_min{numeric_limits<long>::max()};
        long m_max{0};
        long m_avg{0};
};

