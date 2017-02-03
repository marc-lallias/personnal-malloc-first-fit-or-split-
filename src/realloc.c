/*
** realloc.c for realloc in /home/peixot_a/Documents/pierre.peixoto@epitech.eu/rendu/c_tek2/PSU_2016_malloc/src
** 
** Made by pierre.peixoto
** Login   <pierre.peixoto@epitech.eu>
** 
** Started on  Wed Feb  1 14:03:00 2017 pierre.peixoto
** Last update Fri Feb  3 18:09:32 2017 Pierre Peixoto
*/

#include "../header/malloc.h"

void		*realloc(void *ptr, size_t size)
{
  t_meta_data	*begin;
  size_t       	tot_size;
  size_t	i;
  char		*cpy;
  char		*result;
  
  i = 0;
  cpy = ptr;
  if (size == 0)
    return (NULL);
  if (ptr == NULL || ptr == 0)
    return (malloc(size));
  begin = ptr;
  begin = begin - 1;
  if (size == begin->size)
    return (ptr);
  tot_size = size;
  if ((result = malloc(tot_size)) == NULL)
    return (NULL);
  while (i < tot_size && i < begin->size)
    {
      result[i] = cpy[i];
      ++i;
    }
  free(ptr);
  return (result);
}
