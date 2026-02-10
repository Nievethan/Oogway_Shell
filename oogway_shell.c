#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 1024 // Line size limit
#define MAX_ARGS 64 // Argument quantity limit

int main(int argc, char *argv[]) {
	// Remove these later
	(void)argc;
	(void)argv;

	char input_buffer[MAX_LINE]; // Typespace array for shell commands
	char *args[MAX_ARGS]; // Character pointer holding the arguments
	char cwd[MAX_LINE]; // Buffer for current working directory path
	char shell_path[MAX_LINE]; // Buffer for the shell path
	
	// Creating shell path
	if (getcwd(cwd, sizeof(cwd)) != NULL) {
		strcpy(shell_path, cwd);
		strcat(shell_path, "/oogway_shell");
	}
	else {
		perror("Could not determine shell path");
	}

	// Main Program Loop
	while (1) {
		int i = 0; // Counter reset with program

		printf("oogway_shell$ "); // Primary prompt string
		fflush(stdout); // Flushing stdout for instantanous output

		// Exit program handling
		if (fgets(input_buffer, MAX_LINE, stdin) == NULL) {
			break;
		}

		args[i] = strtok(input_buffer, " \t\n"); // Parsing the first argument

		// Loop throught the rest of the arguments
		while (args[i] != NULL) {
			i++;
			args[i] = strtok(NULL, " \t\n");
		}

		// Handling user hitting "enter" with no command
		if (args[0] == NULL) {
			continue; 
		}

		// QUIT command
		if (strcmp(args[0], "quit") == 0) {
			exit(0);
		}
		// CLEAR command
		else if (strcmp(args[0], "clr") == 0) {
			system("clear");
		}
		// CHANGE DIRECTORY command
		else if (strcmp(args[0], "cd") == 0) {
			if (args[1] == NULL) {
				if (getcwd(cwd, sizeof(cwd)) != NULL) {
					printf("%s\n", cwd);
				}
				else {
					perror("oogway_shell");
				}
			}
			else {
				if (chdir(args[1]) == -1) {
					perror("Directory not found");
				}
				else {
					if (getcwd(cwd, sizeof(cwd)) != NULL) {
						setenv("PWD", cwd, 1);
					}
				}
			}
		}
		else {
			// Creating child process
			pid_t pid = fork();
			
			// Fork fail handling
			if (pid < 0) {
				perror("Fork failed");
				exit(1);
			}
			// Child Process
			else if (pid == 0) {
				setenv("parent", shell_path, 1);
				// Invalid command error handling
				if (execvp(args[0], args) == -1) {
					perror("Command execution failed");
				}
				exit(1);
			}
			// Parent Process
			else {
				int status;
				waitpid(pid, &status, 0);
			}
		}
	}
	return 0;
}
