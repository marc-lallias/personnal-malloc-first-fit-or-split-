/*
** test_realloc.c for test_realloc in /home/peixot_a/Documents/pierre.peixoto@epitech.eu/rendu/c_tek2/PSU_2016_malloc/test
** 
** Made by pierre.peixoto
** Login   <pierre.peixoto@epitech.eu>
** 
** Started on  Wed Feb  1 14:26:00 2017 pierre.peixoto
** Last update Wed Feb  1 14:59:21 2017 pierre.peixoto
*/

#include <stdlib.h>
#include <stdio.h>

void		*my_realloc(void *ptr, const size_t size)
{
  size_t	i;
  char		*cpy;
  char		*result;

  if ((result = malloc(size)) == NULL)
    return (NULL);
  i = 0;
  cpy = ptr;
  while (i < size)
    {
      result[i] = cpy[i];
      ++i;
    }
  free (ptr);
  return (result);
}

int		main(void)
{
  short int	*intp;
  size_t	size;
  int		i;

  size = 5;
  intp = malloc(size * sizeof(short int));
  intp[0] = 1;
  intp[1] = 2;
  intp[2] = 4;
  intp[3] = 6;
  intp[4] = 9;
  for (i = 0; i < 5; i++)
    printf("b: %d\n", intp[i]);
  intp = my_realloc(intp, sizeof(short int) * 7);
  intp[5] = 11;
  intp[6] = 13;
  for (i = 0; i < 7; i++)
    printf("a: %d\n", intp[i]);
  free(intp);
  return 0;
}
