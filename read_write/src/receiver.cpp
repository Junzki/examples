
#include "read_write.h"

bool alive = true;



int
main(void) {
    auto ctx = read_write::shm_read_write();

    while (alive) {

        auto data = ctx.read_to_string();
        if (data.empty()) {
            sleep(1);
            continue;
        }

        if (read_write::shutdown_keyword == data) {
            std::cout << "Shutdown keyword received, exit" << std::endl;
            alive = false;
            return EXIT_SUCCESS;
        }

        std::cout << data << std::endl;
    }

    return EXIT_SUCCESS;
}
