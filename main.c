#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "func.h"

#define max 10

int next = 0;

typedef struct
{
  int value;
} Array;

Array Values[max];

void clear();

void create();
void delete();
void list();
void sort();

int main()
{
  int option;
  while (1)
  {
    clear();
    printf("\n Bubble Sort");
    printf("\n ----------------------------------");
    printf("\n  1 - Create record.");
    printf("\n  2 - Delete record.");
    printf("\n  3 - List records.");
    printf("\n  4 - Sort records.");
    printf("\n  5 - Exit program.");
    printf("\n ----------------------------------");
    printf("\n Choose an option: ");
    scanf("%d", &option);
    fflush(stdin);

    if (option < 1 || option > 5)
    {
      printf("\n Invalid option. Please choose a valid option.");
      pause("\n\n Press any key to continue...");
      continue;
    }

    system("clear");
    switch (option)
    {
    case 1:
      printf("\n Create record");
      printf("\n ----------------------------------");
      create();
      break;
    case 2:
      printf("\n Remove record");
      printf("\n ----------------------------------");
      delete ();
      break;
    case 3:
      printf("\n List records");
      printf("\n ----------------------------------");
      list();
      break;
    case 4:
      printf("\n Sort records");
      printf("\n ----------------------------------");
      sort();
      break;
    case 5:
      printf("\n Exiting program...");
      exit(0);
    }

    pause("\n\n Press any key to continue...");
  }

  return 0;
}

void create()
{
  if (next == max)
  {
    printf("\n Full list.");
    return;
  }

  int value;
  printf("\n Input value: ");
  scanf("%d", &value);
  fflush(stdin);
  Values[next].value = value;
  next++;
  printf("\n Record added!");
}

void delete()
{
  if (next == 0)
  {
    printf("\n Empty list.");
    return;
  }

  int value;
  printf("\n Input value to remove: ");
  scanf("%d", &value);
  fflush(stdin);
  for (int i = 0; i < next; i++)
  {
    if (Values[i].value == value)
    {
      next--;
      for (int ind = i; ind < next; ind++)
      {
        Values[ind].value = Values[ind + 1].value;
      }
      printf("\n Record removed!");
      break;
    }
  }
}

void list()
{
  if (next == 0)
  {
    printf("\n Empty list.");
    return;
  }

  printf("\n INDEX\t| POS\t| VALUE");
  printf("\n ----------------------");
  for (int i = 0; i < next; i++)
    printf("\n [%d]\t| %d\t| %d", i, i + 1, Values[i].value);
  printf("\n ----------------------");
  printf("\n\n All records are listed!");
}

void sort()
{
  Array copy[next];
  Array aux;

  int repeat = 0, count = 0;

  for (int i = 0; i < next; i++)
    copy[i].value = Values[i].value;

  do
  {
    repeat = 0;
    for (int i = 0; i < next - 1; i++)
    {
      count++;
      if (copy[i].value > copy[i + 1].value)
      {
        repeat = 1;
        aux = copy[i];
        copy[i] = copy[i + 1];
        copy[i + 1] = aux;
      }
    }
  } while (repeat != 0);
  printf("\n INDEX\t| POS\t| VALUE");
  printf("\n ----------------------");
  for (int x = 0; x < next; x++)
    printf("\n [%d]\t| %d\t| %d", x, x + 1, copy[x].value);
  printf("\n ----------------------");
  printf("\n Loops: %d", count);
  printf("\n The list has been sorted!");
}