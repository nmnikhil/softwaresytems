#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_USERNAME_LENGTH 100
#define MAX_PASSWORD_LENGTH 100

void getUserInput(char *username, char *password);

int main() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

        printf("Enter username: ");
    fgets(username, MAX_USERNAME_LENGTH, stdin);
    username[strlen(username) - 1] = '\0'; // Remove newline character

    printf("Enter password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    password[strlen(password) - 1] = '\0'; // Remove newline character

    // Open the "account.txt" file for reading
    int fd = open("account.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    int authenticated = 0;
    char line[MAX_USERNAME_LENGTH + MAX_PASSWORD_LENGTH + 2]; // +2 for ":" and newline

    while (1) {
        ssize_t bytesRead = read(fd, line, sizeof(line));
        if (bytesRead <= 0) {
            break; // End of file or error, exit the loop
        }

        line[bytesRead] = '\0'; // Null-terminate the read data

        char *storedUsername = strtok(line, ":");
        char *storedPassword = strtok(NULL, "\n");

        if (storedUsername != NULL && storedPassword != NULL) {
            if (strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0) {
                authenticated = 1;
                break; // Authentication successful, exit the loop
            }
        }

        // Use lseek to move to the beginning of the next line
        lseek(fd, -bytesRead + 1, SEEK_CUR);
    }

    close(fd);

    if (authenticated) {
        printf("Authentication successful.\n");
    } else {
        printf("Authentication failed.\n");
    }

    return 0;
}
 



