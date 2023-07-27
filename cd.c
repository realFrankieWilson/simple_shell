#include "main.h"

/**
 * cd_dot -> changes to the parent directory
 * @lineptr: data relevant (environ)
 *
 * Return: no return
 */

void cd_dot(shell_input *lineptr)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_strtok_pwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = str_dup(pwd);
	set_env("OLDPWD", cp_pwd, lineptr);
	dir = lineptr->args[1];
	if (str_cmp(".", dir) == 0)
	{
		set_env("PWD", cp_pwd, lineptr);
		free(cp_pwd);
		return;
	}
	if (str_cmp("/", cp_pwd) == 0)
	{
		free(cp_pwd);
		return;
	}
	cp_strtok_pwd = cp_pwd;
	rev_string(cp_strtok_pwd);
	cp_strtok_pwd = strtok(cp_strtok_pwd, "/");
	if (cp_strtok_pwd != NULL)
	{
		cp_strtok_pwd = strtok(NULL, "\0");

		if (cp_strtok_pwd != NULL)
			rev_string(cp_strtok_pwd);
	}
	if (cp_strtok_pwd != NULL)
	{
		chdir(cp_strtok_pwd);
		set_env("PWD", cp_strtok_pwd, lineptr);
	}
	else
	{
		chdir("/");
		set_env("PWD", "/", lineptr);
	}
	lineptr->status = 0;
	free(cp_pwd);
}



/**
 * cd_to - changes to a directory given
 * by the user
 * @lineptr: data relevant (directories)
 *
 * Return: no return
 */


void cd_to(shell_input *lineptr)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_dir;

	getcwd(pwd, sizeof(pwd));
	dir = lineptr->args[1];
	if (chdir(dir) != -1)
	{
		cp_pwd = str_dup(pwd);
		set_env("OLDPWD", cp_pwd, lineptr);

		cp_dir = str_dup(dir);
		set_env("PWD", cp_dir, lineptr);

		free(cp_pwd);
		free(cp_dir);

		lineptr->status = 0;
		chdir(dir);
	}
	else
	{
		get_error(lineptr, 2);
		return;
	}
}



/**
 * cd_previous - changes to the previous directory
 * @lineptr: data relevant (environ)
 *
 * Return: Nothing
 */

void cd_previous(shell_input *lineptr)
{
	char pwd[PATH_MAX];
	char *p_pwd, *p_oldpwd, *cp_pwd, *cp_oldpwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = str_dup(pwd);

	p_oldpwd = _getenv("OLDPWD", lineptr->_environ);

	if (p_oldpwd == NULL)
		cp_oldpwd = cp_pwd;
	else
		cp_oldpwd = str_dup(p_oldpwd);

	set_env("OLDPWD", cp_pwd, lineptr);

	if (chdir(cp_oldpwd) != -1)
		set_env("PWD", cp_oldpwd, lineptr);
	else
		set_env("PWD", cp_pwd, lineptr);


	p_pwd = _getenv("PWD", lineptr->_environ);

	write(STDOUT_FILENO, p_pwd, str_len(p_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_pwd);
	if (p_oldpwd)
		free(cp_oldpwd);

	lineptr->status = 0;
	chdir(p_pwd);
}



/**
 * cd_to_home -> changes to home directory
 * @lineptr: data relevant (environ)
 *
 * Return: Nothing.
 */
void cd_to_home(shell_input *lineptr)
{
	char *p_pwd, *home;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	p_pwd = str_dup(pwd);
	home = _getenv("HOME", lineptr->_environ);

	if (home == NULL)
	{
		set_env("OLDPWD", p_pwd, lineptr);
		free(p_pwd);
		return;
	}

	if (chdir(home) == -1)
	{
		get_error(lineptr, 2);
		free(p_pwd);
		return;
	}

	set_env("OLDPWD", p_pwd, lineptr);
	set_env("PWD", home, lineptr);
	free(p_pwd);
	lineptr->status = 0;
}
