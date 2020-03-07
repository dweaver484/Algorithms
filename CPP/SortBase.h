#include <algorithm>
#include <vector>

using namespace std;

class SortBase {
    public:
        SortBase( string name = "" ) : m_name(name) {}
        virtual void Sort( vector<int> & v ) = 0;
        void Exchange( int & i, int & j ) { swap( i, j ); }
        bool LessThan( int & i, int & j ) { return i < j; }
        string GetName() { return m_name; }
    private:
        string m_name;
};

