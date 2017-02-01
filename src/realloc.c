/*
** realloc.c for realloc in /home/peixot_a/Documents/pierre.peixoto@epitech.eu/rendu/c_tek2/PSU_2016_malloc/src
** 
** Made by pierre.peixoto
** Login   <pierre.peixoto@epitech.eu>
** 
** Started on  Wed Feb  1 14:03:00 2017 pierre.peixoto
** Last update Wed Feb  1 15:18:14 2017 pierre.peixoto
*/

#include "../header/malloc.h"

void		*realloc(void *ptr, const size_t size)
{
  t_meta_data	*begin;
  size_t	i;
  char		*cpy;
  char		*result;

  begin = start;
  while (start != (ptr - SIZE_META_DATA) && start != NULL)
    start = start->next;
  if (start == NULL)
    {
      start = begin;
      return (NULL);
    }
  if ((result = malloc(size)) == NULL)
    return (NULL);
  i = 0;
  cpy = ptr;
  while (i < start->size)
    {
      result[i] = cpy[i];
      ++i;
    }
  start = begin;
  free(ptr);
  return (result);
}
