/*
** my_malloc.c for  in /home/darkmark/rendu/PSU_2016_malloc
** 
** Made by DarKmarK
** Login   <marc.lallias@epitech.eu>
** 
** Started on  Tue Jan 24 12:08:28 2017 DarKmarK
** Last update Fri Feb  3 21:03:49 2017 Pierre Peixoto
*/

#include "../header/malloc.h"

// todo: Mettre des const pour empecher les copies mémoires

t_meta_data		*start		= NULL;
void			*end		= 0;

t_meta_data	*alloc_block_end(t_meta_data *prev, const size_t size)
{
  t_meta_data	*new;
  
  if ((new = sbrk(SIZE_META_DATA + size)) == (void *) -1)
    return (NULL);
  new->size		= size;
  new->is_free		= false;
  new->next		= (void *)((size_t)new + SIZE_META_DATA + size);
  if (start != NULL)
    {
      new->prev		= prev;
      prev->next	= (void*)new;
    }
  else
    {
      new->prev		= prev;
      start		= new;
    }

  end = new->next;
  
  return (new);
}

t_meta_data	*found_space(const size_t size)
{
  t_meta_data	*offset;

  offset = start;
  while (offset != NULL && offset->next != end)
    {
      if ((offset->is_free == true) &&
	  ((size_t)offset->size > ((size_t)size + (size_t)SIZE_META_DATA)))
	return (offset);
      offset = offset->next;
    }
  return (offset);
}

t_meta_data	*fragmentat(t_meta_data *offset, const size_t size)
{
  t_meta_data	*new;

  new			= (void *)((size_t)offset + size + SIZE_META_DATA);
  new->next		= offset->next;
  new->size		= (size_t)new->next - (size_t)(new) - SIZE_META_DATA;
  new->is_free		= true;
  new->prev		= offset;

  offset->size		= size;
  offset->is_free	= false;
  offset->next		= new;

  return (offset);
}

void		*malloc(size_t size)
{
  t_meta_data	*block;

  block = found_space(size);
  /* if ((block == NULL) || (block->next == end)) */
    block = alloc_block_end(block, size);
  /* else */
  /*   block = fragmentat(block, size); */
  if (block == NULL)
    return (NULL);
  return (block + 1);
}
