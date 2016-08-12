#include <iostream>
#include "cache.hpp"

using namespace std;
using namespace zhuyuesut;

int main() {
    
    cout << "Result is ";
    make_cache(42) >> [](auto i){return i*2;} >> [](auto i){return i/2;} >> cout << '.' << endl;
    
    cout << "What's is you name? ";
    Cache<string>() << cin >> [](auto i){return "Hello, " + i + "!";} >> cout << endl;
    
    return 0;
}
