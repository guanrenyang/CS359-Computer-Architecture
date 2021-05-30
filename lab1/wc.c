#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
void wc(FILE *ofile, FILE *infile, char *inname) {
  // your code here:
  
  int byte_count=0;
  int line_count=0;
  int word_count=0;
  
  char last_char=' ';
  char current_char;

  while (last_char!=EOF)
  {
	  if(infile==NULL)
	  	current_char=getchar();
	  else
	  	current_char=getc(infile);

	  if(current_char!=EOF)
	  {
		  byte_count++;
	  }
	  else if(last_char!='\n')
	  {
		  line_count++;
	  }
	  if(current_char=='\n')
	  {
		  line_count++;
	  }
	  if(current_char==' '||current_char=='\n'||current_char=='\t'||current_char==EOF)
	  	if(last_char!=' '&&last_char!='\n'&&last_char!='\t')//when the current character read is space or a '\n', then check if the last read character is a empty character. 
		{
			word_count++;
		}
	  last_char=current_char;
  }
  if(ofile==NULL) // when the out_file is default
  	printf(" %d %d %d %s",line_count,word_count,byte_count,inname);
  else
  {
	  char byte_count_string[10000];
	  char line_count_string[10000];
	  char word_count_string[10000];

	  sprintf(byte_count_string,"%d",byte_count);
	  sprintf(line_count_string,"%d",line_count);
	  sprintf(word_count_string,"%d",word_count);

	  strcat(byte_count_string," ");
	  strcat(line_count_string," ");
	  strcat(word_count_string," ");
	
	  fputs(" ",ofile);
	  fputs(line_count_string,ofile);
	  fputs(word_count_string,ofile);
	  fputs(byte_count_string,ofile);
	  fputs(inname,ofile);
  }
}

int main (int argc, char *argv[]) {

  	char* out_file_name = NULL;
	char* inname = NULL;
	if(argc == 1) wc(NULL,NULL,NULL);
	else if(argc == 2){
		inname = argv[1];
		FILE *infile = fopen(inname,"r");
		if(!infile){
			perror("Input file opening failed");
			exit(1);
		}
		wc(NULL,infile,inname);
	}
	else if(argc == 3){
		inname = argv[1];
		FILE *infile = fopen(inname,"r");
		if(!infile){
			perror("Input file opening failed");
			exit(1);
		}
		FILE *out_file = fopen(argv[2],"w");
		if(!out_file){
			perror("Output file opening failed");
			exit(1);
		}
		wc(out_file,infile,inname);
	}
	else{
		printf("arguments error\n");
		exit(1);
	}
	return 0;

}
