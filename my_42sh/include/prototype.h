/*
** EPITECH PROJECT, 2018
** prototype.h
** File description:
** prototype for my_runner
*/

#ifndef __PROTOTYPE_H__
#define __PROTOTYPE_H__
#include "my.h"

/*main.c*/
int main(int ac, char **av, char **env);

/*signal.c*/
void my_signal(void);
void my_signal_sigint(int sig);
void my_signal_sigsegv(int sig);
void my_signal_sigfpe(int sig);

/*my_shell.c*/
int my_shell(t_node *envCpy);
void set_executable_command(char ***commands, t_node *envCpy);
int execute_command(char ***commands, int *index, t_fds *fds, t_node *envCpy);
int execute_complex_command(char ***commands, int *index,
    t_fds *fds, t_node *envCpy);
int check_fail(int status, char ***commands, int index);

/*
** entry_commands_treatment
*/

/*get_commands.c*/
char ***get_commands(char ***commands);
char ***free_commands(char ***commands);
char ***check_entry(char ***commands, char *entry);
int check_last_operator(char ***commands);

/*entry_checking.c*/
int count_command_nb(char *entry);
int command_nb_operator(char *entry, int index, int *nb);

/*entry_parsing.c*/
void parse_entry(char *entry, char ***commands, int commandNb);
char **str_to_tab(char *str);
char **str_to_tab_malloc(char *str, char **tab);
void parse_in_strings(char *entry, char **commands_str);
char *command_dup_cut(char *entry);

/*
** operator
*/

/*operator_gestion.c*/
int operator_switch(char ***commands, int *index, t_fds *fds);
void pipe_operator(t_fds *fds);
int greater_than_operator(char ***commands, int *index, t_fds *fds);
void greater_than_operator_set_fd(t_fds *fds, int fd);
int less_than_operator(char ***commands, int *index, t_fds *fds);

/*
** command execution
*/

/*run_command.c*/
int run_command(char **command, t_fds *fds, t_node *envList);
void run_command_redirection(t_fds *fds);
void run_command_close(t_fds *fds, int saveIn, int saveOut);

/*command_treatment.c*/
int treat_command(char *entry, t_node *envList);
int treat_command_sec(char *entry, t_node *envList);
int treat_command_thd(char *entry, t_node *envList);
int exit_value(char *entry, t_node *envList);
int other_entry(char *entry, t_node *envList);

/*other_command.c*/
int system_command(char *entry, t_node *envList);
void free_double_array(char **array);
int try_execute_command(char *entry, char **env, char **pathList);
void forking_execution(char *path, char **arg, char **env);

/*parse_info.c*/
char *get_function_name(char *entry);
char **get_arg_name(char *entry);
char **get_arg_name_malloc(char *entry, int count, int index);

/*path.c*/
char **get_path(t_node *envList);
char **str_to_arr(char *str, int start, char **result);
char **malloc_path(char *path);
int path_nb(char *str);

/*command_execution_tools.c*/
int check_parity(char *a, char *b, int toTheEnd);
char *str_join(char *str1, char *str2);
char *tab_to_str(char **tab);

/*
** built_in
*/

/*my_cd.c.c*/
int my_cd(char *entry, t_node *head);
int my_cd_empty(t_node *head);
int my_cd_action(char *path, t_node *head);
int my_cd_pwd(t_node *head);
int check_cd_dash(char *entry, int index, int *result, t_node *head);
int my_cd_oldpwd_action(t_node *head);
char *check_cd_oldpwd(t_node *traveler, char *tmp);
int my_cd_oldpwd(t_node *head);

/*shell_unsetenv.c*/
int my_unsetenv(t_node *head, char *entry);
void my_unsetenv_sec(t_node *trav, t_node *travSave, char **arg);
char **my_unsetenv_get_arg(char *argStr);
int my_unsetenv_check(char *entry, t_node *traveler, char **arg);
t_node *verify_path_existance(t_node *head);

/*shell_env_setenv.c*/
int my_env(t_node *head);
int my_setenv(t_node *head, char *entry);
void my_setenv_sec(t_node *head, char *arg1, char *arg2);
char *my_setenv_create_arg(char *args, int whichOne);
int check_setenv_syntax(char *arg1, char *arg2);

/*
** printing
*/

/*display.c*/
void display_prompt(void);

/*print.c*/
void my_putchar(char c);
void my_putchar_error(char c);
void my_putstr(char const *str);
void my_putstr_error(char const *str);
void my_put_nbr(int nb);

/*
** tools
*/

/*tools.c*/
int str_to_int(char *str);
int is_a_number(char *str);

/*str_tools.c*/
char *my_strdup(char *str);
int my_strlen(char *str);
char *clean_str(char *str);
int clean_str_count_malloc(char *str, int index);

/*linked_list.c*/
t_node *linked_list_store(char **dubArray);
t_node *linked_list_add(t_node *head, char *str);
void free_linked_list(t_node *head);
char **linked_list_to_array(t_node *head);

/*echo*/
int echo_command_center(char *str);
int set_switches(t_echo *echo);
int print_hub(t_echo *echo);
int set_switches_two(t_echo *echo, int line);

/*echo_tools*/
int nbr_of_arg(char *str);
int strlen_to_space(char *str);
char *my_strcpy(char *src);
char *adress_move(char *str);
int check_switches(t_echo *echo, int line, int point);

/*echo_fct*/
int switch_print_reverse(char a);
int finale(t_echo *echo);
int print(t_echo *echo, int line);
int check_quotes(t_echo *echo, int index);

#endif