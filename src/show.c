/*
** show.c for  in /home/darkmark/rendu/PSU_2016_malloc
** 
** Made by DarKmarK
** Login   <marc.lallias@epitech.eu>
** 
** Started on  Sat Jan 28 21:22:06 2017 DarKmarK
** Last update Sun Feb 12 12:37:29 2017 DarKmarK
*/

#include "../header/malloc.h"

static int	my_putchar(const char c)
{
  return ((write(1, &c, 1) == 0) ? 0 : -1);
}

int		my_put_str(const char *str)
{
  int		i;

  i = 0;
  while (str[i])
    ++i;
  return ((write(1, str, i) == 0) ? 0 : -1);
}

static void		my_put_nbr_addr(const size_t nb)
{
  char			hexa[16] = { '0', '1', '2', '3', '4', '5', '6',
				     '7', '8', '9', 'a', 'b', 'c', 'd',
				     'e', 'f' };

  if (nb / 16)
    my_put_nbr_addr(nb / 16);
  if (my_putchar(hexa[nb % 16]) == -1)
    return;
}

static void		my_put_nbr_hexa(const size_t nb)
{
  my_put_str("0x");
  my_put_nbr_addr(nb);
}

void			my_put_nbr(const unsigned int nb)
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

  my_put_str("break: ");
  addr = (size_t)sbrk(0);
  my_put_nbr_hexa(addr);
  my_put_str("\n");
  if (start == NULL)
    return ;
  begin = start;
  while (start != NULL)
    {
      addr = (size_t)start + SIZE_META_DATA;
      my_put_nbr_hexa(addr);
      my_put_str(" - ");
      if (start->next == NULL)
	addr = (size_t)start + SIZE_META_DATA + start->size;
      else
	addr = (size_t)start->next;
      my_put_nbr_hexa(addr);
      my_put_str(" : ");
      my_put_nbr(start->size);
      my_put_str(" bytes\n");
      start = start->next;
    }
  start = begin;
}
