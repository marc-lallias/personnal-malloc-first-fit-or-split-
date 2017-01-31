/*
** my_malloc.c for  in /home/darkmark/rendu/PSU_2016_malloc
** 
** Made by DarKmarK
** Login   <marc.lallias@epitech.eu>
** 
** Started on  Tue Jan 24 12:08:28 2017 DarKmarK
** Last update Tue Jan 31 10:19:34 2017 DarKmarK
*/

#include "../header/malloc.h"

// todo: Mettre des const pour empecher les copies mémoires

//t_meta_data		*start		= NULL;
//void			*end		= 0;

t_meta_data	*alloc_block_end(t_meta_data *prev, size_t size)
{
  t_meta_data	*new;
  
  if ((new = sbrk(SIZE_META_DATA + size)) == (void *) -1)
    return (NULL);
  new->prev		= prev;
  new->next		= new + SIZE_META_DATA + size;// !!! si ca pete c est ici
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

  //printf("XXXX offset->size %d\n", (int)offset->size);
  //
  new			= offset + size + SIZE_META_DATA;//POUR LES AUTRES LE CAST
  new->next		= offset->next;// !!! si ca pete c est ici
  new->size		= offset->size - size - SIZE_META_DATA;
  new->is_free		= true;
  new->prev		= offset;

  //
  //printf("PENIS!!\n");// POURQUOI DES PB AVEC LE PREV qui fait chier  dans le while prev de concat
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
    fragmentat(block, size);
  if (block == NULL)
    return (NULL);
  return (block + 1);
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
