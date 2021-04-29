#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#define RED     "\033[31m"      /* Red */
#define RESET   "\033[0m"


int incDecStatus = 0;
int changeStatus = 2;

void sighand(int);

int main (void) { 
    int sayi; 

    sigaction(SIGINT, &(struct sigaction){ .sa_handler = sighand }, NULL);
    sayi = rand() % 101 + 100;

   while(1) {

       if (sayi<100 || sayi>200) {
        exit(0);
        }

        if (changeStatus == 1 && incDecStatus == 0) {
            printf(RED "\r<CTRL-C>\n" RESET "[Increasing]\n");
            changeStatus = 0;
        }
        else if (changeStatus == 1 && incDecStatus == 1){
            printf(RED "\r<CTRL-C>\n" RESET "[Decreasing]\n");
            changeStatus = 0;
        }
        else if (changeStatus == 2) {
            printf("\r[Increasing]\n");
            changeStatus = 0;
        }


        if (incDecStatus == 0) {
            sayi = sayi + 10;
        }
        else if (incDecStatus == 1) {
            sayi = sayi - 10;
        }

        printf("\rVariable: %d\n",sayi);
        sleep(1);
   }
   return(0);
}

void sighand(int signum) {

    changeStatus = 1;

    if (incDecStatus == 0) {
        incDecStatus = 1;
    }
    else if (incDecStatus == 1){
        incDecStatus = 0;
    }
}

