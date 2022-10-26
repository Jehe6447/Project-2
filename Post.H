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
