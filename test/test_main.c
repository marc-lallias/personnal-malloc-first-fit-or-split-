/*
** test_main.c for  in /home/darkmark/rendu/PSU_2016_malloc
** 
** Made by DarKmarK
** Login   <marc.lallias@epitech.eu>
** 
** Started on  Tue Jan 24 15:34:55 2017 DarKmarK
** Last update Mon Jan 30 15:19:30 2017 DarKmarK
*/

#include "../header/malloc.h"
#include <stdlib.h>

int main()
{
  char	*ptr;
  char	*ptr2;
  char	*ptr3;
  
  ptr	= my_malloc(1000);
  ptr2	= my_malloc(1000);
  ptr3	= my_malloc(4000);
  my_free(ptr2);
  my_free(ptr);
  my_free(ptr3);
  my_malloc(400);
  //my_free(ptr3);
  //my_free(ptr);
  show_alloc_mem();
  return (0);
}
