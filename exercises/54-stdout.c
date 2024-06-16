/* Under what circumstances will this program finish with success or failure return codes? 
==========================================================================================
The output of the code will depend on the files specified as command-line arguments. The program 
reads each file and prints its contents to the standard output.  If all specified files can be 
successfully opened and read, their contents will be printed to the standard output. If any file 
cannot be opened, an error message will be printed to the standard error stream, indicating the 
reason for the failure to open the file.*/
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
enum { buf_max = 32, };
int main(int argc, char *argv[argc + 1])
{
    int ret = EXIT_FAILURE;
    char buffer[buf_max] = { 0 };
    for (int i = 1; i < argc; ++i) {
	// Processes args
	FILE *instream = fopen(argv[i], "r");	// as filenames
	if (instream) {
	    while (fgets(buffer, buf_max, instream)) {
		fputs(buffer, stdout);
	    }
	    fclose(instream);
	    ret = EXIT_SUCCESS;
	    printf("Success");
	} else {
	    /* Provides some error diagnostic . */
	    fprintf(stderr, " Could not open %s:", argv[i]);
	    perror(0);
	    errno = 0;
	    // Resets the error code
	    printf("Failure");
	}
    }

    return ret;
}
