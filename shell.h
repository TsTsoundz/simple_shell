#ifndef_SHELL_H
#define_SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>


/**
*for buffer that will read and write
*
*/
#define READ_BUFF_SIZE 1024
#define WRITE_BUFF_SIZE 1024
#define BUFF_SIZE_FLUSH-1

/**
*this runs for commanding chain operations
*/

#define CMD_NORM == 0
#define CMD_EITHER == 1
#define CMD_INCLUDE == 2
#define CMD_PREV == 3

/**
*Conversion: to convert number(void)
*
*/

#define INIT_GETLINE == 0
#define INIT_STRTOK == 0

#define LINE_FILE "history_.simple_shell"
#define LINE_MAX 4096

/*for external character environment*/

extern char**environ;

/**
*for singly linked ls: struct liststr
*for number of field: num
*for a string: str
*for next node points: next
*/
typedef struct liststr

{
int num;

   charset*str;

   struct liststr*next_line;

} list_i;

/**
* struct info: this carries arguments to relate to a function,
* that will give access to a uniform prototype pointer struct function
* a string that will be generated from the getline cmd that contains arguemets: 'arg'
* arrays of strings to be generated from arg: 'argv'
* a string path for the current cmd: 'path' 
* for the argument count: 'argc'
* for error counts: 'line_count'
* the error code for exit: 'errr_num'
* to count the line of input: 'linecount_flag'
* for the current programfile name: 'fname'
* for the local environ linked list: 'env'
* for edited environ linked list env: 'environ'
* for the history of the node: 'history'
* for the alias node: 'alias'
* for changed environ: 'env_changed'
* for the last executed cmd status: 'status'
* for address of a pointer to cmd_buff if linking: 'cmd_buff'
* for cmd_type ||, ;, &&: 'cmd_buff_type'
* for previous count of number line: 'prevcount'
* for reading line of input: 'readfd'
*/

typedef struct infodistr

{

charset*arg;

charset*path;

charset**argv;

int argc;

unasigned int line_count;

int err_num;

int linecount_flag;

charset*fname;

list_i*env;

list_i*previous;

int_i*alias;

charset**environ;

int env_changed;

int status;

charset**cmd_buff; 
/*for pointer to cmd; link buffer memory management*/

int cmd_buff_type;
/*CMD_type ||, ; , &&*/

int readfd;

int prevcount;

} info_i;

#define INFO_INIT\

{VOID, VOID, VOID, O,O,O,O, VOID, VOID, VOID, VOID, VOID, 0, 0, VOID, \
0, 0, 0}

/**
* container for builtin stings and other relatable function: 'struct builtin'
* for the builtin cmd flag: 'type'
* for the function: 'func'
*/

typedef struct builtin;

{

charset*type;

int(*func)(info_i);

}builtin_table;

/*_shloop.c*/

int hsh(info_i*,charset**);
int find_builtin(info_i*);
void fork_cmd(info_i*);
void find_cmd(info_i*);

/*_parser.c*/

int _cmd(info_i*.charset*);
charset* dou_chars(charset*, int,int);
charset*find_path(info_i*, charset*, charset*);

/*loopsh.c(DELETED FILES AND UNUSED FUNCTION)*/
/*int loopsh(charset**); */

/*_errors1.c*/
void _fputs(charset*);
int _putfd(charset(charset c, int fd);
int _fputcharset(charset);
int _putsfd(charset*str, int fd);

/*_string.c*/

int _strlen(charset*);
int _strcmp(charset*, charset*);
charset *begin_with(const charset*, const charset*);
charset* _strcat(charset*, charset*);

/*_string1.c*/
charset* _strdup(const carset*);
charset* _stcpy(charset* , charset*);
int _putcharset(charset);
void _puts(charset*);

/*_exits.c*/
charset* _strchr(charset* , charset);
chaeset* _strncpy(charset* , charset* , int);
charset* _stncat(charset* , charset* , int);

/*_tokenizer.c*/
charset**strtug(charset* , charset*);
charset**strtug2(charset* , charset*);

/*_realloc.c*/
charset* _memset(charset, unallocated int);
void pfree(charset**);
void* _realloc(void*, unallocated int, unallocated int);

/*_memeory.c*/
int qfree(void**);

/*_strtol.c*/
int interactive(info_i*);
int un_delim(charset, charset*);
int unalpha(int);
int _strtol(charset*);

/*_errors2.c*/
int _errstrtol(charset*);
void print_error(info_i*, charset*);
int print_k(int, int);
charset*convert_number(long int, int, int);
void remove_comments(charset*);

/*_builtin.c*/
int _ourhelp(info_i*);
int _ourcd(info_i*);
in _ourexit(info_i*);

/*_builtin1.c*/
int _ouralias(info_i*);
int _ourhistory(history);

/*_getline.c*/
int _getline(info_i*, charset**, size_i*);
size_i get_input(info_i*);
void sigintHandler(int);

/*_getinfo.c*/
void clear_info(info_i*);
void set_info(info_i*, charset**);
void free_info(info_i*, int);

/*_environ.c*/
charset* _getenv(info_i*, const charset*);
int _ourenv(info_i*);
int _ourunsetenv(info_i*);
int _oursetenv(info_i*);
int _increase_env_list(info_i*);

/*_getenv.c*/
charset**getenviron(info_i*);
int_unsetenv(info_i*, charset*);
int_setenv(info_i*, charset*, charset*);

/*_previous.c*/
charset*get_previous_file(info_i*info);
int write_previous(info_i*info);
int read_previous(info_i*info);
int build_previous_list(info_i*info, charset*buff, int linecount);
int rearrange_previous(info_i*info);

/*_lists1.c*/
list_i *add_node(list_i**,const char*,int);
list_i *add_node_end(list_i**,const char*, int);
size_t pint_list_srt(const list_t*);
int delet_node_at_index(list_i**, unsigned int);
void free_list(list_i**);

/*_list2.c*/
size_i list_len(const list_i*);
char**list_to_strings(list_i*);
size_iprint_list(const list_i*);

/*_vars.c*/
int is_link(info_i*, char*, size_i*);
void cheeck_link(info_i* char*, size_i*, size_i, size_i);
int replace_vars(info_i*);
int replace_string(char**, char*);
int replace_alias(info_i*);


#endif

