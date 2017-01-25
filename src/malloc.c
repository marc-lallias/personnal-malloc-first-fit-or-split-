/*
** my_malloc.c for  in /home/darkmark/rendu/PSU_2016_malloc
** 
** Made by DarKmarK
** Login   <marc.lallias@epitech.eu>
** 
** Started on  Tue Jan 24 12:08:28 2017 DarKmarK
** Last update Tue Jan 24 19:25:31 2017 marc lallias
*/

#include "../header/malloc.h"
#include <unistd.h>

void	*malloc(size_t size)
{
  (void)size;
  write(1, "XXX\n", 4);
  return (NULL);
}
