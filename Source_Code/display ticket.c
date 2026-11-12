#include "globals.h"
void DisplayTicket(struct ticket *ticketrecord, int index) {

    printf("\n========== TICKET RECEIPT ==========\n");

    printf("Ticket ID: %d\n", ticketrecord[index].Id);
    printf("Customer ID: %d\n", ticketrecord[index].customerId);
    printf("Train ID: %d\n", ticketrecord[index].trainId);

    printf("Departure: %s\n", ticketrecord[index].from);
    printf("Destination: %s\n", ticketrecord[index].to);
    printf("Travel Date: %s\n", ticketrecord[index].date);

    printf("Seat: Row %d, Column %d\n",
           ticketrecord[index].row, ticketrecord[index].col);

    printf("------------------------------------\n");

    printf("Base Fare: %.2f\n", ticketrecord[index].basefare);
    printf("Add-on Cost: %.2f\n", ticketrecord[index].addon);
    printf("GST: %.2f\n", ticketrecord[index].gst);

    printf("------------------------------------\n");

    printf("TOTAL: %.2f\n", ticketrecord[index].total);

    printf("====================================\n");
}
