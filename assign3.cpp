#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <cassert>
#include <cstdlib>

using namespace std;
int main() {

/* Comment out (CTRL + K + U) the sections to test each part of the project */


    /* PART 1 - A*/
    // char * commandString[2];
    // string command="cat";
    // string arg="dupMessages.txt"; 
    // commandString[0]=(char*) command.c_str();
    // commandString[1]=(char*) arg.c_str();
    // commandString[2]=NULL;
    // size_t Maxsize=100;
    // int fd[2], nBytes;
    // int fileDP = open("dupMessages.txt", O_WRONLY | O_APPEND);
    // int oldFD = dup(STDOUT_FILENO);
    // int copy_fd = dup2(fileDP, 1);
    // pid_t childPid;
    // char readBuffer[100], currentDir[256];
    // char sharedStr1[] = "Hello from Eric Hovda\n";
    // char sharedStr2[] = "Part of the Computer Science Department\n";
    // char sharedStr3[] = "@ ehovda321@gmail.com\n";

    // childPid = fork();
    // if (childPid == 0) {
    //     string msg1 = "Hello from Eric Hovda\n";
    //     string msg2 = "Part of the Computer Science Department\n";
    //     string msg3 = "@ ehovda321@gmail.com\n";
    //     cout << msg1 <<endl;cout << msg2 <<endl;cout << msg3 <<endl;
       
    // }  else if (childPid<0) {
    //     cout<<"ERROR! No child created\n";
    //     return 1;
    // } else {
    //     wait(0);
    //     close(fileDP);
    //     dup2(oldFD, 1);
    //     if (execvp(commandString[0], commandString) < 0) {
    //         cout<<"Error reading from file\n";
    //     }
    // }






    /* PART 1 - B */
    // if (pipe(fd) < 0) {
    //     exit(1); //Error no pipe created
    // }
    // childPid = fork(); //This trapped in the if statement seems to make the fork process not work at all?
    // if (childPid == 0) {//This is the CHILD process
    //     //Ensure input side of pipe is closed
    //     close(fd[0]);
    //     //Send str thru output side of pipe
    //     write(fd[1],sharedStr1,(strnlen(sharedStr1, Maxsize)));
    //     write(fd[1], sharedStr2,(strnlen(sharedStr2, Maxsize)));
    //     write(fd[1], sharedStr3, (sizeof(sharedStr3))); //We do this at the end else we seem to get some null characters added on...Tis odd
    //     exit(0);
    // }  else if (childPid<0) {
    //     cout<<"ERROR! No child created\n";
    //     return 1;
    // } else { //PARENT process
    //     wait(0);
    //     //Parent process will close up output to be safe
    //     close(fd[1]);
    //     //Read in str from pipe
    //     read(fd[0],readBuffer,sizeof(readBuffer));
    //     cout<<"From Parent: " <<readBuffer<<endl;
    // }




    /* PART 1 - D */
    // char * commandString[3];
    // string command="";
    // string arg=""; 
    // string arg1=""; 
    // string arg2=""; 
    // string history="history.txt"; 
    // pid_t pid;
    // char currentDir[256];
    // cout << "Current Directory:" << getcwd(currentDir, sizeof(currentDir)) << endl;
    // do {
    //     cout<<"Enter a Unix Command\n\n";
    //     getline(cin, command, '\n');
    //     cout<<"Enter some arguements for it (Optional)\n\n";
    //     getline(cin, arg, '\n');
    // } while(command.empty());
    // int fileDP = open("history.txt", O_WRONLY | O_APPEND);
    // int oldFD = dup(STDOUT_FILENO);
    // int copy_fd = dup2(fileDP, 1);
    // cout << command << arg << endl;
    // close(fileDP);
    // dup2(oldFD, 1);
    // commandString[0]=(char*) command.c_str();
    // commandString[1]=(char*) arg.c_str();
    // commandString[2]=NULL;

    // pid = fork();
    // if (pid==0) {
    //     if (execvp(commandString[0], commandString) < 0) {
    //         cout <<"ERROR: Execution failed\n";
    //         exit(1);
    //     } 

    //     cout<< "Im the child process\n";
    // } else if (pid<0) {
    //     cout<<"ERROR! No child created\n";
    //     return 1;
    // } else {
    //     wait(0);
    //     command = "awk";
    //     arg1 = "{print NR, $0}";
    //     arg2 = "history.txt";
    //     commandString[0]=(char*) command.c_str();
    //     commandString[1]=(char*) arg1.c_str();
    //     commandString[2]=(char*) arg2.c_str();
    //     commandString[3]=NULL;

    //     if (execvp(commandString[0], commandString) < 0) {
    //         cout <<"ERROR: Execution failed\n";
    //         exit(1);
    //     } 

    //     cout<<"Im the parent process\n";
    // }
    




    /* PART 2 - A */
    
    char * commandString[3];
    string command="";
    string arg="";
    cout << "Testing Part 2 - 4 - Type './myExe < partD.txt > partD.txt'" << endl;
    getline(cin, command, '\n');

    if(command == "./myExe < partD.txt > partD.txt"){
        int fileDPin = open("partD.txt", O_RDONLY | O_APPEND);
        int oldStdIn = dup(STDIN_FILENO);
        int copy_fdIn = dup2(fileDPin, 0);

        srand(time(0));
        int x = rand() % 100;

        pid_t pid = fork();

        if (fileDPin < 0) {
            cout << "Can not open the file!";
        }  

        if(pid < 0)
        {
            cout << "ERROR creating the child!";
            return 1;
        }

        if(pid == 0)
        {
            cout << "READING..." << endl;
            string newCommand = "cat";
            arg = "partD.txt";
            commandString[0]=(char*) newCommand.c_str();
            commandString[1]=(char*) arg.c_str();
            commandString[2]=NULL;

            cout << "The file currently reads..." << endl;
            if (execvp(commandString[0], commandString) < 0) {
                cout <<"ERROR: Execution failed\n";
                exit(1);
            } 
            
            wait(0);
            close(fileDPin);
            dup2(oldStdIn, 0);
        }

        if(pid > 0){
            if(wait(0) == -1){
                perror("wait");
            }
            else{
                cout << "WRITING..." << endl;
                int fileDPout = open("partD.txt", O_WRONLY | O_APPEND);
                int oldStdOut = dup(STDOUT_FILENO);
                int copy_fdOut = dup2(fileDPout, 1);

                if(fileDPout < 0){
                    cout << "Error writing to file!";
                }

                else { 
                    cout << x << endl;
                    wait(0);
                    close(fileDPout);
                    dup2(oldStdOut, 1);
                    cout << "Successfully wrote '" << x << "' to file!" << endl;
                }
            }
        }

    }

    //Part 5 reading stuff from program 1
    std::string line;

    while(std::getline(std::cin, line)) // read from std::cin
    {
        // show that it arrived
        std::cout << "Line Received: " << line << '\n';
    }





    /* PART 2 - B */

    // string command = "";
    // cout << "Type './myProg1 | ./myProg2'" << endl;
    // getline(cin, command, '\n');
    
    // if(command == "./myProg1 | ./myProg2"){
    //     int p2cfd[2];
    //     int c2pfd[2];
    //     char buffer[10];
    //     ssize_t bytes_read = 0;

    //     memset (buffer, 0, sizeof (buffer));

    //     if ((pipe (p2cfd) < 0) || (pipe (c2pfd) < 0))
    //     {
    //         printf ("ERROR: Failed to open pipe\n");
    //         exit (1);
    //     }

    //     pid_t child_pid = fork ();
    //     assert (child_pid >= 0);

    //     /* MyProg1 */
    //     if (child_pid == 0)
    //     {
    //         close (p2cfd[1]);
    //         close (c2pfd[0]);
    //         bytes_read = read (p2cfd[0], buffer, 10);
    //         if (bytes_read <= 0) exit (0);
    //         cout << "Child received: '%s'\n";

    //         strncpy (buffer, "goodbye", sizeof (buffer));
    //         write (c2pfd[1], buffer, 10);
    //         exit (0);
    //     }

    //     close (p2cfd[0]);
    //     close (c2pfd[1]);

    //     /* MyProg2 */
    //     strncpy (buffer, "hello", sizeof (buffer));
    //     cout << "Parent is sending '%s'\n";
    //     write (p2cfd[1], buffer, sizeof (buffer));

    //     bytes_read = read (c2pfd[0], buffer, 10);
    //     if (bytes_read <= 0) exit (1);
    //     cout << "Parent received: '%s'\n";
    // }
}