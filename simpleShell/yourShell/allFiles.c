#include "shell.h"

/* ................................NUM 1 START..............................*/
/**
 * string_reverse - Reverses a string
 * @s: string to reverse
 *
 * Return: Nothing
 */
void string_reverse(char *s)
{
        int x = 0, y = 0, z;
        char tempVar = 'A';

        while (s[x])
                x++;
        z = x / 2, x = x - 1;
        while (x >= z)
        {
                string_reverseSub(s, tempVar, x, y);
        }
}

/* ................................NUM 1 BTW................................*/
/**
 * string_reverse - Reverses a string
 * @s: string to reverse
 *
 * Return: Nothing
 */
void string_reverseSub(char *s, char tempVar, int x, int y)
{
        tempVar  = s[y];
        s[y] = s[x];
        s[x] = tempVar;
        x--, y++;
}
/* ................................NUM 1 END................................*/

/* ................................NUM 3 START..............................*/
/* ................................NUM 3 BTW................................*/
/* ................................NUM 3 END................................*/
/**
 * blen - obtains length of number in base
 *
 * @n: number
 * @base: base of number
 *
 * Return: length of number
 */
int blen(unsigned long int n, unsigned long int base)
{
        unsigned long int x, negNum = 0, ret;

        for (x = 0; n > 0; x++)
                n = n / base;
        ret = x + negNum;
        return (ret);
}
/**
 * _itoa - converts an integer to string
 *
 * @n: number
 *
 * Return: pointer to string
 */
char *_itoa(int n)
{
        unsigned long int x = 0, base = 10;
        char *str;

        if (n != 0)
                str = malloc(blen(n, base) + 1);
        else
                str = malloc(2), str[x] = '0', x++;

        if (str == 0)
                return (0);

        for (; n > 0; x++)
        {
                str[x] = (n % base) + '0';
                n = n / base;
        }
        str[x] = '\0';
        string_reverse(str);
        return (str);
}

char *_error2(int errn, char *conc2, char *option);
/**
 * _error - creates a string with error line
 * @errn: number corresponding to type of error
 * @shpack: struct containing shell information
 * @exnum: value of exit the shell should have
 *
 * Return: 0 success, -1 fail
 */
int _error(int errn, hshpack *shpack, int exnum)
{
        /**
         * 0 - file or cmd not found , 1 - permission denied, 2 - illegal exit number
         * 3 - setenv error,         , 4 - can´t cd         , 5 - invalid option cd
         * 6 - help _error           , 7 - memory allocation, 8 - Alias Error
         **/
        int count = shpack->errnum[0], z = 0;
        char *cmd = shpack->cmd, **option = shpack->options;
        char *shelln = shpack->hshname;
        char *nstring, *conc1, *conc2, *colspace = ": ";
        char *err[] = {
                "not found", "Permission denied", "Illegal number",
                "name is NULL, points to string of len 0, or has an '=' char.",
                "can't cd to ", "Illegal option ", "Help command error",
                "Error allocating memory", "Wrong Alias",
                NULL
        };

        conc1 = str_concat(shelln, colspace);
        if (!conc1) /*hsh: */
                return (write(2, "Memory Error", 22), -1);

        if (errn == 7) /* Alloc Error */
        {
                conc2 = str_concat(conc1, err[errn]); /*hsh: count: error*/
                if (!conc2)
                        return (free(conc1), write(2, "Memory Error", 22), -1);
                free(conc1);
                while (conc2[z] != 0)
                        z++;
                write(2, conc2, z), write(2, "\n", 1);
                free(conc2);
                return (0);

        }

        nstring = _itoa(count);
        if (!nstring)  /* number to string */
                return (free(conc1), write(2, "Memory Error", 22), -1);

        conc2 = str_concat(conc1, nstring);
        if (!conc2) /*hsh: count*/
        {
                write(2, "Memory Error", 22);
                return (free(conc1), free(nstring),  -1);
        }
        free(conc1), free(nstring);

        conc1 = str_concat(conc2, colspace);
        if (!conc1) /*hsh: count: */
                return (free(conc2), write(2, "Memory Error", 22), -1);

        free(conc2);
        conc2 = str_concat(conc1, cmd);
        if (!conc2) /*hsh: count: cmd*/
                return (free(conc1), write(2, "Memory Error", 22), -1);
        free(conc1);

        conc1 = str_concat(conc2, colspace);
        if (!conc1) /*hsh: count: cmd: */
                return (free(conc2), write(2, "Memory Error", 22), -1);
        free(conc2);

        conc2 = str_concat(conc1, err[errn]);
        if (!conc2) /*hsh: count: cmd: error*/
                return (free(conc1), write(2, "Memory Error", 22), -1);
        free(conc1);

        if (errn > 1 && errn < 6 && errn != 3)
                conc2 = _error2(errn, conc2, option[1]);
        if (conc2 == NULL)
        {
                write(2, "Memory Error", 22);
                return (-1);
        }

        while (conc2[z] != 0)
                z++;
        write(2, conc2, z), write(2, "\n", 1);
        free(conc2);
        shpack->exitnum[0] = exnum;
        return (0);

}
/**
 * _error2 - extra modes for error generation
 * @errn: number corresponding to type of error
 * @conc2: error part from _error
 * @option: cmd option thaat
 *
 * Return: pointer to string
 */
char *_error2(int errn, char *conc2, char *option)
{
        /**
         * 0 - file or cmd not found , 1 - permission denied, 2 - illegal exit number
         * 3 - setenv error,         , 4 - can´t cd         , 5 - invalid option cd
         * 6 - help _error           , 7 - memory allocation, 8 - Alias Error
         **/
        char *conc1, *colspace = ": ";

        if (errn == 2) /* exit error */
        {

                conc1 = str_concat(conc2, colspace);
                if (!conc1) /*hsh: count: cmd: error: */
                {
                        write(2, "Memory Error", 22);
                        return (free(conc2), NULL);
                }
                free(conc2);

                conc2 = str_concat(conc1, option);

                if (!conc2) /*hsh: count: cmd: error: option*/
                {
                        write(2, "Memory Error", 22);
                        return (free(conc1), NULL);
                }
                free(conc1);
        }
        if (errn > 3) /* Errors with options at end */
        {
                conc1 = str_concat(conc2, option);
                if (!conc1) /*hsh: count: cmd: error option*/
                {
                        write(2, "Memory Error", 22);
                        return (free(conc2), NULL);
                }
                free(conc2);
                return (conc1);
        }
        return (conc2);

}


/**
 * _exit_cmd - built in command exit
 * @shpack: struct containing shell info
 *
 * Return: -1 if error
 */
ssize_t _exit_cmd(hshpack *shpack)
{
        long valueToExit;

        if (shpack->options[1] == NULL || _isnumber(shpack->options[1]))
        {
                valueToExit = _atoi(shpack->options[1]);

                if (valueToExit >= 0 && valueToExit < INT_MAX)
                {
                        if (valueToExit > 255)
                                valueToExit %= 256;
                        if (shpack->options[1] == NULL)
                                valueToExit = shpack->exitnum[0];
                        free(*(shpack->options));
                        free(shpack->options);
                        if (*(shpack->envCpy))
                                free_doubpoint(*(shpack->envCpy));
                        free(shpack);
                        exit(valueToExit);
                }
        }

        _error(2, shpack, 2);
        free(shpack->options);
        return (-1);
}
/**
 * _env_cmd - built in command env
 * @shpack: struct containing shell info
 *
 * Return: 1 if succesful
 */
ssize_t _env_cmd(hshpack *shpack)
{
        char **str;
        int checker = 1;

        if (*(shpack->envCpy) == NULL)
        {
                write(2, "Environment is Null, Can't Print it\n", 36);
                shpack->exitnum[0] = 2;
                free(shpack->options);
                return (-1);
        }

        str = *(shpack->envCpy);

        if (shpack->options[1] == NULL)
        {
                for (; str && *str; str++)
                {
                        write(1, *str, _strlen(*str));
                        write(1, "\nfol1", 4);
                }
        }
        else
        {
                _error(0, shpack, 2);
                checker = -1;
        }

        free(shpack->options);
        return (checker);
}
/**
 * _setenv_cmd - built in command setenv
 * @shpack: struct containing shell info
 *
 * Return: 1 if succesful, -1 if fail
 */
ssize_t _setenv_cmd(hshpack *shpack)
{
        char **newenv;
        char *variable = NULL;
        char *value = NULL;

        if (shpack->options[1])
        {
                variable = shpack->options[1];
                if (!shpack->options[2])
                {
                        write(2, "Invalid VALUE\n", 14);
                        shpack->exitnum[0] = 2;
                        free(shpack->options);
                        return (-1);
                }
                else
                        value = shpack->options[2];

        }
        if (variable == 0)
        {
                write(2, "Invalid VARIABLE\n", 17);
                shpack->exitnum[0] = 2;
                free(shpack->options);
                return (-1);
        }

        newenv = _setenv(*(shpack->envCpy), variable, value, shpack);

        if (newenv == 0)
        {
                free(shpack->options);
                return (-1);
        }

        *(shpack->envCpy) = newenv;
        free(shpack->options);
        return (1);
}
/**
 * _unsetenv_cmd - built in command unsetenv
 * @shpack: struct containing shell info
 *
 * Return: 1 if succesful, -1 if fail
 */
ssize_t _unsetenv_cmd(hshpack *shpack)
{
        char **newenv;
        char *variable = NULL;

        if (shpack->options[1])
                variable = shpack->options[1];
        else
        {
                shpack->exitnum[0] = 2;
                write(2, "Please provide an argument\n", 27);
                return (free(shpack->options), -1);
        }

        if (variable == 0)
        {
                free(shpack->options);
                return (1);
        }

        newenv = _unsetenv(*(shpack->envCpy), variable, shpack);

        if (newenv == 0 && shpack->unsetnull[0] == 0)
        {
                free(shpack->options);
                shpack->exitnum[0] = 2;
                return (-1);
        }

        *(shpack->envCpy) = newenv;
        free(shpack->options);
        return (1);
}

/**
 * built_ints - checks if cmd is a built in
 * @shpack: struct containing shell info
 *
 * Return: On fail 0
 */
ssize_t built_ints(hshpack *shpack)
{
        b_ins ops[] = {
                {"exit", _exit_cmd},
                {"env", _env_cmd},
                {"setenv", _setenv_cmd},
                {"unsetenv", _unsetenv_cmd},
                {"cd", _cd_cmd},
                {"help", _help_cmd}
        };

        int x = 6, builtcheck; /* lenght of ops array */

        while (x--)
                if (!_strcmp(shpack->cmd, ops[x].cmd))
                {
                        shpack->errnum[0] += 1;
                        builtcheck = ops[x].f(shpack);
                        if (builtcheck == 1)
                                shpack->exitnum[0] = 0;
                        return (builtcheck);
                }

        return (0);
}


/**
 * auxcd2 - auxiliary function of cd built in
 * @shpack: struct containing shell info
 * @currdir: current directory
 *
 * Return: pointer to HOME or NULL if fail
 */
char *auxcd2(hshpack *shpack, char *currdir)
{
        char *home, *dir = NULL;

        (void) currdir;
        home = _getenv("HOME", *(shpack->envCpy));
        if (home)
                dir = home + 5;

        return (dir);
}

/**
 * auxcd - auxiliary function of cd built in
 * @shpack: struct containing shell info
 * @currdir: the current directory
 *
 * Return: Pointer to dir or NULL if fail
 */
char *auxcd(hshpack *shpack, char *currdir)
{
        char *oldpwd2 = NULL, *oldpwd = NULL, *dir = NULL;

        if (shpack->options[1] && shpack->options[2])
        {
                write(2, "cd: too many arguments\n", 23);
                shpack->exitnum[0] = 2;
                free(shpack->options);
                free(currdir);
                return (dir);
        }

        oldpwd2 = _strdup(_getenv("OLDPWD", *(shpack->envCpy)));
        if (oldpwd2)
                oldpwd = _strdup(oldpwd2 + 7), free(oldpwd2);
        if (!oldpwd2)
        {
                oldpwd = _strdup(currdir);
                /* free(oldpwd), free(shpack->options), free(currdir); */
                /* return (shpack->exitnum[0] = 2, NULL); */
        }

        dir = oldpwd;

        return (dir);
}

/**
 * _cd_cmd - built in command cd
 * @shpack: struct containing shell info
 *
 * Return: 1 if succesful, -1 if fail
 */
ssize_t _cd_cmd(hshpack *shpack)
{
        char *currdir = NULL, *dir = NULL, **newenv, *oldpwd = NULL;
        int exit = 1, checker = 1, checkerminus = 0;

        currdir = getcwd(NULL, 4096);
        if (!currdir)
                return (_error(4, shpack, 2), free(shpack->options), -1);
        if (!shpack->options[1] ||
                        (shpack->options[1] && (!_strcmp(shpack->options[1], "~"))))
        {
                dir = auxcd2(shpack, currdir);
                if (!dir)
                        return (free(shpack->options), free(currdir), 1);
        }
        else
                if (!_strcmp(shpack->options[1], "-"))
                {
                        dir = auxcd(shpack, currdir);
                        if (!dir)
                                return (free(shpack->options), free(currdir), 1);
                        checkerminus = 1;
                }
                else
                        dir = shpack->options[1];
        if (dir)
                checker = chdir(dir);
        if (checker == 0 && checkerminus == 1)
                write(1, dir, _strlen(dir)), write(1, "\n", 1);
        if (checker != 0)
                _error(4, shpack, 2), exit = -1;
        else
        {
                newenv = _setenv(*(shpack->envCpy), "PWD", dir, shpack);
                *(shpack->envCpy) = newenv;
                newenv = _setenv(*(shpack->envCpy), "OLDPWD", currdir, shpack);
                *(shpack->envCpy) = newenv;
        }
        free(shpack->options), free(currdir), free(oldpwd);
        if (checkerminus == 1)
                free(dir);
        return (exit);
}


/**
 * _pow - gets the result of base to ower
 * @base: base decimal
 * @pot: power
 *
 * Return: result
 */
long _pow(long base, long pot)
{
        long x = 0;
        long res = 1;

        for (x = 0; x < pot; x++)
                res *= base;

        return (res);
}

/**
 * _atoi - convert a char input to int
 * @s: char input
 *
 *
 * Return: input transformed to integer
 * On error: -1 inapropiate entry
 */

long _atoi(char *s)
{
        long x = 0;
        long k = 0;
        long len = 0;
        unsigned long result = 0;
        long toReturn = 0;
        long minus = 0;
        long offset = 48;

        if (!s)
                return (0);

        for (x = 0; *(s + x) != '\0'; x++)
        {
                if (*(s + x) >= 48 && *(s + x) <= 57)
                        len++;
                else if (len != 0)
                        break;

                if (*(s + x) == '-')
                        minus++;
        }

        for (x--; len > 0; x--, k++, len--)
                result +=  (*(s + x) - offset) * _pow(10, k);

        toReturn = (minus % 2 != 0) ? result * (-1) : result;

        return (toReturn);
}
/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 0 if strings are equal or another value if not
 *
 */
int _strcmp(char *s1, char *s2)
{
        int x = 0;
        int equal = 0;

        for (x = 0; (*(s1 + x) || *(s2 + x)) && !equal; x++)
                if (*(s1 + x) != *(s2 + x))
                        equal = *(s1 + x) - *(s2 + x);

        return (equal);
}
/**
 * _isdigit - checks if a character is a digit
 * @c: character
 *
 * Return: 1 if digit, 0 if not
 *
 */
int _isdigit(int c)
{
        return ((c >= 48 && c <= 57) ? 1 : 0);
}
/**
 * _isnumber - checks if a string is composed of numbers
 * @s: string
 *
 * Return: 1 if string has only numbers, 0 if not
 */
int _isnumber(char *s)
{
        for (; *s; s++)
                if (!_isdigit(*s))
                        return (0);
        return (1);
}


/**
 * checkInput - checks for input in after shell prompt
 * @ac: count of main arguments
 * @av: main arguments
 * @bufsize: size of buffer in prompt
 * @buffer: buffer in prompt
 * @shpack: struct of shell info
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
char **checkInput(int ac, char **av, size_t *bufsize,
                   char **buffer, hshpack *shpack)
{
        ssize_t characters;
        char **command;
        int exitnum;

        if (ac == 1)
        {
                if (isatty(STDIN_FILENO))
                        write(1, "$ ", 2);
                characters = getline(buffer, bufsize, stdin);

                if (characters == -1)
                {
                        exitnum = shpack->exitnum[0];
                        free(*buffer);
                        if (*(shpack->envCpy))
                                free_doubpoint(*(shpack->envCpy));
                        free(shpack);
                        if (isatty(STDIN_FILENO))
                                write(1, "\n", 1);
                        exit(exitnum);
                }
                if (**buffer == '#' || !characters || **buffer == '\n')
                        return (NULL);
                *buffer = deleteComment(*buffer);
                command = getParameters(*buffer, shpack);
        }
        else
        {
                command = malloc(sizeof(char *) * (ac - 1));
                if (!command)
                {
                        _error(7, shpack, 1);
                        return (NULL);
                }

                command[ac - 1] = '\0';
                while (ac--)
                        command[ac - 1] = av[ac];
        }
        return (command);
}

/**
 * deleteComment - deletes a commnet inside a command line
 *
 * @str: string to operate
 *
 * Return: pointer to string
 *
 */
char *deleteComment(char *str)
{
        char *org = str;

        for (; str && *str; str++)
                if (*str == '#' && *(str - 1) == ' ')
                {
                        *str = '\0';
                        break;
                }

        return (org);
}



/**
 * executeCmd - creates a child process to execute a cmd
 *
 * @program: command that will be executed
 * @command: arguments of command
 * @env: current environment
 * @shpack: struct with shell information
 *
 * Return: pointer to the value in the environment,
 * or NULL if there is no match
 *
 */
int executeCmd(char *program, char *command[], char **env, hshpack *shpack)
{
        pid_t process, status;
        int execveSts = 0, waitSts = 0;

        process = fork();
        signal(SIGINT, signal_handler2);
        if (process == -1)
        {
                write(2, "Fork Error", 10);
                exit(-1);
        }
        if (process == 0)
        {

                execveSts = execve(program, command, env);
                if (execveSts == -1)
                {
                        _exit(-1);
                }
        }
        else
        {
                waitSts = wait(&status);
                signal(SIGINT, signal_handler);
                if (waitSts == -1)
                        exit(-1);
                if (WEXITSTATUS(status) == 0)
                        shpack->exitnum[0] = 0;
                else
                        shpack->exitnum[0] = 2;
        }

        shpack->errnum[0] += 1;
        return (0);
}


/**
 * _getenv - gets an environment variable
 *
 * @name: name of environmental variable
 * @env: current environment
 *
 * Return: pointer to the value in the environment,
 * or NULL if there is no match
 *
 */
char *_getenv(const char *name, char **env)
{
        int x, y, check, z = 0;

        if (!env)
                return (NULL);

        while (name[z] != 0)
                z++;

        for (x = 0; env[x] != 0; x++)
        {
                for (check = 0, y = 0; y < z && env[x][y] != 0; y++)
                        if (env[x][y] == name[y])
                                check++;
                if (check == z && env[x][check] == '=')
                        return (env[x]);
        }

        return (NULL);
}


#define BSIZE 4
/**
 * _memset - fills memory with constant byte
 * @s: memory area
 * @b: constant byte b
 * @n: first n bytes of memory area pointed by s
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
char *_memset(char *s, char b, unsigned int n)
{
        unsigned int x;

        for (x = 0; x < n; x++)
                s[x] = b;
        return (s);
}
/**
 * _memcpy - copies memory
 * @dest: destination
 * @src: source
 * @n: size of memory to copy
 *
 * Return: Returns memory copied
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
        unsigned int x;

        for (x = 0; x < n; x++)
                dest[x] = src[x];
        return (dest);
}
/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to modify
 * @old_size: current size of memory
 * @new_size: size memory will now have
 *
 * Return: Pointer to reallocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
        void *ptr2;

        if (old_size == new_size)
                return (ptr);

        if (ptr == NULL)
        {
                ptr2 = malloc(new_size);
                if (ptr2 == 0)
                        return (0);
                free(ptr);
                return (ptr2);
        }

        if (new_size == 0 && ptr != NULL)
        {
                free(ptr);
                return (0);
        }

        ptr2 = malloc(new_size);

        if (ptr2 == 0)
                return (0);

        ptr2 = _memset(ptr2, '\0', new_size);

        _memcpy(ptr2, ptr, old_size);
        free(ptr);
        return (ptr2);
}
/**
 * _getline - read a string or a line from an input stream
 * @buffer: pointer to a space where the stdin read will be saved
 * as a string
 * @bufsize: current size of buffer (must be given as 0 initially)
 * @fd: stream to read
 *
 * Return: Number of Characters Read
 */
int _getline(char **buffer, size_t *bufsize, int fd)
{
        static char *buff;
        static size_t size;
        unsigned int len = 0, x = 0, sizeold;
        int r;

        if (*bufsize == 0)
                size = BSIZE;
        if (*buffer == 0)
        {
                buff = malloc(sizeof(char) * size);
                if (!buff)
                        return (write(2, "Memory Error", 22), 0);
                *buffer = buff;
        }
        buff = _memset(buff, '\0', size);
        do {

                r = read(fd, buff + len, BSIZE);
                if (r >= 0)
                        x = len, len += r;
                if (r == -1 || r == 0)
                        return (-1);
                if  (len >= size)
                {
                        sizeold = size, size += BSIZE;
                        buff = _realloc(buff, sizeold, size);
                        if (!buff)
                                return (write(2, "Memory Error", 22), 0);
                }
                for (; x < len; x++)
                {
                        if (buff[x] == '\n')
                        {
                                *buffer = buff, *bufsize = size;
                                return (len);
                        }
                }

        } while (1);
        return (len);
}

/**
 * getParameters - obtains parameters from buffer of prompt
 * @raw_buffer: raw_buffer
 * @shpack: struct containing shell info
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
char **getParameters(char *raw_buffer, hshpack *shpack)
{
        char **buffer, *cp_raw_buffer;
        ssize_t cnt = 0, i = 0;

        cp_raw_buffer = _strdup(raw_buffer);
        if (!cp_raw_buffer)
        {
                _error(7, shpack, 1);
                exit(-1);
        }

        if (_strtok(cp_raw_buffer, " \n"))
                cnt++;
        else
        {
                free(cp_raw_buffer);
                return (NULL);
        }
        while (_strtok(NULL, " \n"))
                cnt++;

        free(cp_raw_buffer);
        buffer = malloc(sizeof(char *) * (cnt + 1));
        if (!buffer)
        {
                _error(7, shpack, 1);
                exit(-1);
        }
        buffer[0] = _strtok(raw_buffer, " \n");
        for (i = 1; i < cnt && buffer[i - 1]; i++)
                buffer[i] = _strtok(NULL, " \n");

        if (!buffer[i - 1])
        {
                free_doubpoint(buffer);
                return (NULL);
        }

        buffer[i] = NULL;
        return (buffer);
}


/**
 * _pathcheck - check if current dir must be added
 * @path: path env variable
 *
 * Return: Pointer to adress of new PATH
 *
 */

char *_pathcheck(char *path)
{
        char *npath;
        int x, y, nsize, count = 0;

        for (x = 0; path[x]; x++)
        {

                if (path[x] == '=' && path[x + 1] == ':')
                        count++;
                if (path[x] == ':' && path[x + 1] == ':')
                        count++;
                if (path[x] == ':' && path[x + 1] == '\0')
                        count++;
        }
        if (count == 0)
                return (0);
        nsize = _strlen(path) + 1 + count;
        npath = malloc(sizeof(char) * nsize);

        for (x = 0, y = 0; x < nsize; x++, y++)
        {
                if (path[y] == '=' && path[y + 1] == ':')
                {
                        npath[x] = path[y], npath[x + 1] = '.', x++;
                        continue;
                }
                if (path[y] == ':' && path[y + 1] == ':')
                {
                        npath[x] = path[y], npath[x + 1] = '.', x++;
                        continue;
                }
                if (path[y] == ':' && path[y + 1] == '\0')
                {
                        npath[x] = path[y], npath[x + 1] = '.', x++;
                        continue;
                }
                npath[x] = path[y];
        }
        free(path);
        return (npath);
}
/**
 * _path - Searches for a cmd in PATH
 * @cmd: string contating env variable PATH
 * @env: current environment
 * @shpack: struct containing shell info
 *
 * Return: Pointer to adress of cmd in PATH or by itself
 *
 */

char *_path(char *cmd, char **env, hshpack *shpack)
{
        char *path, *path2;
        struct stat st;
        char *token, *concat, *concat2, *pathcheck, *delim = ":=";
        int x;

        for (x = 0; cmd[x]; x++)
                if (cmd[x] == '/')
                {
                        if (stat(cmd, &st) == 0)
                                return (concat = str_concat(cmd, '\0'));
                        else
                                return (0);
                }

        path2 = _getenv("PATH", env);
        (void) shpack;
        if (!path2)
                return (0);
        path = _strdup(path2);
        pathcheck = _pathcheck(path);
        if (pathcheck)
                path = pathcheck;
        token = _strtok(path, delim);
        for (token = _strtok(0, delim); token; token = _strtok(0, delim))
        {
                concat = str_concat(token, "/");
                concat2 = str_concat(concat, cmd);
                free(concat);
                if (stat(concat2, &st) == 0)
                {
                        /*Found the command in PATH*/
                        free(path);
                        return (concat2);
                }
                free(concat2);
        }

        free(path);
        return (0);
}



/**
 * _puts - prints string to std output
 * @s: string (must be NULL terminated)
 *
 * Return: No Return
 */
void _puts(char *s)
{
        write(1, s, _strlen(s));
}
/**
 * help_exit - prints help of exit built in
 *
 * Return: No Return
 */
void help_exit(void)
{
        _puts("exit: exit [n]\n");
        _puts("    Exit the shell.\n\n");
        _puts("    Exits the shell with a status of N.  ");
        _puts("    If N is omitted, the exit status\n");
        _puts("    is that of the last command executed.\n");
}
/**
 * help_env - prints help of env built in
 *
 * Return: No Return
 */
void help_env(void)
{
        _puts("env: env\n");
        _puts("    prints the current environment.\n\n");
        _puts("    Has no options\n");
}
/**
 * help_setenv - prints help of setenv built in
 *
 * Return: No Return
 */
void help_setenv(void)
{
        _puts("setenv: setenv [VARIABLE] [VALUE]\n");
        _puts("    Initializes a new environment variable, ");
        _puts("    or modifies an existing one.\n\n");
        _puts("    VARIABLE must not have the character '='.\n");
        _puts("    If no arguments are given, setenv prints ");
        _puts("    the current environment.\n");
}


/**
 * _help_cmd - help of built in commands
 * @shpack: struct containing shell info
 *
 * Return: 1 if succesful, -1 if fail
 */
ssize_t _help_cmd(hshpack *shpack)
{
        int check = 1, bcheck = 0;
        helps help[] = {
                {"exit", help_exit},
                {"env", help_env},
                {"setenv", help_setenv},
                {"unsetenv", help_unsetenv},
                {"cd", help_cd},
                {"help", help_help},
                {"alias", help_alias}
        };

        int i = 7;
        int p = 1;

        for (; shpack->options[p]; p++, i = 7)
        {
                while (i--)
                        if (!_strcmp(shpack->options[p], help[i].built))
                                help[i].h(), bcheck = 1;
        }
        if (shpack->options[1] == NULL)
        {
                printsHelp();
                bcheck = 1;
        }
        if (bcheck == 0)
        {
                check = -1;
                _error(6, shpack, 2);
        }

        free(shpack->options);
        return (check);
}


/**
 * help_unsetenv - prints help of unsetenv built in
 *
 * Return: No Return
 */
void help_unsetenv(void)
{
        _puts("unsetenv: unsetenv [VARIABLE]\n");
        _puts("    Initializes a new environment variable, or ");
        _puts("    modifies an existing one.\n\n");
        _puts("    VARIABLE must not have the character '='.\n");
        _puts("    If no arguments are given, setenv prints the current ");
        _puts("    environment.\n");
}

/**
 * help_cd - prints help of cd built in
 *
 * Return: No Return
 */
void help_cd(void)
{
        _puts("cd: cd [DIRECTORY]\n");
        _puts("    Change the shell working directory.\n\n");
        _puts("    Change the current directory to DIR.  ");
        _puts("    The default DIR is the value of the\n");
        _puts("    HOME shell variable.\n\n");
        _puts("    Options:\n");
        _puts("    -  If a minus signed is used instead a directory, ");
        _puts("    cd will change to the\n");
        _puts("       previous used directory\n\n");
        _puts("    Each time cd runs successfuly, the env variable ");
        _puts("    PWD is updated\n\n");
        _puts("    Exit Status:\n");
        _puts("    Returns 1 if the directory is changed, and if $PWD is set ");
        _puts("    successfully when\n");
        _puts("    is used; -1 otherwise.\n");
}
/**
 * help_help - prints help of help built in
 *
 * Return: No Return
 */
void help_help(void)
{
        _puts("help: help [BUILTIN ...]\n");
        _puts("    Display information about builtin commands.\n\n");
        _puts("    Displays brief summaries of builtin commands.  If BUILTIN is\n");
        _puts("    specified, gives detailed help on all commands ");
        _puts("    matching BUILTIN,\n");
        _puts("    otherwise the list of help topics is printed.\n\n");
        _puts("    Arguments:\n");
        _puts("      BUILTIN   Builtin specifying a help topic\n\n");
        _puts("    Exit Status:\n");
        _puts("    Returns success unless PATTERN is not found or an invalid ");
        _puts("    option is given.\n");
}
/**
 * help_alias - prints help of alias built in
 *
 * Return: No Return
 */
void help_alias(void)
{
        _puts("alias: alias alias [name[='value'] ...]\n");
        _puts("    Define or display aliases.\n\n");
        _puts("    Without arguments, `alias' prints the list of aliases ");
        _puts("    in the reusable\n");
        _puts("    form `alias NAME=VALUE' on standard output.\n\n");
        _puts("     Otherwise, an alias is defined for each NAME whose ");
        _puts("    VALUE is given.\n");
        _puts("    A trailing space in VALUE causes the next word to ");
        _puts("    be checked for\n");
        _puts("    alias substitution when the alias is expanded.\n\n");
        _puts("    Exit Status:\n");
        _puts("    alias returns true unless a NAME is supplied for which ");
        _puts("    no alias has been\n");
        _puts("    defined.\n");
}

/**
 * printsHelp - prints help of help built in
 *
 * Return: No Return
 */
void printsHelp(void)
{
        _puts("Shell HSH, version 1.0(1)-release (x86_64-pc-linux-gnu)\n");
        _puts("These shell commands are defined internally.\n");
        _puts("Type `help' to see this list.\n");
        _puts("Type help  'BUILTIN'' to find out more about ");
        _puts("the function 'BUILTIN'.\n\n");
        _puts(" exit [n]\n");
        _puts(" env\n");
        _puts(" setenv [VARIABLE] [VALUE]\n");
        _puts(" unsetenv [VARIABLE]\n");
        _puts(" cd [DIRECTORY]\n");
        _puts(" help [BUILTIN ...]\n");
        _puts(" alias [name[='value'] ...]\n");
}


/**
 * free_doubpoint - frees a double pointer array of strings
 * (must end in NULL)
 *
 * @p: double pointer to free
 *
 * Return: no return
 */
void free_doubpoint(char **p)
{
        int x, z = 0;

        while (p[z] != 0)
                z++;

        for (x = 0; x < z; x++)
        {
                free(p[x]);
        }
        free(p);
}
/**
 * _copydoublep - copies an array of strings (double pointer)
 *
 * @p: double pointer to copy
 * @old_size: original size of P
 * @new_size: size of copy
 *
 * Return: Pointer malloec
 */
char **_copydoublep(char **p, int old_size, int new_size)
{
        char **copy;
        int x, csize;

        if (!p && (old_size == new_size))
                return (NULL);

        if (new_size < old_size)
        {
                csize = new_size;
                copy = malloc(sizeof(char *) * (csize + 1));
        }
        else
        {
                csize = old_size;
                copy = malloc(sizeof(char *) * (new_size + 1));
        }
        if (copy == 0)
                return (0);

        if (p)
                for (x = 0; x < csize; x++)
                {
                        copy[x] = _strdup(p[x]);
                        if (copy[x] == 0)
                        {
                                x--;
                                for (; x >= 0; x--)
                                        free(copy[x]);
                                free(copy);
                                return (0);
                        }
                }

        /* Add Null in the end */
        copy[new_size] = '\0';

        return (copy);
}
/**
 * _strlendp - calculates length of double pointer (ending in NULL)
 * @s: double pointer
 *
 * Return: Length of double pointer
 *
 */
int _strlendp(char **s)
{
        int x = 0;

        if (!s)
                return (0);

        while (s[x] != NULL)
                x++;
        return (x);
}
/**
 * _setenv - overwrite an env variable or creates it
 *
 * @env: array of env variables
 * @variable: env variable to set
 * @value: value to set
 * @shpack: struct with shell info
 *
 * Return: 0 on success, -1 on error
 */
char **_setenv(char **env, char *variable, char *value, hshpack *shpack)
{
        int x, y, check, z = 0, zenv = 0;
        char *envjoin, *envjoin2, *copydup, **copy;

        if (_strlen(variable) == 0 || variable == 0)
                return (_error(3, shpack, 1), NULL);
        envjoin2 = str_concat(variable, "=");
        if (envjoin2 == 0)
                return (_error(3, shpack, 1), NULL);
        envjoin = str_concat(envjoin2, value), free(envjoin2);
        if (envjoin == 0)
                return (_error(3, shpack, 1), NULL);
        z = _strlen(variable), zenv = _strlendp(env);
        for (x = 0; env && env[x] != 0; x++)
        {
                for (check = 0, y = 0; y < z && env[x][y] != 0; y++)
                {
                        if (variable[y] == '=')
                                return (free(envjoin), _error(3, shpack, 2), NULL);
                        if (env[x][y] == variable[y])
                                check++;
                }
                if (check == z && env[x][check] == '=')
                {
                        free(env[x]), copydup = _strdup(envjoin), free(envjoin);
                        if (copydup == 0)
                                return (_error(3, shpack, 1), NULL);
                        return (env[x] = copydup, env);
                }
        }
        copy = _copydoublep(env, zenv, zenv + 1);
        if (env)
                free_doubpoint(env);
        if (copy == 0)
                return (free(envjoin), _error(3, shpack, 1), NULL);
        env = copy, copydup = _strdup(envjoin), free(envjoin);
        if (copydup == 0)
                return (_error(3, shpack, 1), NULL);
        return (env[zenv] = copydup, env);
}


/**
 * signal_handler - handles ctrl + c in runtime
 * @x: unused value, just for betty
 *
 * Return: No return
 */
void signal_handler(int x)
{
        (void) x;
        write(1, "\n$ ", 3);
}
/**
 * signal_handler2 - handles ctrl + c during cmd exec
 * @x: unused value, just for betty
 *
 * Return: No return
 */
void signal_handler2(int x)
{
        (void) x;
        write(1, "\n", 1);
}



/**
 * str_concat - concatenates two strings
 * @s1: string1
 * @s2: string2
 *
 * Return: Pointer
 */
char *str_concat(char *s1, char *s2)
{
        int l1, l2, i, j;
        char *s;
        char *nul = "";

        if (s1 == NULL)
                s1 = nul;
        if (s2 == NULL)
                s2 = nul;

        l1 = 0, l2 = 0;
        while (*(s1 + l1))
                l1++;
        while (*(s2 + l2))
                l2++;

        s = malloc(sizeof(char) * (l1 + l2 + 1));

        if (s == 0)
                return (0);

        for (i = 0; i < l1; i++)
                *(s + i) = *(s1 + i);

        for (i = 0, j = l1; i <= l2; j++, i++)
                *(s + j) = *(s2 + i);

        return (s);
}


/**
 * _strcpy - copy a source input ont destinated input
 * @dest: target where will be stored the input
 * @src: source to copy from
 *
 *
 * Return: dest address
 * On error: -1 inapropiate entry
 */

char *_strcpy(char *dest, char *src)
{
        int i = 0;

        for (i = 0; *(src + i) != '\0'; i++)
                *(dest + i) = *(src + i);

        *(dest + i) = *(src + i); /* adding '\0' character */

        return (dest);
}

/**
 * _strlen - function that returns the length of a string
 * @s: string address
 *
 *
 * Return: nothing
 * On error: -1 inapropiate entry
 */

int _strlen(char *s)
{
        return ((!*s) ? 0 : 1 + _strlen(s + 1));
}

/**
 * _strdup - function that returns a pointer to a newly allocated space
 * in memory, which contains a copy of the string given as a parameter
 * @str: source to copy
 *
 *
 * Return: address where is stored the result
 * On error: -1 inapropiate entry
 */

char *_strdup(char *str)
{
        char *arr;

        if (!str)
                return (NULL);

        arr = malloc((_strlen(str) * sizeof(*arr)) + 1);

        if (!arr)
                return (NULL);

        _strcpy(arr, str);

        return (arr);
}


/**
 * _strtok - tokenizes a string based on a delimiter
 *
 * @str: string to operate
 * @delim: delimiter
 *
 * Return: pointer to string
 * or NULL if there is no match
 *
 */
char *_strtok(char *str, const char *delim)
{
        const char *org = delim;
        int issEqual = 1, issGetInto = 0;
        static char *step, *stepNull;
        static int isEnd;

        if (str)
                isEnd = 0;
        if (isEnd)
                return (NULL);
        step = (str) ? str : (stepNull + 1);
        if (str)
                stepNull = str;
        else
                str = step;
        while (*str && issEqual)
        {
                issEqual = 0;
                for (delim = org; *delim; delim++)
                        if (*str == *delim)
                                issEqual = 1;
                str = (!issEqual) ? str : str + 1;
                isEnd = (*str) ? 0 : 1;
                if (isEnd)
                        return (NULL);
        }
        step = str;
        while (*str && !issEqual)
        {
                issEqual = 0;
                for (delim = org; *delim; delim++)
                        if (*str == *delim)
                        {
                                issGetInto = 1, issEqual = 1;
                                isEnd = (*(str + 1)) ? 0 : 1, *str = '\0';
                        }
                str = (issEqual) ? str : str + 1;
                if (!issGetInto && !*str)
                        isEnd = 1;
        }
        return (stepNull = str, step);
}


/**
 * _copydoublepDel - copies an array of strings (double pointer)
 *
 * @p: double pointer to copy
 * @new_size: size of copy
 * @jump: value that must be skipped in copy
 *
 * Return: Pointer malloec
 */
char **_copydoublepDel(char **p, int new_size, int jump)
{
        char **copy;
        int i, j, csize;

        csize = new_size;
        copy = malloc(sizeof(char *) * (csize + 1));
        if (copy == 0)
                return (0);

        for (i = 0, j = 0; j < csize; i++, j++)
        {
                if (i == jump)
                        i++;
                copy[j] = _strdup(p[i]);
                if (copy[j] == 0)
                {
                        j--;
                        for (; j >= 0; j--)
                                free(copy[j]);
                        free(copy);
                        return (0);
                }
        }

        copy[new_size] = '\0';

        return (copy);
}

/**
 * _unsetenv - unsets an enviromental variable
 *
 * @env: array of env variables
 * @variable: env variable to unset
 * @shpack: struct with shell info
 *
 * Return: 0 on success, -1 on error
 */
char **_unsetenv(char **env, char *variable, hshpack *shpack)
{
        int i, j, check, l = 0, lenv = 0, found = 0;
        char **copy;

        shpack->unsetnull[0] = 0;
        if (!env)
                return (write(2, "Environment is NULL\n", 20), NULL);
        if (_strlen(variable) == 0 || variable == 0)
                return (_error(3, shpack, 1), NULL);
        l = _strlen(variable), lenv = _strlendp(env);
        for (i = 0; env[i] != 0; i++)
        {
                for (check = 0, j = 0; j < l && env[i][j] != 0; j++)
                {
                        if (variable[j] == '=')
                                return (_error(3, shpack, 2), NULL);
                        if (env[i][j] == variable[j])
                                check++;
                }
                if (check == l && env[i][check] == '=')
                {
                        /* Found env to erase */
                        found = 1;
                        if ((lenv - 1) != 0)
                        {
                                copy = _copydoublepDel(env, lenv - 1, i);
                         if (copy == 0)
                                        return (_error(7, shpack, 1), NULL);
                        }
                        else
                                shpack->unsetnull[0] = 1, copy = NULL;
                        free_doubpoint(env), env = copy;
                        return (env);
                }
        }
        if (found == 0)
                return (write(2, "VARIABLE not found\n", 19), NULL);
        return (env);
}
