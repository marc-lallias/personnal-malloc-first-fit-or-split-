/*
** test_main.c for  in /home/darkmark/rendu/PSU_2016_malloc
** 
** Made by DarKmarK
** Login   <marc.lallias@epitech.eu>
** 
** Started on  Tue Jan 24 15:34:55 2017 DarKmarK
** Last update Thu Feb  2 09:25:05 2017 DarKmarK
*/

//#include "../header/malloc.h"
#include <stdlib.h>

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

int main()
{
  char	*ptr;
  char	*ptr2;
  char	*ptr3;
  char	*ptr4;
  int	*intp;
  int	i;

  /* char	*ptr66; */
  
  /* ptr	= my_malloc(1000); */

  /* ptr2	= my_malloc(1000); */

  /* ptr3	= my_malloc(4000); */

  /* ptr66	= my_malloc(5); */
  
  /* show_alloc_mem(); */
  
  /* my_free(ptr); */
  /* my_free(ptr2); */
  /* my_free(ptr66); */
  /* my_free(ptr3); */
  
  /* show_alloc_mem(); */

  
  /* ptr4	= my_malloc(11); */
  /* test(ptr4); */
  /* ptr4[10] = '\0'; */

  /* //printf("str: %s \n", ptr4); */

  /* show_alloc_mem(); */

  intp = malloc(5 * sizeof(int));
  intp[0] = 100;
  intp[1] = 99;
  intp[2] = 98;
  intp[3] = 97;
  intp[4] = 96;

  //show_alloc_mem();
  
  //for (i = 0; i < 5; i++)
  //printf("intp:%d\n", intp[i]);

  intp = realloc(intp, sizeof(int) * 7);
  intp[5] = 10;
  intp[6] = 11;

  //show_alloc_mem();

  //for (i = 0; i < 7; i++)
  //printf("intp2:%d\n", intp[i]);
  
  //printf("XXXXXXXapre all free= %d    %d\n", sbrk(0), end);
  return (0);
}

/*int	main(void)
{
  char	**str;
  int	i;

  i = 0;
  while (i < 90)
    {
      str[i] = my_malloc(sizeof(char) * 100);
      str[i] = my_realloc(str[i], sizeof(char) * 200);
      str[i] = "bite";
      ++i;
    }
  i = 0;
  printf("~~~~~~~~~\n");
  printf("%s\n", str[42]);
  str[42] = "TEST";
  printf("%s\n", str[42]);
  return (0);
}*/
