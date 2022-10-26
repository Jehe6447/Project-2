#include "Post.h"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

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
