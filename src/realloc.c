/*
** realloc.c for realloc in /home/peixot_a/Documents/pierre.peixoto@epitech.eu/rendu/c_tek2/PSU_2016_malloc/src
** 
** Made by pierre.peixoto
** Login   <pierre.peixoto@epitech.eu>
** 
** Started on  Wed Feb  1 14:03:00 2017 pierre.peixoto
** Last update Wed Feb  1 16:06:12 2017 pierre.peixoto
*/

#include "../header/malloc.h"

void		*xrealloc(void *ptr, size_t size)
{
  t_meta_data	*begin;
  size_t	i;
  char		*cpy;
  char		*result;

  begin = ptr - sizeof(t_meta_data);
  if (begin == NULL)
    return (NULL);
  if ((result = malloc(size)) == NULL)
    return (NULL);
  i = 0;
  cpy = ptr;
  while (i < begin->size && i < size)
    {
      result[i] = cpy[i];
      ++i;
    }
  free(ptr);
  return (result);
}
