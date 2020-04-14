#include <chrono>
#include <iomanip>
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>
#include <cstdlib>

#include "SortingAlgos.h"

using namespace std;

void PrintVector( string msg, vector<long> v ) {
    cout << msg;
    for( auto & i : v ) cout << i << " ";
    cout << endl;
}

void VerifySort( vector<long> v ) {
    for( long i = 1; i < v.size(); ++i ) {
        if( v[i-1] > v[i] ) {
            cout << "FAILED" << endl;
            return;
        }
    }
    cout << "PASSED" << endl;
}

vector<long> GenerateTestData( long num ) {
    vector<long> v(num);
    long sampleSize = num;
    while( num-- ) {
        v[num] = rand() / (RAND_MAX / sampleSize);
    }
    return v;
}

int main(int argc, char* argv[])
{
    long numElements = 1000;
    long numRuns = 1;
    long* parms[] = {&numElements, &numRuns};
    for(int i = 1; i < argc; ++i) {
        stringstream ss(argv[i]);
        ss >> *parms[i-1];
    }
    cout << endl;
    vector<shared_ptr<SortBase>> vSA { 
        make_shared<SelectSort>(),
        make_shared<InsertSort>(),
        make_shared<ShellSort>(), 
        make_shared<MergeSort>(), 
        make_shared<QuickSort>(), 
    };
    //vector<long> v = {20, 1, 19, 2, 18, 3, 17, 4, 16, 5, 15, 6, 14, 7, 13, 8, 12, 9, 11, 10};
    vector<long> v = GenerateTestData(numElements);
    vector<long> test;
    cout << "numElements = " << numElements << ", numRuns = " << numRuns << endl;
    if(numElements <= 200) PrintVector( "\nIN: ", v);
    while( numRuns-- > 0 ) {
        for( auto pSA : vSA ) {
            test = v; // Make a copy
            //PrintVector( "\nIN: ", test );
            auto ts = chrono::high_resolution_clock::now();
            pSA->Sort( test );
            auto te = chrono::high_resolution_clock::now();
            //PrintVector( "OUT: ", test );
            VerifySort( test );
            auto duration = chrono::duration_cast<chrono::nanoseconds>(te - ts);
            cout << setw(12) << pSA->GetName() << " execution time:" << setw(15) << duration.count() << " nS" << endl;
        }
    }
    return 0;
}


