/*#ifndef ADMIN_FUNCTIONS
#define ADMIN_FUNCTIONS
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/file.h>
#include <sys/socket.h>
#include "structure.h"


int authenticateadmin(int clientSocket)
{
    char username[100];
    char pass[100];

    // Send a prompt for the username
    const char *userPrompt = "\nEnter Username of Admin: ";
    send(clientSocket, userPrompt, strlen(userPrompt), 0);

    // Receive the username from the client
    ssize_t bytesRead = recv(clientSocket, username, sizeof(username), 0);
    if (bytesRead <= 0)
    {
        close(clientSocket);
        return false;
    }
    if (username[bytesRead - 1] == '\n')
    {
        username[bytesRead - 1] = '\0';
    }
    else
    {
        username[bytesRead] = '\0';
    }

    // Send a prompt for the password
    const char *passPrompt = "\nEnter password of the Admin: ";
    send(clientSocket, passPrompt, strlen(passPrompt), 0);

    // Receive the password from the client
    bytesRead = recv(clientSocket, pass, sizeof(pass), 0);
    if (bytesRead <= 0)
    {
        close(clientSocket);
        return false;
    }
    if (pass[bytesRead - 1] == '\n')
    {
        pass[bytesRead - 1] = '\0';
    }
    else
    {
        pass[bytesRead] = '\0';
    }

    // Compare the received username and password with stored credentials
    if (strcmp(username, adminCredentials.username) == 0 &&
        strcmp(pass, adminCredentials.pass) == 0)
    {
        // Authentication successful
        send(clientSocket, "Authentication successful\n", strlen("Authentication successful\n"), 0);
        return true;
    }
    else
    {
        // Authentication failed
        send(clientSocket, "Authentication failed\n", strlen("Authentication failed\n"), 0);
        close(clientSocket);
        return false;
    }
}

int addStudent(int clientSocket){
    struct student stud_info;

    //Client will enter the login Id
    send(clientSocket,"Enter the Login Id of the student you want to add\n",strlen("Enter the Login Id of the student you want to add\n"),0);
    int bytesRead = recv(clientSocket, stud_info.login_id, strlen(stud_info.login_id), 0);
    if(bytesRead <= 0){
        perror("Error whlie receiving Login id");
		return false;
    }
    stud_info.login_id[bytesRead] = '\0';

    //Client will enter the Password
    send(clientSocket,"Enter the Password of the student you want to add\n",strlen("Enter the Password of the student you want to add\n"),0);
    bytesRead = recv(clientSocket, stud_info.password, strlen(stud_info.password), 0);
    if(bytesRead <= 0){
        perror("Error whlie receiving Password");
		return false;
    }
    stud_info.password[bytesRead] = '\0';

    //Client will enter the Dept;
    send(clientSocket,"Enter the Department of the student you want to add\n",strlen("Enter the Department of the student you want to add\n"),0);
    bytesRead = recv(clientSocket, stud_info.dept, strlen(stud_info.dept), 0);
    if(bytesRead <= 0){
        perror("Error whlie receiving Deptartment\n");
		return false;
    }
    stud_info.dept[bytesRead] = '\0';

    //Client will enter the name
    send(clientSocket,"Enter the Name of the student you want to add\n",strlen("Enter the Name of the student you want to add\n"),0);
    bytesRead = recv(clientSocket, stud_info.name, strlen(stud_info.name), 0);
    if(bytesRead <= 0){
        perror("Error whlie receiving Name\n");
		return false;
    }
    stud_info.name[bytesRead] = '\0';

    //Client will enter the age
    send(clientSocket,"Enter the Age of the student you want to add\n",strlen("Enter the Age of the student you want to add\n"),0);
    bytesRead = recv(clientSocket, stud_info.age, strlen(stud_info.age), 0);
    if(bytesRead <= 0){
        perror("Error whlie receiving Age\n");
		return false;
    }
    stud_info.age[bytesRead] = '\0';

    //Client will enter the email
    send(clientSocket,"Enter the Email of the student you want to add\n",strlen("Enter the Email of the student you want to add\n"),0);
    bytesRead = recv(clientSocket, stud_info.email, strlen(stud_info.email), 0);
    if(bytesRead <= 0){
        perror("Error whlie receiving Email\n");
		return false;
    }
    stud_info.email[bytesRead] = '\0';

    //Open the file to enter this data in the database
    int fd = open("student_database.txt", O_WRONLY | O_APPEND|O_CREAT,0666); // Open the file in append mode

    if (fd == -1)
    {
        perror("Error opening the file\n");
        close(fd);
        return 1;
    }

    // Use flock to apply mandatory lock
    if (flock(fd, LOCK_EX) == -1)
    {
        perror("Error applying lock");
        close(fd);
        return 1;
    }

    // Use lseek to move the file pointer to the end of the file
    if (lseek(fd, 0, SEEK_END) == -1)
    {
        perror("Error using lseek");
        flock(fd, LOCK_UN); // Release the lock before closing the file
        close(fd);
        return 1;
    }

    // Write the structure data to the file
    if (write(fd, &stud_info, sizeof(struct student)) == -1)
    {
        perror("Error writing to the file");
        flock(fd, LOCK_UN); // Release the lock before closing the file
        close(fd);
        return 1;
    }

    flock(fd, LOCK_UN); // Release the lock
    close(fd);          // Close the file

    return 0;

}

//return 1 if login successfully else 0
int admin_functionality(int clientSocket) 
{
    if (authenticateadmin(clientSocket))
    {
        
        char readbuff[1000], writebuff[1000]; // A buffer used for reading & writing to the client
        while (1)
        {
            send(clientSocket, "Login Successfully\n", strlen("Login Successfully\n"), 0);
            char adminPrompt[] = "\nAdmin can Do:\n - 1.Add Student\n - 2.Add Faculty\n - 3.Deactivate Student\n - 4. Deactivate Faculty\n - 6. Update Student\n - 7. Update Faculty\n - 8.Exit from this menu\n";

            send(clientSocket, adminPrompt, strlen(adminPrompt), 0);
            //readBytes store no of bytes read from the client by the server
            ssize_t readBytes = recv(clientSocket, readbuff, sizeof(readbuff), 0);
            if (readBytes == -1)
            {
                perror("Error in the choice you provided");
                return false;
            }
            int choice = atoi(readbuff);
            //send(clientSocket,readbuff,sizeof(readbuff),0);

            switch (choice)
            {
            case 1:if(!addStudent(clientSocket))
                    continue;;
                break;
            
            default:
                break;
            }


           
        }
    }
    else{
        return 0;
    }
     
}
