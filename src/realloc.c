/*
** realloc.c for realloc in /home/peixot_a/Documents/pierre.peixoto@epitech.eu/rendu/c_tek2/PSU_2016_malloc/src
** 
** Made by pierre.peixoto
** Login   <pierre.peixoto@epitech.eu>
** 
** Started on  Wed Feb  1 14:03:00 2017 pierre.peixoto
** Last update Thu Feb  2 09:47:46 2017 DarKmarK
*/

#include "../header/malloc.h"
//#include <string.h>

void		*realloc(void *ptr, size_t size)
{
  t_meta_data	*begin;
  size_t       	tot_size;
  size_t	i;
  char		*cpy;
  char		*result;
  
  i = 0;
  cpy = ptr;
  if (ptr == NULL || ptr == 0)
    {
      return (malloc(size));
    }
  begin = ptr;
  begin = begin - 1;
  //my_put_nbr((unsigned int)ptr);
  //write(1, "YYY\n", 5);
  tot_size = size;
  //write(1, "YYY\n", 5);
  tot_size = tot_size + (size_t)begin->size;
  //write(1, "YYY\n", 5);
  if ((result = malloc(tot_size)) == NULL)
    return (NULL);
  while (i < begin->size)
    {
      result[i] = cpy[i];
      ++i;
    }
  free(ptr);
  return (result);
}
