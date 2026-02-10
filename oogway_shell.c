#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE 1024 // Line size limit
#define MAX_ARGS 64 // Argument quantity limit

int main(int argc, char *argv[]) {
	// Remove these later
	(void)argc;
	(void)argv;

	char input_buffer[MAX_LINE]; // Typespace array for shell commands
	char *args[MAX_ARGS]; // Character pointer holding the arguments

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

		// Testing if the parsing works
		for (int j = 0; args[j] != NULL; j++) {
			printf("Token %d: %s\n", j, args[j]);
		}
	}

	return 0;
}
