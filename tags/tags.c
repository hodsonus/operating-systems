#include "tags.h"
#include <unistd.h>
#include <sys/syscall.h>

#define __NR_get_tag 335
#define __NR_set_tag 336

int set_tag(int pid, int new_tag) {
    return syscall(__NR_set_tag, pid, new_tag);
}

int get_tag(int pid) {
    return syscall(__NR_get_tag, pid);
}
