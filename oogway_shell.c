#include "oogway_shell.h"

int main(int argc, char *argv[]) {
	char input_buffer[MAX_LINE]; // Typespace array for shell commands
	char cwd[MAX_LINE]; // Buffer for current working directory path
	char shell_path[MAX_LINE]; // Buffer for the shell path
	FILE *input_stream = stdin;

	// Creating shell path
	if (getcwd(cwd, sizeof(cwd)) != NULL) {
		strcpy(shell_path, cwd);
		strcat(shell_path, "/oogway_shell");
	}
	else {
		perror("Could not determine shell path");
	}

	//Batch Mode Logic
	if (argc == 2) {
		input_stream = fopen(argv[1], "r");
		// Batch file error handling
		if (input_stream == NULL) {
			perror("Error opening batch file");
			exit(1);
		}
	}

	// Main Program Loop
	while (1) {
		char prompt_path[MAX_LINE];

		if (input_stream == stdin) {
			getcwd(prompt_path, sizeof(prompt_path));
			printf("oogway_shell:%s$ ", prompt_path);
		}
		else {
			printf("oogway_shell$ ");
		}
		fflush(stdout); // Flushing stdout for instantanous output

		// Exit program handling
		if (fgets(input_buffer, MAX_LINE, input_stream) == NULL) {
			break;
		}

		// Call Utility.c file
		process_command(input_buffer, shell_path);
	}

	if (input_stream != stdin) {
		fclose(input_stream);
	}
	return 0;
}
