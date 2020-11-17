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
    //cout << "PASSED" << endl;
}

vector<long> GenerateTestData( long num, long numKeys ) {
    vector<long> v(num);
    while( num-- ) {
        v[num] = rand() / (RAND_MAX / numKeys);
    }
    return v;
}

int runTest(long numElements, long numRuns, long numKeys, vector<long> *pv = nullptr)
{
    if(numKeys == -1) numKeys = numElements;
    cout << endl;
    vector<shared_ptr<SortBase>> vSA { 
        make_shared<SelectSort>(),
        //make_shared<InsertSort>(),
        //make_shared<ShellSort>(), 
        //make_shared<MergeSort>(),  // Recurses on non-virtual method // No observable difference between virtual & non-virtual method
        //make_shared<MergeSort2>(), // Recurses on virtual method     // No observable difference between virtual & non-virtual method
        make_shared<QuickSort>(), 
        //make_shared<QuickSortS>(), // Uses std::swap() & is actually slower than using tmp variable
        //make_shared<QuickSortH>(), // HackerRank
        //make_shared<QuickSortP>(), // Uses std::partition()
        //make_shared<QuickSort5>(), 
        //make_shared<QuickSort3Way>(), 
        //make_shared<QuickSort3Way2>(), // QuickSort3way2 uses std::swap() & is actually slower than using tmp variable
        make_shared<HeapSort>(), 
    };
    if( pv ) numElements = pv->size();
    cout << "numElements = " << numElements << ", numRuns = " << numRuns << ", numKeys = " << numKeys << endl;
    for( long runNum=0; runNum < numRuns; ++runNum ) {
        vector<long> v = pv ? *pv : GenerateTestData(numElements, numKeys);
        if(runNum == 0 && numElements <= 100) PrintVector( "IN: ", v);
        vector<long> test;
        for( auto pSA : vSA ) {
            test = v; // Make a copy
            //PrintVector( "IN: ", test );
            pSA->Prep( test );
            auto ts = chrono::high_resolution_clock::now();
            pSA->Sort( test );
            auto te = chrono::high_resolution_clock::now();
            pSA->Finish( test );
            //PrintVector( "OUT: ", test );
            VerifySort( test );
            auto duration = chrono::duration_cast<chrono::nanoseconds>(te - ts);
            pSA->AddTime(duration);
            //cout << setw(12) << pSA->GetName() << " execution time:" << setw(15) << duration.count() << " nS" << endl;
        }
    }
    cout << setw(15) << "Sort" <<  setw(15) << "Min" << setw(15) << "Max" << setw(15) << "Avg" << endl;
    for( auto pSA : vSA ) {
        cout << setw(15) << pSA->GetName() << setw(15) << pSA->GetMin() << setw(15) << pSA->GetMax() << setw(15) << pSA->GetAvg() << " nS" << endl;
    }
    cout << "=============================================================" << endl;
    return 0;
}

//
// Usage: ./TestSort numElements numRuns numKeys
//
int main(int argc, char* argv[])
{
    long numElements = 1000;
    long numRuns = 1;
    long numKeys = -1;
    if(argc > 1) {
        long* parms[] = {&numElements, &numRuns, &numKeys};
        for(int i = 1; i < argc; ++i) {
            stringstream ss(argv[i]);
            ss >> *parms[i-1];
        }
        if(numKeys == -1) numKeys = numElements;
        runTest(numElements, numRuns, numKeys);
    }
    else {
        runTest(5, 10, -1);
        runTest(7, 10, -1);
        runTest(10, 10, -1);
        runTest(15, 10, -1);
        runTest(50, 10, -1);
        runTest(100, 10, -1);
        runTest(1000, 10, -1);
        runTest(10000, 10, -1);
        //runTest(100, 10, 2);
        //runTest(100, 10, 5);
        //runTest(100, 10, 10);
        //runTest(10000, 10, 5);
        //runTest(10000, 10, 10);
        //runTest(10000, 10, 100);
    }
    return 0;
}

