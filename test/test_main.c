/*
** test_main.c for  in /home/darkmark/rendu/PSU_2016_malloc
** 
** Made by DarKmarK
** Login   <marc.lallias@epitech.eu>
** 
** Started on  Tue Jan 24 15:34:55 2017 DarKmarK
** Last update Tue Feb  7 16:41:00 2017 DarKmarK
*/

//#include "../header/malloc.h"
#include <stdlib.h>
#include <unistd.h>

/*
 * TOOLS
 */
int		my_put_str(const char *str);
void		my_put_nbr(const unsigned int nb);
void		show_alloc_mem(void);

void	test(char *ptr)
{
  int	i;

  
  i = 0;
  while (i < 10)
    {
      ptr[i] = 'S';
      ++i;
    }

  return ;
}

int main()//mutex lock debut lock fin
{
  char	*ptr;
  char	*ptr1;
  char	*ptr2;
  char	*ptr3;
  char	*ptr4;

  my_put_str("sbrk(0) ------------------------->");
  my_put_nbr((unsigned int)sbrk(0));
  my_put_str("\n");
  
  ptr = malloc(50);
  ptr1 = malloc(20);
  ptr2 = malloc(3973);
  show_alloc_mem();
  //ptr = realloc(ptr, 6000);
  //ptr = malloc(6000);

  /* ptr1 = malloc(100); */
  /* ptr2 = malloc(200); */
  /* ptr3 = malloc(300); */
  //ptr4 = realloc(ptr3, 301);
  /* free(ptr); */
  my_put_str("_________________________________________________\n");
  /* free(ptr2); */
  free(ptr2);
  free(ptr);
  free(ptr1);
  /* free(ptr2); */
  show_alloc_mem();

  /* write(1, "\n", 1); */
  /* free(ptr2); */
  /* free(ptr); */
  /* free(ptr1); */
  /* //free(ptr3); */
  /* show_alloc_mem(); */

  /*write(1, "\n", 1);
  ptr = realloc(NULL, 6);
  ptr = realloc(ptr, 8);
  ptr = realloc(ptr, 20);
  show_alloc_mem();*/
  
  return (0);
}

/* int	main(void) */
/* { */
/*   char	**str; */
/*   int	i; */

/*   i = 0; */
/*   str = malloc(sizeof(char *) * 1000); */
/*   while (i < 900) */
/*     { */
/*       str[i] = malloc(sizeof(char) * 100); */
/*       str[i] = realloc(str[i], sizeof(char) * 200); */
/*       str[i] = "bite"; */
/*       ++i; */
/*     } */
/*   i = 0; */
/*   printf("~~~~~~~~~\n"); */
/*   printf("%s\n", str[42]); */
/*   str[42] = "TEST"; */
/*   printf("%s\n", str[42]); */
/*   return (0); */
/* } */
