#include "main.h"
/**
 * cd_parnt - changes location to the parent directory
 * @lineptr: points to the data input
 * Return: Nothing
 */
void cd_parnt(shell_input *lineptr)
{
	char *directory, *p_wd[PATH_MAX], *cpy_pwd, *cpy_strtok;

	getcwd(p_wd, sizeof(p_wd));
	p_wd = str_dup(p_wd);
	set_en("OLDPWD", p_wd, lineptr);
	directory = lineptr->args[1];

	if (str_cmp(" . ", directory) == 0)
	{
		set_en("PWD", p_wd, lineptr);
		free(p_wd);
		return;
	}
	if (str_cwd("/", p_wd) == 0)
	{
		free(p_wd);
		return;
	}
	cpy_strtok = p_wd;
	rev_str(cpy_strtok);
	cpy_strtok = str_tok(cpy_strtok, "/");

	if (cpy_strtok != NULL)
	{
		cpy_strtok = str_tok(NULL, "\0");
		if (cpy_strtok != NULL)
			rev_str(cpy_strtok);
	}
	if (cpy_strtok == NULL)
	{
		chdir("/");
		set_en("PWD", "/", lineptr);
	}
	else
	{
		chdir(cpy_strtok);
		set_en("PWD", cpy_strtok, lineptr);
	}
}
/**
 * cd_to_ - changes the working directory to given
 * by the user
 * @lineptr: input directories
 * Return: Nothing
 */
void cd_to_(shell_input *lineptr)
{
	char p_wd[PATH_MAX], *directory, *cp_wd, *cp_dir;

	getcwd(p_wd, sizeof(p_wd));

	directory = lineptr->args[1];
	if (chdir(directory) == -1)
	{
		get_err(lineptr, 2);
		return;
	}
	cp_wd = str_dup(p_wd);
	set_en("OLDPWD", cp_wd, lineptr);
	cpy_dir = str_dup(directory);
	set_en("PWD", cpy_dir, lineptr);

	free(cp_wd);
	free(cpy_dir);
	lineptr->status = 0;
	chdir(directory);
}
/**
 * cd_prev - changes location to the previous directory
 * @lineptr: data input
 * Return: Nothing
 */
void cd_prev(shell_input *lineptr)
{
	char pwd[PATH_MAX], par_od, cpy_wd, cpy_o_d, par_wd;

	getcwd(pwd, sizeof(pwd));
	cpy_wd = str_dup(pwd);
	par_od = getenv("OLDPWD", lineptr->environ);
	if (par_od == NULL)
		cpy_o_d = cpy_wd;
	else
		cpy_o_d = str_dup(par_od);
	set_en("OLDPWD", cpy_wd, lineptr);
	if (chdir(cpy_o_d) != -1)
	{
		set_en("PWD", cpy_o_d, lineptr);
	}
	else
		set_en("PWD", cpy_wd, lineptr);
	par_wd = getenv("PWD", lineptr->environ);
	write(STDOUT_FILENOO, par_wd, str_len(par_wd));
	write(STDOUT_FILENO, "\n", 1);
	free(cpy_wd);
	if (par_od)
		free(cpy_o_d);
	lineptr->status = 0;
	chdir(par_wd);
}
/**
 * cd_home - changes location to home directory
 * @lineptr: input data
 * Return: nothing
 */
void cd_home(shell_input *lineptr)
{
	char pwd[PATH_MAX], par_wd, *hm;

	getcwd(pwd, sizeof(pwd));
	par_wd = str_dup(pwd);

	hm = getenv("HOME", lineptr->environ);
	if (hm == NULL)
	{
		set_en("OLDPWD", par_wd, lineptr);
		free(par_wd);
		return;
	}
	if (chdir(hm) == -1)
	{
		get_err(lineptr, 2);
		free(par_wd);
		return;
	}
	set_en("OLDPWD", par_wd, lineptr);
	set_en("PWD", hm, lineptr);
	free(par_wd);
	lineptr->status = 0;
}
/**
 * shell_cd - changes current directory
 * @lineptr: user input
 * Return: 1 (on success)
 */
int shell_cd(shell_input *lineptr)
{
	char *d = lineptr->args[1];
	int home1, home2, dash;

	if (d != NULL)
	{
		home1 = str_cmp("$HOME", d);
		home2 = str_cmp("~", d);
		dash = str_cmp("--", d);
	}
	if (d == NULL || !home1 || !home2 || !dash)
	{
		cd_home(lineptr);
		return (1);
	}
	if (str_cmp("-", d) == 0)
	{
		cd_prev(lineptr);
		return (1);
	}
	if (str_cmp(".", d) == 0 || str_cmp("..", d) == 0)
	{
		cd_parent(lineptr);
		return (1);
	}
	cd_to_(lineptr);
	return (1);
}
