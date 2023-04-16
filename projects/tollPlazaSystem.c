#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
/* dataBase */

int noOfvehicleType = 7,
    registeredVehicleNumb = 0;

char clrStr[] = "clear",
     vehilceType[10][50] = {
         "Car/Jeep/Van",
         "LCV",
         "Bus/Truck",
         "Upto 3 Axle Vehicle",
         "4 to 6 Axle ",
         "HCM/EME",
         "7 or more Axle "};

float fareSingleList[] = {70, 115, 235, 260, 370, 370, 450},
      fareReturnList[] = {105, 170, 355, 385, 555, 555, 675};

void *mainMenu;

typedef struct vehicleNode
{
    int index;
    char ownerName[50],
        vehicleNumber[50],
        registerDate[50];
    float recordFare;
    struct vehicleNode *nextNode;
} vn;

vn *top = NULL;
/* dataBase */
void validChoice(int choice, int i, void *gotoLabel)
{
    if (choice > i)
    {
        system(clrStr);
        headerMessage("Invalid Choice");
        goto *gotoLabel;
    }
}

bool strPatMatch(char str[], char pat[])
{
    int i = 0, j;
    for (; i < strlen(str); i++)
    {
        for (j = 0; j < strlen(pat); j++)
        {
            if (str[i + j] != pat[j])
            {
                break;
            }
        }
        if (j == strlen(pat))
        {
            return true;
        }
    }

    return false;
}

void headerMessage(char mess[]) // function to print heading
{
    printf("\n\n----------------------- %s ------------------------\n", mess);
}

void holdForMainMenu()
{
    char t[10];
    printf("\n\n Type anything and Press Enter to Go to Main Menu ... ");
    scanf("%s", &t);
    system(clrStr);
    goto *mainMenu;
}

void menuDisplay(int *choice)
{
    printf("\n Menu ----------->\n");
    printf("\n\t1.) Display the fare details for different category of vehicles");
    printf("\n\t2.) Update basic fare for each category of vehicle in case of single side or return included (n-wheeler based)");
    printf("\n\t3.) Record the daily traffic details");
    printf("\n\t4.) Delete the vehicle record");
    printf("\n\t5.) Search a vehicle record");
    printf("\n\t6.) Exit");
    printf("\n\nEnter Your Choice : ");
    scanf("%d", choice);
}

void getVehicleDetails(char ownerName[], char vehicleNumber[], char fareDate[])
{
    system(clrStr);
    headerMessage("Vehicle Details ");

    printf("\n Enter Owner Name : ");
    gets(ownerName);
    gets(ownerName);
    printf("\n Vehicle Number : ");
    gets(vehicleNumber);
    printf("\n Date : ");
    gets(fareDate);
}

void registerData(char ownerName[], char vehicleNumber[], char fareDate[], float fare)
{
    vn *node = (vn *)malloc(sizeof(vn));
    vn *temp = top;
    strcpy(node->ownerName, ownerName);
    strcpy(node->vehicleNumber, vehicleNumber);
    strcpy(node->registerDate, fareDate);
    node->recordFare = fare;
    node->index = ++registeredVehicleNumb;
    node->nextNode = NULL;
    if (top == NULL)
    {
        top = node;
        return;
    }

    while (temp != NULL && temp->nextNode != NULL)
    {
        temp = temp->nextNode;
    }

    temp->nextNode = node;
}

void RecordFareDetails() // Record the fare details for different category of vehicles
{
    int i = 0,
        choice,
        choiceVehilceType;
    float fare;
    char ownerName[50],
        date[50],
        vehicleNumber[50],
        confirm;
    system(clrStr);
recordStart:
    headerMessage("Fare Details ");
    printf("\n Vehicles ----------->\n");

    for (; i < noOfvehicleType; i++)
    {
        printf("\n\t%02d.) %s", i + 1, vehilceType[i]);
    }

    printf("\n\t%02d.) Go to Main Menu", i + 1);
    printf("\n\nEnter Your Choice : ");

    scanf("%d", &choice);
    if (choice == i + 1)
    {
        system(clrStr);
        goto *mainMenu;
    }
    else if (choice > i + 1)
    {
        system(clrStr);
        headerMessage("[!] Invalid Choice ");
        goto recordStart;
    }

    choiceVehilceType = choice - 1;
    system(clrStr);
    headerMessage("Fare Details ");
    {
        printf("\n Routes ----------> \n");
        printf("\n\t 1.) Single Journey");
        printf("\n\t 2.) Return Journey");
        printf("\n\t 3.) GO Back");
        printf("\n\nEnter Your Choice : ");
    }
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        fare = fareSingleList[choiceVehilceType];
        break;
    case 2:
        fare = fareReturnList[choiceVehilceType];
        break;

    default:
        system(clrStr);
        headerMessage("[!] Invalid Choice ");
        goto recordStart;
    }

    getVehicleDetails(ownerName, vehicleNumber, date);
    printf("\n\n Waiting for payment complition of %f Rs (y/n)", fare);
    scanf("%c", &confirm);
    if (confirm == 'y' || confirm == 'Y')
    {
        headerMessage("Payment Succed ");
        registerData(ownerName, vehicleNumber, date, fare);
    }
    else
    {
        headerMessage("Payment Cancelled ");
    }
    holdForMainMenu();
    goto *mainMenu;
}

void displayFareDetails()
{
    int i = 0;
    system(clrStr);

    headerMessage("Update Fare");
    printf("\n\n S.no.\t|\t Single Fare\t|\t Return Fare\t|\tType");
    for (i = 0; i < noOfvehicleType; i++)
    {
        printf("\n   %d\t\t%.2f\t\t\t%.2f\t\t\t%s", i + 1, fareSingleList[i], fareReturnList[i], vehilceType[i]);
    }
    holdForMainMenu();
}

void updateFare()
{
    int i = 0, choice, vehilceTypeChoice;
    void *labelUpdateFareStart;
    system(clrStr);
updateFareStart:
    labelUpdateFareStart = &&updateFareStart;
    headerMessage("Update Fare");
    printf("\n\n S.no.\t|\t Single Fare\t|\t Return Fare\t|\tType");
    for (i = 0; i < noOfvehicleType; i++)
    {
        printf("\n   %d\t\t%.2f\t\t\t%.2f\t\t\t%s", i + 1, fareSingleList[i], fareReturnList[i], vehilceType[i]);
    }
    printf("\n\nEnter S.No. to change Fare : ");
    scanf("%d", &vehilceTypeChoice);
    vehilceTypeChoice -= 1;

    validChoice(vehilceTypeChoice, i, labelUpdateFareStart);
    system(clrStr);
    headerMessage("Fare Details ");
    {
        printf("\n choice route to change fare ----------> \n");
        printf("\n\t 1.) Single Journey");
        printf("\n\t 2.) Return Journey");
        printf("\n\t 3.) GO Back");
        printf("\n\nEnter Your Choice : ");
    }
    scanf("%d", &choice);
    validChoice(choice, 4, labelUpdateFareStart);
    switch (choice)
    {
    case 1:
        printf("\n\n Current Fare = %.2f Rs", fareSingleList[vehilceTypeChoice]);
        printf("\nEnter New Fare : ");
        scanf("%f", &fareSingleList[vehilceTypeChoice]);
        break;
    case 2:
        printf("\n\n Current Fare = %.2f Rs", fareReturnList[vehilceTypeChoice]);
        printf("\nEnter New Fare : ");
        scanf("%f", &fareReturnList[vehilceTypeChoice]);
        break;

    default:
        goto *labelUpdateFareStart;
        break;
    }

    system(clrStr);
    headerMessage("Fare Updated");
    holdForMainMenu();
}

void searchRecord()
{
    vn *node = top;
    void *searchLabel;
    int i = 1, choice;
    char filter[50];
    float fareFilter;
    system(clrStr);
searchStart:
    searchLabel = &&searchStart;
    headerMessage("Search ");
    printf("\n\n Choose a Filter -----> ");
    printf("\n\t1.) Search by Owner Name");
    printf("\n\t2.) Search by Vehicle Number");
    printf("\n\t3.) Search by Fare");
    printf("\n\t4.) Show all Records");
    printf("\n\t5.) Go to Main Menu");
    printf("\n\nEnter Your Choice : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("\nEnter Owner Name : ");
        gets(filter);
        gets(filter);
        break;
    case 2:
        printf("\nEnter Vehicle Number : ");
        gets(filter);
        gets(filter);
        break;
    case 3:
        printf("\nEnter Fare : ");
        scanf("%f", &fareFilter);
        break;
    case 4:
        break;
    case 5:
        holdForMainMenu();
        break;

    default:
        system(clrStr);
        headerMessage("Invalid Choice");
        goto *searchLabel;
        break;
    }

    printf("\n\n ID \t|\tName\t|\tNumber\t|\tFare\t|\tDate\t");

    while (node != NULL)
    {
        if ((choice == 1 && !strPatMatch(node->ownerName, filter)) || (choice == 2 && !strPatMatch(node->vehicleNumber, filter)) || (choice == 3 && fareFilter != node->recordFare))
        {
            node = node->nextNode;
            continue;
        }
        printf("\n%02d.\t\t%s\t\t%s\t%.2f\t\t%s", node->index, node->ownerName, node->vehicleNumber, node->recordFare, node->registerDate);
        node = node->nextNode;
    }
}

void deleteFareDetails()
{
    vn *node, *lastNode;
    node = top;
    lastNode = node;
    int ID;
    searchRecord();
    printf("\n\nEnter ID to delete : ");
    scanf("%d", &ID);

    while (node->index != ID)
    {
        lastNode = node;
        node = node->nextNode;
    }

    if (node == top)
    {
        top = top->nextNode;
    }
    else
    {
        lastNode->nextNode = lastNode->nextNode->nextNode;
    }

    if (node->index == ID)
    {
        free(node);
        headerMessage("Deleted");
        registeredVehicleNumb--;
    }
    holdForMainMenu();
}

int main()
{

    int choice;

    system(clrStr);
startMenu:

    mainMenu = &&startMenu;
    headerMessage("Toll Plaza System");
    menuDisplay(&choice);

    switch (choice)
    {
    case 1:
        displayFareDetails();
        break;
    case 2:
        updateFare();
        break;
    case 3:
        RecordFareDetails();
        break;
    case 4:
        deleteFareDetails();
        break;
    case 5:
        searchRecord();
        holdForMainMenu();

        break;
    case 6:
        system(clrStr);
        headerMessage(" System Closed ");
        exit(0);
        break;
    default:
        system(clrStr);

        headerMessage("[!] Invalid Choice ");
        goto *mainMenu;

        break;
    }
    return 0;
}
