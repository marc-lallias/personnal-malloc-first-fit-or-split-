/*
** test_main.c for  in /home/darkmark/rendu/PSU_2016_malloc
** 
** Made by DarKmarK
** Login   <marc.lallias@epitech.eu>
** 
** Started on  Tue Jan 24 15:34:55 2017 DarKmarK
** Last update Mon Jan 30 16:15:00 2017 DarKmarK
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
  
  ptr	= my_malloc(1000);
  test(ptr);
  ptr2	= my_malloc(1000);
  test(ptr2);
  ptr3	= my_malloc(4000);
  test(ptr3);
  my_free(ptr2);
  my_free(ptr);
  my_free(ptr3);
  ptr4	= my_malloc(400);
  test(ptr4);
  my_free(ptr4);
  my_malloc(10);
  //my_free(ptr3);
  //my_free(ptr);
  show_alloc_mem();
  return (0);
}
