/*
** realloc.c for realloc in /home/peixot_a/Documents/pierre.peixoto@epitech.eu/rendu/c_tek2/PSU_2016_malloc/src
** 
** Made by pierre.peixoto
** Login   <pierre.peixoto@epitech.eu>
** 
** Started on  Wed Feb  1 14:03:00 2017 pierre.peixoto
** Last update Wed Feb  8 10:06:39 2017 pierre.peixoto
*/

#include "../header/malloc.h"

void		*realloc(void *ptr, size_t size)
{
  char		*cast;
  char		*new_ptr;
  t_meta_data	*meta;
  int		i;

  if (ptr == NULL)
    return (malloc(size));
  i = 0;
  meta = ptr;
  meta = meta - 1;
  if ((new_ptr = malloc(size)) == NULL)
    return (NULL);
  cast = ptr;
  while (i < meta->size)
    {
      new_ptr[i] = cast[i];//verifier si bien 1 a 1
      i = i + 1;
    }
  free(ptr);
  return (new_ptr);
}
