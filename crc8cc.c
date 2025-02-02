/*******************************BEGIN**************************************
 *              COPYRIGHT %G% %U% BY GOGO, LLC
 *                      ALL RIGHTS RESERVED
 *      NO PART OF THIS DOCUMENT MAY BE REPRODUCED WITHOUT
 *           THE WRITTEN PERMISSION OF GOGO, LLC,
 *             111 N CANAL ST, CHICAGO, IL 60606
 **************************************************************************
 *
 * Name:        CRC8 Check Character generation tool
 * Type:        Utility program [C Source]
 * Originator:  David Steimle
 * File:        %M%
 * Version:     %I%
 * Reference:   tools
 * Description: 
 *              This program will "parse" characters arriving on stdin and
 *				generate a CRC8 on the value. It can also take a single string
 *				as a command line argument and generate a CRC8 over that.  
 *
 *
 *		To compile, issue the following command:
 *
 *			cc -o crc8cc crc8cc.c
 *
 * Usage: crc8cc [string]
 *
 * Inputs:
 *		standard input or command line
 *
 * Output
 *		standard output
 * 		
 *
 *******************************END****************************************
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define usage "usage: crc8cc [string]"

uint8_t Crc8(const void* data, int len);

/* Return CRC-8 of the data, using x^8 + x^2 + x + 1 polynomial.  A
 * table-based algorithm would be faster, but for only a few bytes it isn't
 * worth the code size. */
uint8_t Crc8(const void* vptr, int len) {
  const uint8_t *data = vptr;
  unsigned crc = 0;
  int i, j;
  for (j = len; j; j--, data++) {
    crc ^= (*data << 8);
    for(i = 8; i; i--) {
      if (crc & 0x8000)
        /*
		 * was originally 0x1070, but changed to match the
		 * crc generated from web page
		 * http://www.sunshine2k.de/coding/javascript/crc/crc_js.html
		 */
		crc ^= (0x1010 << 3);
      crc <<= 1;
    }
  }
  return (uint8_t)(crc >> 8);
}

main(argc, argv)
int argc;
char *argv[];
{
	char line[8192];
	char *line_ptr;
	uint8_t crc;

	 
	/*
	 * if more than one arguement was entered, it is an error
	 */
	 if (argc > 2)
	 {
	 	printf("Error: too many arguments\n");
	 	printf("%s\n", usage);
	 	exit (1);
	 }
	 
	/*
	 * If a single argument, process that string
	 */
	if (argc == 2)
	{
		crc=Crc8(argv[1], strlen(argv[1]));
		/* 
		 * Print the generated crc
		 */
		printf("%X", crc);
	} 
	else /* process stdin */
	{
		/*
		 * Process standard input until end of file.
		 */
		while(fgets(line, sizeof(line), stdin) != NULL)
		{
			/*
			 * Strip the new line, if it exists
			 */
			line_ptr = line;
			while(*line_ptr != '\0')
			{
				if (*line_ptr=='\n')
				{
					*line_ptr='\0';
				}
				line_ptr++;
			}
			 
			/*
			 * Calculate the crc8
			 */
			crc=Crc8(line, strlen(line));
			
			/* 
			 * Print the generated crc
			 */
			printf("%X", crc);
		} /* end while */
	}
	
	exit(0);

}
