#include <stdio.h>

struct time {
  int hour;
  int minute;
  int second;
};


int main()
{
  struct time when;
  int items;

  printf("Enter a time expressed as hh:mm:ss format.\n");
  items = scanf("%02d:%02d:%02d",
        &when.hour, &when.minute, &when.second);
  if (items == 3) {
    printf("You entered: %d hours %d minutes %d seconds\n",
           when.hour, when.minute, when.second);
  } else {
    printf("oops!");
  }
}