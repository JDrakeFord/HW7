
#include "Draft.h"

//-------------------------------------------------------------------------
// Name:        printMenu
// Parameters:  string: teamName (pass-by-value)
// Returns:     nothing
// Purpose:     Displays the menu
//-------------------------------------------------------------------------
void printMenu(const string teamName)
{
    cout << "\n-----Team: " << teamName << " -----\n";
    cout << "Please Choose From the Following Options\n";
    cout << "  1. Print all available players\n"
         << "  2. Print available players based on position\n"
         << "  3. Pick by player name\n"
         << "  4. Pick best overall ranked player\n"
         << "  5. Pick best ranked player based on position\n"
         << "  6. Skip draft pick" << endl
         << "Enter your choice >> ";
}

//-------------------------------------------------------------------------
// Name:        getChoice
// Parameters:  string: teamName (pass-by-value)
// Returns:     int: the validated choice of the user
// Purpose:     Gets the user's choice and validates it
//-------------------------------------------------------------------------
int getChoice(const string teamName)
{
    int choice;
    printMenu(teamName);
    cin >> choice;
    while (choice < 1 || choice > 6)
    {
        cout << "Sorry that is not a valid choice.\n";
        printMenu(teamName);
        cin >> choice;
    }
    return choice;
}

//-------------------------------------------------------------------------
// Name:        getPosition
// Parameters:  Draft: myDraft (pass-by-value)
// Returns:     string, the validated position
// Purpose:     Gets the name of the position from the user input, and 
//              validates it
//-------------------------------------------------------------------------
string getPosition(const Draft myDraft)
{
    string position;
    cout << "Enter the position are you interested in >> ";
    cin >> position;
    while (!myDraft.isValidPosition(position))
    {
        cout << "Sorry, there are no available players for that position.\n";
        cout << "Acceptable positions (although not guaranteed to be available) are: QB, WR, OL, TE, LB, CB, DL, S\n";
        cout << "Enter the position are you interested in: ";
        cin >> position;
    }
    return position;
}

//-------------------------------------------------------------------------
// Name:        doAction
// Parameters:  Draft: myDraft (pass-by-reference)
//				string: TeamName (pass-by-value)
// Returns:     nothing
// Purpose:     Gets the choice of the user and acts on that choice value.
//-------------------------------------------------------------------------
void doAction(Draft &myDraft, const string teamName)
{
	int choice;
	bool picked = false;
    string position;

    // Keep looping until the user has picked a player or skipped (choices 3,4,5,6)
	while(!picked) 
	{
		choice = getChoice(teamName);
		switch(choice)
		{
			case 1:
				// print all available players
				myDraft.printAvailablePlayers();
				break;
			case 2:
				// print available players based on a certain position
                position = getPosition(myDraft);
				myDraft.printAvailablePositionPlayers(position);
				break;
			case 3:
				// pick by player name
				myDraft.pickByName(teamName);
				picked = true;
				break;
			case 4:
				// pick best overall ranked player
				myDraft.pickBestOverall(teamName);
				picked = true;
				break;
			case 5:
				// pick best ranked player based on a certain position
                position = getPosition(myDraft);
    			myDraft.pickBestByPosition(position, teamName);
				picked = true;
				break;
			case 6:
				// skip draft pick
				picked = true;
				break;
			default:
				break;
		}
	}
}

//-------------------------------------------------------------------------
// MAIN function
//-------------------------------------------------------------------------
int main()
{
	Draft NFLDraft; // Create a Draft object
	const int NUM_ROUNDS = 3; // There will be 3 rounds in this draft pick
	const int NUM_TEAMS = 4; // 4 teams (including the user's) in the NFL Draft

    // Name the teams in the draft; feel free to change!
    // You, the user, are drafting as the first team, TeamNames[0]
    string teamNames[NUM_TEAMS] = {"Chiefs", "Cowboys", "Patriots", "Panthers"};

	NFLDraft.readFile("PlayerInfo.txt"); // Read in from the PlayerInfo text file

	cout << "This NFL Draft is written by Drake Ford and Jonah!\n";
	cout << "\n\nWelcome to the 2021 NFL Draft!\n";
	cout << "There are " << NFLDraft.getNumPlayers() << " players available.  ";
    //print out all the players that were read in from the file
	NFLDraft.printAllPlayers();

	// DRAFT SIMULATION, 3 rounds -------------------------------------------
	for(int currentRound=0; currentRound < NUM_ROUNDS; currentRound++)
	{
		cout << "\n=============== ROUND " << (currentRound+1) << " ===============\n";
		doAction(NFLDraft, teamNames[0]); // Do the action for the users team 

        /*
        // This will be the last bit of code that you should uncomment!  You will
        // need to implement pickBestOverall(...) before uncommenting this loop
		for(int otherTeam = 1; otherTeam < NUM_TEAMS; otherTeam++)
		{
            // After you pick a Player, let the other teams pick the best overall available Player
			NFLDraft.pickBestOverall(teamNames[otherTeam]); 
		}
		*/
	}

	// PRINT RESULTS --------------------------------------------------------------------
	cout << "\n\nDRAFT PICKING FOR 2021 IS OVER. HERE ARE THE PLAYERS ADDED TO YOUR TEAM: \n";
	NFLDraft.printTeamPlayers(teamNames[0]);

    //Show how many players are remaining after all of the draft picks
    cout << "\n\nAfter all teams have made their choices, there are " << NFLDraft.getNumAvailable() << " players remaining.\n";
	
    // Print a parting message if desired

	cout << endl << endl;
	return 0;
}
