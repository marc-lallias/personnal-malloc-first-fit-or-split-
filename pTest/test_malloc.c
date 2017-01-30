/*
** test_malloc.c for test_malloc in /home/peixot_a/Documents/pierre.peixoto@epitech.eu/perso/PSU_malloc
** 
** Made by pierre.peixoto
** Login   <pierre.peixoto@epitech.eu>
** 
** Started on  Wed Jan 25 11:33:48 2017 pierre.peixoto
** Last update Fri Jan 27 13:25:22 2017 pierre.peixoto
*/

#include "test_malloc.h"

t_mdata	*b_data;

void		*allocate_new_data(size_t size)
{
  t_mdata	*new_node;
  void		*new_addr;

  if ((new_node = sbrk(0)) == (void *)-1)
    return (NULL);
  if (sbrk(sizeof(t_mdata)) == (void *)-1)
    return (NULL);
  new_node->addr = sbrk(0) + 1;
  new_node->size = size;
  new_node->is_used = true;
  new_node->next = b_data;
  b_data = new_node;
  if (sbrk(size) == (void *)-1)
    return (NULL);
  return (new_node->addr);
}

void		test_free(void *ptr)
{
  t_mdata	*begin;
  int		pos;

  begin = b_data;
  pos = 0;
  while (b_data != NULL && b_data->addr != ptr)
    {
      b_data = b_data->next;
      ++pos;
    }
  if (b_data == NULL)
    b_data = begin;
  else if (pos == 0)
    {
      if (sbrk((b_data->size * -1)) == (void *)-1)
	return;
      b_data = b_data->next;
    }
  else
    {
      b_data->is_used = false;
      b_data = begin;
    }
  return;
}

void		*check_in_free_data(size_t size)
{
  t_mdata	*begin;
  size_t	min_size;
  t_mdata	*best_opt;

  best_opt = NULL;
  min_size = -1;
  while (b_data != NULL)
    {
      if (b_data->size >= size || b_data->size < min_size || min_size == -1)
	{
	  min_size = b_data->size;
	  best_opt = b_data;
	}
      b_data = b_data->next;
    }
  b_data = begin;
  if (best_opt == NULL)
    return (allocate_new_data(size));
  else
    return (best_opt->addr);
}

void		*test_malloc(size_t size)
{
  struct rlimit	limits;

  getrlimit(RLIMIT_STACK, &limits);
  if (size > (unsigned int)limits.rlim_max)
    return (NULL);
  else if (b_data == NULL)
    return (allocate_new_data(size));
  else
    return (check_in_free_data(size));
}
