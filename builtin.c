/**
*_ourexit: action to exits the shell
*@info: arguments used in maintain the function prototype
*return: this will exit with a given status
* return(0) if info.argv[0]!= “exit”
*/
Int _ourexit(info_i*info)
{
	Int exitcheck;
If {info->argv[1])
/* if any exit argument is present*/
 {
	Info->status = 2;
	Print_error(info, “invalid entry: ”);
	_fputs(info->argv[1]);
	If (exitcheck == -1)
	}
	     Info-> status = 2;
	     Print_error(info, “invalid entry: ”);
	     _fputs(info->argv{1});
	     _fputschar(“\n”);
	     Return (1);
	}
}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}
/**
 * _ourcd - changes the current directory of the process
 * @info: this structure contains argument used to maintain
 *  constant function prototype.
 *  Return: Always 0
 */
int _ourcd(info_i *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TASK: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir) {
			chdir_ret = /* TASK: what would you call this? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		return;
	}
                    //do this instead
	}
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TASK: what would you call this? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _ourhelp - changes the current directory of the process
 * @info: this Structure contains arguments used to maintain
 *  function prototype.
 *  Return: Always 0
 */
int _ourhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("assistance call. Function not yet implemented \n");
	else if (0)

		_puts(*arg_array); 
/* temp att_unused workaround */
	return (0);
}

