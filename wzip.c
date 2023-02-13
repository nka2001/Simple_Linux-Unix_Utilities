#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 void writeFile(int count, char *oldbuffer){

   fwrite(&count, 4,1,stdout);
   fwrite(oldbuffer, 1, 1, stdout);
   
}

int main(int argc, char * argv[]){

  FILE *fptr;
  char buffer[2], oldbuffer[2];
  int count;

  if (argc <= 1){
    printf("wzip: file1 [file2...]\n");
    exit(1);

  }

  for(size_t i = 1; i < argc; i++){

    if((fptr = fopen(argv[i], "r")) == NULL){
      printf("wzip: cannot open file\n");
      exit(1);
    }

    while(fread(buffer,1,1,fptr)){
      if(strcmp(buffer, oldbuffer) == 0){
	count++;
      } else {
	if(oldbuffer[0] != '\0'){
	  writeFile(count, oldbuffer);
	}
	count = 1;
	strcpy(oldbuffer, buffer);
    

  }
  

}
    fclose(fptr);
  }
  writeFile(count, oldbuffer);

  return 0;
}
