#include "globals.h"
void LoadTickets(struct ticket **ticketrecord, int *ticketcount, int *capacity) {

    FILE *file = fopen("tickets.dat", "rb");

    if (file == NULL) {
        printf("No previous ticket records found.\n");
        return;
    }

    if (fread(ticketcount, sizeof(int), 1, file) != 1) {
        printf("Unable to read ticket records!\n");
        fclose(file);
        return;
    }

    if (*ticketcount > *capacity) {
        struct ticket *temp = realloc(*ticketrecord,
                                      (*ticketcount) * sizeof(struct ticket));

        if (temp == NULL) {
            printf("Memory allocation failed!\n");
            fclose(file);
            return;
        }

        *ticketrecord = temp;
        *capacity = *ticketcount;
    }

    if (fread(*ticketrecord, sizeof(struct ticket), *ticketcount, file)
        != (size_t)*ticketcount) {
        printf("Unable to load all ticket records!\n");
        *ticketcount = 0;
        fclose(file);
        return;
    }

    fclose(file);

    printf("Tickets loaded successfully!\n");
}
