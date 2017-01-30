/*
** malloc.h for  in /home/darkmark/rendu/PSU_2016_malloc
** 
** Made by DarKmarK
** Login   <marc.lallias@epitech.eu>
** 
** Started on  Tue Jan 24 18:41:24 2017 DarKmarK
** Last update Mon Jan 30 00:11:58 2017 DarKmarK
*/

#ifndef MALLOC_H
# define MALLOC_H

#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>

#define SIZE_META_DATA	sizeof(struct s_meta_data)//faire static passetr au puissance de 4ateur
#define PAGE_SIZE	getpagesize()//faire static passetr au puissance de 4ateur

typedef struct		s_meta_data
{
  size_t       		size;
  bool			is_free;
  struct s_meta_data	*next;
  struct s_meta_data	*prev;
}			t_meta_data;

/*
 * FREE
 */
void		my_free(void *ptr);

/*
 * TOOLS
 */
void		show_alloc_mem(void);

/*
 * MALLOC
 */
//fragmentation
t_meta_data	*alloc_block_end(t_meta_data *prev, size_t size);
t_meta_data	*go_next(t_meta_data *block);
t_meta_data	*found_space(size_t size);
void		*alloc(t_meta_data *block, size_t size);
void		*my_malloc(size_t size);

#endif
