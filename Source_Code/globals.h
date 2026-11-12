#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// --- STRUCTURES ---
struct passenger {
    int customerId;
    char name[80];
    int age;
    char phone[20];
    char email[50];
    int trainIndex;
    char trainName[40];
    char departure[30];
    char destination[30];
    int bookingId;
    int seatno;
    int booked;
    float Fare;
    int foodChoice;
    float serviceCost;
    float totalBill;
    float gst;
    float finalBill;
};

struct Train {
    int trainNumber;
    char trainName[40];
    char stations[10][30];
    int stationCount;
    int farePerStation;
    int totalSeats;
    int availableSeats;
};

struct ticket {
    int Id;
    int customerId;
    int trainId;
    char date[20];
    char from[40];
    char to[40];
    int row;
    int col;
    int active;
    double basefare;
    double addon;
    double discount;
    double gst;
    double total;
};

struct staff {
    char regpass[21]; 
    char regid[61];   
};

// --- GLOBAL VARIABLES ---
extern struct Train trains[20];
extern struct passenger p[200];
extern int trainCount;
extern int passengerCount;
extern int nextCustomerID;
extern int nextBookingID;
extern struct staff *staff_floor;
extern int pcount;

// --- FUNCTION PROTOTYPES ---
// Staff
void staffMenu(void);
int staffReg(void);
int staffLogin(void);
void adminReg(char *username, char *password);
void adminLogin(char *username, char *password);
int errorChk(char *str1, char *str2);
int passchk(char *regpass);

// Trains & Customers (From final_train01.c)
void adminMenu(void);
void addTrain(void);
void displayTrains(void);
void displayCustomers(struct passenger *p, int count);
int findPassenger(struct passenger p[], int count, int id);
void updateCustomer(struct passenger *p, int count);
void deleteCustomer(struct passenger p[], int *count);
void registerCustomer(struct passenger p[], int *count);
void customerInfo(struct passenger *p, int id);
void booking(struct passenger *p);
void services(struct passenger *p);
void billing(struct passenger *p);
void receipt(struct passenger *p);
int phonechk(char phone[]);
int emailchk(char email[]);

// Ticketing
void BookTicket(int cusID, int trainID, int rows, int cols, struct ticket **ticketrecord, int *ticketcount, int *capacity);
void CalculateFare(struct ticket *ticketrecord, int index);
void CancelTicket(struct ticket *ticketrecord, int ticketcount);
void DisplayTicket(struct ticket *ticketrecord, int index);
void SaveTickets(struct ticket *ticketrecord, int ticketcount);
void LoadTickets(struct ticket **ticketrecord, int *ticketcount, int *capacity);
void SendAlert(void);
int SelectSeat(int rows, int cols, struct ticket *ticketrecord, char date[], int ticketcount, int trainId, int *selectedRow, int *selectedCol);
int isSeatBooked(struct ticket *ticketrecord, int ticketcount, int trainId, char date[], int row, int col);
void DisplaySeat(struct ticket *ticketrecord, int ticketcount, int trainId, char date[], int rows, int cols);

#endif
