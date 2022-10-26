#include "Post.h"
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include <cassert>

using namespace std;

void findTagUser(string tag, User users[], int size){
    if (size <= 0) {
        cout << "No users are stored in the database" << endl;
        return;
    }
    bool found = false;
    for (int i = 0; i < size; i++){
        if (users[i].getUsername().find(tag) <= users[i].getUsername().length()){ // if the index of find() is within the bounds of the length of the string
            found = true;
            break; // prevents further looping after found becomes true
        }
    }
    if (!found) { // when the username is not found
        cout << "No matching user found" << endl;
        return;
    }
    // when we are here (in execution), we can assume that all paramater values are populated with at least something
    cout << "Here are all the usernames that contain " << tag << endl;
    for (int i = 0; i < size; i++){
        if (users[i].getUsername().find(tag) <= users[i].getUsername().length()){// if the index of find() is within the bounds of the length of the string
            cout << users[i].getUsername() << endl;
        }
    }
    return;
}
