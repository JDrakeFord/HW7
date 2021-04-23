// Implementation of the Draft header file
// The methods are labeled as 'method x' as denoted in the assignment instructions

#include "Draft.h"

//-------------------------------------------------------------------------
// Name:        Draft (method a)
// Parameters:  none
// Returns:     nothing
// Purpose:     Default constructor of the Draft class; it initalizes the 
//              two instance variables of the class to zero 
//      THIS CODE IS GIVEN TO YOU AND SHOULD NOT NEED TO BE EDITED!
//-------------------------------------------------------------------------
Draft::Draft()
{
	numPlayers = 0;
    numAvailable = 0;
}

//-------------------------------------------------------------------------
// Name:        Draft (method b)
// Parameters:  Draft object 
// Returns:     nothing
// Purpose:     Copy constructor of the Draft class; it copies the instance
//              variables from copyMe to this object.
//              Be sure to also copy each element of the copyMe.allPlayers[]
//              array into this class's allPlayers[] array (you'll need a loop!)
//-------------------------------------------------------------------------
Draft::Draft(const Draft &copyMe)
{
    //Copy attributes
    numPlayers = copyMe.numPlayers;
    numAvailable = copyMe.numAvailable;

    //Copy allPlayers array
    for(int i = 0; i < MAX_PLAYERS; i++)
    {
        allPlayers[i] = copyMe.allPlayers[i];
    }

}

//-------------------------------------------------------------------------
// Name:        ~Draft (method c)
// Parameters:  none
// Returns:     nothing
// Purpose:     Destructor. There is no memory to deallocate, so nothing
//              is implemented here
//      THIS CODE IS GIVEN TO YOU AND SHOULD NOT NEED TO BE EDITED!
//-------------------------------------------------------------------------
Draft::~Draft()
{
    
}

//-------------------------------------------------------------------------
// Name:        draftPlayer (method k)
// Parameters:  string: teamName, the name of the drafting team (pass-by-value)
//				int: playerIndex, the index of the player who is being drafted (pass-by-value)
// Returns:     nothing
// Purpose:     Private helper function. Sets the Player's (in the array at index
//              PlayerIndex) status to taken, changes their team name to the
//              team to which they were drafted.  Once a Player is drafted,
//              the number of available Players should decrease
//-------------------------------------------------------------------------
/*void Draft::draftPlayer(const string teamName, const int playerIndex)
{
    // Set the Player (at the provided index) as taken and set the team name to the drafting team

    // Print out a message letting the user know that the Player has been drafted

    // decrease the number of available Players
    
}*/

//-------------------------------------------------------------------------
// Name:        getNumPlayers (method f)
// Parameters:  none
// Returns:     int, the number of total players in the class
// Purpose:     accessor (getter) for our private instance variable
//-------------------------------------------------------------------------
int Draft::getNumPlayers() const
{
    return numPlayers;
}

//-------------------------------------------------------------------------
// Name:        getNumAvailable (method g)
// Parameters:  none
// Returns:     int, the number of available players in the class
// Purpose:     accessor (getter) for our private instance variable
//-------------------------------------------------------------------------
int Draft::getNumAvailable() const
{
    return numAvailable;
}

//-------------------------------------------------------------------------
// Name:        readFile (method e)
// Parameters:  string, fileName, the name of the file we're opening (pass-by-value)
// Returns:     nothing
// Purpose:     Get the Player information from a text file of the Players
//              who have entered the draft.
//              There are FIVE pieces of data per line: firstName (string), 
//              lastName (string), position (string), overallRank (integer), 
//              and positionalRank (integer)
//              When you have retrieved one line of the text file, use the
//              Player class setters to set information in the allPlayers[] array 
//-------------------------------------------------------------------------
void Draft::readFile(const string filename)
{
    // open the file
    ifstream infile;
    infile.open(filename);

    // create temporary variables to read information into
       string tempFirstName, tempLastName, tempPosition;
       int tempOverallRank, tempPositionalRank;

    // Read the file (in a loop), reading each line into the temporary variables
        while(infile >> tempFirstName >> tempLastName >> tempPosition >> tempOverallRank >> tempPositionalRank)
        {
            //Set attributes
            allPlayers[numPlayers].setName(tempFirstName, tempLastName);
            allPlayers[numPlayers].setPosition(tempPosition);
            allPlayers[numPlayers].setOverallRank(tempOverallRank);
            allPlayers[numPlayers].setPositionRank(tempPositionalRank);
            allPlayers[numPlayers].setUntaken();

            // increment the number of players on the team
            numPlayers++;
        }

    // Close the file
    infile.close();

}

//-------------------------------------------------------------------------
// Name:        isValidPosition (method i)
// Parameters:  string: position, the position we are validating (pass-by-value)
// Returns:     boolean, if the user input is valid
// Purpose:     Goes through allPlayers[] array and checks if the given
//			    position is valid - checking both that the user input is a valid
//              position name, AND that there exists at least one undrafted player
//              still available in that position
//-------------------------------------------------------------------------
/*bool Draft::isValidPosition(const string position) const
{
	// Go through the all_players array and if there's a position name match of an
	// undrafted player, return true.  Else, return false since either the position 
	// doesn't exist or all available players in that position have already been drafted

}*/

//-------------------------------------------------------------------------
// Name:        isValidName (method l)
// Parameters:  string: lastName, the Player's last name (pass-by-value)
// Returns:     boolean, whether the name passed in matches a name in our array
// Purpose:     Checks whether a given name is valid.
// 		        Returns true if the name is found in the allPlayers array
//		        Returns false if it is not found
//-------------------------------------------------------------------------
/*bool Draft::isValidName(const string lastName) const
{
    // Create a variable to keep track of whether we have a valid name (start at false)

    // loop through the allPlayers[] array

        //If the lastName that is passed in matches the current Player's lastname,
        //set your variable to true

    // return your variable indicating whether there was a match
    
}*/

//-------------------------------------------------------------------------
// Name:        pickByName (method m)
// Parameters:  string: teamName, the team that is drafting (pass-by-value)
// Returns:     nothing
// Purpose:     Chooses Player based on given name
//-------------------------------------------------------------------------
/*void Draft::pickByName(const string teamName)
{
    // Make sure there are still players available to draft.  If not, print a message
    // and don't try to get a player name


        // Create variables to keep track of the user input, and whether the
        // user input is valid (both in terms of a valid name AND an available Player)

    	// (outer) Loop until a valid AND available Player name is given

    	    // Check for valid name
			// Ask the user to input the last name and validate it
			// If it is an invalid name, continue asking for more input


            // Once you have a valid name, find that Player's index in the allPlayers[] array


            // Check for available Player (is he already drafted/taken?)
            // If not drafted/taken, draft that Player (at that found index) to the 
            // given team name and note that you have a valid AND available Player name 
            // and should stop the outer loop after this bit of code


			// else, if the Player IS taken, output a statement that the Player is already taken.
			// At this point, the outer loop should start again, asking for a valid player name
			// and repeating

}*/

//-------------------------------------------------------------------------
// Name:        pickBestOverall (method o)
// Parameters:  string: teamName, the team that is drafting (pass-by-value)
// Returns:     nothing
// Purpose:     Drafts the best Player based on overallRank value to the team
//              whose name is passed in
//          Note: a smaller value is better (i.e. an overallRank of 1 is best)
//-------------------------------------------------------------------------
/*void Draft::pickBestOverall(const string teamName) 
{
    // Create some variables to keep track of the best index and best rank found so far

	// loop over all players to find the lowest overall rank
	// and the index of the player with the lowest overall rank
	// Make sure the Player has not already been drafted/taken



    // Draft the player using the index and the given teamName

}*/

//-------------------------------------------------------------------------
// Name:        pickBestByPosition (method p)
// Parameters:  string: position (pass-by-value)
//				string: teamName, the team that is drafting (pass-by-value)
// Returns:     nothing
// Purpose:     Drafts the best Player in a specified position based on 
//              positionRank value to the team whose name is passed in
//          Note: a smaller value is better (i.e. a positionRank of 1 is best)
//-------------------------------------------------------------------------
/*void Draft::pickBestByPosition(const string position, const string teamName) 
{
    // Create some variables to keep track of the position rank and position index

	// loop over all players to find the lowest position rank
	// and the index of the player with the lowest position rank
	// Make sure the Player has not already been drafted/taken and that they are
	// playing the position we are searching for
	

    // Finally, draft the player using the index and the given teamName

}*/

//-------------------------------------------------------------------------
// Name:        printAllPlayers (method d)
// Parameters:  none
// Returns:     nothing
// Purpose:     Prints all Players in the draft, regardless of whether or 
//              not they've been drafted
//      THIS CODE IS GIVEN TO YOU AND SHOULD NOT NEED TO BE EDITED!
//-------------------------------------------------------------------------
void Draft::printAllPlayers() const
{
    cout << "Here are all the players in the draft: \n";
    // Loop through the allPlayers[] array
	for(int i=0; i<numPlayers; i++)
	{
	    // Print each Player
		allPlayers[i].print();
	}
}

//-------------------------------------------------------------------------
// Name:        printAvailablePlayers (method h)
// Parameters:  none
// Returns:     nothing
// Purpose:     Prints all available Players (if they are not drafted/taken)
//-------------------------------------------------------------------------
void Draft::printAvailablePlayers() const
{
    // Print a message indicating the number of available players to the screen
    cout << "There are: " << getNumAvailable() << " players available.";

    // Loop through the allPlayers[] array
    for(int i = 0; i < numPlayers; i++)
    {
        // If the Player is not taken, print them
        if(!allPlayers[i].isTaken())
        {
            allPlayers[i].print();
        }
    }
}

//-------------------------------------------------------------------------
// Name:        printAvailablePositionPlayers (method j)
// Parameters:  string: position (pass-by-value)
// Returns:     nothing
// Purpose:     Prints all available Players who play a certain Position
//-------------------------------------------------------------------------
/*void Draft::printAvailablePositionPlayers(const string position) const
{
    // Loop through the allPlayers[] array

    	// If not taken, print the Players who match the position passed in
    	
    	
}*/

//-------------------------------------------------------------------------
// Name:        printTeamPlayers (method n)
// Parameters:  string: teamName, name of the team of whom to print the roster (pass-by-value)
// Returns:     nothing
// Purpose:     Prints the roster of Players in a given teamName.
//-------------------------------------------------------------------------
/*void Draft::printTeamPlayers(const string teamName) const
{
    // Loop through the allPlayers[] array

        // Print all Players who match the given teamName


}*/
