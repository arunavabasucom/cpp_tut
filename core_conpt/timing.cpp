#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

int main(){
    auto start = chrono::high_resolution_clock::now();
    this_thread::sleep_for(1s);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> duration = end - start;
    cout << duration.count() << "s" << endl;
    return 0;
}