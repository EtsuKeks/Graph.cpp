#ifndef _GRAPH_H_
#define _GRAPH_H_

using namespace std;

template <class T>
class graph
{
public:
    enum GRAPH_ERR {
        EMALLOC,
        EABSENCE,
        EINVARG
    };

    graph();
    graph(int size);
    graph(const graph &g);
    ~graph();
    T Pop_Edge(int i, int j);
    void Push_Edge(T val, int i, int j);
    graph& operator =(const graph &g);
    pair<int, T> *arr() const { return g_arr; };
    int size() const { return g_size; };

    friend ostream &operator <<(ostream &output, const graph<T> &g) {
        output << "Graph: size " << g.size() << endl;
        output << "data: " << (void*)g.arr() << endl;
        for (int i = 1; i <= g.size(); i++) {
            for (int j = 1; j <= g.size(); j++) {
                int number;
                if (i < j) {
                    number = (j - 1) * (j - 1) + i - 1;
                } else if (j < i) {
                    number = i * (i - 1) + j - 1;
                } else {
                    number = i * i - 1;
                }
                pair<int, T> temp = g.arr()[number];
                if (temp.first == 1) {
                    output << setw(10) << temp.second;
                } else {
                    output << setw(10) <<  "---";
                }
            }
            output << endl;
        }
        output << endl;
        return output;
    };

private:
    pair<int, T> *g_arr;
    int g_size;
};

#endif  // _GRAPH_H_
