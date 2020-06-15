/*
  Name: 12to24.c
  Description: Converts 12hr time -->  24hr time
*/

#include <stdio.h>
#include <ctype.h>

int main() {
  int hr, s;
  char meridiem;

  printf("Enter a 12-hour time: ");
  scanf("%d:%d %c", &hr, &s, &meridiem);

  printf("Equivalent 24-hour time: %d:%d\n",
	 (toupper(meridiem) == 'P' ? hr+12 : hr), s);
  /* printf("%d:%d %cM\n", hr, s, toupper(meridiem)); */

  
  return 0;
}


/*
VOCAB

meridiem: midday

ante meridiem (AM): before midday
post meridiem (PM): after midday
*/
