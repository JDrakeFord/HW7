// Implementation of the Player header file for homework 7
// THIS FILE SHOULD NOT NEED EDITING!

#include "Player.h"

// Constructors
Player::Player()
{
	firstName = "";
	lastName = "";
	position = "";
	overallRank = -1;
	positionRank = -1;
	taken = false;
    teamName = "Undrafted";
}

Player::Player(const Player &copyMe)
{
	firstName = copyMe.firstName;
	lastName = copyMe.lastName;
	position = copyMe.position;
	overallRank = copyMe.overallRank;
	positionRank = copyMe.positionRank;
	taken = copyMe.taken;
	teamName = copyMe.teamName;
}

//Destructor
Player::~Player()
{
}

// Mutators (setters)
void Player::setName(const string fName, const string lName)
{
	firstName = fName;
	lastName = lName;
}

void Player::setPosition(const string pos)
{
	position = pos;
}

void Player::setOverallRank(const int oRank)
{
	overallRank = oRank;
}

void Player::setPositionRank(const int pRank)
{
	positionRank = pRank;
}

void Player::setUntaken()
{
	taken = false;
}

void Player::setTaken()
{
	taken = true;
}

void Player::setTeamName(const string tName)
{
	teamName = tName;
}

// Accessors (getters)
string Player::getFirstName() const
{
	return firstName;
}

string Player::getLastName() const
{
	return lastName;
}

string Player::getPosition() const
{
	return position;
}

int Player::getOverallRank() const
{
	return overallRank;
}

int Player::getPositionRank() const
{
	return positionRank;
}

bool Player::isTaken() const
{
	return taken;
}

string Player::getTeamName() const
{
	return teamName;
}

// Print method
void Player::print() const
{
	cout << "  Name: " << firstName << " " << lastName << endl
	     << "     Position: " << position << endl
		 << "     Overall Rank: " << overallRank << endl
		 << "     Position Rank: " << positionRank << endl;
}
