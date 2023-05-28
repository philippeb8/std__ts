#include "ts.h"

int main()
{
    std::ts::list<int> l;
    
    l.emplace_back(0);
    l.emplace_back(1);
    l.emplace_back(2);
    
    return 0;
}
