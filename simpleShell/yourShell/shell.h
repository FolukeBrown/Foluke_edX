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
	char *hshname;		  /* Name of shell argv[0] */
	char *buffer;		  /* complete line written in prompt */
	char *cmd;			  /* current command */
	char **options;		  /* options of current command */
	char *path;			  /* absolute path of command */
	int *errnum;		  /* error number for message */
	int *exitnum;		  /* exit number */
	int *relation;		  /* 0 Undef, 1 ||, 2 && */
	int *run_able;		  /* 0 False 1 True (Is able to run)*/
	struct Hshpack *next; /*adress of next cmd to run */
	char ***envCpy;		  /* current environment */
	int *unsetnull;		  /*check for setting environment to NULL */

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
char *searchPath(char *cmd, char **env, hshpack *shpack);
char *stringDuplicateFunc(char *str);
char *stringCatenator(char *s1, char *s2);
int stringLengthFunc(char *s);
char *stringCopy(char *dest, char *src);
char *stringTokenizeFunc(char *str, const char *delim);
char **fetchParam(char *buffer, hshpack *shpack);
int excuteCmd(char *program, char *command[], char **env, hshpack *shpack);
void sigHandlr(int x);
void sigHandlr2(int x);
int fetchLine(char **buffer, size_t *bufsize, int fd);
int strLenPtr(char **s);
char **chckInputFunc(int ac, char **av, size_t *bufsize,
					 char **buffer, hshpack *shpack);
hshpack *shellStructDef(char *argv0, int *errn, int *exnum, int *relation,
						int *run_able, char ***env, int *unsetnull);
int errorSetStr(int errn, hshpack *shpack, int exnum);
void addComnd(hshpack *shpack, char *buffer, char *command, char **parameters);
void addPath2Comnd(hshpack *shpack, char *pathCmd);
ssize_t chckBuiltIn(hshpack *shpack);
ssize_t exitCmdFunc(hshpack *shpack);
int stringCompare(char *s1, char *s2);
long atoiFol(char *s);
long powerFunc(long base, long pot);
char **cpyDoblePtr(char **p, int old_size, int new_size);
char **setEnvironm(char **env, char *variable, char *value, hshpack *shpack);
char **unSetEnviron(char **env, char *variable, hshpack *shpack);
int isDigitFunc(int c);
int isNumba(char *s);
ssize_t cdComndFunc(hshpack *shpack);
char *delComnt(char *str);

ssize_t _help_cmd(hshpack *shpack);
void putsFunctn(char *s);
void hlpUnSetEnviron(void);
void cdHelp(void);
void help_help(void);
void help_alias(void);
void printsHelp(void);

void freeCharFoluke(char *temp);
void freeDobleCharPntrFoluke(char **p);

void string_reverse(char *s);
void string_reverseSub(char *s, char tmp, int x, int y);
int lenBTen(unsigned long int n, unsigned long int base);
char *_itoa(int n);
char *errorSub(int errn, char *concB, char *optn);
ssize_t envCmd(hshpack *shpack);
ssize_t setEnvironCmd(hshpack *shpack);
ssize_t unSetEnvironComnd(hshpack *shpack);
char *secAuxCd(hshpack *shpack, char *currdir);
char *secAuxCdFol(char *home, char *dire);
char *firstAuxCd(hshpack *shpack, char *currdir);
ssize_t cDirCmnd(hshpack *shpack);
long powerFuncFol(long base, long res);
long atoiFolFol(long subtracn);
char *memorySet(char *s, char b, unsigned int n);
char *memoryCopy(char *dest, char *src, unsigned int n);
void *reAllocateFunc(void *ptr, unsigned int old_size, unsigned int new_size);
int stringCompareFol(char *s1, char *s2, int x);
char delComntFol(char str);
char memorySetFol(char *s, char b, unsigned int x);
char memoryCopyFol(char *dest, char *src, unsigned int x);
char *pthChcker(char *path);
char pthChckerFol(char *path, char *npath, int x, int y);
void hlpExitFunc(void);
void hlpExitFuncFol(void);
void hlpEnviron(void);
void hlpEnvironFol(void);
void hlpSetEnviron(void);
void hlpSetEnvironFol(void);
void hlpUnSetEnviron(void);
void hlpUnSetEnvironFol(void);
void hlpHlp(void);
void hlpHlpFol(void);
void hlpAlias(void);
void hlpAliasFol(void);
void prntHlp(void);
void prntHlpFol(void);
char *stringCatenator(char *s1, char *s2);
char *stringCatenatorFol();
char stringCatenatorFol2(char *sx, char *sy, int k);
char stringCopyFol(char *destinatn, char *source, int i);

#endif
