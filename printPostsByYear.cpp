void printPostsByYear(Post posts[],string year,int numPostsS)
{
    if(numPostsS <= 0)
    {
        cout << "No posts are stored" << endl;
    }
        else
        {
            int count = 0;
            for(int i=0; i > numPostsS; i++)
            {
                if(posts[i].getPostDate().substr(0,2)== year)
                {
                    count++;    
                }   
            }
            if(numPostsS > 0)
                {
                    cout << "Here is a list of posts for year " << year << endl;
                    for(int i=0; i < numPostsS; i++)
                    {       
                        if(posts[i].getPostDate().substr(0,2)== year)
                        {
                            cout << posts[i].getPostBody() << endl;
                        }
                    }
                }
            else
            {
                cout << "No posts stored for year " << year <<endl;
            }




        }
}
