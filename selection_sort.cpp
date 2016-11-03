#include <chrono>
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <sstream>
using namespace std;
#define MAX_LINE_LENGTH 256

vector<string> ip_selection_sort(vector<string> L) 
{
    int n = L.size();

    for (int k = 0; k < n - 1; ++k) 
	{
        int j = k;
        for (int i = (k + 1); i < n; ++i) 
		{
            if (strncmp(L[i].c_str(), L[j].c_str(),MAX_LINE_LENGTH) < 0) 
			{
                j = i;
            }
        }
        swap(L[k], L[j]);
    }
    return L;
}

void run(int n, string filename, bool preassigned = false) 
{
    ifstream f(filename);
    vector<string> L;
    string line;
    int i = 0;

    while (getline(f, line)) 
	{
        if (i == n) 
			break;

        L.push_back(line);
        ++i;
    }

    f.close();

    if ( ! preassigned)
	{
		for (int i = 0; i < 10; ++i)
		{
        	cout << (i + 1) << "  " << L[i] << endl;
		}
	}

    if ( ! preassigned)
        cout << "\nIn-place selection sort..." << endl;

    auto start = chrono::high_resolution_clock::now();

    vector<string> sorted = ip_selection_sort(L);

    auto end = chrono::high_resolution_clock::now();

    int microseconds = chrono::duration_cast<chrono::microseconds>(end - start).count();
    double seconds = microseconds / 1E6;

    if ( ! preassigned) 
	{
        cout << "Sorted:" << endl;
		for (int i = 0; i < 10; ++i)
		{
        	cout << (i + 1) << "  " << sorted[i] << endl;
		}
    }

    if ( ! preassigned) 
	{
        cout << "Elapsed time: " << seconds << " seconds" << endl;
    } 
	else 
	{
        cout << seconds << endl;
    }
}

int main(int argc, char** argv) 
{
    string filename = "beowulf.txt";

    try 
	{
        bool preassigned = false;
        int n;

        if (argc > 1) 
		{
            preassigned = true;
            n = atoi(argv[1]);
        } 
		else 
		{
            cout << "Enter value for n: ";
            cin >> n;
        }

        if (preassigned) 
		{
            for (int i = 1; i <= n; ++i) 
			{
                run(i, filename, preassigned);
            }
        } 
		else 
		{
            run(n, filename);
        }
    } 

	catch (ifstream::failure e) 
	{
        cerr << "Error opening file";
        exit(EXIT_FAILURE);
    }

    return 0;
}
