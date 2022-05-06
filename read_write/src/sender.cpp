#include "read_write.h"


int
main(void) {
    auto ctx = read_write::shm_read_write();

    std::string line;
    while(true) {
        std::getline(std::cin, line);
        ctx.write_from_string(line);

        if (read_write::shutdown_keyword == line)
            return EXIT_SUCCESS;
    }

    return EXIT_SUCCESS;
}
