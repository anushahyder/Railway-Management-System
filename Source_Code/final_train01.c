#include "globals.h"

// FUNCTION PROTOTYPE (findPassenger is defined later but used earlier)
int findPassenger(struct passenger p[], int count, int id);

//validate phone number
int phonechk(char phone[])
{
    int i;
    if (strlen(phone) != 11)
    {
        return 0;
    }
    if (phone[0] != '0')
    {
        return 0;
    }
    for (i = 0; phone[i] != '\0'; i++)
    {
        if (!isdigit((unsigned char)phone[i]))
        {
            return 0;
        }
    }
    return 1;
}

//validate email
int emailchk(char email[])
{
    int i;
    int at = -1, dot = -1;
    for (i = 0; email[i] != '\0'; i++)
    {
        if (email[i] == '@')
        {
            if (at != -1)
                return 0;
            at = i;
        }

        if (email[i] == '.')
        {
            dot = i;
        }
    }
    if (at <= 0 || dot <= at + 1 || email[dot + 1] == '\0')
    {
        return 0;
    }
    return 1;
}

// USERNAME VALIDATION FUNCTION
int userchk(char *username)
{
    int i;

    if (strlen(username) <= 5)
    {
        return 0;
    }

    for (i = 0; username[i] != '\0'; i++)
    {
        if (!isalpha((unsigned char)username[i]))
        {
            return 0;
        }
    }

    return 1;
}

void addTrain()
{
    int i;
    if(trainCount >= 20)
    {
        printf("\nTrain limit reached!\n");
        return;
    }
    printf("\n--- ADD NEW TRAIN ---\n");
    printf("Enter train number: ");
    scanf("%d", &trains[trainCount].trainNumber);
    printf("Enter train name: ");
    scanf(" %39[^\n]", trains[trainCount].trainName);
    printf("Enter number of stations (2-10): ");
    scanf("%d", &trains[trainCount].stationCount);

    if(trains[trainCount].stationCount < 2 || trains[trainCount].stationCount > 10)
    {
        printf("Invalid station count!\n");
        return;
    }
    for(i = 0; i < trains[trainCount].stationCount; i++)
    {
        printf("Enter station %d: ", i + 1);
        scanf(" %29[^\n]", trains[trainCount].stations[i]);
    }
    printf("Enter fare per station: ");
    scanf("%d", &trains[trainCount].farePerStation);
    printf("Enter total seats: ");
    scanf("%d", &trains[trainCount].totalSeats);

    if(trains[trainCount].totalSeats <= 0)
    {
        printf("Invalid seat capacity!\n");
        return;
    }
    trains[trainCount].availableSeats = trains[trainCount].totalSeats;
    trainCount++;
    printf("\nTrain added successfully!\n");
}

//DISPLAY ALL TRAINS
void displayTrains()
{
    int i,j;
    if(trainCount == 0)
    {
        printf("\nNo trains added yet!\n");
        return;
    }
    printf("\n========== TRAIN RECORDS ==========\n");
    for(i = 0; i < trainCount; i++)
    {
        printf("\nTrain Number: %d",trains[i].trainNumber);
        printf("\nTrain Name: %s",trains[i].trainName);
        printf("\nRoute: ");
        for(j = 0; j < trains[i].stationCount; j++)
        {
            printf("%s", trains[i].stations[j]);
            if(j < trains[i].stationCount - 1)
                printf(" -> ");
        }
        printf("\nFare Per Station: Rs. %d",trains[i].farePerStation);
        printf("\nTotal Seats: %d",trains[i].totalSeats);
        printf("\nAvailable Seats: %d\n",trains[i].availableSeats);
    }
}

// DISPLAY ALL CUSTOMERS
void displayCustomers(struct passenger *p, int count)
{
    int i;
    printf("\n====== ALL CUSTOMER RECORDS ======\n");
    if (count == 0)
    {
        printf("No customers registered yet!\n");
        return;
    }
    for (i = 0; i < count; i++)
    {
        printf("\nCustomer %d\n", i + 1);
        printf("Customer ID: %d\n", p[i].customerId);
        printf("Name: %s\n", p[i].name);
        printf("Age: %d\n", p[i].age);
        printf("Phone: %s\n", p[i].phone);
        printf("Email: %s\n",p[i].email);
        printf("-----------------------------\n");
    }
}

// UPDATE CUSTOMER INFORMATION
void updateCustomer(struct passenger *p, int count)
{
    int i, ID;
    printf("\n====== UPDATE CUSTOMER INFORMATION ======\n");
    printf("Enter ID: ");
    scanf("%d", &ID);

    i = findPassenger(p, count, ID);

    if (i != -1)
    {
        printf("Current Name: %s\n", p[i].name);
        printf("Enter New Name: ");
        getchar();
        fgets(p[i].name, sizeof(p[i].name), stdin);
        p[i].name[strcspn(p[i].name, "\n")] = '\0';

        do
        {
            printf("Enter New Age: ");
            scanf("%d", &p[i].age);
            if (p[i].age <= 0 || p[i].age > 120)
            {
                printf("Invalid Age! Try again.\n");
            }
        } while (p[i].age <= 0 || p[i].age > 120);

        do
        {
            printf("Enter New Phone Number: ");
            scanf("%19s", p[i].phone);
            if (!phonechk(p[i].phone))
            {
                printf("Invalid Phone Number! Try again.\n");
            }
        } while (!phonechk(p[i].phone));

        do
        {
            printf("Enter New Email: ");
            scanf("%49s", p[i].email);
            if (!emailchk(p[i].email))
            {
                printf("Invalid Email! Try again.\n");
            }
        } while (!emailchk(p[i].email));

        printf("\nCustomer Information Updated Successfully!\n");
    }
    else
    {
        printf("\nCustomer ID Not Found!\n");
    }
}

// DELETE CUSTOMER RECORD
void deleteCustomer(struct passenger p[], int *count)
{
    int i, j, deleteID;
    int found = 0;

    printf("\n====== DELETE CUSTOMER ======\n");
    printf("Enter Customer ID to delete: ");
    scanf("%d", &deleteID);

    for (i = 0; i < *count; i++)
    {
        if (p[i].customerId == deleteID)
        {
            found = 1;
            if (p[i].booked == 1)
            {
                trains[p[i].trainIndex].availableSeats++;
            }
            for (j = i; j < *count - 1; j++)
            {
                p[j] = p[j + 1];
            }
            (*count)--;
            printf("\nCustomer Deleted Successfully!\n");
            break;
        }
    }

    if (found == 0)
    {
        printf("\nCustomer ID Not Found!\n");
    }
}

void registerCustomer(struct passenger p[], int *count)
{
    int i, duplicate;

    while (1)
    {
        duplicate = 0;
        printf("Enter Customer ID: ");
        scanf("%d", &p[*count].customerId);

        for (i = 0; i < *count; i++)
        {
            if (p[i].customerId == p[*count].customerId)
            {
                duplicate = 1;
                break;
            }
        }

        if (duplicate)
            printf("Customer ID already exists!\n");
        else if (p[*count].customerId <= 0)
            printf("Invalid ID!\n");
        else
            break;
    }

    printf("Enter Customer Name: ");
    getchar();
    fgets(p[*count].name, sizeof(p[*count].name), stdin);
    p[*count].name[strcspn(p[*count].name, "\n")] = '\0';

    do
    {
        printf("Enter Age: ");
        scanf("%d", &p[*count].age);
    } while (p[*count].age <= 0 || p[*count].age > 120);

    do
    {
        printf("Enter Phone: ");
        scanf("%19s", p[*count].phone);
    } while (!phonechk(p[*count].phone));

    do
    {
        printf("Enter Email: ");
        scanf("%49s", p[*count].email);
    } while (!emailchk(p[*count].email));
    
    (*count)++;
    printf("\nCustomer Registered Successfully!\n");
}

void booking(struct passenger *p)
{
    char source[30], destination[30];
    int i, j, selected = -1;
    int sourcePos, destPos;
    int trainNo, fare;

    if(p->booked == 1)
    {
        printf("\nCustomer already has a booking!");
        return;
    }
    printf("\n===== TRAIN BOOKING =====");
    printf("\nEnter Source Station: ");
    scanf(" %29[^\n]", source);
    printf("Enter Destination Station: ");
    scanf(" %29[^\n]", destination);

    printf("\n===== AVAILABLE TRAINS =====\n");
    for(i = 0; i < trainCount; i++)
    {
        sourcePos = -1;
        destPos = -1;

        for(j = 0; j < trains[i].stationCount; j++)
        {
            if(strcmp(trains[i].stations[j], source) == 0)
                sourcePos = j;
            if(strcmp(trains[i].stations[j], destination) == 0)
                destPos = j;
        }

        if(sourcePos != -1 && destPos != -1 && sourcePos < destPos && trains[i].availableSeats > 0)
        {
            fare = (destPos - sourcePos) * trains[i].farePerStation;
            printf("\nTrain Number: %d",trains[i].trainNumber);
            printf("\nTrain Name: %s",trains[i].trainName);
            printf("\nAvailable Seats: %d",trains[i].availableSeats);
            printf("\nTicket Fare: Rs. %d\n", fare);
        }
    }

    printf("\nEnter Train Number to Book: ");
    scanf("%d", &trainNo);

    for(i = 0; i < trainCount; i++)
    {
        if(trains[i].trainNumber == trainNo)
        {
            sourcePos = -1;
            destPos = -1;
            for(j = 0; j < trains[i].stationCount; j++)
            {
                if(strcmp(trains[i].stations[j], source) == 0)
                    sourcePos = j;

                if(strcmp(trains[i].stations[j], destination) == 0)
                    destPos = j;
            }

            if(sourcePos != -1 && destPos != -1 && sourcePos < destPos && trains[i].availableSeats > 0)
            {
                selected = i;
            }
            break;
        }
    }

    if(selected == -1)
    {
        printf("\nInvalid Train or Route!");
        return;
    }

    fare = (destPos - sourcePos) * trains[selected].farePerStation;

    printf("\n===== BOOKING DETAILS =====");
    printf("\nPassenger: %s", p->name);
    printf("\nTrain: %s", trains[selected].trainName);
    printf("\nSource: %s", source);
    printf("\nDestination: %s", destination);
    printf("\nFare: Rs. %d", fare);

    printf("\nConfirm Booking (1=Yes, 0=No): ");
    if(scanf("%d", &i) != 1 || i != 1)
    {
        printf("\nBooking Cancelled!");
        return;
    }

    p->trainIndex = selected;
    strcpy(p->trainName, trains[selected].trainName);
    strcpy(p->departure, source);
    strcpy(p->destination, destination);
    p->Fare = fare;
    p->seatno = trains[selected].totalSeats - trains[selected].availableSeats + 1;
    p->bookingId = nextBookingID++;
    p->booked = 1;
    trains[selected].availableSeats--;

    printf("\n\nBOOKING SUCCESSFUL!");
    printf("\nBooking ID: %d", p->bookingId);
    printf("\nSeat Number: %d", p->seatno);
}

void services(struct passenger *p)
{
    if(p->booked == 0)
    {
        printf("\nBook your ticket first!\n");
        return;
    }
    printf("\n--- SERVICES ---\n");
    printf("1. Food - Rs. 500\n");
    printf("0. No Service\n");
    printf("Choose Service: ");
    scanf("%d",&p->foodChoice);

    if(p->foodChoice==1)
        p->serviceCost=500;
    else
    {
        p->foodChoice=0;
        p->serviceCost=0;
    }
}

void billing(struct passenger *p)
{
    float discount = 0;
    if(p->booked == 0)
    {
        printf("\nBook your ticket first!\n");
        return;
    }
    printf("\n--- BILLING ---\n");
    printf("Ticket Fare: Rs. %.2f\n", p->Fare);
    printf("Service Cost: Rs. %.2f\n", p->serviceCost);
    p->totalBill = p->Fare + p->serviceCost;
    if(p->age >= 60 || p->age <= 10)
    {
        discount = p->totalBill * 0.50;
        printf("You get 50%% discount!\n");
    }
    p->totalBill = p->totalBill - discount;
    p->gst = p->totalBill * 0.20;
    p->finalBill = p->totalBill + p->gst;
    printf("\nSubtotal after discount: Rs. %.2f",p->totalBill);
    printf("\nGST (20%%): Rs. %.2f", p->gst);
    printf("\nFinal Amount: Rs. %.2f\n",p->finalBill);
}

void receipt(struct passenger *p)
{
    if(p->booked == 0)
    {
        printf("\nNo booking found!\n");
        return;
    }
    printf("\n========== RAILWAY RECEIPT ==========\n");
    printf("Customer ID: %d\n", p->customerId);
    printf("Name: %s\n", p->name);
    printf("Phone: %s\n", p->phone);
    printf("Booking ID: %d\n", p->bookingId);
    printf("Train: %s\n", p->trainName);
    printf("Departure: %s\n", p->departure);
    printf("Destination: %s\n", p->destination);
    printf("Seat Number: %d\n", p->seatno);
    printf("Ticket Fare: Rs. %.2f\n", p->Fare);
    printf("Service Cost: Rs. %.2f\n", p->serviceCost);
    printf("Subtotal after discount: Rs. %.2f\n",p->totalBill);
    printf("GST: Rs. %.2f\n", p->gst);
    printf("Final Amount: Rs. %.2f\n",p->finalBill);
    printf("=====================================\n");
}

void customerInfo(struct passenger *p, int id)
{
    memset(p, 0, sizeof(struct passenger));
    p->customerId = id;

    printf("Enter passenger name: ");
    scanf(" %79[^\n]", p->name);

    do
    {
        printf("Enter age: ");
        scanf("%d",&p->age);
        if (p->age <= 0 || p->age > 120)
        {
            printf("Invalid Age! Try again.\n");
        }
    } while (p->age <= 0 || p->age > 120);

    do
    {
        printf("Enter phone number: ");
        scanf("%19s",p->phone);
        if (!phonechk(p->phone))
        {
            printf("Invalid Phone Number! Try again.\n");
        }
    } while (!phonechk(p->phone));

    do
    {
        printf("Enter email: ");
        scanf("%49s",p->email);
        if (!emailchk(p->email))
        {
            printf("Invalid Email! Try again.\n");
        }
    } while (!emailchk(p->email));

    printf("\nRegistration successful!\n");
    printf("Customer ID: %d\n",p->customerId);
}

int findPassenger(struct passenger p[],int count,int id)
{
    int i;
    for(i = 0;i<count;i++)
    {
        if (p[i].customerId==id)
        {
            return i;
        }
    }
    return -1;
}

void adminMenu()
{
    int count = 0;
    int nextId = 1001;
    int choice, id, index;

    do
    {
        printf("\n===== TRAIN MANAGEMENT SYSTEM =====\n");
        printf("1. Register Passenger\n");
        printf("2. Display All Passengers\n");
        printf("3. Find Passenger\n");
        printf("4. Update Passenger\n");
        printf("5. Delete Passenger\n");
        printf("6. Book Ticket\n");
        printf("7. Services\n");
        printf("8. Billing\n");
        printf("9. Receipt\n");
        printf("10. Add Train\n");
        printf("11. Display Trains\n");
        printf("12. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (count<200)
                {
                    customerInfo(&p[count],nextId);
                    count++;
                    nextId++;
                }
                else
                {
                    printf("Passenger limit reached!\n");
                }
                break;
            case 2:
                displayCustomers(p, count);
                break;
            case 3:
                printf("Enter customer ID: ");
                scanf("%d",&id);
                index=findPassenger(p, count, id);
                if (index != -1)
                {
                    printf("\nPassenger found!\n");
                    printf("ID: %d\n",p[index].customerId);
                    printf("Name: %s\n",p[index].name);
                    printf("Age: %d\n",p[index].age);
                    printf("Phone: %s\n",p[index].phone);
                    printf("Email: %s\n",p[index].email);
                }
                else
                {
                    printf("Passenger not found!\n");
                }
                break;
            case 4:
                updateCustomer(p, count);
                break;
            case 5:
                deleteCustomer(p, &count);
                break;
            case 6:
                printf("Enter customer ID: ");
                scanf("%d",&id);
                index=findPassenger(p, count, id);
                if (index !=-1)
                {
                    booking(&p[index]);
                }
                else
                {
                    printf("Passenger not found!\n");
                }
                break;
            case 7:
                printf("Enter customer ID: ");
                scanf("%d",&id);
                index=findPassenger(p,count,id);
                if (index!=-1)
                {
                    services(&p[index]);
                }
                else
                {
                    printf("Passenger not found!\n");
                }
                break;
            case 8:
                printf("Enter customer ID: ");
                scanf("%d",&id);
                index = findPassenger(p, count, id);
                if (index !=-1)
                {
                    billing(&p[index]);
                }
                else
                {
                    printf("Passenger not found!\n");
                }
                break;
            case 9:
                printf("Enter customer ID: ");
                scanf("%d", &id);
                index=findPassenger(p, count, id);
                if (index!=-1)
                {
                    receipt(&p[index]);
                }
                else
                {
                    printf("Passenger not found!\n");
                }
                break;
            case 10:
                addTrain();
                break;
            case 11:
                displayTrains();
                break;
            case 12:
                printf("Program ended.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 12);
}
