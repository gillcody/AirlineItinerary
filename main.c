#include <stdio.h>
#include <stdlib.h>
#include "itinerary.h"
#include "main.h"

/* 
    printMenu
    ---------------------------
    This function prints the main menu.
    Returns: Nothing
*/
void printMenu()
{
    printf( "\n#########################################\n" );
    printf( "#            Trip Planner Menu          #\n" );
    printf( "#########################################\n" );
    printf( " 1 - Insert a Destination\n" );
    printf( " 2 - Remove a Destination\n" );
    printf( " 3 - Print Destinations\n" );
    printf( " 4 - Print Itinerary\n" );
    printf( " 5 - Clear Itinerary\n" );
    printf( " 0 - Quit\n" );
    printf( "Enter your selection: " );
}

/*Main Function*/
int main( void )
{
 	/* all variables*/
	int choice;
	char userCode[4];
	char insert[4];
	Destination *head = NULL;
	Destination *temp = NULL;	 

	while( TRUE )
	{ 
		printMenu();
	        scanf( "%d", &choice );

        switch( choice )
        {
            case 1:
		printf("Enter the airport code:\n");
		scanf("%s", userCode);
		if (head == NULL)
		{
			head = create(userCode);
		}
		else{
			temp = create(userCode);
			printf("After which destination would you like to add the new destination? 
                        Enter ZZZ to insert in the beginning of list.\n");
			scanf("%s", insert);
			head = insertAfter(head, temp, insert);
			}
		
		printf("Destination successfully added.\n");
                break;

            case 2:
		printf("Enter an airport code:\n");
		scanf("%s", userCode);

		if (find(head, userCode) == NULL)\
		{
			printf("Error.\n");
		}
		else
		{
			removeNode(head, userCode);
			printf("Destination successfully removed.\n");
		}	
                break;

            case 3:
		print(head);
                break;

            case 4:
		printItinerary(head);
                break;

            case 5:
		destruct(head);
                break;

            case 0:
		printf("Goodbye.\n");
		destruct(head);
                return 1;

            default:
		if (choice < 0 || choice > 5)
		{
			printf("Invalid choice. Enter a valid choice: 0-5.\n");
		}
                break;
        }
	}

    return 0;
}
