#include "globals.h"
void BookTicket(int cusID, int trainID, int rows, int cols,
                struct ticket **ticketrecord, int *ticketcount, int *capacity) {

    if (*ticketcount == *capacity) {

        struct ticket *temp = realloc(*ticketrecord, (*capacity + 10) * sizeof(struct ticket));

        if (temp == NULL) {
            printf("Memory reallocation failed!\n");
            return;
        }

        *ticketrecord = temp;
        *capacity += 10;
    }

    (*ticketrecord)[*ticketcount].Id = *ticketcount + 1;
    (*ticketrecord)[*ticketcount].customerId = cusID;
    (*ticketrecord)[*ticketcount].trainId = trainID;
    (*ticketrecord)[*ticketcount].active = 1;

    printf("Enter departure station: ");
    scanf(" %39[^\n]", (*ticketrecord)[*ticketcount].from);

    printf("Enter destination station: ");
    scanf(" %39[^\n]", (*ticketrecord)[*ticketcount].to);

    printf("Enter travel date (DD/MM/YYYY): ");
    scanf(" %19s", (*ticketrecord)[*ticketcount].date);

    int r, c;

    if (SelectSeat(rows, cols, *ticketrecord, (*ticketrecord)[*ticketcount].date,
                   *ticketcount, trainID, &r, &c)) {

        (*ticketrecord)[*ticketcount].row = r;
        (*ticketrecord)[*ticketcount].col = c;
    }

    printf("Enter base fare: ");
    scanf("%lf", &(*ticketrecord)[*ticketcount].basefare);

    printf("Enter add-on cost: ");
    scanf("%lf", &(*ticketrecord)[*ticketcount].addon);

    CalculateFare(*ticketrecord, *ticketcount);

    (*ticketcount)++;

}
