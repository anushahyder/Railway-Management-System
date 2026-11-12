#include "globals.h"

// Define the global variables here
struct Train trains[20];
struct passenger p[200];
int trainCount = 0;
int passengerCount = 0;
int nextCustomerID = 1001;
int nextBookingID = 5001;
struct staff *floor = NULL;
int pcount = 0;

int main() {
    int choice;
    
    // Initialize ticket array
    struct ticket *ticketrecord = NULL;
    int ticketcount = 0;
    int capacity = 10;
    ticketrecord = (struct ticket *)malloc(capacity * sizeof(struct ticket));
    
    // Load any saved tickets from file
    LoadTickets(&ticketrecord, &ticketcount, &capacity);

    while (1) {
        printf("\n===================================\n");
        printf("  RAILWAY MANAGEMENT SYSTEM\n");
        printf("===================================\n");
        printf("1. Staff Management (Login/Reg)\n");
        printf("2. Admin System (Customers, Trains, Billing)\n");
        printf("3. Ticketing System (Seats, Book, Cancel)\n");
        printf("4. Alerts\n");
        printf("5. Save & Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                staffMenu();
                break;
            case 2:
                adminMenu(); 
                break;
            case 3:
                // Quick menu for ticketing functions
                printf("\n--- TICKETING ---\n");
                printf("1. Book a Ticket\n");
                printf("2. Cancel a Ticket\n");
                printf("3. Display Ticket\n");
                printf("4. View Available Seats\n");
                int tChoice;
                scanf("%d", &tChoice);
                
                if (tChoice == 1) {
                    int cid, tid, r, c;
                    printf("Enter Customer ID: "); scanf("%d", &cid);
                    printf("Enter Train ID: "); scanf("%d", &tid);
                    printf("Enter total rows: "); scanf("%d", &r);
                    printf("Enter total cols: "); scanf("%d", &c);
                    BookTicket(cid, tid, r, c, &ticketrecord, &ticketcount, &capacity);
                } else if (tChoice == 2) {
                    CancelTicket(ticketrecord, ticketcount);
                } else if (tChoice == 3) {
                    int idx;
                    printf("Enter ticket index (0 to %d): ", ticketcount - 1);
                    scanf("%d", &idx);
                    if(idx >= 0 && idx < ticketcount) DisplayTicket(ticketrecord, idx);
                    else printf("Invalid index.\n");
                } else if (tChoice == 4) {
                    int tid, r, c;
                    char date[20];
                    printf("Enter Train ID: "); scanf("%d", &tid);
                    printf("Enter Date (DD/MM/YYYY): "); scanf("%s", date);
                    printf("Enter total rows: "); scanf("%d", &r);
                    printf("Enter total cols: "); scanf("%d", &c);
                    DisplaySeat(ticketrecord, ticketcount, tid, date, r, c);
                }
                break;
            case 4:
                SendAlert();
                break;
            case 5:
                SaveTickets(ticketrecord, ticketcount);
                free(ticketrecord);
                free(floor);
                printf("Exiting system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
