// bench.cpp
#include <chrono>
#include <iomanip>
#include <iostream>
#include "textEdit.h"
using namespace std;
using Clock = chrono::steady_clock;

template <class F>
double timeMs(F f) {
    auto s = Clock::now();
    f();
    return chrono::duration<double, milli>(Clock::now() - s).count();
}

int main() {
    cout << fixed << setprecision(2);
    cout << "n\tinsert\tundo\tredo   (ms)\n";
    
    for (int n : {1000, 10000, 100000, 1000000, 2000000}) {
        Text t;
        string big(200, 'x');
		double ins = timeMs([&] { for (int i = 0; i < n; i++) t.insertText(big, i * 200); });
        double und = timeMs([&] { for (int i = 0; i < n; i++) t.undo(); });
        double red = timeMs([&] { for (int i = 0; i < n; i++) t.redo(); });
        cout << n << "\t" << ins << "\t" << und << "\t" << red << endl;
    }
}	