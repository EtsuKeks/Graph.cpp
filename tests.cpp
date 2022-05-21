#include "graph.cpp"
#include <iostream>

using namespace std;

void check(graph<int> g) {
	cout << g;
}

void check(graph<graph<int>> g) {
	cout << g;
}

int main() {
    graph<int> *g1 = NULL;
	graph<int> *g2 = NULL;
	
	try {
		g1 = new graph<int>(3);
	} catch (...) {
		cout << "Test_1\t->\tFAILED" << endl;
	}
	cout << "Test_1\t->\tPASSED" << endl;
	
	try {
		g2 = new graph<int>();
	} catch (...) {
		cout << "Test_2\t->\tFAILED" << endl;
	}
	cout << "Test_2\t->\tPASSED" << endl;

	try {
		g1->Pop_Edge(1, 1);
	} catch (const graph<int>::GRAPH_ERR &ex) {
		if (ex == graph<int>::EABSENCE)
			cout << "Test_3\t->\tPASSED" << endl;
		else
			cout << "Test_3\t->\tFAILED" << endl;
	} catch (...) {
		cout << "Test_3\t->\tFAILED" << endl;
	}

	try {
		g1->Push_Edge(1, 1, 1);
	} catch (...) {
		cout << "Test_4\t->\tFAILED" << endl;
	}
	cout << "Test_4\t->\tPASSED" << endl;

	try {
		g1->Push_Edge(2, 4, 4);
	} catch (...) {
		cout << "Test_5\t->\tFAILED" << endl;
	}
	cout << "Test_5\t->\tPASSED" << endl;

	try {
		*g2 = *g1;
	} catch (...) {
		cout << "Test_6\t->\tFAILED" << endl;
	}
	cout << "Test_6\t->\tPASSED" << endl;

	check(*g1);
	check(*g2);

	try {
		if (g2->Pop_Edge(1, 1) != 1)
			cout << "Test_7\t->\tFAILED" << endl;
	} catch (...) {
		cout << "Test_7\t->\tFAILED" << endl;
	}
	cout << "Test_7\t->\tPASSED" << endl;

	try {
		if (g2->Pop_Edge(4, 4) != 2)
			cout << "Test_8\t->\tFAILED" << endl;
	} catch (...) {
		cout << "Test_8\t->\tFAILED" << endl;
	}
	cout << "Test_8\t->\tPASSED" << endl;

	try {
		g2->Pop_Edge(1, 2);
	} catch (const graph<int>::GRAPH_ERR &ex) {
                if (ex == graph<int>::EABSENCE)
			cout << "Test_9\t->\tPASSED" << endl;
		else
			cout << "Test_9\t->\tFAILED" << endl;
	} catch (...) {
		cout << "Test_9\t->\tFAILED" << endl;
	}

	graph<graph<int>> *g3 = NULL;

	try {
		g3 = new graph<graph<int>>(2);
	} catch (...) {
		cout << "Test_10\t->\tFAILED" << endl;
	}
	cout << "Test_10\t->\tPASSED" << endl;

	try {
		g3->Push_Edge(*g2, 1, 1);
	} catch (...) {
		cout << "Test_11\t->\tFAILED" << endl;
	}
	cout << "Test_11\t->\tPASSED" << endl;

	try {
		g3->Push_Edge(*g1, 2, 2);
	} catch (...) {
		cout << "Test_12\t->\tFAILED" << endl;
	}
	cout << "Test_12\t->\tPASSED" << endl;

	check(*g3);

	graph<int> tmp;
	try {
		tmp = g3->Pop_Edge(1, 1);
	} catch (...) {
		cout << "Test_13\t->\tFAILED" << endl;
	}
	cout << "Test_13\t->\tPASSED" << endl;

	int val = 0;
	try {
		val = tmp.Pop_Edge(1, 1);
	} catch (...) {
		cout << "Test_14\t->\tFAILED" << endl;
	}
	if (val == 1)
		cout << "Test_14\t->\tPASSED" << endl;
	else
		cout << "Test_14\t->\tFAILED" << endl;
	
	try {
        g1->Pop_Edge(-1, 1);
    } catch (const graph<int>::GRAPH_ERR &ex) {
		if (ex == graph<int>::EINVARG) {
        	cout << "Test_15\t->\tPASSED" << endl;
		} else {
			cout << "Test_15\t->\tFAILED" << endl;
		}
    }

	try {
        g1->Pop_Edge(1, -1);
    } catch (const graph<int>::GRAPH_ERR &ex) {
        if (ex == graph<int>::EINVARG) {
            cout << "Test_16\t->\tPASSED" << endl;
        } else {
            cout << "Test_16\t->\tFAILED" << endl;
        }
    }

	try {
        g1->Pop_Edge(2, 1);
    } catch (const graph<int>::GRAPH_ERR &ex) {
        if (ex == graph<int>::EABSENCE) {
            cout << "Test_17\t->\tPASSED" << endl;
        } else {
            cout << "Test_17\t->\tFAILED" << endl;
        }
    }

	try {
        g1->Pop_Edge(-1, 1);
    } catch (const graph<int>::GRAPH_ERR &ex) {
        if (ex == graph<int>::EINVARG) {
            cout << "Test_18\t->\tPASSED" << endl;
        } else {
            cout << "Test_18\t->\tFAILED" << endl;
        }
    }

	try {
        g1->Push_Edge(-1, 1, -1);
    } catch (const graph<int>::GRAPH_ERR &ex) {
        if (ex == graph<int>::EINVARG) {
            cout << "Test_19\t->\tPASSED" << endl;
        } else {
            cout << "Test_19\t->\tFAILED" << endl;
        }
    }

	try {
        g1->Push_Edge(-1, -1, 1);
    } catch (const graph<int>::GRAPH_ERR &ex) {
        if (ex == graph<int>::EINVARG) {
            cout << "Test_20\t->\tPASSED" << endl;
        } else {
            cout << "Test_20\t->\tFAILED" << endl;
        }
    }

	try {
        g1->Push_Edge(-1, 1, 2);
    } catch (...) {
        cout << "Test_21\t->\tFAILED" << endl;
    }
	cout << "Test_21\t->\tPASSED" << endl;

	try {
        g1->Push_Edge(-1, 2, 1);
    } catch (...) {
        cout << "Test_22\t->\tFAILED" << endl;
    }
	cout << "Test_22\t->\tPASSED" << endl;

	try {
        g1->Push_Edge(-1, -1, 2);
    } catch (const graph<int>::GRAPH_ERR &ex) {
        if (ex == graph<int>::EINVARG) {
            cout << "Test_23\t->\tPASSED" << endl;
        } else {
            cout << "Test_23\t->\tFAILED" << endl;
        }
    }

	try {
        g1->Push_Edge(-1, 1, -1);
    } catch (const graph<int>::GRAPH_ERR &ex) {
        if (ex == graph<int>::EINVARG) {
            cout << "Test_24\t->\tPASSED" << endl;
        } else {
            cout << "Test_24\t->\tFAILED" << endl;
        }
    }

	

	delete g1;
	delete g2;
	delete g3;
	return 0;
}

