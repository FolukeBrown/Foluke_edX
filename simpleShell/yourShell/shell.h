#ifndef SHELL_H
#define SHELL_H

#define BSIZE 4

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <signal.h>
#include <sys/wait.h>

/**
 * struct Hshpack - struct containing important shell info
 * @hshname: name of the shell (argv[0])
 * @buffer: full buffer written in prompt
 * @cmd: command written after prompt
 * @options: options of the command
 * @path: path of the cmd if found, else cmd itself
 * @errnum: error count
 * @exitnum: number of exit that the shell will have
 * @relation: true or false for logical operators
 * @run_able: check for running or not a command
 * @next: singly list link
 * @envCpy: copy of environment
 * @unsetnull: check for setting environment to NULL
 *
 * Description: Struct containing important shell info
 *
 */
typedef struct Hshpack
{
	char *hshname;        /* Name of shell argv[0] */
	char *buffer;         /* complete line written in prompt */
	char *cmd;            /* current command */
	char **options;       /* options of current command */
	char *path;           /* absolute path of command */
	int *errnum;          /* error number for message */
	int *exitnum;         /* exit number */
	int *relation;        /* 0 Undef, 1 ||, 2 && */
	int *run_able;        /* 0 False 1 True (Is able to run)*/
	struct Hshpack *next; /*adress of next cmd to run */
	char ***envCpy;       /* current environment */
	int *unsetnull;       /*check for setting environment to NULL */

} hshpack;

/**
 * struct b_ins - struct for built ins
 * @cmd: built in
 * @f: function of built in
 *
 * Description: Struct for calling built in functions
 *
 */
typedef struct b_ins
{
	char *cmd;
	ssize_t (*f)(hshpack *shpack);
} b_ins;

/**
 * struct Helps - struct for built ins
 * @built: built in command
 * @h: help function of built in
 *
 * Description: Struct for calling built in functions
 *
 */
typedef struct Helps
{
	char *built;
	void (*h)(void);
} helps;




char *fetchEnviron(const char *name, char **env);
char *_path(char *cmd, char **env, hshpack *shpack);
char *_strdup(char *str);
char *str_concat(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strtok(char *str, const char *delim);
char **getParameters(char *buffer, hshpack *shpack);
int executeCmd(char *program, char *command[], char **env, hshpack *shpack);
void signal_handler(int x);
void signal_handler2(int x);
int _getline(char **buffer, size_t *bufsize, int fd);
void free_doubpoint(char **p);
int _strlendp(char **s);
char **checkInput(int ac, char **av, size_t *bufsize,
		  char **buffer, hshpack *shpack);
hshpack *set_struct(char *argv0, int *errn, int *exnum, int *relation,
		    int *run_able, char ***env, int *unsetnull);
int _error(int errn, hshpack *shpack, int exnum);
void addCmd(hshpack *shpack, char *buffer, char *command, char **parameters);
void addPathToCmd(hshpack *shpack, char *pathCmd);
ssize_t built_ints(hshpack *shpack);
ssize_t exitCmd(hshpack *shpack);
int stringCompare(char *s1, char *s2);
long atoiFol(char *s);
long powerFunc(long base, long pot);
char **_copydoublep(char **p, int old_size, int new_size);
int _strlendp(char **s);
char **_setenv(char **env, char *variable, char *value, hshpack *shpack);
char **_unsetenv(char **env, char *variable, hshpack *shpack);
int isDigitFunc(int c);
int isNumba(char *s);
ssize_t _cd_cmd(hshpack *shpack);
char *delComnt(char *str);


ssize_t _help_cmd(hshpack *shpack);
void _puts(char *s);
void help_unsetenv(void);
void help_cd(void);
void help_help(void);
void help_alias(void);
void printsHelp(void);

void freeCharFoluke(char *temp);

void string_reverse(char *s);
void string_reverseSub(char *s, char tmp, int x, int y);
int lenBTen(unsigned long int n, unsigned long int base);
char *_itoa(int n);
char *errorSub(int errn, char *concB, char *optn);
ssize_t envCmd(hshpack *shpack);
ssize_t setEnvironCmd(hshpack *shpack);
ssize_t unSetEnvironComnd(hshpack *shpack);
char *secAuxCd(hshpack *shpack, char *currdir);
char *secAuxCdDaf(char *home, char *dire);
char *firstAuxCd(hshpack *shpack, char *currdir);
ssize_t cDirCmnd(hshpack *shpack);
long powerFuncDaf(long base, long res);
long atoiFolDaf(long subtracn);
char *memorySet(char *s, char b, unsigned int n);
char *memoryCopy(char *dest, char *src, unsigned int n);
void *reAllocateFunc(void *ptr, unsigned int old_size, unsigned int new_size);


#endif
