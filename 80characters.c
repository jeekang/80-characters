/*
** This program reads data from input until the end of input
** and checks whether or not any line in the input is greater 
** than 80 characters. If a line has more than 80 characters,
** a * will be placed in front of the line and characters past
** 80 will have a caret placed underneath. This program assumes
** the max number of characters in any line to be 1000. 
*/


#include <stdio.h>
#define MAX_CHARS 1000
int main(void) {
  int character_count, line_count, arr_pos, i=0;
  char ch;

  scanf("%c", &ch); /*read character*/
  while(!feof(stdin)) {
    /*loops back here for start of everyline
      reset array, character count, array
      position and increment line count*/
    char line_contents[MAX_CHARS];
    arr_pos = 0;
    character_count = 0;
    line_count++;

    while(ch !='\n') {
      line_contents[arr_pos] = ch;
      arr_pos++;
      
      /*handling tab character*/
      if(ch =='\t') {
	if(character_count < 8) {
	  character_count = 8;
	} else {
	  character_count++;
	  while(character_count % 8 != 0) {
	    character_count++;
	  }
	}
	/*if character is not \t*/
      } else {
	character_count++;
      }
      scanf("%c", &ch);
    }

    /*if character count in line is greater than 80*/
    if(character_count > 80) {
      printf("%c%5d%c ",'*', line_count, ':');

      for(i = 0; i < arr_pos; i++) {
	printf("%c", line_contents[i]); 
      }
      printf("\n");
      
      /*number of characters past 80*/
      character_count -= 80;
      
      for(i = 0; i < 88; i++) {
	printf(" ");
      }
     
      for(i = 0; i < character_count; i ++) {
	printf("^");
      }
      printf("\n");
      
    } else { /*if line is < 80 characters*/
      printf("%c%5d%c ", ' ', line_count, ':');
      for(i = 0; i < arr_pos; i++) {
	printf("%c", line_contents[i]);
      }
      printf("\n");
    }
    scanf("%c", &ch);
  }
  return 0;
}
