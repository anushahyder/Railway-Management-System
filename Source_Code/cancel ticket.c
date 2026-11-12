void CancelTicket(struct ticket *ticketrecord, int ticketcount) {

    int ticketID, found = 0;
    double refund = 0.0;

    printf("Enter Ticket ID to cancel: ");
    scanf("%d", &ticketID);

    for (int i = 0; i < ticketcount; i++) {

        if (ticketrecord[i].Id == ticketID) {

            found = 1;

            if (ticketrecord[i].active == 0) {
                printf("This ticket has already been cancelled.\n");
                return;
            }

            refund = ticketrecord[i].total * 0.80;

            ticketrecord[i].active = 0;

            printf("Ticket cancelled successfully!\n");
            printf("Original fare: %.2f\n", ticketrecord[i].total);
            printf("Refund amount (80%%): %.2f\n", refund);

            return;
        }
    }

    if (found == 0) {
        printf("Ticket ID not found.\n");
    }
}
