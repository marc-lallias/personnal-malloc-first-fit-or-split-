/*
** realloc.c for realloc in /home/peixot_a/Documents/pierre.peixoto@epitech.eu/rendu/c_tek2/PSU_2016_malloc/src
** 
** Made by pierre.peixoto
** Login   <pierre.peixoto@epitech.eu>
** 
** Started on  Wed Feb  1 14:03:00 2017 pierre.peixoto
** Last update Wed Feb  1 18:15:59 2017 pierre.peixoto
*/

#include <string.h>
#include "../header/malloc.h"

void		*my_realloc(void *ptr, size_t size)
{
  t_meta_data	*begin;
  size_t	i;
  char		*cpy;
  char		*result;

  begin = ptr - sizeof(t_meta_data);
  if (begin == NULL)
    return (NULL);
  if ((result = my_malloc(size)) == NULL)
    return (NULL);
  cpy = ptr;
  i = 0;
  while (i < begin->size)
    {
      result[i] = cpy[i];
      ++i;
    }
  my_free(ptr);
  return (result);
}
