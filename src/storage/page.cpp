#include "page.h"

namespace vdb {

Page::Page() : data_{} {}

std::byte* Page::data() {
    return data_.data();
}

const std::byte* Page::data() const {
    return data_.data();
}

std::size_t Page::size() const {
    return data_.size();
}

}  // namespace vdb
