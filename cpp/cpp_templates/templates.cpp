// TODO: finding a max value in an array
// Returning a const reference, saving memory and avoiding being modified
// using function template
#include <iostream>
#include <vector>

using namespace std;

template <typename Comparable>
const Comparable& findMax(const vector<Comparable>& a){
    int maxIndex = 0;
    for(int i = 1; i < a.size(); i++)
        if(a[maxIndex] < a[i]) maxIndex = i;
    
    return a[maxIndex];
}