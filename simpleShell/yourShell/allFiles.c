#include "shell.h"

/* ................................NUM 1 START..............................*/
/**
 * string_reverse - Reverses string
 * @s: str to rev
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
 * string_reverse - R
 * @s: str
 */
void string_reverseSub(char *s, char tempVar, int x, int y)
{
        tempVar  = s[y];
        s[y] = s[x];
        s[x] = tempVar;
        x--, y++;
}
/* ................................NUM 1 END................................*/

/* ................................NUM 2 START..............................*/
/**
 * empty_dif_list - frees
 * @head: head
 */

void freeCharFoluke(char *temp)
{
        free(temp);
}
/* ................................NUM 2 END................................*/


/**
 * lenBTen - get length
 *
 * @n: number
 * @base: base
 * Return: length
 */
int lenBTen(unsigned long int n, unsigned long int base)
{
        unsigned long int x, negNum = 0, ret;

        for (x = 0; n > 0; x++)
                n = n / base;
        ret = x + negNum;
        return (ret);
}
/**
 * _itoa - converts
 * @n: number
 * Return: ptr
 */
char *_itoa(int n)
{
        unsigned long int x = 0, base = 10;
        char *str;

        if (n != 0)
                str = malloc(lenBTen(n, base) + 1);
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


/**
 * errorSetStr - creates str
 * @errn: numb
 * @shpack: struct
 * @exnum: val
 * Return: 0
 */
int errorSetStr(int errn, hshpack *shpack, int exnum)
{
        int cnt = shpack->errnum[0], z = 0;
        char *cmd = shpack->cmd, **optn = shpack->options;
        char *hshname = shpack->hshname;
        char *nustr, *concA, *concB, *coluspc = ": ";
        char *err[] = {
                "not found", "Permission denied", "Invalid number",
                "name is NULL, points to string of length 0, or has an '=' chararacter",
                "can't cd(change dire) to ", "Invalid optn ", "Help command error",
                "Error allocating memory", "Wrong Alias",
                NULL
        };

        concA = stringCatenator(hshname, coluspc);
        if (!concA) /*hsh: */
                return (write(2, "Memory Error", 22), -1);

        if (errn == 7) /* Alloc Error */
        {
                concB = stringCatenator(concA, err[errn]); /*hsh: cnt: error*/
                if (!concB)
                        return (freeCharFoluke(concA), write(2, "Memory Error", 22), -1);
                freeCharFoluke(concA);
                while (concB[z] != 0)
                        z++;
                write(2, concB, z), write(2, "\n", 1);
                freeCharFoluke(concB);
                return (0);

        }

        nustr = _itoa(cnt);
        if (!nustr)  /* number to string */
                return (freeCharFoluke(concA), write(2, "Memory Error", 22), -1);

        concB = stringCatenator(concA, nustr);
        if (!concB) /*hsh: cnt*/
        {
                write(2, "Memory Error", 22);
                return (freeCharFoluke(concA), freeCharFoluke(nustr),  -1);
        }
        freeCharFoluke(concA), freeCharFoluke(nustr);

        concA = stringCatenator(concB, coluspc);
        if (!concA) /*hsh: cnt: */
                return (freeCharFoluke(concB), write(2, "Memory Error", 22), -1);

        freeCharFoluke(concB);
        concB = stringCatenator(concA, cmd);
        if (!concB) /*hsh: cnt: cmd*/
                return (freeCharFoluke(concA), write(2, "Memory Error", 22), -1);
        freeCharFoluke(concA);

        concA = stringCatenator(concB, coluspc);
        if (!concA) /*hsh: cnt: cmd: */
                return (freeCharFoluke(concB), write(2, "Memory Error", 22), -1);
        freeCharFoluke(concB);

        concB = stringCatenator(concA, err[errn]);
        if (!concB) /*hsh: cnt: cmd: error*/
                return (freeCharFoluke(concA), write(2, "Memory Error", 22), -1);
        freeCharFoluke(concA);

        if (errn > 1 && errn < 6 && errn != 3)
                concB = errorSub(errn, concB, optn[1]);
        if (concB == NULL)
        {
                write(2, "Memory Error", 22);
                return (-1);
        }

        while (concB[z] != 0)
                z++;
        write(2, concB, z), write(2, "\n", 1);
        freeCharFoluke(concB);
        shpack->exitnum[0] = exnum;
        return (0);

}
/**
 * errorSub - extra modes
 * @errn: number
 * @concB: error
 * @optn: cmd
 * Return: pointer
 */
char *errorSub(int errn, char *concB, char *optn)
{
        char *concA, *coluspc = ": ";

        if (errn == 2) /* exit error */
        {

                concA = stringCatenator(concB, coluspc);
                if (!concA) /*hsh: cnt: cmd: error: */
                {
                        write(2, "Memory Error", 22);
                        return (freeCharFoluke(concB), NULL);
                }
                freeCharFoluke(concB);

                concB = stringCatenator(concA, optn);

                if (!concB) /*hsh: cnt: cmd: error: optn*/
                {
                        write(2, "Memory Error", 22);
                        return (freeCharFoluke(concA), NULL);
                }
                freeCharFoluke(concA);
        }
        if (errn > 3) /* Errors with options at end */
        {
                concA = stringCatenator(concB, optn);
                if (!concA) /*hsh: cnt: cmd: error optn*/
                {
                        write(2, "Memory Error", 22);
                        return (freeCharFoluke(concB), NULL);
                }
                freeCharFoluke(concB);
                return (concA);
        }
        return (concB);
}


/**
 * exitCmdFunc - exit command
 * @shpack: struct
 * Return: -1 if error
 */
ssize_t exitCmdFunc(hshpack *shpack)
{
        long exit_value;

        if (shpack->options[1] == NULL || isNumba(shpack->options[1]))
        {
                exit_value = atoiFol(shpack->options[1]);

                if (exit_value >= 0 && exit_value < INT_MAX)
                {
                        if (exit_value > 255)
                                exit_value %= 256;
                        if (shpack->options[1] == NULL)
                                exit_value = shpack->exitnum[0];
                        free(*(shpack->options));
                        free(shpack->options);
                        if (*(shpack->envCpy))
                                freeDobleCharPntrFoluke(*(shpack->envCpy));
                        free(shpack);
                        exit(exit_value);
                }
        }
        errorSetStr(2, shpack, 2);
        free(shpack->options);
        return (-1);
}

/**
 * envCmd - env command
 * @shpack: struct
 * Return: 1 
 */
ssize_t envCmd(hshpack *shpack)
{
        char **str;
        int chckr = 1;

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
                        write(1, *str, stringLengthFunc(*str));
                        write(1, "\n", 0);
                }
        }
        else
        {
                errorSetStr(0, shpack, 2);
                chckr = -1;
        }

        free(shpack->options);
        return (chckr);
}
/**
 * setEnvironCmd - setenv command
 * @shpack: struct
 * Return: 1
 */
ssize_t setEnvironCmd(hshpack *shpack)
{
        char **nenviron, *var1 = NULL, *val1 = NULL;

        if (shpack->options[1])
        {
                var1 = shpack->options[1];
                if (!shpack->options[2])
                {
                        write(2, "Invalid VALUE\n", 14);
                        shpack->exitnum[0] = 2;
                        free(shpack->options);
                        return (-1);
                }
                else
                        val1 = shpack->options[2];
        }
        if (var1 == 0)
        {
                write(2, "Invalid VARIABLE\n", 17);
                shpack->exitnum[0] = 2;
                free(shpack->options);
                return (-1);
        }

        nenviron = setEnvironm(*(shpack->envCpy), var1, val1, shpack);

        if (nenviron == 0)
        {
                free(shpack->options);
                return (-1);
        }

        *(shpack->envCpy) = nenviron;
        free(shpack->options);
        return (1);
}
/**
 * unSetEnvironComnd - unsetenv command
 * @shpack: struct
 * Return: 1
 */
ssize_t unSetEnvironComnd(hshpack *shpack)
{
        char **nenviron, *var1 = NULL;

        if (shpack->options[1])
                var1 = shpack->options[1];
        else
        {
                shpack->exitnum[0] = 2;
                write(2, "Please provide an argument\n", 27);
                return (free(shpack->options), -1);
        }

        if (var1 == 0)
        {
                free(shpack->options);
                return (1);
        }

        nenviron = unSetEnviron(*(shpack->envCpy), var1, shpack);

        if (nenviron == 0 && shpack->unsetnull[0] == 0)
        {
                free(shpack->options);
                shpack->exitnum[0] = 2;
                return (-1);
        }

        *(shpack->envCpy) = nenviron;
        free(shpack->options);
        return (1);
}

/**
 * chckBuiltIn - checks if the command is built in
 * @shpack: struct
 * Return: On fail 0
 */
ssize_t chckBuiltIn(hshpack *shpack)
{
        b_ins ops[] = {
                {"exit", exitCmdFunc},
                {"env", envCmd},
                {"setenv", setEnvironCmd},
                {"unsetenv", unSetEnvironComnd},
                {"cd", cDirCmnd},
                {"help", _help_cmd}
        };

        int x = 6, builtcheck; /* lenght of ops array */

        while (x--)
                if (!stringCompare(shpack->cmd, ops[x].cmd))
                {
                        shpack->errnum[0] += 1;
                        builtcheck = ops[x].f(shpack);
                        if (builtcheck == 1)
                                shpack->exitnum[0] = 0;
                        return (builtcheck);
                }

        return (0);
}


/* ................................NUM 3 START..............................*/

/**
 * secAuxCd - auxiliary built in func of cd
 * @shpack: struct
 * @curDir: current dir
 * Return: pointer
 */
char *secAuxCd(hshpack *shpack, char *curDir)
{
        char *home, *dire = NULL;

        (void) curDir;
        home = fetchEnviron("HOME", *(shpack->envCpy));
        if (home)
                dire = secAuxCdFol(home, dire);

        return (dire);
}
/* ................................NUM 3 BTW................................*/
/**
 * secAuxCd - auxiliary built in func of cd
 * @shpack: struct
 * @curDir: current dir
 * Return: pointer
 */
char *secAuxCdFol(char *home, char *dire)
{
        dire = home + 5;
        return (dire);
}
/* ................................NUM 3 END................................*/


/**
 * secAuxCd - auxiliary built in func of cd
 * @shpack: struct
 * @curDir: current dir
 * Return: Pointe
 */
char *firstAuxCd(hshpack *shpack, char *curDir)
{
        char *oldpwd2 = NULL, *oldpwDir = NULL, *dire = NULL;

        if (shpack->options[1] && shpack->options[2])
        {
                write(2, "cd: too many arguments\n", 23);
                shpack->exitnum[0] = 2;
                free(shpack->options);
                freeCharFoluke(curDir);
                return (dire);
        }

        oldpwd2 = stringDuplicateFunc(fetchEnviron("OLDPWD", *(shpack->envCpy)));
        if (oldpwd2)
                oldpwDir = stringDuplicateFunc(oldpwd2 + 7), free(oldpwd2);
        if (!oldpwd2)
        {
                oldpwDir = stringDuplicateFunc(curDir);
                /* free(oldpwDir), free(shpack->options), free(curDir); */
                /* return (shpack->exitnum[0] = 2, NULL); */
        }

        dire = oldpwDir;

        return (dire);
}

/**
 * cDirCmnd - built in command for cd
 * @shpack: struct
 * Return: 1
 */
ssize_t cDirCmnd(hshpack *shpack)
{
        char *curDir = NULL, *dire = NULL, **nenviron, *oldpwDir = NULL;
        int exit = 1, chckr = 1, checkerSubtrctn = 0;

        curDir = getcwd(NULL, 4096);
        if (!curDir)
                return (errorSetStr(4, shpack, 2), free(shpack->options), -1);
        if (!shpack->options[1] ||
                        (shpack->options[1] && (!stringCompare(shpack->options[1], "~"))))
        {
                dire = secAuxCd(shpack, curDir);
                if (!dire)
                        return (free(shpack->options), freeCharFoluke(curDir), 1);
        }
        else
                if (!stringCompare(shpack->options[1], "-"))
                {
                        dire = firstAuxCd(shpack, curDir);
                        if (!dire)
                                return (free(shpack->options), freeCharFoluke(curDir), 1);
                        checkerSubtrctn = 1;
                }
                else
                        dire = shpack->options[1];
        if (dire)
                chckr = chdir(dire);
        if (chckr == 0 && checkerSubtrctn == 1)
                write(1, dire, stringLengthFunc(dire)), write(1, "\n", 1);
        if (chckr != 0)
                errorSetStr(4, shpack, 2), exit = -1;
        else
        {
                nenviron = setEnvironm(*(shpack->envCpy), "PWD", dire, shpack);
                *(shpack->envCpy) = nenviron;
                nenviron = setEnvironm(*(shpack->envCpy), "OLDPWD", curDir, shpack);
                *(shpack->envCpy) = nenviron;
        }
        free(shpack->options), freeCharFoluke(curDir), freeCharFoluke(oldpwDir);
        if (checkerSubtrctn == 1)
                freeCharFoluke(dire);
        return (exit);
}

/* ................................500..............................*/




/* ................................NUM 4 START..............................*/
/**
 * powerFunc - gets the result of base to ower
 * @base: base
 * @pot: power
 *
 * Return: result
 */
long powerFunc(long base, long pot)
{
        long x = 0, res = 1;

        for (x = 0; x < pot; x++)
                powerFuncFol(base, res);

        return (res);
}

/* ................................NUM 4 BTW................................*/
/**
 * powerFunc - gets the result of base to ower
 * @base: base
 * @pot: power
 * Return: result
 */
long powerFuncFol(long base, long res)
{
        res *= base;
        return (res);
}
/* ................................NUM 4 END................................*/


/* ................................NUM 5 START..............................*/

/**
 * atoiFol - convert char to int
 * @s: char input
 * Return: input
 */

long atoiFol(char *s)
{
        long x = 0, k = 0, len = 0, toRet = 0, subtracn = 0, offset = 48;                                       
        unsigned long result = 0;
        

        if (!s)
                return (0);

        for (x = 0; *(s + x) != '\0'; x++)
        {
                if (*(s + x) >= 48 && *(s + x) <= 57)
                        len++;
                else if (len != 0)
                        break;

                if (*(s + x) == '-')
                        subtracn = atoiFolFol(subtracn);
        }

        for (x--; len > 0; x--, k++, len--)
                result +=  (*(s + x) - offset) * powerFunc(10, k);

        toRet = (subtracn % 2 != 0) ? result * (-1) : result;

        return (toRet);
}

/* ................................NUM 5 BTW................................*/
/**
 * atoiFol - convert char to int
 * @s: char
 * Return: input
 */

long atoiFolFol(long subtracn)
{
       return (subtracn++);
}
/* ................................NUM 5 END................................*/


/* ................................NUM 6 START..............................*/

/**
 * stringCompare - compares two strings
 * @s1: str1
 * @s2: str
 * Return: 0 if strings are eql or another val1 if not
 */
int stringCompare(char *s1, char *s2)
{
        int x = 0, eql = 0;

        for (x = 0; (*(s1 + x) || *(s2 + x)) && !eql; x++)
                if (*(s1 + x) != *(s2 + x))
                        eql = stringCompareFol(s1, s2, x);

        return (eql);
}
/* ................................NUM 6 BTW................................*/
/**
 * stringCompare - compares two strings
 * @s1: str1
 * @s2: str
 * Return: 0 if strings are eql or another val1 if not
 *
 */
int stringCompareFol(char *s1, char *s2, int x)
{
        int eql;
        
        eql = *(s1 + x) - *(s2 + x);
        return (eql);
}
/* ................................NUM 6 END................................*/

/**
 * isDigitFunc - checks if a character is a digit num
 * @c: character
 * Return: 1
 *
 */
int isDigitFunc(int c)
{
        return ((c >= 48 && c <= 57) ? 1 : 0);
}

/**
 * isNumba - checks if a str has numbers
 * @s: str
 * Return: 1 
 */
int isNumba(char *s)
{
        for (; *s; s++)
                if (!isDigitFunc(*s))
                        return (0);
        return (1);
}


/**
 * chckInputFunc - checks for input
 * @ac: numb of main arguments
 * @av: main arg
 * @bufsize: size of buffer
 * @buffer: buffer
 * @shpack: struct of shell info
 * Return: On success 1.
 */
char **chckInputFunc(int ac, char **av, size_t *bufsize,
                   char **buffer, hshpack *shpack)
{
        ssize_t charctrs;
        char **command;
        int exitnum;

        if (ac == 1)
        {
                if (isatty(STDIN_FILENO))
                        write(1, "prompt_by_foluke $ ", 19);
                charctrs = getline(buffer, bufsize, stdin);

                if (charctrs == -1)
                {
                        exitnum = shpack->exitnum[0];
                        freeCharFoluke(*buffer);
                        if (*(shpack->envCpy))
                                freeDobleCharPntrFoluke(*(shpack->envCpy));
                        free(shpack);
                        if (isatty(STDIN_FILENO))
                                write(1, "\n", 1);
                        exit(exitnum);
                }
                if (**buffer == '#' || !charctrs || **buffer == '\n')
                        return (NULL);
                *buffer = delComnt(*buffer);
                command = fetchParam(*buffer, shpack);
        }
        else
        {
                command = malloc(sizeof(char *) * (ac - 1));
                if (!command)
                {
                        errorSetStr(7, shpack, 1);
                        return (NULL);
                }

                command[ac - 1] = '\0';
                while (ac--)
                        command[ac - 1] = av[ac];
        }
        return (command);
}


/* ................................NUM 7 START..............................*/

/**
 * delComnt - deletes a commnet
 * @str: str
 * Return: pointer
 */
char *delComnt(char *str)
{
        char *C_org = str;

        for (; str && *str; str++)
                if (*str == '#' && *(str - 1) == ' ')
                {
                        *str = delComntFol(*str);
                        break;
                }

        return (C_org);
}
/* ................................NUM 7 BTW................................*/
/**
 * delComnt - deletes a commnet
 * @str: str
 * Return: pointer
 */
char delComntFol(char str)
{
        str = '\0';
        return (str);
}
/* ................................NUM 7 END................................*/


/**
 * excuteCmd - creates a child prcss to execute a cmd
 * @program: command
 * @command: arg
 * @env: curr env
 * @shpack: struct
 * Return: pointer
 */
int excuteCmd(char *program, char *command[], char **env, hshpack *shpack)
{
        pid_t prcss, sttus;
        int execSts = 0, wait1_Sts = 0;

        prcss = fork();
        signal(SIGINT, sigHandlr2);
        if (prcss == -1)
        {
                write(2, "Fork Error", 10);
                exit(-1);
        }
        if (prcss == 0)
        {

                execSts = execve(program, command, env);
                if (execSts == -1)
                {
                        _exit(-1);
                }
        }
        else
        {
                wait1_Sts = wait(&sttus);
                signal(SIGINT, sigHandlr);
                if (wait1_Sts == -1)
                        exit(-1);
                if (WEXITSTATUS(sttus) == 0)
                        shpack->exitnum[0] = 0;
                else
                        shpack->exitnum[0] = 2;
        }

        shpack->errnum[0] += 1;
        return (0);
}


/**
 * fetchEnviron - fetch an environ var
 *
 * @name: name
 * @env: current env
 * Return: pointer to the val1 in the environment, *
 */
char *fetchEnviron(const char *name, char **env)
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


/* ................................NUM 8 START..............................*/
/**
 * memorySet - fills memory
 * @s: memory
 * @b: constant
 * @n: first n byte
 * Return: On success 1.
 */
char *memorySet(char *s, char b, unsigned int n)
{
        unsigned int x;

        for (x = 0; x < n; x++)
                s[x] = memorySetFol(s, b, x);
        return (s);
}
/* ................................NUM 8 BTW................................*/
/**
 * memorySet - fills memory
 * @s: memory
 * @b: constant
 * @n: first n byte
 * Return: On success 1.
 */
char memorySetFol(char *s, char b, unsigned int x)
{
        s[x] = b;
        return (s[x]);
}
/* ................................NUM 8 END................................*/


/* ................................NUM 9 START..............................*/
/**
 * memoryCopy - copies mem
 * @dest: destination
 * @src: source
 * @n: size of memory
 *
 * Return: Returns memory copied
 */
char *memoryCopy(char *dest, char *src, unsigned int n)
{
        unsigned int x;

        for (x = 0; x < n; x++)
                dest[x] = memoryCopyFol(dest, src, x);
        return (dest);
}
/* ................................NUM 9 BTW................................*/
/**
 * memoryCopy - copies mem
 * @dest: destination
 * @src: source
 * @n: size of memory
 *
 * Return: Returns memory copied
 */
char memoryCopyFol(char *dest, char *src, unsigned int x)
{
        dest[x] = src[x];
        return (dest[x]);
}
/* ................................NUM 9 END................................*/

/**
 * reAllocateFunc - reallocates a memory block
 * @ptr: pointer
 * @old_size: current size
 * @new_size: size of memory
 * Return: Pointer
 */
void *reAllocateFunc(void *ptr, unsigned int old_size, unsigned int new_size)
{
        void *pointr3;

        if (old_size == new_size)
                return (ptr);

        if (ptr == NULL)
        {
                pointr3 = malloc(new_size);
                if (pointr3 == 0)
                        return (0);
                freeCharFoluke(ptr);
                return (pointr3);
        }

        if (new_size == 0 && ptr != NULL)
        {
                freeCharFoluke(ptr);
                return (0);
        }

        pointr3 = malloc(new_size);

        if (pointr3 == 0)
                return (0);

        pointr3 = memorySet(pointr3, '\0', new_size);

        memoryCopy(pointr3, ptr, old_size);
        freeCharFoluke(ptr);
        return (pointr3);
}
/**
 * fetchLine - read string/line from an input stream
 * @buffer: pointer
 * @bufsize: current size
 * @fd: stream
 * Return: Number
 */
int fetchLine(char **buffer, size_t *bufsize, int fd)
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
        buff = memorySet(buff, '\0', size);
        do {

                r = read(fd, buff + len, BSIZE);
                if (r >= 0)
                        x = len, len += r;
                if (r == -1 || r == 0)
                        return (-1);
                if  (len >= size)
                {
                        sizeold = size, size += BSIZE;
                        buff = reAllocateFunc(buff, sizeold, size);
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
 * fetchParam - obtains parameters
 * @raw_buffer: Rbuffer
 * @shpack: struct of shell info
 * Return: On success 1.
 */
char **fetchParam(char *raw_buffer, hshpack *shpack)
{
        char **buffer, *cp_raw_buffer;
        ssize_t cnt = 0, i = 0;

        cp_raw_buffer = stringDuplicateFunc(raw_buffer);
        if (!cp_raw_buffer)
        {
                errorSetStr(7, shpack, 1);
                exit(-1);
        }

        if (stringTokenizeFunc(cp_raw_buffer, " \n"))
                cnt++;
        else
        {
                free(cp_raw_buffer);
                return (NULL);
        }
        while (stringTokenizeFunc(NULL, " \n"))
                cnt++;

        free(cp_raw_buffer);
        buffer = malloc(sizeof(char *) * (cnt + 1));
        if (!buffer)
        {
                errorSetStr(7, shpack, 1);
                exit(-1);
        }
        buffer[0] = stringTokenizeFunc(raw_buffer, " \n");
        for (i = 1; i < cnt && buffer[i - 1]; i++)
                buffer[i] = stringTokenizeFunc(NULL, " \n");

        if (!buffer[i - 1])
        {
                freeDobleCharPntrFoluke(buffer);
                return (NULL);
        }

        buffer[i] = NULL;
        return (buffer);
}

/* ................................1000..............................*/




/* ................................NUM 10 START..............................*/

/**
 * pthChcker - check if current dire must be added
 * @path: path env var1
 *
 * Return: Pointer to adress of new PATH
 *
 */

char *pthChcker(char *path)
{
        char *npath;
        int x, y, nsize, cnt = 0;

        for (x = 0; path[x]; x++)
        {

                if (path[x] == '=' && path[x + 1] == ':')
                        cnt++;
                if (path[x] == ':' && path[x + 1] == ':')
                        cnt++;
                if (path[x] == ':' && path[x + 1] == '\0')
                        cnt++;
        }
        if (cnt == 0)
                return (0);
        nsize = stringLengthFunc(path) + 1 + cnt;
        npath = malloc(sizeof(char) * nsize);

        for (x = 0, y = 0; x < nsize; x++, y++)
        {
                if (path[y] == '=' && path[y + 1] == ':')
                {
                        npath[x] = pthChckerFol(path, npath, x, y);
                        continue;
                }
                if (path[y] == ':' && path[y + 1] == ':')
                {
                        npath[x] = pthChckerFol(path, npath, x, y);
                        continue;
                }
                if (path[y] == ':' && path[y + 1] == '\0')
                {
                        npath[x] = pthChckerFol(path, npath, x, y);
                        continue;
                }
                npath[x] = path[y];
        }
        freeCharFoluke(path);
        return (npath);
}
/* ................................NUM 10 BTW................................*/
/**
 * pthChcker - check if current dire must be added
 * @path: path env var1
 *
 * Return: Pointer to adress of new PATH
 *
 */

char pthChckerFol(char *path, char *npath, int x, int y)
{
        npath[x] = path[y], npath[x + 1] = '.', x++;
        return (npath[x]);
}
/* ................................NUM 10 END................................*/


/**
 * searchPath - Searches for a cmd in PATH
 * @cmd: string contating env var1 PATH
 * @env: current environment
 * @shpack: struct containing shell info
 *
 * Return: Pointer to adress of cmd in PATH or by itself
 *
 */

char *searchPath(char *cmd, char **env, hshpack *shpack)
{
        char *path, *path2;
        struct stat st;
        char *token, *concat, *concat2, *pathcheck, *delim = ":=";
        int x;

        for (x = 0; cmd[x]; x++)
                if (cmd[x] == '/')
                {
                        if (stat(cmd, &st) == 0)
                                return (concat = stringCatenator(cmd, '\0'));
                        else
                                return (0);
                }

        path2 = fetchEnviron("PATH", env);
        (void) shpack;
        if (!path2)
                return (0);
        path = stringDuplicateFunc(path2);
        pathcheck = pthChcker(path);
        if (pathcheck)
                path = pathcheck;
        token = stringTokenizeFunc(path, delim);
        for (token = stringTokenizeFunc(0, delim); token; token = stringTokenizeFunc(0, delim))
        {
                concat = stringCatenator(token, "/");
                concat2 = stringCatenator(concat, cmd);
                freeCharFoluke(concat);
                if (stat(concat2, &st) == 0)
                {
                        /*Found the command in PATH*/
                        free(path);
                        return (concat2);
                }
                freeCharFoluke(concat2);
        }

        freeCharFoluke(path);
        return (0);
}




/**
 * putsFunctn - prints string to std output
 * @s: string (must be NULL terminated)
 *
 * Return: No Return
 */
void putsFunctn(char *s)
{
        write(1, s, stringLengthFunc(s));
}




/* ................................NUM 11 START..............................*/
/**
 * hlpExitFunc - prints help of exit built in
 *
 * Return: No Return
 */
void hlpExitFunc(void)
{
        hlpExitFuncFol();
}
/* ................................NUM 11 BTW................................*/
/**
 * hlpExitFunc - prints help of exit built in
 *
 * Return: No Return
 */
void hlpExitFuncFol(void)
{
        putsFunctn("exit: exit [n]\n");
        putsFunctn("    Exit the shell.\n\n");
        putsFunctn("    Exits the shell with a sttus of N.  ");
        putsFunctn("    If N is omitted, the exit sttus\n");
        putsFunctn("    is that of the last command executed.\n");
}
/* ................................NUM 11 END................................*/



/* ................................NUM 12 START..............................*/
/**
 * hlpEnviron - prints help of env built in
 *
 * Return: No Return
 */
void hlpEnviron(void)
{
        hlpEnvironFol();
}
/* ................................NUM 12 BTW................................*/
/**
 * hlpEnviron - prints help of env built in
 *
 * Return: No Return
 */
void hlpEnvironFol(void)
{
        putsFunctn("env: env\n");
        putsFunctn("    prints the current environment.\n\n");
        putsFunctn("    Has no options\n");
}
/* ................................NUM 12 END................................*/




/* ................................NUM 13 START..............................*/
/**
 * hlpSetEnviron - prints help of setenv built in
 *
 * Return: No Return
 */
void hlpSetEnviron(void)
{
        hlpSetEnvironFol();
}
/* ................................NUM 13 BTW................................*/
/**
 * hlpSetEnviron - prints help of setenv built in
 *
 * Return: No Return
 */
void hlpSetEnvironFol(void)
{
        putsFunctn("setenv: setenv [VARIABLE] [VALUE]\n");
        putsFunctn("    Initializes a new environment var1, ");
        putsFunctn("    or modifies an existing one.\n\n");
        putsFunctn("    VARIABLE must not have the character '='.\n");
        putsFunctn("    If no arguments are given, setenv prints ");
        putsFunctn("    the current environment.\n");
}
/* ................................NUM 13 END................................*/


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
                {"exit", hlpExitFunc},
                {"env", hlpEnviron},
                {"setenv", hlpSetEnviron},
                {"unsetenv", hlpUnSetEnviron},
                {"cd", cdHelp},
                {"help", hlpHlp},
                {"alias", hlpAlias}
        };

        int i = 7;
        int p = 1;

        for (; shpack->options[p]; p++, i = 7)
        {
                while (i--)
                        if (!stringCompare(shpack->options[p], help[i].built))
                                help[i].h(), bcheck = 1;
        }
        if (shpack->options[1] == NULL)
        {
                prntHlp();
                bcheck = 1;
        }
        if (bcheck == 0)
        {
                check = -1;
                errorSetStr(6, shpack, 2);
        }

        free(shpack->options);
        return (check);
}


/* ................................NUM 14 START..............................*/
/**
 * hlpUnSetEnviron - prints help of unsetenv built in
 *
 * Return: No Return
 */
void hlpUnSetEnviron(void)
{
        hlpUnSetEnvironFol();
}
/* ................................NUM 14 BTW................................*/
/**
 * hlpUnSetEnviron - prints help of unsetenv built in
 *
 * Return: No Return
 */
void hlpUnSetEnvironFol(void)
{
        putsFunctn("unsetenv: unsetenv [VARIABLE]\n");
        putsFunctn("    Initializes a new environment var1, or ");
        putsFunctn("    modifies an existing one.\n\n");
        putsFunctn("    VARIABLE must not have the character '='.\n");
        putsFunctn("    If no arguments are given, setenv prints the current ");
        putsFunctn("    environment.\n");
}
/* ................................NUM 14 END................................*/


/* ................................NUM 15 START..............................*/
/**
 * cdHelp - prints help of cd built in
 *
 * Return: No Return
 */
void cdHelp(void)
{
        void cdHelpFol(void);
}
/* ................................NUM 15 BTW................................*/
/**
 * cdHelp - prints help of cd built in
 *
 * Return: No Return
 */
void cdHelpFol(void)
{
        putsFunctn("cd: cd [DIRECTORY]\n");
        putsFunctn("    Change the shell working directory.\n\n");
        putsFunctn("    Change the current directory to DIR.  ");
        putsFunctn("    The default DIR is the val1 of the\n");
        putsFunctn("    HOME shell var1.\n\n");
        putsFunctn("    Options:\n");
        putsFunctn("    -  If a subtracn signed is used instead a directory, ");
        putsFunctn("    cd will change to the\n");
        putsFunctn("       previous used directory\n\n");
        putsFunctn("    Each time cd runs successfuly, the env var1 ");
        putsFunctn("    PWD is updated\n\n");
        putsFunctn("    Exit Status:\n");
        putsFunctn("    Returns 1 if the directory is changed, and if $PWD is set ");
        putsFunctn("    successfully when\n");
        putsFunctn("    is used; -1 otherwise.\n");
}
/* ................................NUM 15 END................................*/



/* ................................NUM 16 START..............................*/
/**
 * hlpHlp - prints help of help built in
 *
 * Return: No Return
 */
void hlpHlp(void)
{
        hlpHlpFol();
}
/* ................................NUM 16 BTW................................*/
/**
 * hlpHlp - prints help of help built in
 *
 * Return: No Return
 */
void hlpHlpFol(void)
{
        putsFunctn("help: help [BUILTIN ...]\n");
        putsFunctn("    Display information about builtin commands.\n\n");
        putsFunctn("    Displays brief summaries of builtin commands.  If BUILTIN is\n");
        putsFunctn("    specified, gives detailed help on all commands ");
        putsFunctn("    matching BUILTIN,\n");
        putsFunctn("    otherwise the list of help topics is printed.\n\n");
        putsFunctn("    Arguments:\n");
        putsFunctn("      BUILTIN   Builtin specifying a help topic\n\n");
        putsFunctn("    Exit Status:\n");
        putsFunctn("    Returns success unless PATTERN is not found or an invalid ");
        putsFunctn("    optn is given.\n");
}
/* ................................NUM 16 END................................*/


/* ................................NUM 17 START..............................*/
/**
 * hlpAlias - prints help of alias built in
 *
 * Return: No Return
 */
void hlpAlias(void)
{
        hlpAliasFol();
}
/* ................................NUM 17 BTW................................*/
/**
 * hlpAlias - prints help of alias built in
 *
 * Return: No Return
 */
void hlpAliasFol(void)
{
        putsFunctn("alias: alias alias [name[='val1'] ...]\n");
        putsFunctn("    Define or display aliases.\n\n");
        putsFunctn("    Without arguments, `alias' prints the list of aliases ");
        putsFunctn("    in the reusable\n");
        putsFunctn("    form `alias NAME=VALUE' on standard output.\n\n");
        putsFunctn("     Otherwise, an alias is defined for each NAME whose ");
        putsFunctn("    VALUE is given.\n");
        putsFunctn("    A trailing space in VALUE causes the next word to ");
        putsFunctn("    be checked for\n");
        putsFunctn("    alias substitution when the alias is expanded.\n\n");
        putsFunctn("    Exit Status:\n");
        putsFunctn("    alias returns true unless a NAME is supplied for which ");
        putsFunctn("    no alias has been\n");
        putsFunctn("    defined.\n");
}
/* ................................NUM 17 END................................*/


/* ................................NUM 18 START..............................*/
/**
 * prntHlp - prints help of help built in
 *
 * Return: No Return
 */
void prntHlp(void)
{
        prntHlpFol();
}
/* ................................NUM 18 BTW................................*/
/**
 * prntHlp - prints help of help built in
 *
 * Return: No Return
 */
void prntHlpFol(void)
{
        putsFunctn("Shell HSH, version 1.0(1)-release (x86_64-pc-linux-gnu)\n");
        putsFunctn("These shell commands are defined internally.\n");
        putsFunctn("Type `help' to see this list.\n");
        putsFunctn("Type help  'BUILTIN'' to find out more about ");
        putsFunctn("the function 'BUILTIN'.\n\n");
        putsFunctn(" exit [n]\n");
        putsFunctn(" env\n");
        putsFunctn(" setenv [VARIABLE] [VALUE]\n");
        putsFunctn(" unsetenv [VARIABLE]\n");
        putsFunctn(" cd [DIRECTORY]\n");
        putsFunctn(" help [BUILTIN ...]\n");
        putsFunctn(" alias [name[='val1'] ...]\n");
}
/* ................................NUM 18 END................................*/

/**
 * freeDobleCharPntrFoluke - frees a double pointer array of strings
 * (must end in NULL)
 *
 * @p: double pointer to free
 *
 * Return: no return
 */
void freeDobleCharPntrFoluke(char **p)
{
        int x, z = 0;

        while (p[z] != 0)
                z++;

        for (x = 0; x < z; x++)
        {
                freeCharFoluke(p[x]);
        }
        free(p);
}


/**
 * cpyDoblePtr - copies an array of strings (double pointer)
 *
 * @p: double pointer to copy
 * @old_size: original size of P
 * @new_size: size of copy
 *
 * Return: Pointer malloec
 */
char **cpyDoblePtr(char **p, int old_size, int new_size)
{
        char **copy;
        int x, copSize;

        if (!p && (old_size == new_size))
                return (NULL);

        if (new_size < old_size)
        {
                copSize = new_size;
                copy = malloc(sizeof(char *) * (copSize + 1));
        }
        else
        {
                copSize = old_size;
                copy = malloc(sizeof(char *) * (new_size + 1));
        }
        if (copy == 0)
                return (0);

        if (p)
                for (x = 0; x < copSize; x++)
                {
                        copy[x] = stringDuplicateFunc(p[x]);
                        if (copy[x] == 0)
                        {
                                x--;
                                for (; x >= 0; x--)
                                        freeCharFoluke(copy[x]);
                                freeDobleCharPntrFoluke(copy);
                                return (0);
                        }
                }
        /* Add Null in the end */
        copy[new_size] = '\0';

        return (copy);
}



/**
 * strLenPtr - calculates length of double pointer (ending in NULL)
 * @s: double pointer
 *
 * Return: Length of double pointer
 *
 */
int strLenPtr(char **s)
{
        int x = 0;

        if (!s)
                return (0);

        while (s[x] != NULL)
                x++;
        return (x);
}



/**
 * setEnvironm - overwrite an env var1 or creates it
 *
 * @env: array of env variables
 * @var1: env var1 to set
 * @val1: val1 to set
 * @shpack: struct with shell info
 *
 * Return: 0 on success, -1 on error
 */
char **setEnvironm(char **env, char *var1, char *val1, hshpack *shpack)
{
        int x, y, check, z = 0, env6 = 0;
        char *catEnvs1, *catEnvs2, *DupCp, **copy;

        if (stringLengthFunc(var1) == 0 || var1 == 0)
                return (errorSetStr(3, shpack, 1), NULL);
        catEnvs2 = stringCatenator(var1, "=");
        if (catEnvs2 == 0)
                return (errorSetStr(3, shpack, 1), NULL);
        catEnvs1 = stringCatenator(catEnvs2, val1), free(catEnvs2);
        if (catEnvs1 == 0)
                return (errorSetStr(3, shpack, 1), NULL);
        z = stringLengthFunc(var1), env6 = strLenPtr(env);
        for (x = 0; env && env[x] != 0; x++)
        {
                for (check = 0, y = 0; y < z && env[x][y] != 0; y++)
                {
                        if (var1[y] == '=')
                                return (free(catEnvs1), errorSetStr(3, shpack, 2), NULL);
                        if (env[x][y] == var1[y])
                                check++;
                }
                if (check == z && env[x][check] == '=')
                {
                        free(env[x]), DupCp = stringDuplicateFunc(catEnvs1), free(catEnvs1);
                        if (DupCp == 0)
                                return (errorSetStr(3, shpack, 1), NULL);
                        return (env[x] = DupCp, env);
                }
        }
        copy = cpyDoblePtr(env, env6, env6 + 1);
        if (env)
                freeDobleCharPntrFoluke(env);
        if (copy == 0)
                return (free(catEnvs1), errorSetStr(3, shpack, 1), NULL);
        env = copy, DupCp = stringDuplicateFunc(catEnvs1), free(catEnvs1);
        if (DupCp == 0)
                return (errorSetStr(3, shpack, 1), NULL);
        return (env[env6] = DupCp, env);
}


/**
 * sigHandlr - handles ctrl + c in runtime
 * @x: unused val1, just for betty
 *
 * Return: No return
 */
void sigHandlr(int x)
{
        (void) x;
        write(1, "\n$ ", 3);
}



/**
 * sigHandlr2 - handles ctrl + c during cmd exec
 * @x: unused val1, just for betty
 *
 * Return: No return
 */
void sigHandlr2(int x)
{
        (void) x;
        write(1, "\n", 1);
}


/* ................................NUM 19 START..............................*/
/**
 * stringCatenator - concatenates two strings
 * @s1: string1
 * @s2: string2
 *
 * Return: Pointer
 */
char *stringCatenator(char *s1, char *s2)
{
        int l1, l2, i, j;
        char *s;
        /* char *nul = ""; */

        if (s1 == NULL)
                s1 = stringCatenatorFol();
        if (s2 == NULL)
                s2 = stringCatenatorFol();

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
/* ................................NUM 19 BTW................................*/
/**
 * stringCatenator - concatenates two strings
 * @s1: string1
 * @s2: string2
 * Return: Pointer
 */
char *stringCatenatorFol()
{
        char *sx;

        return (sx = "");
}

/* ................................NUM 19 END................................*/


/* ................................NUM 20 START..............................*/
/**
 * stringCopy - copy a source input ont destinated input
 * @dest: target where will be stored the input
 * @src: source to copy from
 * Return: dest address
 * On error: -1 inapropiate entry
 */
char *stringCopy(char *dest, char *src)
{
        int i = 0;

        for (i = 0; *(src + i) != '\0'; i++)
                stringCopyFol(dest, src, i);
                /* *(dest + i) = *(src + i); */
        
        stringCopyFol(dest, src, i);
        /* *(dest + i) = *(src + i); */ /* adding '\0' character */

        return (dest);
}
/* ................................NUM 20 BTW................................*/
/**
 * stringCopy - copy a source input ont destinated input
 * @dest: target where will be stored the input
 * @src: source to copy from
 * Return: dest address
 * On error: -1 inapropiate entry
 */
char stringCopyFol(char *destinatn, char *source, int i)
{
        *(destinatn + i) = *(source + i);
        return (*(destinatn + i));
}
/* ................................NUM 20 END................................*/



/**
 * stringLengthFunc - function that returns the length of a string
 * @s: string address
 *
 *
 * Return: nothing
 * On error: -1 inapropiate entry
 */

int stringLengthFunc(char *s)
{
        return ((!*s) ? 0 : 1 + stringLengthFunc(s + 1));
}


/**
 * stringDuplicateFunc - function that returns a pointer to a newly allocated space
 * in memory, which contains a copy of the string given as a parameter
 * @str: source to copy
 *
 *
 * Return: address where is stored the result
 * On error: -1 inapropiate entry
 */

char *stringDuplicateFunc(char *str)
{
        char *arr;

        if (!str)
                return (NULL);

        arr = malloc((stringLengthFunc(str) * sizeof(*arr)) + 1);

        if (!arr)
                return (NULL);

        stringCopy(arr, str);

        return (arr);
}

/* ................................NUM 21 START..............................*/
/* ................................NUM 21 BTW................................*/
/* ................................NUM 21 END................................*/
/**
 * stringTokenizeFunc - tokenizes a string based on a delimiter
 *
 * @str: string to operate
 * @delim: delimiter
 *
 * Return: pointer to string
 * or NULL if there is no match
 *
 */
char *stringTokenizeFunc(char *str, const char *delim)
{
        const char *C_org = delim;
        int issEql = 1, issGetInto = 0;
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
        while (*str && issEql)
        {
                issEql = 0;
                for (delim = C_org; *delim; delim++)
                        if (*str == *delim)
                                issEql = 1;
                str = (!issEql) ? str : str + 1;
                isEnd = (*str) ? 0 : 1;
                if (isEnd)
                        return (NULL);
        }
        step = str;
        while (*str && !issEql)
        {
                issEql = 0;
                for (delim = C_org; *delim; delim++)
                        if (*str == *delim)
                        {
                                issGetInto = 1, issEql = 1;
                                isEnd = (*(str + 1)) ? 0 : 1, *str = '\0';
                        }
                str = (issEql) ? str : str + 1;
                if (!issGetInto && !*str)
                        isEnd = 1;
        }
        return (stepNull = str, step);
}


/**
 * cpyDoblePtrDel - copies an array of strings (double pointer)
 *
 * @p: double pointer to copy
 * @new_size: size of copy
 * @jump: val1 that must be skipped in copy
 *
 * Return: Pointer malloec
 */
char **cpyDoblePtrDel(char **p, int new_size, int jump)
{
        char **copy;
        int i, j, copSize;

        copSize = new_size;
        copy = malloc(sizeof(char *) * (copSize + 1));
        if (copy == 0)
                return (0);

        for (i = 0, j = 0; j < copSize; i++, j++)
        {
                if (i == jump)
                        i++;
                copy[j] = stringDuplicateFunc(p[i]);
                if (copy[j] == 0)
                {
                        j--;
                        for (; j >= 0; j--)
                                free(copy[j]);
                        freeDobleCharPntrFoluke(copy);
                        return (0);
                }
        }

        copy[new_size] = '\0';

        return (copy);
}

/**
 * unSetEnviron - unsets an enviromental var1
 *
 * @env: array of env variables
 * @var1: env var1 to unset
 * @shpack: struct with shell info
 *
 * Return: 0 on success, -1 on error
 */
char **unSetEnviron(char **env, char *var1, hshpack *shpack)
{
        int i, j, check, l = 0, lenv = 0, found = 0;
        char **copy;

        shpack->unsetnull[0] = 0;
        if (!env)
                return (write(2, "Environment is NULL\n", 20), NULL);
        if (stringLengthFunc(var1) == 0 || var1 == 0)
                return (errorSetStr(3, shpack, 1), NULL);
        l = stringLengthFunc(var1), lenv = strLenPtr(env);
        for (i = 0; env[i] != 0; i++)
        {
                for (check = 0, j = 0; j < l && env[i][j] != 0; j++)
                {
                        if (var1[j] == '=')
                                return (errorSetStr(3, shpack, 2), NULL);
                        if (env[i][j] == var1[j])
                                check++;
                }
                if (check == l && env[i][check] == '=')
                {
                        /* Found env to erase */
                        found = 1;
                        if ((lenv - 1) != 0)
                        {
                                copy = cpyDoblePtrDel(env, lenv - 1, i);
                         if (copy == 0)
                                        return (errorSetStr(7, shpack, 1), NULL);
                        }
                        else
                                shpack->unsetnull[0] = 1, copy = NULL;
                        freeDobleCharPntrFoluke(env), env = copy;
                        return (env);
                }
        }
        if (found == 0)
                return (write(2, "VARIABLE not found\n", 19), NULL);
        return (env);
}
