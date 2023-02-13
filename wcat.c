

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){


  if (argc == 1){//if there arent any arguments, then it wont work
    printf("wcat: One too few arguments\n");
    exit(0);
  }

  


  for(int i = 1; i < argc; i++){//lopp for looping through the different files, if there are many
    FILE * fp = fopen(argv[i],"r");//create a file pointer and open the file at argv[i] in read mode

    if(fp == NULL){
      printf("wcat: cannot open file\n");
      exit(1);
    }

 int c; //end of file num
    while(1){//basically while true, loop through the file
      c = fgetc(fp);//get the current state, whether end of file or not
      if(feof(fp)){ //if the file is at the end of the file then break out
     break;
   }
      printf("%c", c);//otherwise print the contents

 }
    fclose(fp);//when all is done, then close the file
  }
 return 0;

  
  

  


  

}
