#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"

/* This function is not important, just a simple helper to read a file to a buffer */
/* Do not forget to free the buffer after usage ! */
void read_file_to_buffer(char *file_name, unsigned char **file_buf, long *file_size)
{
	FILE *fp = fopen (file_name, "rb");
	if (!fp)
		loge_and_exit("File \"%s\" not found!", file_name);

	fseek(fp, 0L, SEEK_END);
	*file_size = ftell(fp);
	fseek(fp, 0L ,SEEK_SET);
	logd("Filename \"%s\", file_size %lu", file_name, *file_size);

	*file_buf = malloc(*file_size);
	if (*file_buf == NULL)
		loge_and_exit("Not enough memory!");

	if (fread(*file_buf, sizeof(char), *file_size, fp) != *file_size)
		loge_and_exit("fread() error while reading \"%s\"!", file_name);

	fclose(fp);
}

