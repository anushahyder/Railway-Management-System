
struct Train
{
    int trainNumber;
    char trainName[40];

    char stations[10][30];
    int stationCount;

    int farePerStation;
    int totalSeats;
    int availableSeats;
};
struct Train trains[20];
struct passenger p[200];
int trainCount = 0;
int passengerCount = 0;
int nextCustomerID = 1001;
int nextBookingID = 5001;

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
    trains[trainCount].availableSeats =trains[trainCount].totalSeats;
    trainCount++;
    printf("\nTrain added successfully!\n");
}