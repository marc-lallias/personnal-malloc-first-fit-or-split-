/*
** my_malloc.c for  in /home/darkmark/rendu/PSU_2016_malloc
** 
** Made by DarKmarK
** Login   <marc.lallias@epitech.eu>
** 
** Started on  Tue Jan 24 12:08:28 2017 DarKmarK
** Last update Tue Jan 31 16:57:02 2017 pierre.peixoto
*/

#include "../header/malloc.h"

// todo: Mettre des const pour empecher les copies mémoires

t_meta_data		*start		= NULL;
void			*end		= 0;

t_meta_data	*alloc_block_end(t_meta_data *prev, size_t size)
{
  t_meta_data	*new;
  
  if ((new = sbrk(SIZE_META_DATA + size)) == (void *) -1)
    return (NULL);
  new->prev		= prev;
  new->next		= (unsigned int)new + (unsigned int)SIZE_META_DATA + (unsigned int)size;
  new->size		= size;
  new->is_free		= false;
  if (prev != NULL)
      prev->next	= new;
  else
      start		= new;

  end = new->next;
  
  return (new);
}

t_meta_data	*found_space(size_t size)
{
  t_meta_data	*offset;

  offset = start; //Pour le premier
  while (offset != NULL && offset->next != end)
    {
      if ((offset->is_free == true) &&
	  (offset->size >= size + SIZE_META_DATA))
  	{

  	  return (offset);
  	}
      offset = offset->next;
    }

  return (offset);
}


t_meta_data	*fragmentat(t_meta_data *offset, size_t size)
{
  t_meta_data	*new;

  //
  new			= offset + size + SIZE_META_DATA;
  new->next		= offset->next;
  new->size		= offset->size - size - SIZE_META_DATA;
  new->is_free		= true;
  new->prev		= offset;

  //
  offset->size		= size;
  offset->is_free	= false;
  offset->next		= new;

  return (offset);
}

void		*malloc(size_t size)
{
  t_meta_data	*block;

  //write(1,"MALLOC\n", 7);
  block = found_space(size);
  if ((block == NULL) || (block->next == end))
    block = alloc_block_end(block, size);
  else
    block = fragmentat(block, size);
  if (block == NULL)
    return (NULL);
  return (block + 1);
}
