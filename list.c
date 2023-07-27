#include "main.h"

/**
 * add_sep_node_end - adds a separator found at the end
 * of a sep_list.
 * @head: head of the linked list.
 * @sep: separator found (; | &)
 *
 * Return: address of the head.
 */
sep_list *add_sep_node_end(sep_list **head, char sep)
{
	sep_list *new, *temp;

	new = malloc(sizeof(sep_list));
	if (new == NULL)
		return (NULL);

	new->separator = sep;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}



/**
<<<<<<< HEAD
 * free_sep_list -> frees a sep_list
=======
 * free_sep_list - frees a sep_list
>>>>>>> update
 * @head: head of the linked list.
 *
 * Return: no return.
 */

void free_sep_list(sep_list **head)
{
	sep_list *temp;
	sep_list *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}



/**
<<<<<<< HEAD
 * add_line_node_end -> adds a command line at the end
 * of a line_list.
 * @head: head of the linked list.
 * @line: command line
 *
=======
 * add_line_node_end - adds a command line at the end
 * of a line_list.
 * @head: head of the linked list.
 * @line: command line.
>>>>>>> update
 * Return: address of the head.
 */

line_list *add_line_node_end(line_list **head, char *line)
{
<<<<<<< HEAD
	line_list *temp;

	line_list *new = malloc(sizeof(line_list));

=======
	line_list *new, *temp;

	new = malloc(sizeof(line_list));
>>>>>>> update
	if (new == NULL)
		return (NULL);

	new->line = line;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
<<<<<<< HEAD

=======
>>>>>>> update
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}



/**
 * free_line_list - frees a line_list
 * @head: head of the linked list.
 * Return: no return.
 */

void free_line_list(line_list **head)
{
<<<<<<< HEAD
	line_list *temp, *curr;
=======
	line_list *temp;
	line_list *curr;
>>>>>>> update

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}
