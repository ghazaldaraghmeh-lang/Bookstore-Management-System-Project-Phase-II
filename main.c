/*
              Ghazal_Salah_Daraghmeh
                     1230542
               Dr.Alaa_Nairat
                   sec:7/Lecture
                   sec:14/Lab

*/

#include <stdio.h>
#include <stdio.h>
#define MAXSIZE 100

void displayMainMenu();      	 // displays the main menu
void addBook(int bins[], double prices[],int *size);   	// adds information for a new book
void removeBook(int bins[], double prices[], int *size);  	   // removes information of old book
void searchForBook(int bins[], double prices[], int size);  	    // searches for a book in the store
void uploadDataFile(int bins[], double prices[], int *size);       	// uploads book data from file
void printBooklist(int bins[], double prices[], int size);        // print the information (bins and prices)
void updateDataFile(int bins[], double prices[], int size);            // saves book data updates to file



int main()
{
    int bins[MAXSIZE];
    double prices[MAXSIZE];
    int size=0;

    printf("Welcome to My BookStore Management System:\n");
    printf("\n");
    uploadDataFile(bins,prices,&size);
    printf("\n");

    int option;

    do
    {
        displayMainMenu();
        scanf("%d",&option);

        switch (option)
        {
        case 1:
            addBook(bins,prices,&size);
            break;

        case 2:
            removeBook(bins,prices,&size);
            break;

        case 3:
            searchForBook(bins,prices,size);
            break;

        case 4:
            printBooklist(bins,prices,size);
            printf("\n");
            break;

        case 5:
            printf("\n");
            updateDataFile(bins,prices,size);
            break;


        default:
            printf("No such operation!  Please try again.\n");
            printf("\n");
        }

    }
    while ( option !=5 );

    return 0;
}


void displayMainMenu()
{
    printf("Please Select an Operation(1-4):\n");
    printf("1- Add a Book:\n");
    printf("2- Remove a Book:\n");
    printf("3- Search for a Book:\n");
    printf("4- Print Book List:\n");
    printf("5- Exit System:\n");
    printf("\n");

}

void addBook(int bins[], double prices[],int *size)
{

    if ( *size < MAXSIZE)
    {
        int newbin;
        double newprice;

        printf("Enter bin number for book:\n");
        scanf("%d",&newbin);

          int indx = -1;
       for (int i = 0; i < *size; i++) {
        if (bins[i] == newbin) {
            indx = i;
            printf("Book with bin %d already exists\n\n",newbin);
            break;
            }
        }

        if (indx == -1) {

          int position = 0;
            while ( position < *size && bins[position] < newbin) {
                    position++;
               }

            printf("Enter price of book:\n");
            scanf("%lf",&newprice);


            for (int i = *size; i > position; i--)
            {
                bins[i] = bins[i - 1];
                prices[i] = prices[i - 1];
                }

            bins[position] = newbin;
            prices[position] = newprice;

            (*size)++;

            printf("Book with bin %d has been added\n", newbin);
         }

    }
    printf("\n");
}

void removeBook(int bins[], double prices[], int *size)
{
    // Check if the list is not empty
    if (*size > 0)
    {
        int binToremoved;
        printf("Enter bin number for book to remove\n");
        scanf("%d", &binToremoved);

        // Search for the bin number to be removed
        int position = -1;

        for (int i = 0; i < *size; i++)
        {
            if (bins[i] == binToremoved)
            {
                 position = i;

               for (int i = position; i < *size - 1; i++) {
                     bins[i] = bins[i + 1];
                     prices[i] = prices[i + 1]; }

                (*size)--;

                    printf("Book with bin %d has been removed\n", binToremoved);
                break;
            }
        }

        if (position == -1)
        {
            printf("Book with bin %d does not exist\n", binToremoved);
        }
    }

    printf("\n");
}

void searchForBook(int bins[], double prices[], int size)
{
    // Check if the list is not empty
    if (size > 0)
    {
        int binSearch;
        printf("Enter bin number for book to search for\n");
        scanf("%d", &binSearch);

        // Search for the bin number
       int index = -1;
    for (int i = 0; i < size; i++) {
        if (bins[i] == binSearch) {
            index = i;
            printf(" bin# = %d    price = %.2f\n",binSearch, prices[i]);
            break;
            }
        }

        if (index == -1) {
          printf("Book with bin %d not found\n", binSearch);
           printf("\n");
           }
     }
        else {
           printf("The list is empty. No books to search for.\n");
           }

    printf("\n");
}

void uploadDataFile(int bins[], double prices[], int *size)
{

    printf("Uploading data file ...\n");
    *size = 0;
    FILE *input = fopen("books.txt", "r"); // Open the data file and read book information
    if (input == NULL) {
        printf("Error: Could not open file for reading.\n");
        return; }

    while(fscanf(input,"%d %lf", &bins[*size], &prices[*size])!= EOF)
    {
        (*size)++;
    }

    fclose(input);
    printf("Data File uploaded\n");
    printf("\n");

}


void printBooklist(int bins[], double prices[], int size)
{

    for (int i = 0 ; i < size ; i++)
    {
        printf(" bin# = %d    price = %.2f\n", bins[i], prices[i]);
    }

}

void updateDataFile(int bins[], double prices[], int size)
{
    printf("Updating data file ...\n");
    FILE *input = fopen("books.txt", "w");
    for (int i = 0; i < size; i++)
    {
        fprintf(input, "%d %.2f\n", bins[i], prices[i]);
    }

    fclose(input);
    printf("Data File updated\n");
    printf("\n");
    printf("Thank you for using My BookStore Management  System. GoodBye.");
}

