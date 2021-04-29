#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#define RED     "\033[31m"      /* Red */
#define RESET   "\033[0m"

int count = 0;
int changeStatus = 2;
int alpNumstatus = 0;
void sighand(int);

int main (void) { 
    int sayi; 
    sigaction(SIGINT, &(struct sigaction){ .sa_handler = sighand }, NULL);
    
while(1) {

       if (count>15) {
        exit(0);
        }

        if (changeStatus == 1 && alpNumstatus == 0) {
            printf(RED "\r<CTRL-C>\n" RESET);
            changeStatus = 0;
        }
        else if (changeStatus == 1 && alpNumstatus == 1){
            printf(RED "\r<CTRL-C>\n" RESET);
            changeStatus = 0;
        }
        else if (changeStatus == 2) {
            
            changeStatus = 0;
        }

        if (alpNumstatus == 0) {
    sayi = rand() % 10;
    printf("%d\n", sayi);
    sleep(1);
    count++;
        }
        else if (alpNumstatus == 1) {
 char alph[] = "abcdefghijklmnopqrstuvwxyz";
   char letter = alph[(rand() % 26)];
  printf("%c\n", letter );
  sleep(1);
  count++;
        }     
   }
   return(0);
}
void sighand(int signum) {

    changeStatus = 1;

    if (alpNumstatus == 0) {
        alpNumstatus = 1;
    }
    else if (alpNumstatus == 1){
        alpNumstatus = 0;
    }
}
