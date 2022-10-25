int readLikes (string fileName, User users[],int numUsersS, int usersArrSize, int maxPosts)
{

    if(numUsersS == usersArrSize)
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
    while(numUsersS < usersArrSize && getline(input,line))
    {
        if(line != "")
        {
            string temp[51];
            bool unCheck = false;
            split(line, ',', temp, 51) ;
            
            for(int i=0; i< numUsersS; i++)
            {
                if(users[i].getUsername() == temp[0])
                {
                    unCheck= true;
                }
            }
            if (unCheck == false)
            {
            User tUser = User();
            tUser.setUsername(temp[0]);
            tUser.setNumPosts(maxPosts);
            
            for(int i= 0; i < maxPosts; i++)
            {
                tUser.setLikesAt(i, stoi(temp[i+1]));
            }
            users[numUsersS] = tUser;
            numUsersS++;
            }
        }
        
    }
return numUsersS;
}
