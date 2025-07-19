/*
Mainly we use 2 type of file types - 
1. .cpp 2..h or .hpp
precompiled code called a librarry -> .dll and .lib
FOLDER STRUCTURE ->
/include - contains the header files
/bin - .dll files (DYNAMIC LIB) -> after compilation the source code compiled program needed to access the
.dll files(SIZE WOULD BE SMALLER)
/lib - folder contains the .lib files(STATIC LIB) -> it recompile with the source code makes that code that needs to run the whole program(SIZE IS GOING TO BE LARGER)
*/
/*
COMPILATION STEP
>>FOR STATIC - g++ main.cpp -L. -lmylib -static -o app
>> FOR DYNAMIC - g++ main.cpp -L. -lmylib -o app
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}