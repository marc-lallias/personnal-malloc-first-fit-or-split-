/*
** malloc.h for  in /home/darkmark/rendu/PSU_2016_malloc
** 
** Made by DarKmarK
** Login   <marc.lallias@epitech.eu>
** 
** Started on  Tue Jan 24 18:41:24 2017 DarKmarK
** Last update Tue Jan 31 09:28:36 2017 DarKmarK
*/

#ifndef MALLOC_H
# define MALLOC_H

#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>

#define SIZE_META_DATA	sizeof(struct s_meta_data)//faire static passetr au puissance de 4ateur
#define PAGE_SIZE	getpagesize()//faire static passetr au puissance de 4ateur

/*
** Structures
*/
typedef struct __attribute__((__packed__))	s_meta_data
{
  struct s_meta_data				*next;
  struct s_meta_data				*prev;
  size_t					size;
  bool						is_free;
}						t_meta_data;

/*
** Static globals
*/
static t_meta_data	*start = NULL;
static void		*end = 0;

/*
 * MALLOC
 */
void		*malloc(size_t size);

/*
 * FREE
 */
void		free(void *ptr);

/*
 * TOOLS
 */
void		show_alloc_mem(void);

#endif
