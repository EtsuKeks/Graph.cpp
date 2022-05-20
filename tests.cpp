#include <cstdlib>
#include <unistd.h>
#include <tuple>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <typeinfo>
#include <cmath>
#include <cstring>
#include <iostream>
#include "graph.cpp"

using namespace std;

int main() {
    graph<string> temp(3);
    temp.Push_Edge("HUI", 1, 1);
    temp.Push_Edge("DA", 2, 2);
    temp.Push_Edge("PIZDA", 3, 2);
    temp.Push_Edge("NET", 3, 3);
    cout << temp.Pop_Edge(2, 2) << endl;

    cout << temp;
    return 0;
}

