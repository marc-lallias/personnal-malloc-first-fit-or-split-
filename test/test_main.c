/*
** test_main.c for  in /home/darkmark/rendu/PSU_2016_malloc
** 
** Made by DarKmarK
** Login   <marc.lallias@epitech.eu>
** 
** Started on  Tue Jan 24 15:34:55 2017 DarKmarK
** Last update Sun Feb 12 11:30:05 2017 pierre.peixoto
*/

#include "../header/malloc.h"

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

int	main()
{
  char	*ptr;
  char	*ptr1;
  char	*ptr2;
  char	*ptr3;
  char	*ptr4;

  ptr = malloc(0);
  if (ptr == NULL)
    write(1, "Err\n", 4);
  ptr1 = malloc(20);
  ptr2 = malloc(4000);
  show_alloc_mem();
  free(ptr);
  free(ptr1);
  free(ptr2);
  show_alloc_mem();
  return (0);
}
