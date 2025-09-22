#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int choice;
    bool run = true;
    string genre, choice2, song;

    while(run){
        cout << "===================================" <<endl;
        cout << " Spotify Playlist Recommender v1.0" <<endl;
        cout << " Contributor: Ng Jie Sheng, Pan Han Cheng" <<endl;
        cout << "===================================" <<endl;

        cout << "Choose a genre:" <<endl;
        cout << "1. Pop" <<endl;
        cout << "2. Rock" <<endl;
        cout << "3. Jazz" <<endl;
        cout << "4. Sad" <<endl;
        cout << "5. Workout" <<endl;
        cout << "6. EDM" <<endl;
        cout << "7. End Program" <<endl;
        cout << "Enter your choice (1-7): ";
        cin >> choice;

        if (choice == 7){
            run = false;
            break;
        }
        
        switch (choice)
        {
        case 1:
            genre = "Pop.txt";
            break;
        case 2:
            genre = "Rock.txt";
            break;
        case 3:
            genre = "Jazz.txt";
            break;
        case 4:
            genre = "Sad.txt";
            break;
        case 5:
            genre = "Workout.txt";
            break;
        case 6:
            genre = "EDM.txt";
            break;
        
        default:
            break;
        }

        fstream playlist(genre);

        while(getline(playlist, song)){
            cout << song <<endl;
        }

        playlist.close();

        cout << "Choose another genre? (y/n)" <<endl;
        cin >> choice2;

        if (choice2 == "n"){
            run = false;
            break;
        }

    };

    return 0;
}