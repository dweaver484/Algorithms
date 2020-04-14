#include <algorithm>
#include <vector>

using namespace std;

class SortBase {
    public:
        SortBase( string name = "" ) : m_name(name) {}
        virtual void Sort( vector<long> & v ) = 0;
        void Exchange( long & i, long & j ) { swap( i, j ); }
        bool LessThan( long & i, long & j ) { return i < j; }
        string GetName() { return m_name; }
    private:
        string m_name;
};

