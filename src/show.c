/*
** show.c for  in /home/darkmark/rendu/PSU_2016_malloc
** 
** Made by DarKmarK
** Login   <marc.lallias@epitech.eu>
** 
** Started on  Sat Jan 28 21:22:06 2017 DarKmarK
** Last update Tue Jan 31 14:10:39 2017 pierre.peixoto
*/

void		show_alloc_mem(void)
{
  t_meta_data	*begin;

  if (start == NULL)
    return ;
  printf("break: %p\n", end);
  begin = start;
  while (start != NULL)
    {
      printf("%p - %p : %d bytes\n", start + SIZE_META_DATA, start + SIZE_META_DATA + start->size);
      start = start->next;
    }
  start = begin;
}
