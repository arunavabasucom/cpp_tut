#include<iostream>
#ifndef IO_SETUP_H
#define IO_SETUP_H

#ifndef ONLINE_JUDGE
struct IOInit {
    IOInit() {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
};
static IOInit io_init;
#endif

#endif
