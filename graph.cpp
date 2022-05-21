#include <cstdlib>
#include <tuple>
#include <iomanip>
#include <algorithm>
#include <iostream>
#include "graph.h"

using namespace std;

template <class T>
graph<T>::graph()
{
    g_arr = new pair<int, T> [0];
    g_size = 0;
}

template <class T>
graph<T>::graph(int size)
{
    g_arr = new pair<int, T> [size * size];
    for (int i = 0; i < size * size; i++) {
        pair<int, T> temp;
        temp.first = 0;
        g_arr[i] = temp;
    }
    g_size = size;
}

template <class T>
graph<T>::graph(const graph &g)
{
    g_arr = new pair<int, T> [g.size() * g.size()];
    g_size = g.size();
    for (int i = 0; i < g_size * g_size; i++) {
        g_arr[i] = g.arr()[i];
    }
}

template <class T>
graph<T>::~graph()
{
    delete [] g_arr;
    g_arr = NULL;
}

template <class T>
T graph<T>::Pop_Edge(int i, int j)
{
    if (i < 1 || i > g_size) {
        cerr << "Invalid argument: " << i << endl;
        throw EINVARG;
    }
    if (j < 1 || j > g_size) {
        cerr << "Invalid argument: " << j << endl;
        throw EINVARG;
    }

    int number;
    if (i < j) {
        number = (j - 1) * (j - 1) + i - 1;
    } else if (j < i) {
        number = i * (i - 1) + j - 1;
    } else {
        number = i * i - 1;
    }

    pair<int, T> temp = g_arr[number];
    T val;
    if (temp.first == 1) {
        val = temp.second;
    } else {
        cerr << "Invalid argument: there's no such edge as (" << i << ", " << j << ")" << endl;
        throw EABSENCE;
    }
    return val;
}

template <class T>
void graph<T>::Push_Edge(T val, int i, int j)
{
    if (i <= 0) {
        cerr << "Invalid argument: " << i << endl;
        throw EINVARG;
    }

    if (j <= 0) {
        cerr << "Invalid argument: " << j << endl;
        throw EINVARG;
    }

	if (g_size < i || g_size < j) {
            int n = max(i, j);
            pair<int, T> *temporary;
            temporary = new pair<int, T> [n * n];
            for (int k = 0; k < g_size * g_size; ++k) {
                temporary[k] = g_arr[k];
            }
            for (int k = g_size * g_size; k < n * n; ++k) {
                pair<int, T> temp;
                temp.first = 0;
                temporary[k] = temp;
            }
            g_size = n;
            delete [] g_arr;
            g_arr = temporary;
    }

    int number;
    if (i < j) {
        number = (j - 1) * (j - 1) + i - 1;
    } else if (j < i) {
        number = i * (i - 1) + j - 1;
    } else {
        number = i * i - 1;
    }
    pair<int, T> temp;
    temp.first = 1;
    temp.second = val;
    g_arr[number] = temp;
}

template <class T>
graph<T> &graph<T>::operator =(const graph<T> &g)
{
    delete [] g_arr;
    g_arr = new pair<int, T> [g.size() * g.size()];
    g_size = g.size();
    for (int i = 0; i < g_size * g_size; i++)
        g_arr[i] = g.arr()[i];
    return *this;
}
