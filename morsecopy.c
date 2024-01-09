#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "library.h" //my own library, consists of morse encoder and decoder functions
#include <sys/wait.h>

char recieved_morse[10]; //initializing buffer for recieved morse code strings
char decoded_char[1]; //initializing buffer for decoded morse -> char

int dest_file = 0; //initialzing int for destination file 

void handle_signal(int sig) {
    //if dash (-) is found, concatenate it to the recieved_morse buffer
    if(sig==SIGUSR1){
        strcat(recieved_morse,"-");
    //if dot (.) is found, concatenate it to the recieved_morse buffer
    } else if(sig==SIGUSR2) {
        strcat(recieved_morse,".");
    //if end of character is found, decode the recieved_morse buffer
    } else if(sig==SIGALRM) {
        decoder(recieved_morse,decoded_char);
        //write the decoded char to the end of the destination file
        lseek(dest_file,0,SEEK_END);
        write(dest_file,decoded_char,sizeof(char));
        //reset both buffers
        strcpy(recieved_morse,"");
        strcpy(decoded_char,"");
    }
}


int main(int argc, char *argv[]){
    //checking if log file exists, creating one if not
    
    struct flock lock;//making the file lock struct
    
    int logfd = open("morse.log",O_WRONLY);
    if(logfd==-1){
        logfd=open("morse.log",O_CREAT);
        logfd=open("morse.log",O_WRONLY);
    }
    lseek(logfd,0,SEEK_END); //finding the end of log file
    
    //making the lock a write lock and locking the log file
    memset(&lock,0,sizeof(lock));
    lock.l_type = F_WRLCK;
    fcntl(logfd,F_SETLKW,&lock);


    //wrong amount of arguments
    if(argc!=3) {
        printf("Please use the correct syntax:\n./hello [file1] [file2]\n");
        write(logfd,"Failed function call\n",sizeof(char)*21);//logging failed function
        exit(1);
    }
    //creating child process
    int id = fork();   
    if(id<0) {
        //fork failed
        write(logfd,"Failed function call\n",sizeof(char)*21);//logging failed function
        exit(1);
    }
    //child process:
    if(id==0){
    int parentid = getppid(); //get parent id
    int fd_source = open (argv[1], O_RDONLY); //get source file
    if(fd_source==-1){
    //source file not found
    printf("Could not find source file\n");
    //killing parent
    kill(parentid, SIGINT);
    write(logfd,"Failed function call\n",sizeof(char)*21);//logging the error
    exit(1);
    }
    char buffer[1]; //initilazing buffer for read character
    int i = 0;
    int current = -1; //initializing int for the index of the current char of the source file
    int last = lseek(fd_source,-1,SEEK_END);
    //looping while we haven't reached the end of the source file
    while(current!=last) {
    char morsebuffer[10]; //initializing buffer for the encoded morse code
    current = lseek(fd_source,i,SEEK_SET); //finding the i:th char of the source file
    read(fd_source,buffer,sizeof(char)); //reading the current char
    encoder(buffer, morsebuffer); //encoding the char to morse
    
    for(int j=0;j<strlen(morsebuffer);j++){
       // printf("%d: ",j);
       if(morsebuffer[j]=='-'){
        //printf("- found in child\n");
        kill(parentid,SIGUSR1);
        
    }else if(morsebuffer[j]=='.'){
        //printf(". found in child\n");
         kill(parentid,SIGUSR2);
    }
    else if(morsebuffer[j]==' '){
        //printf("space found in child\n");
        kill(parentid,SIGALRM);
    }
    //else printf("unknown character\n");
    usleep(100);
    }
    i = i+1;
    usleep(100);
    }
    usleep(100);
    //when done with signaling, kill the parent process
    kill(parentid,SIGINT);
    }else{
    //parent process
    
    dest_file = open(argv[2], O_WRONLY);
   
    if(dest_file==-1){
        //destination file not found
        printf("Could not find destination file\n");
        write(logfd,"Failed function call\n",sizeof(char)*21);
        kill(0,SIGINT);//killing child process
        exit(1);
    }
 
        //signal handler related code
        struct sigaction sig;
        sig.sa_flags=0;
        sig.sa_handler = &handle_signal;
        sigaction(SIGUSR1,&sig,NULL);
        sigaction(SIGUSR2, &sig,NULL);
        sigaction(SIGALRM, &sig, NULL);
        while(1){ //looping infinitely, only stop when child sends SIGINT i.e. when signaling is over
            wait(NULL);
        }
    }
    write(logfd,"Successfully wrote to the destination file\n",sizeof(char)*43);//logging successful function
    
    //unlocking the log file
    lock.l_type=F_UNLCK; 
    fcntl(logfd,F_SETLKW,&lock);
   
    return(0);
}