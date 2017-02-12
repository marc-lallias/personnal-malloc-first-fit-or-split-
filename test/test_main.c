/*
** test_main.c for  in /home/darkmark/rendu/PSU_2016_malloc
** 
** Made by DarKmarK
** Login   <marc.lallias@epitech.eu>
** 
** Started on  Tue Jan 24 15:34:55 2017 DarKmarK
** Last update Sun Feb 12 19:02:37 2017 pierre.peixoto
*/

#include "../header/malloc.h"

int	main()
{
  char	*ptr;
  char	*ptr1;
  char	*ptr2;
  char	*ptr3;
  char	*ptr4;

  ptr = malloc(-50);
  if (ptr == NULL)
    write(1, "OK\n", 3);
  ptr1 = malloc(20);
  ptr2 = malloc(4500);
  ptr3 = malloc(0);
  show_alloc_mem();
  free(ptr);
  free(ptr);
  free(ptr1);
  free(ptr2);
  free(ptr3);
  show_alloc_mem();
  return (0);
}
