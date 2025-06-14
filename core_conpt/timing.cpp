#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono;

struct Timer {
    time_point<system_clock> start, end;
    duration<float> dur;
    Timer() {
        start = high_resolution_clock::now();
    }
    ~Timer() {
        end = high_resolution_clock::now();
        dur = end - start;
        cout << (dur.count() * 1000.0F) <<"ms";

    }
};
void fn() {
    Timer timer;
    for (int i = 0; i < 100;++i) {
        // cout << "hello" << endl; // slow
        cout << "hello\n"; //fast
    }
}
int main() {
    /*
    auto start = chrono::high_resolution_clock::now();
    this_thread::sleep_for(1s);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> duration = end - start;
    cout << duration.count() << "s" << endl;
    */
    fn();
    return 0;
}