
#include "disk_manager.h"

namespace vdb {

DiskManager::DiskManager(const std::string& file_name)
    : file_(file_name, std::ios::in | std::ios::out | std::ios::binary) {

    if (!file_.is_open()) {
        std::ofstream create_file(file_name, std::ios::binary);
        create_file.close();

        file_.open(
            file_name,
            std::ios::in | std::ios::out | std::ios::binary
        );
    }
}

void DiskManager::write_page(std::size_t page_id, const Page& page) {
    const std::size_t offset = page_id * PAGE_SIZE;

    file_.seekp(offset);
    file_.write(
        reinterpret_cast<const char*>(page.data()),
        PAGE_SIZE
    );

    file_.flush();
}

void DiskManager::read_page(std::size_t page_id, Page& page) {
    const std::size_t offset = page_id * PAGE_SIZE;

    file_.seekg(offset);
    file_.read(
        reinterpret_cast<char*>(page.data()),
        PAGE_SIZE
    );
}

}  // namespace vdb
