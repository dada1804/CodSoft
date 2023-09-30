#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int NUM_ROWS = 5;
const int NUM_COLS = 10;
const double TICKET_PRICE = 10.0;

// Function to display the seating arrangement
void displaySeats(const vector<vector<char>>& seats) {
    cout << "  ";
    for (int col = 0; col < NUM_COLS; col++) {
        cout << setw(2) << col + 1 << " ";
    }
    cout << endl;

    for (int row = 0; row < NUM_ROWS; row++) {
        cout << char('A' + row) << " ";
        for (int col = 0; col < NUM_COLS; col++) {
            cout << seats[row][col] << "  ";
        }
        cout << endl;
    }
}

// Function to book a seat
bool bookSeat(vector<vector<char>>& seats, int row, int col) {
    if (row < 0 || row >= NUM_ROWS || col < 0 || col >= NUM_COLS || seats[row][col] == 'X') {
        cout << "Invalid seat selection. Please try again." << endl;
        return false;
    }

    seats[row][col] = 'X'; // Mark the seat as booked
    return true;
}

int main() {
    vector<vector<char>> seats(NUM_ROWS, vector<char>(NUM_COLS, 'O')); // 'O' represents an available seat

    cout << "Welcome to the Movie Ticket Booking System!" << endl;

    while (true) {
        cout << "\nMovie Listings:" << endl;
        // Add your movie listings here

        displaySeats(seats);

        char row;
        int col;

        cout << "\nEnter the row (A-E) and seat number (1-10) to book a seat (e.g., A3): ";
        cin >> row >> col;
        row = toupper(row); // Convert row to uppercase

        col--; // Adjust col to be zero-based

        if (bookSeat(seats, row - 'A', col)) {
            double totalCost = TICKET_PRICE;
            cout << "\nSeat booked successfully!" << endl;
            cout << "Total cost: $" << fixed << setprecision(2) << totalCost << endl;
        }

        cout << "\nDo you want to book another seat? (Y/N): ";
        char choice;
        cin >> choice;
        if (choice != 'Y' && choice != 'y') {
            cout << "Thank you for using the Movie Ticket Booking System. Enjoy your movie!" << endl;
            break;
        }
    }

    return 0;
}
