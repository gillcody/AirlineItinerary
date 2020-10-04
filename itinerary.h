#ifndef ITINERARY_H 
#define ITINERARY_H

/* Struct Destination holds an airport code as well as a pointer to the next airport*/
typedef struct Destination
{
	char code[4];
	struct Destination *next;
} Destination;

/* Function Prototypes*/
Destination *create( char * );
Destination *insertAfter( Destination *, Destination *, char * );
Destination *find( Destination *, char * );
Destination *removeNode( Destination *, char * );
void print( Destination * );
void printItinerary( Destination * );
Destination *destruct( Destination * );

#endif
