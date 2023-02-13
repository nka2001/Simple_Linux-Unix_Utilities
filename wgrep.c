#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){

  int comp = strcmp(argv[1], "");

  if(comp == 0){
    printf("Error empty string, this will not match any lines");
    exit(0);
  }

  
  if(argc == 1){
    printf("wgrep: searchterm [file...]\n");
    exit(1);
  }

  if(argc == 2){
    char line[1000];

    while(fgets(line, sizeof(line), stdin)!= NULL){

      if(strstr(line, argv[1])){
	puts(line);
      }
    }

    
    exit(0);
  }


  for(int i = 2; i < argc; i++){
    
    
    char str[50];

    FILE *fp  = fopen(argv[i],"r");

  if(!fp){
    printf("wgrep: cannot open file\n");
    exit(1);
  }
  while(fgets(str, 50, fp) != NULL){
    if(strstr(str, argv[1])){
	fputs(str, stdout);
      }
      }
	      


  }
  exit(0);
}
