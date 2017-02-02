/*
** free.c for  in /home/darkmark/rendu/PSU_2016_malloc
** 
** Made by DarKmarK
** Login   <marc.lallias@epitech.eu>
** 
** Started on  Sat Jan 28 21:22:09 2017 DarKmarK
** Last update Thu Feb  2 10:05:48 2017 DarKmarK
*/

#include "../header/malloc.h"

void		concat_free_after(t_meta_data *meta)
{
  t_meta_data	*offset;

  offset	= meta;
  while ((offset->next != end) && (offset->next->is_free == true))
    offset	= offset->next;
  meta->size	= ((size_t)(offset->next) - (size_t)(meta)) - (size_t)SIZE_META_DATA;//PROBLEM
  meta->next	= offset->next;
}


void		concat_free_before(t_meta_data *meta)
{
  
  t_meta_data	*offset;

  offset	= meta;
  while ((offset->prev != 0) && (offset != start) && (offset->prev->is_free == true))
    offset	= offset->prev;
  /*if (offset == start)
    {
    start	= offset; 
    }*/
  //meta->size = 99;
  //printf("offset->next %d -- meta->next %d\n\n", offset->next, meta->next);
  if (offset != meta)
    {
      offset->size		= (size_t)meta->next - (size_t)(offset + 1);//PROBLEM
      offset->next		= meta->next;
      offset->is_free		= true;
    }
}

void		concat_free(t_meta_data *meta)
{
  concat_free_after(meta);//check
  concat_free_before(meta);//check dans concat_free_before()prev->next->next;

  return ;
}

void		free(void *ptr)
{
  t_meta_data	*meta;

  if (ptr == NULL || start == NULL)
    return ;
  meta = ptr;
  meta = meta - 1;
  if (meta->next == end)//
    {
      while ((meta->prev != 0) && (meta->prev->is_free == true))
  	{
  	  meta = meta->prev;
  	}
      if (meta != start)
	{
	  end = meta;
	  //write(1, "AAAA\n", 5);
	  brk(meta);
	}
      else
  	{
	  brk(meta);
  	  start = NULL;
  	  end = 0;
  	}
      return ;
    }
  //concat_free(meta);
  //write(1, "AAAA\n", 5);
  meta->is_free = true;//PROBLEME
  //write(1, "CCCC\n", 5);
}
