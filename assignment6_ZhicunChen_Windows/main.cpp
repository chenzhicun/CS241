#include <iostream>
#include <limits>
#include <ctime>
#include <vector>
#include "sort.h"
using namespace std;
typedef float T; // Change the type here


int main()
{
    int r, round, i_th;
    T x;

    // Q1:
    cout << "--------------------------------- "<< endl;
    cout << " Q1: Test Partition" << endl;
    cout << "--------------------------------- "<< endl;

    cout << "How many times you want to test Partition?"<<endl;
    cin >> round;
    // input 0 to skip this part

    for (int i = 0; i < round; ++i) {
        // clear the input buffer, no need to change.
        try {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Input values: " << endl;
            vector<T> data;
            data.clear();
            while (cin >> x) {
                /*
                *to do : store the inputs
                */
                data.push_back(x);
            }

            cout << "Partition array by random select pivot\n";
            // to do :
            int n = data.size();
            if (n == 0)
                throw EmptyArray();
            r = rand() % (n); // n is the size of current array

            /*
            * to do ：print r and A[r];
            */
            cout << r << ' ' << data[r] << '\n';
            /*
            * to do : Partition array by A[r]
            *         print the rearranged array
            */
            Partition(data, r,0,data.size()-1);
            vector<T>::iterator it;
            for (it = data.begin(); it != data.end(); ++it)
                cout << *it << ' ';
            cout << endl;
        }catch(EmptyArray){
            cerr<<"Invalid action on an empty array!\n";
        }
    }

    // Q2:
    // clear the input buffer, no need to change.
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "--------------------------------- "<< endl;
    cout << " Q2: Test Quicksort " << endl;
    cout << "--------------------------------- "<< endl;

    cout << "How many times you want to test Quicksort?"<<endl;
    cin >> round;
    // ----- input 0 to skip this part
    for(int i = 0; i< round; ++i) {
        try {
            // clear the input buffer, no need to change.
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Input values: " << endl;
            vector<T> data;
            data.clear();
            while (cin >> x) {
                /*
                 *to do : store the inputs
                 */
                data.push_back(x);
            }
            cout << "Sort Array"<<endl;
            if (data.size() == 0)
                throw EmptyArray();
            /*
             *to do : quicksort
             *        print the sorted array
             */
            Quicksort(data);
            for (vector<T>::iterator it = data.begin(); it != data.end(); ++it) {
                cout << *it << ' ';
            }
            cout << endl;
        }catch(EmptyArray){
            cerr<<"Invalid action on an empty array!\n";
        }
    }

    // Q3:
    // clear the input buffer, no need to change.
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "--------------------------------- "<< endl;
    cout << " Q3: Test Rselect " << endl;
    cout << "--------------------------------- "<< endl;

    cout << "How many times you want to test Rselect?"<<endl;
    cin >> round;
    //input 0 to skip this part
    for(int i = 0; i < round; ++i) {
        // clear the input buffer, no need to change.
        try {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Input values: " << endl;
            vector<T> data;
            data.clear();
            while (cin >> x) {
                /*
                 *to do : store the inputs
                 */
                data.push_back(x);
            }
            // to do:
            int n=data.size();
            if(n==0)
                throw EmptyArray();
            i_th = rand() % (n) + 1; // n is the size of current array
            cout << "select i-th smallest element" << endl;
            /*
             *to do : random selection
             *        print i-th and i-th value
             */
            T res=Rselect(data,0,data.size()-1,i_th);
            cout<<i_th<<' '<<res<<endl;
        }catch(EmptyArray){
            cerr<<"Invalid action on an empty array!\n";
        }
    }


    // Q4:
    // clear the input buffer, no need to change.
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "--------------------------------- "<< endl;
    cout << " Q4: Test Dselect " << endl;
    cout << "--------------------------------- "<< endl;

    cout << "How many times you want to test Dselect?"<<endl;
    cin >> round;
    //input 0 to skip this part
    for(int i = 0; i< round; ++i) {
        // clear the input buffer, no need to change.
        try {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Input values: " << endl;
            vector<T> data;
            data.clear();
            while (cin >> x) {
                /*
                 *to do : store the inputs
                 */
                data.push_back(x);
            }
            // to do :
            int n=data.size();
            if(n==0)
                throw EmptyArray();
            i_th = rand() % (n) + 1; // n is the size of current array

            cout << "select i-th smallest element" << endl;
            /*
             *to do : deterministic selection
             *        print i-th and i-th value
             */
            T res=Dselect(data,i_th);
            cout<<i_th<<' '<<res<<endl;
        }catch(EmptyArray){
            cerr<<"Invalid action on an empty array!\n";
        }
    }
    return 0;
}