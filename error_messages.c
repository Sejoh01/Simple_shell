#include <unistd.h>
#include "shell.h"
#include "main.h"
/**
 * write_error - write error message to stderr
 * @params: parameters struct containing info about the command and program
 * @msg: error message to print
 *
 * This function takes a parameter struct containing information about current
 * command and program and an error message to print to stderr. The function
 * builds an error message string from the information in the parameter struct
 * and the error message, and writes it to stderr using the write system call.
*/
void write_error(param_t *params, char *msg)
{
	char errBuffer[1024] = {0};
	char *headshow = errBuffer, *bufPtr = errBuffer;

	_strcpy(headshow, params->argv[0]);
	headshow = bufPtr + _strlen(bufPtr);
	_strcpy(headshow, ": ");
	headshow = bufPtr + _strlen(bufPtr);
	_strcpy(headshow, get_number(params->lineCount));
	headshow = bufPtr + _strlen(bufPtr);
	_strcpy(headshow, ": ");
	headshow = bufPtr + _strlen(bufPtr);
	_strcpy(headshow, params->args[0]);
	headshow = bufPtr + _strlen(bufPtr);
	_strcpy(headshow, ": ");
	headshow = bufPtr + _strlen(bufPtr);
	_strcpy(headshow, msg);
	headshow = bufPtr + _strlen(bufPtr);

	write(STDERR_FILENO, errBuffer, _strlen(bufPtr));
}
