#include "oogway_shell.h"

void process_command(char *input_buffer, char *shell_path) {
	char *args[MAX_ARGS]; // Character pointer for holding arguements
	char cwd[MAX_LINE]; // Buffer for current working directory path
	int i = 0; // Counter resets with the program

	args[i] = strtok(input_buffer, " \t\n"); // Parsing through first argument
	// Looping through all other arguments
	while (args[i] != NULL) {
		i++;
		args[i] = strtok(NULL, " \t\n");
	}

	// No argument handling
	if (args[0] == NULL) {
		return;
	}
	
	// QUIT command
	if (strcmp(args[0], "quit") == 0) {
		exit(0);
	}
	// CLEAR command
	else if (strcmp(args[0], "clear") == 0) {
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

			// Scan for every argument
			for (int k = 0; args[k] != NULL; k++) {
				// Output redirection
				if (strcmp(args[k], ">") == 0) {
					args[k] = NULL;

					char *filename = args[k+1];
					if (filename != NULL) {
						freopen(filename, "w", stdout);
					}
				}
				// Input redirection
				else if (strcmp(args[k], "<") == 0) {
					args[k] = NULL;
					
					char *filename = args[k+1];
					if (filename != NULL) {
						freopen(filename, "r", stdin);
					}
				}
				// Append redirection
				else if (strcmp(args[k], ">>") == 0) {
					args[k] = NULL;

					char *filename = args[k+1];
					if (filename != NULL) {
						freopen(filename, "a", stdout);
					}
				}
			}
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

