/*
** show_alloc_mem.c for  in /home/darkmark/rendu/PSU_2016_malloc
** 
** Made by DarKmarK
** Login   <marc.lallias@epitech.eu>
** 
** Started on  Tue Jan 31 10:21:25 2017 DarKmarK
** Last update Tue Jan 31 11:08:58 2017 pierre.peixoto
*/

#include "../header/malloc.h"

static int	my_putchar(const char c)
{
  return ((write(1, &c, 1) == 0) ? 0 : -1);
}

static int	my_put_nbr(const int nb)
{
  if (nb < 0)
    {
      if (write(1, "-", 1) == -1)
	return (-1);
      nb = nb * -1;
    }
  if (nb / 10)
    my_put_nbr(nb / 10);
  my_putchar((nb % 10) + 48);
  return (0);
}

void		show_alloc_mem(void)
{
  t_meta_data	*begin;

  begin = start;
  if (start == NULL)
    return;
  printf("break: %p\n", end);
  while (start != NULL)
    {
      printf("%p - %p : %d bytes\n", start + SIZE_META_DATA, start + SIZE_META_DATA + start->size,
	     (int)start->size);
      start = start->next;
    }
  start = begin;
}
