#include <fcntl.h>
#include <unistd.h>
#include <xf86drm.h>

#include <iostream>

int main() {
    const char* path = "/dev/dri/renderD128";

    int fd = open(path, O_RDWR | O_CLOEXEC);

    if (fd < 0) {
        perror("Failed to open DRM render node");
        return 1;
    }

    drmVersionPtr version = drmGetVersion(fd);

    if (!version) {
        std::cerr << "Failed to query DRM driver version\n";
        close(fd);
        return 1;
    }

    std::cout << "Driver: " << version->name << '\n';

    std::cout << "Version: " << version->version_major << '.' << version->version_minor << '.'
              << version->version_patchlevel << '\n';

    drmFreeVersion(version);
    close(fd);

    return 0;
}
