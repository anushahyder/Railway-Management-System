#include "globals.h"

int SelectSeat(int rows, int cols, struct ticket *ticketrecord, char date[], int ticketcount, int trainId, int *selectedRow, int *selectedCol) {
    int r = 0, c = 0, temp = 0;

    while (1) {
        printf("Please enter row number: \n");
        scanf("%d", &r);

        printf("Please enter column number: \n");
        scanf("%d", &c);

        if (r < 1 || r > rows || c < 1 || c > cols) {
            printf("Invalid seat selection. Try again.\n");
            continue;
        }

        temp = isSeatBooked(ticketrecord, ticketcount, trainId, date, r, c);

        if (temp == 0) {
            printf("Seat is available!\n");
            *selectedRow = r;
            *selectedCol = c;
            return 1;
        } else {
            printf("Seat is Occupied. Choose another seat: \n");
        }   
    }
    return 0;
}
