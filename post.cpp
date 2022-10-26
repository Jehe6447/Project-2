#include "Post.h"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

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

