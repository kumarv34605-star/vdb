#include <cassert>
#include <cstddef>
#include <iostream>

#include "storage/page.h"

int main() {
    vdb::Page page;

    // Test 1: page has the expected size
    assert(page.size() == 4096);

    // Test 2: first byte can be written and read
    page.data()[0] = std::byte{42};
    assert(std::to_integer<int>(page.data()[0]) == 42);

    // Test 3: last byte can be written and read
    page.data()[4095] = std::byte{99};
    assert(std::to_integer<int>(page.data()[4095]) == 99);

    std::cout << "All Page tests passed.\n";

    return 0;
}
