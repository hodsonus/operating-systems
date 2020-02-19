#include <stdlib.h>
#include "tags.h"

#define __NR_get_tag 335
#define __NR_set_tag 336

/* Returns an int array of 2-4 values that can be used to make the set-tag
system call. */
int* retrieve_set_tag_params(int pid, int new_tag) {

    int* params = malloc(sizeof(int) * 4);

    params[0] = __NR_set_tag;
    params[1] = 2;
    params[2] = pid;
    params[2] = new_tag;

    return params;
}

/* Returns an int array of 2-4 values that can be used to make the get-tag 
system call. */
int* retrieve_get_tag_params(int pid) {
    int* params = malloc(sizeof(int) * 3);

    params[0] = __NR_get_tag;
    params[1] = 1;
    params[2] = pid;

    return params;
}

/* After making the system call, we will pass the syscall return value to this
function call. It should return set_tag’s interpretation of the system call
completing with return value ret_value (i.e., what the library call should
return to the user program). */
int interpret_set_tag_result(int ret_value) {

    if (ret_value >= 0) {
        printf("Tag was successfully set to %d.", ret_value);
    }
    else {
        printf("Tag was unsuccessfully set, system call returned %d.", ret_value);
    }

    return ret_value;
}

/* After making the system call, we will pass the syscall return value to this
function call. It should return get_tag’s interpretation of the system call
completing with return value ret_value (i.e., what the library call should
return to the user program). */
int interpret_get_tag_result(int ret_value) {

    if (ret_value >= 0) {
        printf("Tag was successfully retrieved as %d.", ret_value);
    }
    else {
        printf("Tag was unsuccessfully retrieved, system call returned %d.", ret_value);
    }

    return ret_value;
}