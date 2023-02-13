#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
  FILE *fptr;
  char buffer[5];

  if(argc <= 1){
    printf("wunzip: file1 [file2 ...]\n");
    exit(1);
  }

  for(int i = 1; i < argc; i++){
    if((fptr = fopen(argv[i], "r")) == NULL){
      printf("wunzip: cannot open file\n");
      exit(1);
    }

    int count = 0;

    while(fread(&count, 4,1,fptr)){

      memset(buffer, 0,strlen(buffer));
      
      fread(buffer,1,1,fptr);

      for(size_t i = 0; i < count; i++){

	
	printf("%s", buffer);
      }
    }
    fclose(fptr);
  }

  return 0;
}
