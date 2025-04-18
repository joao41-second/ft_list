/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:20:32 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/14 22:31:41 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "../ft_free/ft_free.h"
# include <stdio.h>

/**
 * @brief create new node int the linst 
 *
 * @param n variabel or stuct add in list
 * @return node the lists alocde 
 */
t_list_	*ft_node_new(void *n);

void ft_add_node(void *node,t_list_ **list);

/**
 * @brief defines an already initialized node int the list 
 *
 * @param lst the adres the end node to list 
 * @param new node the add in end the list  
 */
void	ft_node_add_front(t_list_ **lst, t_list_ *new);

/**
 * @brief set  the list in the start node 
 *
 * @param list in random node 
 * @return list in start node 
 */
t_list_	*ft_node_start(t_list_ *list);

/**
 * @brief set the list in end node 
 *
 * @param list  in random node 
 * @return list int end node 
 */
t_list_	*ft_node_end(t_list_ *list);

/**

	* @brief print the content the list 
	* depending the extrenal funcion specifically for 
 *		the type the list used exple int char sturct expecifc 
 *
 * @param list in the pointer start  
 * @param print funcion expecifc for type the list 
 */
void	print_list(t_list_ *list, void (*print)(void *));

/**
 * @brief return int represent the number the nodes the list 
 *
 * @param list int start node  
 * @return int number nodes the list
 */
int		ft_list_size(t_list_ *list);

/**
 * @brief free in all list 
 *
 * @param list 
 * @param free_struct funcion specifically free type the node the list 
 */
void	free_list(t_list_ *list, void (*free_struct)(void *));

/**

* @brief scroll through the list unit you find the 
 * something the is returnde for funcion locate_node
 *
 * @param list 
 * @param loc past variabel int the funcio locate_node
 * @param locate_node funcion thetrmin end the loop for list  
 */
void	*get_list(t_list_ *list, void *loc, void *(*locate_node)(void *,
				void *));

/**
 * @brief this funcion frees in sent node 
 * @param list in node to free;
 * @param free_struct 
 */
void	ft_free_node(t_list_ **list, void (*free_struct)(void *));

/**
 * @brief not suppossed to use 
 *
 * @param pointer 
 * @param index 
 */
void	*get_index(void *pointer, void *index);

/**
 * @brief get the node corresponding to int index
 *
 * @param list get 
 * @param index number 
 * @return 
 */
t_list_	*get_list_index(t_list_ *list, int index);

void	ft_add_node_list(t_list_ **list, void *content);
#endif
