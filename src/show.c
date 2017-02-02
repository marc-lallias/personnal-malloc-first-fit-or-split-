/*
** show.c for  in /home/darkmark/rendu/PSU_2016_malloc
** 
** Made by DarKmarK
** Login   <marc.lallias@epitech.eu>
** 
** Started on  Sat Jan 28 21:22:06 2017 DarKmarK
** Last update Thu Feb  2 09:21:45 2017 DarKmarK
*/

#include "../header/malloc.h"

static int	my_putchar(const char c)
{
  return ((write(1, &c, 1) == 0) ? 0 : -1);
}

void		my_put_nbr_hexa(const size_t nb)
{
  char			hexa[16] = { '0', '1', '2', '3', '4', '5', '6',
				     '7', '8', '9', 'A', 'B', 'C', 'D',
				     'E', 'F' };

  if (nb / 16)
    my_put_nbr_hexa(nb / 16);
  if (my_putchar(hexa[nb % 16]) == -1)
    return;
}

void		my_put_nbr(const unsigned int nb)
{
  if (nb / 10)
    my_put_nbr(nb / 10);
  if (my_putchar(nb % 10 + 48) == -1)
    return;
}

void		show_alloc_mem(void)
{
  t_meta_data	*begin;
  size_t	addr;

  write(1, "break: ", 7);
  addr = (size_t)sbrk(0);
  my_put_nbr(addr);
  write(1, "   ", 3);
  write(1, "end: ", 5);
  addr = (size_t)(end);
  my_put_nbr(addr);
  write(1, "\n", 1);
  if (start == NULL)
    return ;
  begin = start;
  while (start != end)
    {
      addr = (size_t)start + SIZE_META_DATA;
      my_put_nbr(addr);
      write(1, " - ", 3);
      addr = (size_t)start->next;
      my_put_nbr(addr);
      write(1, " : ", 3);
      my_put_nbr(start->size);
      if (start->is_free == true)
	{
	write(1, " bytes", 6);
	write(1, " is free\n", 9);
	}
      else
	write(1, " bytes\n", 7);
      start = start->next;
    }
  start = begin;
}
