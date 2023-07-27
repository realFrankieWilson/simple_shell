#include "main.h"

/**
<<<<<<< HEAD
 * add_rvar_node -> adds a variable at the end
=======
 * add_rvar_node - adds a variable at the end
>>>>>>> update
 * of a r_var list.
 * @head: head of the linked list.
 * @lvar: length of the variable.
 * @val: value of the variable.
 * @lval: length of the value
 *
 * Return: address of the head.
 */

r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval)
{
<<<<<<< HEAD
	r_var *temp;

	r_var *new = malloc(sizeof(r_var));

=======
	r_var *new, *temp;

	new = malloc(sizeof(r_var));
>>>>>>> update
	if (new == NULL)
		return (NULL);

	new->len_var = lvar;
	new->val = val;
	new->len_val = lval;


	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
<<<<<<< HEAD

	else

=======
	else
>>>>>>> update
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
<<<<<<< HEAD
 * free_rvar_list -> frees a r_var list
=======
 * free_rvar_list - frees a r_var list
>>>>>>> update
 * @head: head of the linked list
 *
 * Return: no return.
 */

void free_rvar_list(r_var **head)
{
<<<<<<< HEAD
	r_var *temp, *curr;
=======
	r_var *temp;
	r_var *curr;
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

