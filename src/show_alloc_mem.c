/*
** show_alloc_mem.c for  in /home/darkmark/rendu/PSU_2016_malloc
** 
** Made by DarKmarK
** Login   <marc.lallias@epitech.eu>
** 
** Started on  Tue Jan 31 10:21:25 2017 DarKmarK
** Last update Tue Jan 31 11:54:42 2017 DarKmarK
*/

#include "../header/malloc.h"

void		show_alloc_mem(void)
{
  t_meta_data	*offset;
  void		*cast_add;

  
  //printf("sizeof(t_meta_data) %d break %d page size %d\n", (int)SIZE_META_DATA, (int)sbrk(0), (int)PAGE_SIZE);
  if (start == NULL)
    return;
  offset = start; //Pour le premier
  while ((offset != NULL) && (offset != end))
    {
      cast_add = offset;
      /*
      if (offset->next == NULL)
	printf("%d - %d : %d bytes   diff %d\n", offset, offset + offset->size + SIZE_META_DATA, 666);
	else
      */
	  printf("%d - %d : %d bytes   free %d\n", offset, offset->next, offset->size, offset->is_free);
      offset = offset->next;
    }

  return ;
}
