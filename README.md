# COMP133 – Bookstore Management System (Phase 2)

## Project Description

In this phase, the major parts of the functions created in Phase 1 are implemented. The program manages a list of books using parallel arrays and provides options to add, remove, search for, and print books.

Each book is represented by:
- **Bin Number:** An integer identifying the book.
- **Price:** A `double` representing the book's price.

The program loads book information from `books.txt` when it starts and saves all changes to the same file when the user exits.

## Main Menu

The program displays the following menu:

```text
Please Select an Operation (1-5):
1- Add a Book
2- Remove a Book
3- Search for a Book
4- Print Book List
5- Exit System
```

The menu is displayed again after each operation until the user selects option 5.

## Required Functions

### `displayMainMenu()`

Displays the main menu, including the new **Print Book List** option.

### `void addBook( int bins[], double prices[], int *size);`

This function will receive the arrays containing the bin numbers and the prices as parameters. It will also receive a pointer to an integer which references the current size of the list (number of books in the list).
The function will check to see if the list is not full. If list is not full ( size < MAXSIZE) then it will search for the appropriate position of a given bin number and if the bin number is already in the list it will display an error message. If not, the function will shift all the bins starting from the position of the new bin to the right of the array and then insert the new bin into that position. Same will be done to add the price of the book to the prices array.

### `removeBook(int bins[], double prices[], int *size);`

This function will receive the arrays containing the bin numbers and the prices as parameters. It will also receive a pointer to an integer which references the current size of the list (number of books in the list).
The function will check if the list is not empty. If it is not empty (size > 0) then it will search for the bin number to be removed and if not found will display an error message. If the bin number exists, the function will remove it and shift all the elements that follow it to the left of the array. Same will be done to remove the price of the book from the prices array.

### `searchForBook(int bins[], double prices[], int size)`

This function will receive the arrays containing the bin numbers and the prices as parameters. It will also receive an integer which has the value of the current size of the list (number of books in the list).
The function will check if the list is not empty. If it is not empty (size > 0) then it will ask the user to enter a bin number and will search for that bin number. If the bin number is not found it will display an error message.
If the bin number is found then it will be displayed along with the price in a suitable format on the screen.

### `uploadDataFile(int bins[], double prices[], int *size)`

This function will receive the arrays containing the bin numbers and the prices as parameters. It will also receive a pointer to an integer which references the current size of the list (number of books in the list).
The function will open a file called  `books.txt` for reading and will read all the book bin numbers and prices and store them in the arrays.

### `updateDataFile(int bins[], double prices[], int size)`

This function will receive the arrays containing the bin numbers and the prices as parameters. It will also receive an integer which has the value of the current size of the list (number of books in the list).
The function will open the file called `books.txt` for writing and will write all the book bin numbers and prices in the arrays to that file ( overwrite file ).

### `printBooks(int bins[], double prices[], int size)`

This function will receive the arrays containing the bin numbers and the prices as parameters. It will also receive an integer which has the value of the current size of the list (number of books in the list).
This function will print the information (bins and prices) currently stored in the arrays.

## Important Requirements

- You need to define a constant called `MAXSIZE` ( max number of books stored ) equal to `100`.
- Use **parallel arrays** (`bins[]` and `prices[]`) exactly as specified. **Do not use structures (`struct`)**. Using structures anywhere in this project phase results in a grade of zero according to the assignment instructions.
- Keep the books in **ascending order by bin number**.
- Do not use sorting functions. Maintain the order by shifting elements during the `addBook()` and `removeBook()` operations.
- Include your full name, student ID, lecture section, and lab section in a comment at the beginning of `main.c`.

## Sample Data
Make sure your program works very similar to the following sample run:
Assuming that at the beginning of the run file `books.txt` has the following information stored (first column = bins  second column = prices):

```text
1234    72.45
2345    25.20
```

         

## Sample Run
<img width="648" height="1041" alt="image" src="https://github.com/user-attachments/assets/a869be63-8f66-4b1a-812c-04451e16324d" />
<img width="672" height="945" alt="image" src="https://github.com/user-attachments/assets/c61e9ad3-172c-4a3d-87fb-bce00e0a180b" />
<img width="792" height="980" alt="image" src="https://github.com/user-attachments/assets/4fa69f75-3e29-430b-9926-d9a955a96170" />


## Programming Language

C

The assignment instructions state that the `main.c` file must be uploaded to ITC as specified. Make sure it contains the required student information comment at the beginning of the file.
