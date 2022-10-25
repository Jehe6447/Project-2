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
            split(line, ',', temp, 51) ;
            int tempLikes[50];
            numUsersS++;
            
        }
        
    }
    return numUsersS;
}
