void SendAlert() {

    int choice;
    char message[200];

    printf("\n===== RAILWAY ALERT SYSTEM =====\n");
    printf("1. Train Delay\n");
    printf("2. Train Cancellation\n");
    printf("3. Medical Assistance\n");
    printf("4. General Emergency\n");

    printf("Select alert type: ");
    scanf("%d", &choice);

    switch (choice) {

        case 1:
            printf("Enter delay announcement: ");
            break;

        case 2:
            printf("Enter cancellation announcement: ");
            break;

        case 3:
            printf("Enter medical assistance details: ");
            break;

        case 4:
            printf("Enter emergency announcement: ");
            break;

        default:
            printf("Invalid alert type!\n");
            return;
    }

    scanf(" %199[^\n]", message);

    printf("\n===== RAILWAY ANNOUNCEMENT =====\n");
    printf("%s\n", message);
    printf("================================\n");
}
