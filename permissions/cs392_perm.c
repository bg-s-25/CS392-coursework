/**
 * CS 392: User permissions practice
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define NUID 1000
#define NGID 1000

int main(int argc, char ** argv) {
    uid_t cur_uid = getuid();
    printf("Current user ID: %d\n", cur_uid);

    // check if current uid is root, drop root privileges
    if (cur_uid == 0) {
        setuid(NUID);
        setgid(NGID);
        printf("New user ID: %d\n", getuid());
    }

    return 0;
}
