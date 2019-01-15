/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "timing.h"


void
timing_prog_1(char *host)
{
	CLIENT *clnt;
	u_long  *result_1;
	char *timing_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, TIMING_PROG, TIMING_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	
	unsigned long timeBefore = (unsigned long) time(NULL);
	unsigned long timeAfter;
	unsigned long roundTripTime;
	unsigned long timeClient;
	unsigned long timeServer; 

	result_1 = timing_1((void*)&timing_1_arg, clnt);
	if (result_1 == (u_long *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	else{
		timeServer = *result_1;
		timeAfter = (unsigned long) time(NULL);
		roundTripTime = timeAfter - timeBefore;
		timeClient = (roundTripTime / 2) + timeServer;
		
		printf("The round trip time: %lu \n", roundTripTime);
		printf("The server returned: %lu \n", *result_1);
		printf("The client time: %lu \n", timeClient);
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	timing_prog_1 (host);
exit (0);
}
