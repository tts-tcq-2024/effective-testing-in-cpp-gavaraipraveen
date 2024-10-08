#include <iostream>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms < 42) {
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

int main() {
    assert(size(37) == 'S');
    assert(size(40) == 'M');
    assert(size(43) == 'L');

    // New tests to catch the bug
    assert(size(-1) == 'S');
    assert(size(38) == 'S');  // This should fail because 38 is not handled correctly
    assert(size(42) == 'M');  // This should fail because 42 is not handled correctly
    assert(size(0) == 'S'); 
    assert(size(1000) == 'L'); 
    
    std::cout << "All is well (maybe!)\n";
    return 0;
}
