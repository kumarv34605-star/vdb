#include <cassert>
#include <cstddef>
#include <cstdio>
#include <iostream>

#include "storage/disk_manager.h"

int main() {
    const char* database_file = "test_vdb.db";

    // Create a disk manager for our test database.
    vdb::DiskManager disk(database_file);

    // Create a page and put known data into it.
    vdb::Page page;

    page.data()[0] = std::byte{42};
    page.data()[100] = std::byte{77};
    page.data()[4095] = std::byte{99};

    // Write the page to disk.
    disk.write_page(0, page);

    // Create a completely separate page.
    vdb::Page loaded_page;

    // Read page 0 back from disk.
    disk.read_page(0, loaded_page);

    // Verify that the data survived the round trip.
    assert(std::to_integer<int>(loaded_page.data()[0]) == 42);
    assert(std::to_integer<int>(loaded_page.data()[100]) == 77);
    assert(std::to_integer<int>(loaded_page.data()[4095]) == 99);

    std::cout << "DiskManager persistence test passed.\n";

    // Remove the temporary test database.
    std::remove(database_file);

    return 0;
}
