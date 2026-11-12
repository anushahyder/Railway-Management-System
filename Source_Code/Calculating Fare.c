void CalculateFare(struct ticket *ticketrecord, int index) {

    double total = 0.0;

    total = ticketrecord[index].basefare + ticketrecord[index].addon;

    ticketrecord[index].gst = total * 0.05;

    total = total + ticketrecord[index].gst;

    ticketrecord[index].total = total;

    printf("5%% GST applied to your base fare and add-on fee.\n");
    printf("Your GST amount is: %.2f\n", ticketrecord[index].gst);
    printf("Your total fee is: %.2f\n", ticketrecord[index].total);
}
