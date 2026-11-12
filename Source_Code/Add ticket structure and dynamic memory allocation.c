#include <stdio.h>
# include <stdlib.h>

struct ticket {

    int	Id;
    int	customerId;
    int	trainId;
    char date[20];
    char from[40];
    char to[40];
    int	row;
    int	col;
    int	active;
    double	basefare;
    double	addon;
    double	discount;
    double	gst;
    double	total;
    
};

struct ticket *InitializeTicket() {

    int capacity = 10, ticketcount = 0;

    struct ticket *ticketrecord;

    ticketrecord = malloc(capacity *sizeof(struct ticket));
    
    if (ticketrecord == NULL){
        printf("Memory allocation failed!");
        return NULL;
    }
    

    struct ticket *temp;

    if (ticketcount == capacity) {
       temp = realloc(ticketrecord, (capacity + 10) *sizeof(struct ticket));

        if (temp == NULL) {
          printf("Memory reallocation failed!");
          return NULL;
        }
        else {
            
            ticketrecord = temp;
            capacity = capacity + 10;
           
        }
    }
   
    return ticketrecord;
}
