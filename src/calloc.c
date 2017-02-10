/*
** calloc.c for calloc in /home/peixot_a/Documents/pierre.peixoto@epitech.eu/rendu/tek2/c_tek2/PSU_2016_malloc/src
** 
** Made by pierre.peixoto
** Login   <pierre.peixoto@epitech.eu>
** 
** Started on  Fri Feb 10 18:27:03 2017 pierre.peixoto
** Last update Fri Feb 10 18:40:01 2017 pierre.peixoto
*/

#include "../header/malloc.h"

void		*calloc(size_t nmemb, size_t size)
{
  void		*addr;
  char		*cpy;
  size_t	i;

  addr = malloc(nmemb * size);
  if ((nmemb * size) == 0)
    return (addr);
  i = 0;
  cpy = addr;
  while (i < nmemb * size)
    {
      cpy[i] = 0;
      ++i;
    }
  return(addr);
}
