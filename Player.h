// Player.h
// Header file for the Player class for homework 7
// THIS FILE SHOULD NOT NEED EDITING!

#include <iostream>

using namespace std;

class Player
{
    private:
		string firstName;
		string lastName;
		string position; // Quarterback, WideReceiver, etc.
		int overallRank; // rank within all players
		int positionRank; // rank within a certain position 
		bool taken; // if player has been chosen yet or not
        string teamName;  // the name of the team that drafts the player
    
    public:
		// Constructors and Destructor
		Player();
		Player(const Player &copyMe);
		~Player();

		// Mutators
		void setName(const string fName, const string lName);
		void setPosition(const string pos);
		void setOverallRank(const int oRank);
		void setPositionRank(const int pRank);
		void setTaken();
		void setUntaken();
		void setTeamName(const string tName);

		// Accessors
		string getFirstName() const;
		string getLastName() const;
		string getPosition() const;
		int getOverallRank() const;
		int getPositionRank() const;
		bool isTaken() const;
		string getTeamName() const;

		// Print methods
		void print() const;
};
