#ifndef OOGWAY_SHELL_H
#define OOGWAY_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define MAX_ARGS 64

void process_command(char *input_buffer, char *shell_path);

#endif
