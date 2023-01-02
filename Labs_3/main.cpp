
#include "processor.h"

using namespace std;

int main() {
    Processor *processor = new Processor();

    processor->show();

    string ans;
    cout << "\n\n\n\n\n" << endl;
    cout << "\n\tMake a tick?\n\ty/n: ";
    cin >> ans;

    while (ans == "y") {
        bool tick = processor->tickTack();

        if (!tick) { break; }

        cout << "\n\n\n\n\n" << endl;
        cout << "\n\tMake a tick?\n\ty/n: ";
        cin >> ans;
    }

    cout << "\n\tPress Enter to exit...";

    delete processor;

    return 0;
}

