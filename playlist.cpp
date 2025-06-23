#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Song {
public:
    string title;
    Song* prev;
    Song* next;

    Song(string t) : title(t), prev(nullptr), next(nullptr) {}
};

class PlaylistManager {
private:
    Song* head;
    Song* tail;
    Song* current;

    stack<Song*> recentlyPlayed;
    queue<Song*> upcomingQueue;

public:
    PlaylistManager() : head(nullptr), tail(nullptr), current(nullptr) {}

    ~PlaylistManager() {
        Song* temp = head;
        while (temp) {
            Song* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
    }

    void addSong(const string& title) {
        Song* temp = head;
        while (temp) {
            if (temp->title == title) {
                cout << "Song \"" << title << "\" already exists in the playlist.\n";
                return;
            }
            temp = temp->next;
        }
    
        Song* newSong = new Song(title);
        if (!head) {
            head = tail = current = newSong;
        } else {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }
        cout << "Song added.\n";
    }
    
    bool deleteSong(const string& title) {
        Song* temp = head;
        while (temp) {
            if (temp->title == title) {
                if (temp->prev) temp->prev->next = temp->next;
                else head = temp->next;

                if (temp->next) temp->next->prev = temp->prev;
                else tail = temp->prev;

                if (current == temp)
                    current = temp->next ? temp->next : temp->prev;

                delete temp;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    bool skipNext() {
        if (current && current->next) {
            recentlyPlayed.push(current);
            current = current->next;
            return true;
        }
        return false;
    }

    bool skipPrevious() {
        if (current && current->prev) {
            recentlyPlayed.push(current);
            current = current->prev;
            return true;
        }
        return false;
    }

    void addToQueue(const string& title) {
        Song* song = new Song(title);
        upcomingQueue.push(song);
    }

    bool playSong() {
        if (upcomingQueue.empty()) {
            Song* temp = head;
            while (temp) {
                upcomingQueue.push(temp);
                temp = temp->next;
            }
        }
    
        if (!upcomingQueue.empty()) {
            if (current)
                recentlyPlayed.push(current);
            current = upcomingQueue.front();
            upcomingQueue.pop();
            return true;
        }
    
        return false;
    }
    

    bool backtrack() {
        if (!recentlyPlayed.empty()) {
            current = recentlyPlayed.top();
            recentlyPlayed.pop();
            return true;
        }
        return false;
    }

    Song* getCurrentSong() const {
        return current;
    }

    vector<string> getPlaylist() const {
        vector<string> songs;
        Song* temp = head;
        while (temp) {
            songs.push_back(temp->title);
            temp = temp->next;
        }
        return songs;
    }
};

void showMenu() {
    cout << "\nPlaylist Manager Menu\n";
    cout << "1. Add Song\n";
    cout << "2. Delete Song\n";
    cout << "3. Skip to Next Song\n";
    cout << "4. Skip to Previous Song\n";
    cout << "5. Show Current Song\n";
    cout << "6. Show Full Playlist\n";
    cout << "7. Add Song to Upcoming Queue\n";
    cout << "8. Play Song\n";
    cout << "9. Backtrack to Recently Played Song\n";
    cout << "0. Exit\n";
    cout << "\n";
    cout << "Enter your choice: ";
}

int main() {
    PlaylistManager pm;
    int choice;
    string title;
    showMenu();

    while (true) {
        if (!(cin >> choice)) break;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter song title: ";
                getline(cin, title);
                pm.addSong(title);
                cout << "Song added.\n";
                break;

            case 2:
                cout << "Enter song title to delete: ";
                getline(cin, title);
                if (pm.deleteSong(title))
                    cout << "Song deleted.\n";
                else
                    cout << "Song not found.\n";
                break;

            case 3:
                if (pm.skipNext())
                    cout << "Skipped to next song.\n";
                else
                    cout << "No next song available.\n";
                break;

            case 4:
                if (pm.skipPrevious())
                    cout << "Skipped to previous song.\n";
                else
                    cout << "No previous song available.\n";
                break;

            case 5:
                if (Song* s = pm.getCurrentSong())
                    cout << "Now playing: " << s->title << endl;
                else
                    cout << "No song is currently playing.\n";
                break;

            case 6: {
                auto songs = pm.getPlaylist();
                cout << "\nPlaylist\n";
                for (const auto& s : songs)
                    cout << s << endl;
                cout << "\n";
                break;
            }

            case 7:
                cout << "Enter song title to queue: ";
                getline(cin, title);
                pm.addToQueue(title);
                cout << "Song added to queue.\n";
                break;

            case 8:
                if (pm.playSong())
                    cout << "Now playing: " << pm.getCurrentSong()->title << endl;
                else
                    cout << "No songs available to play.\n";
                break;

            case 9:
                if (pm.backtrack())
                    cout << "Backtracked to previous song.\n";
                else
                    cout << "No recently played song.\n";
                break;

            case 0:
                cout << "Exiting!\n";
                return 0;

            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}
