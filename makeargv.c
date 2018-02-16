// Program 2.2 from textbook
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int makeargv(const char *s, const char *delimiters, char ***argvp) {
	int error;
	int i;
	int numtokens;
	const char *snew;
	char *t;

	if ((s == NULL) || (delimiters == NULL) || (argvp == NULL))
	{
		errno = EINVAL;
		return -1;
	}
	*argvp = NULL;
	snew = s + strspn(s, delimiters);	// snew is real start of string
	if ((t = malloc(strlen(snew) + 1)) == NULL)
		return -1;
	strcpy(t, snew);
	numtokens = 0;
	if (strtok(t, delimiters) != NULL)	// count the number of tokens in s
		for (numtokens = 1; strtok(NULL, delimiters) != NULL; numtokens++);
	// create argument array for ptrs to the tokens
	if ((*argvp = malloc((numtokens + 1) * sizeof(char *))) == NULL)
	{
		error = errno;
		free(t);
		errno = error;
		return -1;
	}
	// insert pointers to tokens into the argument array
	if (numtokens == 0)
		free(t);
	else
	{
		strcpy(t, snew);
		**argvp = strtok(t, delimiters);
		for (i = 1; i < numtokens; i++)
			*((*argvp) + i) = strtok(NULL, delimiters);
	}
	
	*((*argvp) + numtokens) = NULL;	//put in final null pointer
	return numtokens;
}






/*
// makeargv.c 
// takes a null terminated string s, and a string of delimiters and returns 
// an array of char * pointers, leaving argvp pointing to that array.
// each of the array locations points to a null terminated "token" found in s
// defined by the delimiter array. The number of tokens found is returned by makeargv
#include <string.h>
#include <stdlib.h>
/*
<<<<<<< HEAD
 * Make argv array (*arvp) for tokens in s which are separated b
 * * delimiters.	Return -1 on error or the number of tokens otherwise.
 */
=======
 * Make argv array (*arvp) for tokens in s which are separated by
 * delimiters. Return -1 on error or the number of tokens otherwise.
 *
>>>>>>> testing
int makeargv(char *s, char *delimiters, char ***argvp) {
	char *t;
	char *snew;
	int numtokens;
	int i;
<<<<<<< HEAD
	 //snew is real start of string after skipping leading delimiters */
 	snew = s + strspn(s, delimiters);
	//create space for a copy of snew in t */
	if ((t = calloc(strlen(snew) + 1, sizeof(char))) == NULL) {
		*argvp = NULL;
		numtokens = -1;
	} else {							/* count the number of tokens in snew */
=======
	/* snew is real start of string after skipping leading delimiters *
 	snew = s + strspn(s, delimiters);
	/* create space for a copy of snew in t *
	if ((t = calloc(strlen(snew) + 1, sizeof(char))) == NULL) {
		*argvp = NULL;
		numtokens = -1;
	}
	else {
		/* count the number of tokens in snew *
>>>>>>> testing
		strcpy(t, snew);
		if (strtok(t, delimiters) == NULL)
			numtokens = 0;
		else
<<<<<<< HEAD
			for (numtokens = 1; strtok(NULL, delimiters) != NULL; numtokens++);	
			// create an argument array to contain ptrs to tokens
		if ((*argvp = calloc(numtokens + 1, sizeof(char *))) == NULL) {
=======
			for (numtokens = 1; strtok(NULL, delimiters) != NULL; numtokens++);  
		 /* create an argument array to contain ptrs to tokens *
 		if ((*argvp = calloc(numtokens + 1, sizeof(char *))) == NULL) {
>>>>>>> testing
			free(t);
			numtokens = -1;
		}
		else {				/* insert pointers to tokens into the array *
			if (numtokens > 0) {
				strcpy(t, snew);
				**argvp = strtok(t, delimiters);
				for (i = 1; i < numtokens + 1; i++)
					*((*argvp) + i) = strtok(NULL, delimiters);
			}
			else {
				**argvp = NULL;
				free(t);
			}
		}
	}	
	return numtokens;
}
*/
