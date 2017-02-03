/*
** free.c for  in /home/darkmark/rendu/PSU_2016_malloc
** 
** Made by DarKmarK
** Login   <marc.lallias@epitech.eu>
** 
** Started on  Sat Jan 28 21:22:09 2017 DarKmarK
** Last update Fri Feb  3 21:09:19 2017 Pierre Peixoto
*/

#include "../header/malloc.h"

t_meta_data    	*concat_free_before(t_meta_data *meta)
{
  
  t_meta_data	*offset;

  offset = meta;
  if (offset != start && offset->prev->is_free == true)
    {
      offset = offset->prev;
      offset->size		+= meta->size + SIZE_META_DATA;
      offset->next       	= meta->next;
      if (meta->next != end)
	meta->next->prev = offset;
    }
  return (offset);
}

void		concat_free_after(t_meta_data *meta)
{
  if (meta->next != end && meta->next->is_free == true)
    concat_free_before(meta->next);
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
  while ((void *)offset != end)
    {
      if (offset + 1 == ptr)
	{
	  return (true);
	}
      offset = offset->next;
    }
  return (false);
}

void		free(void *ptr)
{
  t_meta_data	*meta;

  if (ptr == NULL || start == NULL)
    return ;
  /* if (test_pointer(ptr) == false) */
  /*   return ; */
  meta = ptr;
  meta = meta - 1;
  meta->is_free	= true;
  /* meta = concat_free(meta); */
  /* if (meta->next == end) */
  /*   { */
  /*     if (meta != start) */
  /* 	{ */
  /* 	  end = meta; */
  /* 	  brk((void *)meta); */
  /* 	} */
  /*     else */
  /* 	{ */
  /* 	  brk(start); */
  /* 	  end = 0; */
  /* 	  start = NULL; */
  /* 	} */
  /*   } */
}
