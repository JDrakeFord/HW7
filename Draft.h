// Draft.h
// Header file for the Draft class for homework 7
// The methods are labeled as 'method x' as denoted in the assignment instructions

#include <fstream>
#include "Player.h"

class Draft
{
    private:
        /* constants and instance variables (class attributes) */
        static const int MAX_PLAYERS = 100;
		int numPlayers;
		int numAvailable;
		Player allPlayers[MAX_PLAYERS];
		
        /* helper function */
        void draftPlayer(const string teamName, const int playerIndex); //method k
		
    public:
		Draft(); //method a, given
		Draft(const Draft &copyMe); //method b
		~Draft(); //method c, given

		/* Accessors (getters) */
        int getNumPlayers() const; //method f
        int getNumAvailable() const; //method g

		/* Useful Methods */
        void readFile(const string filename); //method e
        bool isValidPosition(const string position) const; //method i
        bool isValidName(const string name) const; //method l
        void pickByName(const string teamName); //method m
        void pickBestOverall(const string teamName); //method o
        void pickBestByPosition(const string position, const string teamName); //method p
        
		/* Print methods */
		void printAllPlayers() const; //method d, given
        void printAvailablePlayers() const; //method h
        void printAvailablePositionPlayers(const string position) const; //method j
        void printTeamPlayers(const string teamName) const; //method n
};
