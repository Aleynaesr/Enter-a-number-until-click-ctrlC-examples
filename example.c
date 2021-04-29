#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#define RED     "\033[31m"      /* Red */
#define RESET   "\033[0m"

int fflag = 0;
int entrynumber = 0;
int totalnumber = 0;
float avg;
void sighand(int);
int main (void) { 
   int nume = 0;
     sigaction(SIGINT, &(struct sigaction){ .sa_handler = sighand }, NULL);
 while(fflag == 0) {
          printf("Enter a number: ");
          if(scanf("%d", &nume) == EOF){
              if (fflag == 1){
                    avg = (float) totalnumber/ (float) entrynumber;
                    printf(RED "\r<CTRL-C>             \n"RESET"Inputs:%d,Average:%.1f\n", entrynumber,avg);
                    fflag = 0;
              }    }
          else{
                if (nume == -1 ){
                    exit(0);
                }
                else {
                    totalnumber = totalnumber + nume;
                    entrynumber++; 
                }        } }
   return(0);
   }

void sighand(int signum) {
    fflag = 1;
}



