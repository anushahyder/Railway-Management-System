#include "globals.h"
void SaveTickets(struct ticket *ticketrecord, int ticketcount) {

    FILE *file = fopen("tickets.dat", "wb");

    if (file == NULL) {
        printf("Unable to save tickets!\n");
        return;
    }

    fwrite(&ticketcount, sizeof(int), 1, file);
    fwrite(ticketrecord, sizeof(struct ticket), ticketcount, file);

    fclose(file);

    printf("Tickets saved successfully!\n");
}
