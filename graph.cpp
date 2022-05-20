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
        return NULL;
    }
    if (j < 1 || j > g_size) {
        cerr << "Invalid argument: " << j << endl;
        throw EINVARG;
        return NULL;
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
        return NULL;
    }
    return val;
}

template <class T>
void graph<T>::Push_Edge(T val, int i, int j)
{

    if (i <= 0) {
        cerr << "Invalid argument: " << i << endl;
        throw EINVARG;
        return;
    }

    if (j <= 0) {
        cerr << "Invalid argument: " << j << endl;
        throw EINVARG;
        return;
    }

    if (g_size < i || g_size < j) {
        int n = max(i, j);
        g_arr = (pair<int, T> *) realloc(g_arr,n * n * sizeof(pair<int, T>));
        if (g_arr == NULL) {
            cerr << "Not enough memory" << endl;
            throw EMALLOC;
            return;
        }

        for (int k = g_size * g_size; k < n * n; ++k) {
            pair<int, T> temp;
            temp.first = 0;
            g_arr[k] = temp;
        }
        g_size = n;
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
