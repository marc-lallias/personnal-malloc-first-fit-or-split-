/*
** free.c for  in /home/darkmark/rendu/PSU_2016_malloc
** 
** Made by DarKmarK
** Login   <marc.lallias@epitech.eu>
** 
** Started on  Sat Jan 28 21:22:09 2017 DarKmarK
** Last update Wed Feb  8 10:53:42 2017 DarKmarK
*/

#include "../header/malloc.h"

void		concat_free_after(t_meta_data *meta)
{
  if ((meta->next == NULL) || (meta->next->is_free == false) || (meta->next->page_begin == true))
    return ;
  meta->size = meta->size + meta->next->size + SIZE_META_DATA;
  if (meta->next->next != NULL)
    meta->next->next->prev = meta;
  meta->next = meta->next->next;
  /* my_put_str("''''''''''''''''CONCAT_FREE_AFTER\n"); */

  return ;
}

t_meta_data    	*concat_free_before(t_meta_data *meta)//
{
  t_meta_data	*prev;

  if ((meta->prev == NULL) || (meta->prev->is_free == false) || (meta->page_begin == true)
      || ((meta->prev->page_begin == true) && (meta->page_begin == true)))
    return (meta);
  prev = meta->prev;
  if (meta->next != NULL)
    meta->next->prev = prev;
  prev->size = prev->size + meta->size + SIZE_META_DATA;
  prev->next = meta->next;
  
  /* meta->prev = meta->prev->prev; */
  /* meta->prev->size = meta->prev->size + meta->size +  SIZE_META_DATA; */
  /* meta->prev->next = meta->next;//segv */
  
  return (meta->prev);
}

t_meta_data    	*concat_free(t_meta_data *meta)
{
  concat_free_after(meta);
  return (concat_free_before(meta));
}

bool		test_pointer(void *ptr)
{
  t_meta_data	*offset;

  offset = start;
  while (offset)
    {
      if (offset + 1 == ptr)
	return (true);
      offset = offset->next;
    }
  return (false);
}

void		free(void *ptr)//fire un check pointeur
{
  t_meta_data	*meta;

  if ((ptr == NULL) || (test_pointer(ptr) == false))
    return ;
  /* my_put_str("free\n"); */
  pthread_mutex_lock(&mutex);
  meta = ptr;
  meta = meta - 1;
  meta->is_free = true;
  meta = concat_free(meta);
  /* if (meta == NULL) */
  /*   my_put_str("META EST EGALE A NULL\n"); */
  /* if (meta->page_begin == true) */
  /*   my_put_str("--TRUE\n"); */
  /* else */
  /*   my_put_str("++FALSE\n"); */
  if ((meta->page_begin == true) && (meta->next == NULL))
    {
      /* my_put_str("MOVE BRK\n"); */
      if (meta->prev == NULL)
      	start = NULL;
      else
  	meta->prev->next = NULL;
      brk(meta);
      /*if (brk(meta) == (void *) -1)
	return ;*/
    }
  pthread_mutex_unlock(&mutex);
  return ;
}
