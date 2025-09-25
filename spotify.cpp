#include <iostream>
#include <fstream>
#include <typeinfo>
#include <limits>
using namespace std;

int main() {
    int choice;
    bool run = true;
    string genre, choice2, song;

    while (run) {

        bool validChoice = true;

        cout << "===================================" << endl;
        cout << " Spotify Playlist Recommender v1.0" << endl;
        cout << " Contributor: Ng Jie Sheng, Pan Han Cheng" << endl;
        cout << "===================================" << endl;

        cout << "Choose a genre:" << endl;
        cout << "1. Pop" << endl;
        cout << "2. Rock" << endl;
        cout << "3. Jazz" << endl;
        cout << "4. Sad" << endl;
        cout << "5. Workout" << endl;
        cout << "6. EDM" << endl;
        cout << "7. End Program" << endl;
        cout << "Enter your choice (1-7): ";
        
        cin >> choice;

        if (choice == 7) {
            cout << "Thank you for using the Spotify Playlist Recommender! " << endl;
            break;
        }

        if (cin.fail()){
            cout << "Invalid choice. Please select a number from 1 to 7." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            validChoice = false;
        }
        else{
            switch (choice) {
            case 1: genre = "Pop.txt"; break;
            case 2: genre = "Rock.txt"; break;
            case 3: genre = "Jazz.txt"; break;
            case 4: genre = "Sad.txt"; break;
            case 5: genre = "Workout.txt"; break;
            case 6: genre = "EDM.txt"; break;
            default:
                cout << "Invalid choice. Please select a number from 1 to 7." << endl;
                validChoice = false;
            }
        }

        if (validChoice == false) {
            continue;  // back to menu
        }

        fstream playlist(genre);
        if (!playlist) {
            cout << "Error: Could not open " << genre << endl;
            continue;
        }

        cout << "-----------------------------------" << endl;
        while (getline(playlist, song)) {
            cout << song << endl;
        }
        cout << "-----------------------------------" << endl;

        playlist.close();

        cout << "Choose another genre? (y/n): ";
        cin >> choice2;

        if (choice2 == "n" || choice2 == "N") {
            cout << "Thank you for using the Spotify Playlist Recommender!" << endl;
            run = false;
        } 
        else if (choice2 == "y" || choice2 == "Y") {
            // loop continues
        } 
        else {
            cout << "Invalid input. Program will now exit." << endl;
            run = false;
        }
    } // closes while loop

    return 0;
} // closes main
