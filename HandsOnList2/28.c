#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key;
    int msqid;
    struct msqid_ds msq_info;

    // Create or get the message queue using a unique key
    key = ftok(".", 'a');
    msqid = msgget(key, 0666 | IPC_CREAT);
    if (msqid == -1) {
        perror("msgget");
        exit(1);
    }

    // Retrieve the current message queue permissions
    if (msgctl(msqid, IPC_STAT, &msq_info) == -1) {
        perror("msgctl IPC_STAT");
        exit(1);
    }

    printf("Message queue permissions: before updating\n");
    printf("Read permissions (owner/group/others): %o/%o/%o\n",
           (msq_info.msg_perm.mode >> 6) & 7,
           (msq_info.msg_perm.mode >> 3) & 7,
           msq_info.msg_perm.mode & 7);

    // Change the permissions (e.g., set read and write permissions for the owner)
    msq_info.msg_perm.mode = 0600; // New permission mode (owner read and write)

    // Set the updated permissions using IPC_SET
    if (msgctl(msqid, IPC_SET, &msq_info) == -1) {
        perror("msgctl IPC_SET");
        exit(1);
    }

    // Display the message queue permissions after updating
    printf("Message queue permissions: after updating\n");
    printf("Read permissions (owner/group/others): %o/%o/%o\n",
           (msq_info.msg_perm.mode >> 6) & 7,
           (msq_info.msg_perm.mode >> 3) & 7,
           msq_info.msg_perm.mode & 7);

    return 0;
}

