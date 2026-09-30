#pragma once

#include <cstddef>
#include <fstream>
#include <string>

#include "page.h"

namespace vdb {

class DiskManager {
public:
    explicit DiskManager(const std::string& file_name);

    void write_page(std::size_t page_id, const Page& page);

    void read_page(std::size_t page_id, Page& page);

private:
    std::fstream file_;
};

}  // namespace vdb
