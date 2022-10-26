#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cassert>

using namespace std;

class Post{
    private:
        string body_;
        string post_author_;
        int num_likes_;
        string date_;
    public:
        Post();
        Post(string body, string postAuth, int numLikes, string date);
        string getPostBody(); //Returns the body_ of the post
        void setPostBody(string post_body); //Sets new body_ for the post
        string getPostAuthor(); //Returns the post_author_ of the post
        void setPostAuthor(string author); //Sets the new post_author_ for the post
        int getPostLikes(); //Returns num_likes_ that the post has received
        void setPostLikes(int likes); //Sets num_likes_ data member to likes if likes is a positive integer or 0.
        string getPostDate(); //Returns the date_ of the post
        void setPostDate(string post_date); //Sets new date_ for the post
};

Post::Post(){
    //Sets body_, post_author_, date_ to empty string and num_likes_ to 0
    body_ = "";
    post_author_ = "";
    date_ = "";
    num_likes_ = 0;
}

Post::Post(string body, string postAuth, int numLikes, string date){
    //Takes a string for body_, string for post_author_, int for num_likes_, and string for date_ (in this order) for initializing the data members of a Post object
    body_ = body;
    post_author_ = postAuth;
    date_ = date;
    num_likes_ = numLikes;
}

string Post::getPostBody(){
    //Returns the body_ of the post
    return body_;
}
void Post::setPostBody(string post_body){
    //Sets the new post_author_ for the post
    body_ = post_body;
       
}

string Post::getPostAuthor(){
   //Returns the post_author_ of the post
    return post_author_;
}
void Post::setPostAuthor(string author){
    //Sets the new post_author_ for the post
    post_author_ = author;
}
int Post::getPostLikes(){
    //Returns num_likes_ that the post has received
    return num_likes_;
}

void Post::setPostLikes(int likes){
    //Sets num_likes_ data member to likes if likes is a positive integer or 0.
    if(likes >= 0){
        num_likes_ = likes;
    }
}
string Post::getPostDate(){
    //Returns the date_ of the post
    return date_;
}
void Post::setPostDate(string post_date){
    //Sets new date_ for the post
    date_ = post_date;
}

class User{
    private:
        static const int size_ = 50;
        string username_;
        int likes_[size_];
        int num_Posts_;        
    public:
        User();
        User(string username, int likes[], int num_posts);
        string getUsername();
        void setUsername(string username);
        int getLikesAt(int post_id);
        bool setLikesAt(int post_id, int num_likes);
        void setNumPosts(int posts);
        int getNumPosts();
        int getSize();
};

//Default constructor 
User::User()
{
    username_ = "";
    for (int i = 0; i<size_; i++){
        likes_[i] = -1;
    }
    num_Posts_ = 0;
}
//Paramaterized constructor
User::User(string username, int likes[], int num_posts){
    username_ = username;
    for (int i = 0; i<size_; i++){
        likes_[i] = -1;
    }
    for (int i = 0; i<num_posts; i++){
        likes_[i] = likes[i];
    }
    num_Posts_ = num_posts;
}


string User::getUsername(){
    return username_;
}
int User::getLikesAt(int post_id){
    if(post_id >= size_ || post_id < 0){
        return -2;
    }
    else{
        return likes_[post_id];
    }
}
int User::getNumPosts(){
    return num_Posts_;
}
int User::getSize(){
    return size_;
}

void User::setUsername(string username){
    username_ = username;
}
bool User::setLikesAt(int post_id, int num_likes){
    if(post_id >= num_Posts_ || post_id < 0 || (num_likes < -1) || (num_likes > 10)){
        return false;
    }
    else{
        likes_[post_id] = num_likes;
        return true;
    }
}
void User::setNumPosts(int posts){
    if(posts > 0 && posts < size_){
        num_Posts_ = posts;
    }
}

int split(string input_string, char seperator, string arr[], int arr_size){
    // varriable declaration
    int currentPieces = 0;
    int seperatorCount = 0;
    int index = 0;
    // storing my string length in a variable
    const int stringLength = input_string.length();
    // if the input string has no elements return 0
    if (input_string == "") return 0;
    // for loop for rows
    for (int i = 0; i < stringLength; i++) {
        int length_to_do = i - index;
        if (currentPieces < arr_size) {
            if (input_string[i] == seperator) {
                arr[currentPieces] = input_string.substr(index, length_to_do);
                currentPieces++;
                seperatorCount++;
                index = i + 1;
            }
            // if 
            if (i + 1 == stringLength) {
                arr[currentPieces] = input_string.substr(index, length_to_do + 1);
                currentPieces++;
            }
        }
        else return -1;
    }
    if (seperatorCount == 0) {
        arr[0] = input_string;
        return 1;
    }
    return currentPieces;
}

int readPosts(string fileName, Post posts[],int numPostsS, int postsArrSize)
{

    if(numPostsS == postsArrSize)
    {
        return -2;
    }
    string line;
    ifstream input;
    input.open(fileName);
    if(!input.is_open())
    {
        return -1;  
    }
    while(numPostsS < postsArrSize && getline(input,line))
    {
        if(line != "")
        {
            string temp[4];
            if(split(line, ',', temp, 4)==4)
            {
                posts[numPostsS] = Post(temp[0], temp[1], stoi(temp[2]), temp[3]);
                numPostsS++;
            }
        }
    }
    return numPostsS;
}

int readLikes(string fileName, User users[],int numUsersS, int usersArrSize, int maxPosts){
    if(numUsersS == usersArrSize)
    {
        return -2;
    }
    string line;
    ifstream input;
    input.open(fileName);   //open file with ifstream 
    if (!input.is_open()){ //test to make sure file can open succesfully
        return -1;
    }
    int index = numUsersS;     //did not need index, optimize gode by replacing with numUsersStored
    while (getline(input, line) && numUsersS < usersArrSize){  //break out of loop when numb users stored is equal to arrsize
        if (line != ""){        //dont test empty lines
            string temp[maxPosts+1];  //temp arr{} to hold everything in split (all ratings plus username)
            int x[50];                  //holder for ratings
            int count = split(line, ',', temp, maxPosts+1);   //split returns # of items in arr{} and fills
            for (int i = 1; i < count; i++){    //for numb items in arr is count but start at one due to username at first position
                int b = stoi(temp[i]); //change from string to int and then adds to the int array for ratings
                x[i-1] = b;
            }
            User tempUser(temp[0], x, count-1); //temp makes new user object and uses perametized variables
            users[index] = tempUser;    //adds temp user object to the array of users
            index++;    //did not need index
            numUsersS++;     //increments numb users
        }
    }
    return numUsersS;
}

void printPostsByYear(Post posts[],string YY,int numPostsS)
{
    if(numPostsS <= 0)
    {
        cout << "No posts are stored" << endl;
        return;
    }
    bool found = false;
    for(int i=0 ; i< numPostsS; i++)
    {
        if(posts[i].getPostDate().substr(6,7)== YY)
        {
            found = true;
            break;
        }
    }
    //if there is a singular presence of the post year in search
    if(found)
    {
       cout << "Here is a list of posts for year " << YY << endl;
       for (int i=0; i< numPostsS;i++)
       {
           if(posts[i].getPostDate().substr(6,7)== YY)
           {
               cout << posts[i].getPostBody() << endl;
           }
       }
    }
    else{ 
        cout << "No posts stored for year " << YY<< endl;
    }
}

int getLikes(string pa, Post posts[], int nps, string username, User users[], int nus){
    // nps: number of posts stored
    // nus: number of users stored
    bool postFound = false;
    bool userFound = false;
    if (nps <= 0 || nus <= 0) return -2;
    int postIndex;
    for (postIndex = 0; postIndex < nps; postIndex++){
        if (posts[postIndex].getPostAuthor() == pa) {
            postFound = true;
            break;
        } 
    }
    int userIndex;
    for (userIndex = 0; userIndex < nus; userIndex++){
        if (users[userIndex].getUsername() == username) {
            userFound = true;
            break;
        }
    }
    if (!postFound || !userFound) return -3;
    return users[userIndex].getLikesAt(postIndex);
}

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

void menu(){ // menu function to avoid rewriting menu
    cout << "======Main Menu======\n1. Read Posts\n2. Print Posts By Year\n3. Read Likes\n4. Get Likes\n5. Find users with matching tag\n6. Quit\n";
}

int main(){
    Post posts[50];
    User users[50];
    int currSize = 0;
    int currSize1 = 0;
    bool quit = false;
    while (!quit){
        int input = 0;
        string fileName = "";
        string fileName1 = "";
        string tag = "";
        int numPosts = 0;
        int numUsers = 0;
        int numLikes = 0;
        menu();
        cin >> input;
        switch (input){
            case 1:
                cout << "Enter a post file name:" << endl;
                cin >> fileName;
                numPosts = readPosts(fileName, posts, currSize, 50);
                if (numPosts == -1){
                    cout << "File failed to open. No posts saved to the database." << endl;
                }
                else if (numPosts == -2){
                    cout << "Database is already full. No posts were added." << endl;
                }
                else if (numPosts == 50){
                    cout << "Database is full. Some posts may have not been added." << endl;
                    currSize = numPosts;
                }
                else if(numPosts >= 0 && numPosts < 50){
                    cout << "Total posts in the database: " << numPosts << endl;
                    currSize = numPosts;
                }
                break;
            case 2:
                cout << "Enter the year(YY):" << endl;
                cin >> fileName;
                printPostsByYear(posts, fileName, currSize);
                break;
            case 3:
                cout << "Enter a user file name:" << endl;
                cin >> fileName;
                numUsers = readLikes(fileName, users, currSize1, 50, 50);
                if(numUsers == -1){
                    cout << "File failed to open. No users saved to the database." << endl;
                }
                else if(numUsers == -2){
                    cout << "Database is already full. No users were added." << endl;
                }
                else if(numUsers == 50){
                    cout << "Database is full. Some users may have not been added." << endl;
                    currSize1 = numUsers;
                }
                else if(numUsers >= 0 && numUsers < 50){
                    cout << "Total users in the database: " << numUsers << endl;
                    currSize1 = numUsers;
                }
                break;
            case 4:
                cout << "Enter a post author:" << endl;
                cin >> fileName;
                cout << "Enter a user name:" << endl;
                cin >> fileName1;
                numLikes = getLikes(fileName, posts, currSize, fileName1, users, currSize1);
                if(numLikes == 0){
                    cout << fileName1 << " has not liked the post posted by " << fileName << endl;
                }
                else if(numLikes == -1){
                    cout << fileName1 << " has not viewed the post posted by " << fileName << endl;
                }
                else if(numLikes == -2){
                    cout << "Database is empty." << endl;
                }
                else if(numLikes == -3){
                    cout << fileName1 << " or " << fileName << " does not exist." << endl;
                }
                else{
                    cout << fileName1 << " liked the post posted by " << fileName << " " << numLikes << " times" << endl;
                }
                break;
            case 5:
                cout << "Enter a tag:" << endl;
                cin >> tag;
                findTagUser(tag, users, currSize1);
                break;
            case 6:
                cout << "Good bye!" << endl;
                quit = true;
                break;
            default:
                cout << "Invalid input.\n";
                break;
        }
    }
    return 0;
}
