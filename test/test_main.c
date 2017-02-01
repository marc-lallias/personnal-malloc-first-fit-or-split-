/*
** test_main.c for  in /home/darkmark/rendu/PSU_2016_malloc
** 
** Made by DarKmarK
** Login   <marc.lallias@epitech.eu>
** 
** Started on  Tue Jan 24 15:34:55 2017 DarKmarK
** Last update Wed Feb  1 14:31:34 2017 DarKmarK
*/

#include "../header/malloc.h"
#include <stdlib.h>

void	test(char *ptr5)
{
  int	i;

  
  i = 0;
  while (i < 50)
    {
      ptr5[i] = (i % 9) + '0';
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
  char	*ptr5;

  //printf("IIIIIstart= %d\n", sbrk(0));
  ptr	= malloc(1000);
  test(ptr);
  ptr2	= malloc(1000);
  test(ptr2);
  ptr3	= malloc(4000);
  test(ptr3);
  free(ptr2);
  free(ptr3);
  //my_free(ptr);
  //my_free(ptr3);
  ptr4	= malloc(400);
  //test(ptr4);
  //my_free(ptr4);
  //ptr4 = my_malloc(10);
  //my_free(ptr4);
  show_alloc_mem();
  
  //printf("XXXXXXXapres all free= %d    %d\n", sbrk(0), end);
  return (0);
}
