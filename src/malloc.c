/*
** my_malloc.c for  in /home/darkmark/rendu/PSU_2016_malloc
** 
** Made by DarKmarK
** Login   <marc.lallias@epitech.eu>
** 
** Started on  Tue Jan 24 12:08:28 2017 DarKmarK
** Last update Wed Feb  8 10:02:10 2017 pierre.peixoto
*/

#include "../header/malloc.h"

// todo: Mettre des const pour empecher les copies mémoires

t_meta_data		*start		= NULL;
//void			*end		= 0;
pthread_mutex_t		mutex = PTHREAD_MUTEX_INITIALIZER;

t_meta_data	*alloc_block_end(t_meta_data *prev, const size_t size)
{
  t_meta_data	*new;
  unsigned int 	to_alloc;

  to_alloc = ((size + SIZE_META_DATA) / PAGE_SIZE) + 1;
  to_alloc = to_alloc * PAGE_SIZE;
  if ((new = sbrk(to_alloc)) == (void *) -1)//size
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

t_meta_data	*fragmentat(t_meta_data *offset, const size_t size)
{
  t_meta_data	*new;

  /* my_put_str("fragmentat\n"); */
  /* my_put_nbr(offset->size); */
  /* write(1, "\n", 1); */
  
  if (offset->size > (size + SIZE_META_DATA))
    {
      new = (void *)offset + size + SIZE_META_DATA;//check cast
      
      /* my_put_str("PAS SEG\n"); */
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
      /* if (offset->prev != NULL) */
      /* 	offset->prev->next = offset; */
  //offset->prev;
  
  
  /* t_meta_data	*new; */

  /* new			= (void *)((size_t)offset + size + SIZE_META_DATA); */
  /* new->next		= offset->next; */
  /* new->size		= (size_t)new->next - (size_t)(new) - SIZE_META_DATA; */
  /* new->is_free		= true; */
  /* new->prev		= offset; */

  /* offset->size		= size; */
  /* offset->is_free	= false; */
  /* offset->next		= new; */

  /* return (offset); */
}

void		*malloc(size_t size)
{
  t_meta_data	*block;

  /* my_put_str("MALLOC\n"); */
  if (size <= 0)
    return (NULL);
  pthread_mutex_lock(&mutex);
  block = found_space(size);
  if (block == NULL || (block->is_free == false) || (block->size < size))//la 2 ?
    {
      /* my_put_str("issou\n"); */
      block = alloc_block_end(block, size);
    }
  if (block == NULL)
    return (NULL);
  block = fragmentat(block, size);
  pthread_mutex_unlock(&mutex);
  return (block + 1);
  /* write(1, "\n+", 2); */
  /* size = align4(size); */
  /* my_put_nbr(size); */
  /* write(1, "-\n", 2); */
  /* my_put_nbr(SIZE_META_DATA); */
  /* write(1, "\n", 1); */
  /* block = found_space(size); */
  /* if ((block == NULL) || (block->next == end)) */
  /*   block = alloc_block_end(block, size); */
  /* //else */
  /* block = fragmentat(block, size); */
  /* if (block == NULL) */
  /*   return (NULL); */
  /* return (block + 1); */
}
