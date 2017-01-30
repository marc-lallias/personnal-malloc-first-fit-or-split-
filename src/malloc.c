/*
** my_malloc.c for  in /home/darkmark/rendu/PSU_2016_malloc
** 
** Made by DarKmarK
** Login   <marc.lallias@epitech.eu>
** 
** Started on  Tue Jan 24 12:08:28 2017 DarKmarK
** Last update Mon Jan 30 15:44:30 2017 DarKmarK
*/

#include "../header/malloc.h"

static t_meta_data		*start		= NULL;
static int			end		= 0;

t_meta_data	*alloc_block_end(t_meta_data *prev, size_t size)
{
  t_meta_data	*new;
  
  if ((new = sbrk(SIZE_META_DATA + size)) == (void *) -1)
    return (NULL);
  new->prev		= prev;
  new->next		= (int)new + SIZE_META_DATA + size;// !!! si ca pete c est ici
  new->size		= size;
  new->is_free		= false;
  if (prev != NULL)
      prev->next	= new;
  else
      start		= new;
  
  end = new->next;
  //printf("\n++++ new->next %d   %d\n\n", SIZE_META_DATA  + (int)new->next + size, sbrk(0));
  return (new);
}

t_meta_data	*found_space(size_t size)
{
  t_meta_data	*offset;

  offset = start; //Pour le premier
  while (offset != NULL && offset->next != end)//was offset->nedxt !=
    {
      if ((offset->is_free == true) &&
	  (offset->size >= size + SIZE_META_DATA))//avec les freee et la PAGE SIZE
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

  printf("XXXX offset->size %d\n", offset->size);
  //
  new			= (int)offset + size + SIZE_META_DATA;//POUR LES AUTRES LE CAST
  new->next		= offset->next;// !!! si ca pete c est ici
  new->size		= offset->size - size - SIZE_META_DATA;
  new->is_free		= true;
  new->prev		= offset;

  //
  printf("PENIS!!\n");// POURQUOI DES PB AVEC LE PREV qui fait chier  dans le while prev de concat
  offset->size		= size;
  offset->is_free	= false;
  offset->next		= new;
  printf("FRAGMENTATION%d -- %d\n");

  return (offset);
}

void		*my_malloc(size_t size)
{
  t_meta_data	*block;

  //write(1,"MALLOC\n", 7);
  block = found_space(size);
  if ((block == NULL) || (block->next == end))
    block = alloc_block_end(block, size);
  else
    fragmentat(block, size);
  if (block == NULL)
    return (NULL);
  return (block + 1);
}



void		concat_free_after(t_meta_data *meta)
{
  t_meta_data	*offset;

  offset	= meta;
  while ((offset->next != end) && (offset->next->is_free == true))
    {
      printf("XXXX");
      offset	= offset->next;
    }
  meta->size	= ((int)(offset->next) - (int)(meta)) - SIZE_META_DATA;//LE + 1 pour le 32
  meta->next	= offset->next;}


void		concat_free_before(t_meta_data *meta)
{
  
  t_meta_data	*offset;

  offset	= meta;
  printf("ICIadd prev %d\n", offset->prev);
  while ((offset->prev != 0) && (offset != start) && (offset->prev->is_free == true))
  {
    printf("YYYY\n");
    printf("add prev %d\n", offset->prev);
    offset	= offset->prev;
  }
  /*if (offset == start)
    {
      start	= offset; 
    }*/
  //meta->size = 99;
  printf("offset->next %d -- meta->next %d\n\n", offset->next, meta->next);
  if (offset != meta)
    {
      offset->size		= (int)meta->next - (int)(meta + 1);//LE + 1 pour le 32
      offset->next		= meta->next;
      offset->is_free		= true;
    }
}

void		concat_free(t_meta_data *meta)
{
  concat_free_after(meta);//check
  //concat_free_before(meta);//check dans concat_free_before()prev->next->next;

  return ;
}

void		my_free(void *ptr)
{
  t_meta_data	*meta;

  if (ptr == NULL)
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

void		show_alloc_mem(void)
{
  t_meta_data	*offset;
  int cast_add;

  
  printf("sizeof(t_meta_data) %d break %d page size %d\n", SIZE_META_DATA, sbrk(0), PAGE_SIZE);
  if (start == NULL)
    return;
  offset = start; //Pour le premier
  while ((offset != NULL) && (offset != end))
    {
      cast_add = offset;
      if (offset->next == NULL)
	printf("%d - %d : %d bytes   diff %d\n", offset, offset + offset->size + SIZE_META_DATA, 666);
	else
	  printf("%d - %d : %d bytes   free %d\n", offset, offset->next, offset->size, offset->is_free);
      offset = offset->next;
    }

  return ;
}


  /*int		next_page;
  int		cast_add;

  if (prev == NULL)
    printf("prev = NULL\n");
  if (prev != NULL && prev->next == NULL)
    printf("prev->next = NULL");
  printf("size comp %d  PAGE_SIZE %d\n", size + SIZE_META_DATA, PAGE_SIZE);
  if ((prev != NULL) )//&& ((size + SIZE_META_DATA) < PAGE_SIZE)
    {
      printf("XXXXXX\n");
      cast_add	= prev->next;
      next_page = cast_add - (cast_add % PAGE_SIZE);
      next_page += PAGE_SIZE;
      printf("futur address %d -- next page %d\n", cast_add + SIZE_META_DATA + size,
	     (cast_add + SIZE_META_DATA + size) % PAGE_SIZE, next_page);
      if ((cast_add + SIZE_META_DATA + size) > next_page)
	  {
	    printf("MANQUE pour atteindre next page%d\n", (next_page - cast_add) - 32);
	    prev = alloc_block_end(prev, (next_page - cast_add) - 32);
	    prev->is_free	= true;//APPELLER FREE PLUS TARD free(new);
	  }
    }*/
