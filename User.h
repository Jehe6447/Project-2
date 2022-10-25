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
