/*-------------------------------------------
// Course: COMP 150
// Last Name: Singh
// First Name: Rajveer
// Student ID: 300202522
// 
// File: survey53_SinghRS
//
// Summary: Outputs a poll between Batman, Spider-Man, and Wolverine in which the user is then prompted 
//			to enter the number of participants and their vote, using a loop. 
//			
//			A summmary is then output which includes the following for any differnt winning scenarios: 
//			the number of votes for each superhero in an order from least to greatest, the winners, and any ties.             	           
//
*-------------------------------------------*/


#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	// Storing information about number of people and tracking superhero votes	
	int num_people, user_preference, batman_votes{0}, spiderman_votes{0}, wolverine_votes{0};
	
	// Outputting welcome message and getting # of participants
	cout << "------------------------------------------------------------------------------------" << endl;
	cout << "Welcome to the SUPERHERO preference survey." << endl;
	cout <<	"This survey polls a preferred superhero between Batman, Spider-Man, and Wolverine." << endl;
	cout << "------------------------------------------------------------------------------------" << endl;
	cout << "\nEnter the total number of participants: ";
	cin >> num_people;


	// Getting every participants vote using a loop
	for (int person{1}; person<=num_people; person++)
	{
		cout << "Participant #" << person << ": Choose your favorite superhero out of the following (type 1-3)" << endl;
		cout << "1) Batman\n"
				"2) Spider-Man\n"
				"3) Wolverine" << endl;
		cin >> user_preference;	
		
		// Handling error if incorrect option entered 
		while (!(user_preference > 0 && user_preference < 4))
		{
			cout << "Invalid value. Type (1), (2), or (3): ";
			cin >> user_preference;
		}
		
		// Adding vote point to the option the participant chose
		switch(user_preference)
		{
			case 1:
				batman_votes++;
				break;
			case 2:
				spiderman_votes++;
				break;
			case 3:
				wolverine_votes++;
				break;
		}
	} // End of loop
	
	
	// Outputting the poll summary and order of the votes/winner/ties depending on all possibe scenarios  
	cout << "\nGenerating results...." << endl;
	cout << "\n------------------------------Survey Results/Summary------------------------------" << endl;
	cout << "Total Participants: " << num_people << endl;
	cout << "\nSuperhero Popularity Order: " << endl;
	
	// OUTPUT FOR: Same number of votes for all superheroes
	if ((batman_votes == spiderman_votes) && (batman_votes == wolverine_votes))
	{
		cout << "1. Batman - " << batman_votes << " votes\n"
		 	 << "2. Spider-Man - " << spiderman_votes << " votes\n"
		 	 << "3. Wolverine - " << wolverine_votes << " votes" << endl;
		cout << "\nThere is no decisive winner, all superheroes have the same number of votes!" << endl;
		cout << "Tie between all superheroes" << endl;
	}
	
	// OUTPUT FOR: Batman has the most votes 
	else if ((batman_votes > spiderman_votes) && (batman_votes > wolverine_votes))
	{
		cout << "1. Batman - " << batman_votes << " votes" << endl;
		// Output for: Spider-Man has more votes than Wolverine
		if (spiderman_votes > wolverine_votes)
		{
			cout << "2. Spider-Man - " << spiderman_votes << " votes" << endl;
			cout << "3. Wolverine - " << wolverine_votes << " votes\n" << endl;
		}
		// Output for: Tie between Spider-Man and Wolverine
		else if (spiderman_votes == wolverine_votes)
		{
			cout << "2. Spider-Man - " << spiderman_votes << " votes" << endl;
			cout << "3. Wolverine - " << wolverine_votes << " votes" << endl;
			cout << "\nTie between Spider-Man and Wolverine!" << endl;
		}
		// Output for: Wolverine has more votes than Spider-Man
		else
		{
			cout << "2. Wolverine - " << wolverine_votes << " votes" << endl;
			cout << "3. Spider-Man - " << spiderman_votes << " votes\n" << endl;
		}
		cout << "Batman has the most votes and is the winner!" << endl;
	}
	
	// OUTPUT FOR: Spider-Man has the most votes
	else if ((spiderman_votes > batman_votes) && (spiderman_votes > wolverine_votes))
	{
		cout << "1. Spider-Man - " << spiderman_votes << " votes" << endl;
		// Output for: Batman has more votes than Wolverine
		if (batman_votes > wolverine_votes)
		{
			cout << "2. Batman - " << batman_votes << " votes" << endl;
			cout << "3. Wolverine - " << wolverine_votes << " votes\n" << endl;
		}
		// Output for: Tie between Batman and Wolverine
		else if (batman_votes == wolverine_votes)
		{
			cout << "2. Batman - " << batman_votes << " votes" << endl;
			cout << "3. Wolverine - " << wolverine_votes << " votes" << endl;
			cout << "\nTie between Batman and Wolverine!" << endl;
		}
		// Output for: Wolverine has more points than Batman
		else
		{
			cout << "2. Wolverine - " << wolverine_votes << " votes" << endl;
			cout << "3. Batman - " << batman_votes << " votes\n" << endl;
		}
		cout << "Spider-Man has the most votes and is the winner!" << endl;
	}
	
	// OUTPUT FOR: Wolverine has the most votes
	else if ((wolverine_votes > batman_votes) && (wolverine_votes > spiderman_votes))
	{
		cout << "1. Wolverine - " << wolverine_votes << " votes" << endl;
		// Output for: Batman has more votes than Spider-Man
		if (batman_votes > spiderman_votes)
		{
			cout << "2. Batman - " << batman_votes << " votes" << endl;
			cout << "3. Spider-Man - " << spiderman_votes << " votes\n" << endl;
		}
		// Output for: Tie between Batman and Spider-Man
		else if (batman_votes == spiderman_votes)
		{
			cout << "2. Batman - " << batman_votes << " votes" << endl;
			cout << "3. Spider-Man - " << spiderman_votes << " votes" << endl;
			cout << "\nTie between Batman and Spider-Man!" << endl;
		}
		// Output for: Spider-Man has more votes than Batman
		else
		{
			cout << "2. Wolverine - " << wolverine_votes << " votes" << endl;
			cout << "3. Spider-Man - " << spiderman_votes << " votes\n" << endl;
		}
		cout << "Wolverine has the most votes and is the winner!" << endl;
	}
	
	// OUTPUT FOR: Tie between Batman and Spider-Man for most votes 
	else if ((batman_votes == spiderman_votes))
	{
		cout << "1. Batman - " << batman_votes << " votes" << endl;
		cout << "2. Spider-Man - " << spiderman_votes << " votes" << endl;
		cout << "3. Wolverine - " << wolverine_votes << " votes" << endl;
		cout << "\nFirst place is tied. Tie between Batman and Spider-Man!" << endl;
		cout << "Wolverine is third with the least amount of votes." << endl;	
	}
	
	// OUTPUT FOR: Tie between Batman and Wolverine for most votes 
	else if ((batman_votes == wolverine_votes))
	{
		cout << "1. Batman - " << batman_votes << " votes" << endl;
		cout << "2. Wolverine - " << wolverine_votes << " votes" << endl;
		cout << "3. Spider-Man - " << spiderman_votes << " votes" << endl;
		cout << "\nFirst place is tied. Tie between Batman and Wolverine!" << endl;
		cout << "Spider-Man is third with the least amount of votes." << endl;	
	}
	
	// OUTPUT FOR: Tie between Spider-Man and Wolverine for most votes 
	else if ((spiderman_votes == wolverine_votes))
	{
		cout << "1. Spider-Man - " << spiderman_votes << " votes" << endl;
		cout << "2. Wolverine - " << wolverine_votes << " votes" << endl;
		cout << "3. Batman - " << batman_votes << " votes" << endl;
		cout << "\nFirst place is tied. Tie between Spider-Man and Wolverine!" << endl;
		cout << "Batman is third with the least amount of votes." << endl;
	}
	
	cout << "----------------------------------------------------------------------------------" << endl;
			
	return 0;
}

