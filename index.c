/****************************************************************************
*
* 201910452 - Felipe Santos Chaparim
* 201910467 - Geison Rodrigo Oriani Junior
* 201910206 - Maicon Vitor Riberio de Oliveira
*
* Bubble Sort
*
****************************************************************************/
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define max 10

int next = 7; // 0

typedef struct
{
  int value;
} Array;

Array Values[max] = {500000, 3, 1, 2, 4, -1, 0};

void insertOne();
void removeOne();
void listAll();
void bubbleSort();

void main()
{
  setlocale(LC_ALL, "Portuguese");
  int option;
  do
  {
    system("cls");
    printf("\n Algoritmo Bubble Sort");
    printf("\n ----------------------------------");
    printf("\n  1 - Inserir.");
    printf("\n  2 - Remover.");
    printf("\n  3 - Listar.");
    printf("\n  4 - Executar.");
    printf("\n  5 - Sair do Programa.");
    printf("\n ----------------------------------");
    printf("\n Opcao(1-5): ");
    scanf("%i", &option);
    fflush(stdin);
  } while (option < 1 || option > 5);

  system("cls");
  switch (option)
  {
  case 1: /* Insert */
    printf("\n Insert Mode.");
    printf("\n ----------------------------------");
    insertOne();
    break;
  case 2: /* Remove */
    printf("\n Remove Mode.");
    printf("\n ----------------------------------");
    removeOne();
    break;
  case 3: /* List */
    printf("\n List Mode.");
    printf("\n ----------------------------------");
    listAll();
    break;
  case 4: /* Execute */
    printf("\n Execute Mode.");
    printf("\n ----------------------------------");
    bubbleSort();
    printf("\n\n Valores Executados com Sucesso!");
    break;
  case 5: /* Quit Program */
    printf("\n Encerrando...");
    exit(0);
  default: /* Invalid Choice */
    printf("\n Escolha Invalida!");
    break;
  }
  printf("\n\n Precione Qualquer Tecla Para Continuar...");
  system("pause>null");
  main();
}

void insertOne()
{
  if (next < max)
  {
    int value;
    printf("\n Digite o valor: ");
    scanf("%d", &value);
    fflush(stdin);
    Values[next].value = value;
    next++;
    printf("\n Valor Inserido com Sucesso!");
  }
  else
  {
    printf("\n Lista Cheia.");
  }
}

void removeOne()
{
  if (next > 0)
  {
    int value;
    printf("\n Digite o valor: ");
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
        printf("\n Valor Removido com Sucesso!");
        break;
      }
    }
  }
  else
  {
    printf("\n Lista Vazia.");
  }
}

void listAll()
{
  if (next > 0)
  {
    printf("\n INDEX\t| POS\t| VALUE");
    printf("\n ----------------------");
    for (int i = 0; i < next; i++)
    {
      printf("\n [%d]\t| %d\t| %d", i, i + 1, Values[i].value);
    }
    printf("\n ----------------------");
    printf("\n\n Valores Listados com Sucesso!");
  }
  else
  {
    printf("\n Lista Vazia.");
  }
}

void bubbleSort()
{

  Array copy[next];
  Array aux;

  int repeat = 0, count = 0;

  for (int i = 0; i < next; i++)
  {
    copy[i].value = Values[i].value;
  }

  printf("\n INDEX\t| POS\t| VALUE");
  printf("\n ----------------------");
  do
  {
    repeat = 0;
    for (int i = 0; i < next - 1; i++)
    {
      for (int x = 0; x < next; x++)
      {
        printf("\n [%d]\t| %d\t| %d", x, x + 1, copy[x].value);
      }
      printf("\n ----------------------");
      count++;
      if (copy[i].value > copy[i + 1].value) // Ordem Crescente = >, Ordem Decrescente = <
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
  {
    printf("\n [%d]\t| %d\t| %d", x, x + 1, copy[x].value);
  }
  printf("\n ----------------------");
  printf("\n Ciclos: %d", count);
}