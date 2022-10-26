#include "Post.h"
#include "User.h"
#include <iostream>
#include <string>

using namespace std;


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
