#include "globals.h"
#include <stdio.h>
# include <stdlib.h>
# include <string.h>

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

int isSeatBooked(struct ticket *ticketrecord, int ticketcount, int trainId, char date[], int row, int col) {

    for (int i = 0; i < ticketcount; i ++) {

        if (ticketrecord[i].active == 1) { 
            if (ticketrecord[i].trainId	== trainId)
                if (strcmp(ticketrecord[i].date, date) == 0)
                    if (ticketrecord[i].row	== row)
                        if (ticketrecord[i].col == col) {
                                return 1;
                            }
                         
        }
        
    }
    return 0;
}

void DisplaySeat(struct ticket *ticketrecord, int ticketcount, int trainId, char date[], int rows, int cols) {

     int temp = 0;

     printf("Available seats \n");

     for (int i = 0; i < rows; i ++){
         for (int j = 0; j < cols; j ++){

             temp = isSeatBooked(ticketrecord, ticketcount, trainId, date, i + 1, j + 1);

                 if (temp == 0){
                   printf("Row %d, Column %d\n", i + 1, j + 1);
                 }
     }}}

    
