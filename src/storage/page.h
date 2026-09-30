#pragma once

#include <array>
#include <cstddef>

namespace vdb {

constexpr std::size_t PAGE_SIZE = 4096;

class Page {
public:
    Page();

    std::byte* data();
    const std::byte* data() const;

    std::size_t size() const;

private:
    std::array<std::byte, PAGE_SIZE> data_;
};

}  // namespace vdb
