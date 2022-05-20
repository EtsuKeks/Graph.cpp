#include "graph.cpp"
#include <iostream>

using namespace std;

void check(graph<int> g) {
	cout << g;
}

void chech(graph<string> g) {
	cout << g;
}

void check(graph<graph<int>> g) {
	cout << g;
}

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

