#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>

using namespace std;


// vector<vector<char>> friends; // global 2d array declaration

int main(){
    // friends.resize(m, vector<char>(3)); // m is a variable. allocating space for global 2d array use


    // vector<vector<int>> vec( n , vector<int> (m, 0));  // declaring 2d vector
    vector<int> v = {4,2,6,2,6,3,1};

    sort(v.begin(),v.end()); // sort 1d vector in ascending order

    for(int j=0;j<v.size();j++){ // print sorted 1d vector
        cout<<v[j]<<" ";
    }
    cout<< "is the 1D array sorted in ascending order."<<endl;

    sort(v.begin(),v.end(), [](int a, int b) {return b<a;} ); // sort 1d vector in descending order. NOTE LAMBDA RETURNS TRUE/FALSE NOT INT
    // for the < or >, note that the return will return true if a goes before b. so if a is bigger than b here, a will go first in array indices

    for(int j=0;j<v.size();j++){ // print backwards sorted 1d vector
        cout<<v[j]<<" ";
    }
    cout<< "is the 1D array sorted in descending order."<<endl;

    vector<int> order = {0,1,2,3,4,5,6};
    // sort order by the way the values of v are arranged
    sort(order.begin(),order.end(),[&v](int a, int b) {return v[a]<v[b];});
    // square brackets contain captures, which aren't parameters but are used in the sorting of the array. captures are passed by reference
    // note if you are sorting structs, instead of int a and int b in round brackets you'd have mystruct &a and mystruct &b
    // for the < or >, note that the return will return true if a goes before b. 

    for(int j=0;j<order.size();j++){ // print order sorted by v's values
        cout<<order[j]<<" ";
    }
    cout<< "is the array order sorted by the way the values in v are arranged.\n"<<endl;

    vector<vector<int>> vv = {{4,2,6,2,6,3,1},{3,6,3,2,7,1,0},{0,1,2,3,4,5,6}};

    sort(vv.begin(),vv.end(),[](vector<int> &rowa, vector<int> rowb){return rowa[0]<rowb[0];}); // sort in ascending order by 1st col

    for(int j=0;j<vv.size();j++){ // print sorted 2d vector by way of 1st col
        for(int k=0;k<vv[j].size();k++){
        cout<<vv[j][k]<<" ";
        }
        cout<<endl;
    }
    cout<< "is the 1sorted 2d vector by way of 1st col."<<endl;
}