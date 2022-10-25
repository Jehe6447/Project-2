int readLikes (string fileName, User user[],int numUsersS, int usersArrSize, int maxPosts)
{

    if(numUsersS == usersArrSize)
    {
        return -2;
    }
    if(line != "")
        {
    }
    string line;
    ifstream input;
    input.open(fileName);
    if(!input.is_open())
    {
        return -1;  
    }
  string line;
  int num_users=0;
    while( getline(input,line))
    {
            string temp[50];
          int size = 0;
            split(line, ',', temp, size) ;
            
         string username = temp[0];
        int templikes[50];
      for(int i=1; i<size; i++)
      {
        templikes[i-1] = stoi(temp[i]);
      }
      User user(username,templikes,size-1);
      if(numUsersS < usersArrSize)
      {
        user[numUsersS]= user;
      num_users++;
      }
      file.close();     
        
        
    }
    return num_users;
}
