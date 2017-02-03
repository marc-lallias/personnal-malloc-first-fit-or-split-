/*
** free.c for  in /home/darkmark/rendu/PSU_2016_malloc
** 
** Made by DarKmarK
** Login   <marc.lallias@epitech.eu>
** 
** Started on  Sat Jan 28 21:22:09 2017 DarKmarK
** Last update Fri Feb  3 15:48:04 2017 DarKmarK
*/

#include "../header/malloc.h"

void		concat_free_after(t_meta_data *meta)
{
  t_meta_data	*offset;

  offset	= meta;
  while ((offset->next != end) && (offset->next->is_free == true))
    offset	= offset->next;
  if (offset != meta)
    {
      meta->size	= ((size_t)(offset->next) - (size_t)(meta)) - (size_t)SIZE_META_DATA;//PROBLEM
      meta->next	= offset;
    }
}


t_meta_data    	*concat_free_before(t_meta_data *meta)
{
  
  t_meta_data	*offset;

  offset = meta;
  /* //write(1, "YYYY\n", 5); */
  /* if (offset == start) */
  /*   return (meta); */
  /* /\* show_alloc_mem(); *\/ */
  /* my_put_nbr(meta->next); */
  /* write(1, "\n", 1); */
  while ((offset != start) && (offset->prev != 0) && (offset->prev->is_free == true))//uninis=zialis
    {
      write(1, "YYYY\n", 5);
      offset = offset->prev;//OFFSET->PREV = LUI MEME
    }
  /* if (offset == start) */
  /*   { */
  /*   } */
  //meta->size = 99;
  //printf("offset->next %d -- meta->next %d\n\n", offset->next, meta->next);
  if (offset != meta)
    {
      //      my_put_nbr(offset);
      write(1, "\n", 1);
      offset->size		= (size_t)meta->next - (size_t)(offset);//PROBLEM
      offset->size		= offset->size - (size_t)SIZE_META_DATA;
      write(1, "XXXX", 4);
      my_put_nbr(offset->size);
      write(1, "\n", 1);
      //offset->size = 5;
      //offset->size = 100;
      offset->next       	= meta->next;
    }
  return (offset);
}

t_meta_data    	*concat_free(t_meta_data *meta)
{
  //concat_free_after(meta);//check
    return (concat_free_before(meta));//check dans concat_free_before()prev->next->next;
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
  if (test_pointer(ptr) == false)
    {
      //show_alloc_mem();
      write(1, "\nTTTT\n", 6);
      /* my_put_nbr((size_t)ptr); */
      /* write(1, "\n", 1); */
      /* write(1, "\n", 1); */
      /* my_put_nbr((size_t)end); */
      /* write(1, "\n", 1); */
      /* write(1, "\n", 1); */
      /* my_put_nbr((size_t)start); */
      /* write(1, "\n", 1); */
      /* my_put_nbr((size_t)start->next); */
      /* write(1, "\n", 1); */
      /* write(1, "\n", 1); */
      
      return ;
    }
  meta = ptr;
  meta = meta - 1;
  meta->is_free	= true;
  meta = concat_free(meta);
  if ((void *)meta->next == end)//
    {
      write(1, "OOOO\n", 5);
      while ((meta != start) && (meta->prev != 0) && (meta->prev->is_free == true))//jump
  	{
  	  meta = meta->prev;
  	}
      if (meta != start)
	{
	  end = (void *)meta;
	  //write(1, "AAAA\n", 5);
	  //brk((void *)meta);
	}
      else
  	{
	  brk(start);
  	  //end = (void *)meta;
	  //write(1, "BBBB\n", 5);
	  end = 0;
  	  start = NULL;
  	}
      
      return ;
    }
  //write(1, "AAAA\n", 5);
  //meta->is_free = true;//PROBLEME
  //write(1, "CCCC\n", 5);
}
