/*
** free.c for  in /home/darkmark/rendu/PSU_2016_malloc
** 
** Made by DarKmarK
** Login   <marc.lallias@epitech.eu>
** 
** Started on  Sat Jan 28 21:22:09 2017 DarKmarK
** Last update Tue Jan 31 16:48:50 2017 pierre.peixoto
*/

#include "../header/malloc.h"

void		concat_free_after(t_meta_data *meta)
{
  t_meta_data	*offset;

  offset	= meta;
  while ((offset->next != end) && (offset->next->is_free == true))
    {
      //printf("XXXX");
      offset	= offset->next;
    }
  meta->size	= ((size_t)(offset->next) - (size_t)(meta)) - SIZE_META_DATA;//LE + 1 pour le 32
  meta->next	= offset->next;}


void		concat_free_before(t_meta_data *meta)
{
  
  t_meta_data	*offset;

  offset	= meta;
  //printf("ICIadd prev %d\n", offset->prev);
  while ((offset->prev != 0) && (offset != start) && (offset->prev->is_free == true))
  {
    //printf("YYYY\n");
    //printf("add prev %d\n", offset->prev);
    offset	= offset->prev;
  }
  /*if (offset == start)
    {
      start	= offset; 
    }*/
  //meta->size = 99;
  //printf("offset->next %d -- meta->next %d\n\n", offset->next, meta->next);
  if (offset != meta)
    {
      offset->size		= (size_t)meta->next - (size_t)(meta + 1);//LE + 1 pour le 32
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
  if (meta->next == end)
    {
      while ((meta->prev != 0) && (meta->prev->is_free == true))
	{
	  meta = meta->prev;
	}
      //brk(meta->prev);     //LE FAIRE
      if (meta != start)
	{
	  //brk(meta->prev->next);//   POURQUOI---------------------------------+++++++++
	  end = meta->prev->next;
	}
      else
	{
	  //brk(start);
	  start = NULL;
	  end = 0;
	}
      return ;
    }
  concat_free(meta);
  meta->is_free = true;
}
