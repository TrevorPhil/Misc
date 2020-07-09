#include <iostream>
#include <vector>

using namespace std;

// TODO: finding a max value in an array
// Returning a const reference, saving memory and avoiding being modified
// using function template
template <typename Comparable>
const Comparable& findMax(const vector<Comparable>& a){
    int maxIndex = 0;
    for(int i = 1; i < a.size(); i++)
        if(a[maxIndex] < a[i]) maxIndex = i;
    
    return a[maxIndex];
}


// TODO: writing a class that mimics a memorycell
// data member: stored value
// function member: read / write data members
// Normally we don't want our constructor to convert parameters implicitly
// We want a default value for our data member
template <typename Object>
class MemoryCell{
public:
    explicit MemoryCell(const Object& initialValue = Object {}):
        storedValue(initialValue){}
    // accessor
    const& Object write() const{
        return storedValue;
    }
    void read(const Object& readValue){
        storedValue = readValue;
    }
private:
    Object storedValue;
};

// function object
// C++ has some fancy syntax to convert function object's name
// operator() can be translated into a function with template name
// find a max with function object
// also C++ can use decltype in this operation(will be covered later)
template <typename Object, typename Comparable>
const Object& findMax(const vector<Object>& arr, Comparable isLessThan){
    int maxIndex = 0;
    for(int i = 1; i < arr.size(); i++){
        if(isLessThan(arr[maxIndex], arr[i])) maxIndex = i;
    }
    return arr[maxIndex];
}

// strcasecmp returns caseInsentive compare lhs < rhs -> < 0
// c_str() transforms a string into a c-format string
// with '/0' as the end
class CaseInsensitiveCompare{
public:
    bool operator()(const string& lhs, const string& rhs) const{
        return strcasecmp(lhs.c_str(), rhs.c_str()) < 0;
    }
};