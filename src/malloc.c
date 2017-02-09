/*
** my_malloc.c for  in /home/darkmark/rendu/PSU_2016_malloc
** 
** Made by DarKmarK
** Login   <marc.lallias@epitech.eu>
** 
** Started on  Tue Jan 24 12:08:28 2017 DarKmarK
** Last update Thu Feb  9 12:14:12 2017 pierre.peixoto
*/

#include "../header/malloc.h"

t_meta_data	*start = NULL;
pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;

t_meta_data	*alloc_block_end(t_meta_data *prev, const size_t size)
{
  t_meta_data	*new;
  unsigned int 	to_alloc;

  to_alloc = ((size + SIZE_META_DATA) / PAGE_SIZE) + 1;
  to_alloc = to_alloc * PAGE_SIZE;
  if ((new = sbrk(to_alloc)) == (void *) -1)
    return (NULL);
  new->page_begin = true;
  new->size = to_alloc - SIZE_META_DATA;
  new->next = NULL;
  new->prev = prev;
  new->is_free = true;
  if (prev != NULL)
    {
      new->prev = prev;
      prev->next = new;
    }
  if (start == NULL)
    start = new;
  return (new);
}

t_meta_data	*found_space(const size_t size)
{
  t_meta_data	*offset;

  offset = start;
  while ((offset != NULL) && (offset->next != NULL))
    {
      if (((offset->size > size + SIZE_META_DATA) || (offset->size == size))
	  && (offset->is_free == true))
	return (offset);
      offset = offset->next;
    }
  return (offset);
}

void		fragmentat(t_meta_data *offset, const size_t size)
{
  t_meta_data	*new;
  
  if (offset->size > (size + SIZE_META_DATA))
    {
      new = (void *)offset + size + SIZE_META_DATA;
      new->size =  offset->size - size - SIZE_META_DATA;
      new->is_free = true;
      new->prev = offset;
      new->next = offset->next;
      new->page_begin = false;
      if (offset->next != NULL)
      	offset->next->prev = new;
      offset->size = size;
      offset->next = new;
    }
  offset->is_free = false;
}

void		*malloc(size_t size)
{
  t_meta_data	*block;

  if (size < 0)
    return (NULL);
  pthread_mutex_lock(&mutex);
  block = found_space(size);
  if (block == NULL || (block->is_free == false) || (block->size < size))
    block = alloc_block_end(block, size);
  if (block == NULL)
    return (NULL);
  fragmentat(block, size);
  pthread_mutex_unlock(&mutex);
  return (block + 1);
}
