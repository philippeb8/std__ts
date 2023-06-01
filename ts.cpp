/**
    Outputs:
    
    1) locked = true
    2) locked = false
*/

#include "ts.h"

#include <iostream>

using namespace std;


int main()
{
    ts::list<int> l;
    
    l.emplace_back(0);
    l.emplace_back(1);
    l.emplace_back(2);
    
    if (auto expression = l.empty(); ! expression)
    {
        cout << "1) locked = " << boolalpha << l.mutex().locked() << endl;
    }
    
    cout << "2) locked = " << boolalpha << l.mutex().locked() << endl;

    return 0;
}
