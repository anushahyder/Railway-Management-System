#include "globals.h"

// Define the global variables here so the whole program can use them
struct Train trains[20];
struct passenger p[200];
int trainCount = 0;
int passengerCount = 0;
int nextCustomerID = 1001;
int nextBookingID = 5001;
struct staff *floor = NULL;
int pcount = 0;

// Recursion Concept (For your checklist)
int recursiveSum(int n) {
    if (n <= 1) return 1;
    return n + recursiveSum(n - 1);
}

int main() {
    int choice;
    int id, index;
    
    // Setup initial tickets
    struct ticket *ticketrecord = NULL;
    int ticketcount = 0;
    int capacity = 10;
    ticketrecord = (struct ticket *)malloc(capacity * sizeof(struct ticket));
    LoadTickets(&ticketrecord, &ticketcount, &capacity);

    while (1) {
        printf("\n===================================\n");
        printf("  RAILWAY MANAGEMENT SYSTEM\n");
        printf("===================================\n");
        printf("1. Staff Management (Login/Reg)\n");
        printf("2. Customer Management\n");
        printf("3. Train Management\n");
        printf("4. Ticketing System\n");
        printf("5. Alerts\n");
        printf("6. Save & Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                staffMenu();
                break;
            case 2:
                adminMenu(); // This is the menu from final_train01.c
                break;
            case 3:
                printf("\n--- TRAIN MANAGEMENT ---\n");
                addTrain();
                displayTrains();
                break;
            case 4:
                // Ticketing logic
                printf("\n--- TICKETING ---\n");
                printf("Enter Customer ID: ");
                scanf("%d", &id);
                // You would call BookTicket here, but it needs rows/cols.
                // For now, we will use the booking() function from final_train01.c
                booking(&p[0]); 
                break;
            case 5:
                SendAlert();
                break;
            case 6:
                SaveTickets(ticketrecord, ticketcount);
                free(ticketrecord);
                free(floor);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}