/*
** show.c for  in /home/darkmark/rendu/PSU_2016_malloc
** 
** Made by DarKmarK
** Login   <marc.lallias@epitech.eu>
** 
** Started on  Sat Jan 28 21:22:06 2017 DarKmarK
** Last update Tue Jan 31 16:43:13 2017 pierre.peixoto
*/

#include "../header/malloc.h"

static int	my_putchar(const char c)
{
  return ((write(1, &c, 1) == 0) ? 0 : -1);
}

void			my_put_nbr_hexa(const unsigned int nb)
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

  if (start == NULL)
    return ;
  write(1, "break: ", 7);
  my_put_nbr((unsigned int)end);
  write(1, "\n", 1);
  begin = start;
  while (start != end)
    {
      my_put_nbr((unsigned int)(start + SIZE_META_DATA));
      write(1, " - ", 3);
      my_put_nbr((unsigned int)(start->next));
      write(1, " : ", 3);
      my_put_nbr(start->size);
      write(1, " bytes\n", 7);
      start = start->next;
    }
  start = begin;
}
