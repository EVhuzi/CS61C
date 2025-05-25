#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
    /* your code here */
    if (head == NULL)
	    return 0;
    node* hare = head->next;
    node* tortoise = hare; 
    if (hare != NULL)
	    hare = hare->next;
    while (hare != NULL)
    {
	    if (hare == tortoise)
		    return 1;
	    else
	    {
		    tortoise = tortoise->next;
		   hare = hare->next;
		  if (hare!= NULL)
			 hare = hare->next; 
	    }

    }
        return 0;
}
