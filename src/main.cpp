/*
Author: Brenda Romero and Ashley G.
Course: CPSC-25-12703

File: main.cpp

Description:
This is the main file for our Castle Adventure RPG game.
It runs the game, shows the menu, lets the player move through rooms,
pick up items, fight enemies, save the game, and load the game.

AI Assistance:
We used ChatGPT as a support tool during development to help clean up code,
improve formatting, explain compile errors, and help debug parts of the
program. All code was reviewed, tested, and understood by our team before use.
*/

#include <iostream>
#include <limits>
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "Room.h"
#include "LinkedList.h"
#include "GameMap.h"
#include "InventoryManager.h"
#include "SaveManager.h"

using namespace std;

// Shows the intro message when the game starts
void introduction()
{
    cout << "=====================================\n";
    cout << "        CASTLE ADVENTURE RPG\n";
    cout << "=====================================\n";
    cout << "Explore rooms, collect items, battle enemies,\n";
    cout << "and try to survive the castle.\n\n";
}

// Makes sure the user enters a valid number from the menu
int getValidatedChoice(int min, int max)
{
    int choice;
    cin >> choice;

    while (cin.fail() || choice < min || choice > max)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid choice. Enter a number from " << min << " to " << max << ": ";
        cin >> choice;
    }

    return choice;
}

// Shows the player's current stats
void showPlayerStatus(const Player& player)
{
    cout << "\n===== PLAYER STATUS =====\n";
    cout << "Name: " << player.getName() << endl;
    cout << "Health: " << player.getHealth() << endl;
    cout << "Score: " << player.getScore() << endl;
    cout << "=========================\n";
}

// Creates a different enemy depending on which room the player is in
Enemy createEnemyForRoom(const string& roomName)
{
    if (roomName == "Throne Room")
        return Enemy("Royal Guard", 40, 10);
    else if (roomName == "Hall of Knights")
        return Enemy("Armored Knight", 35, 8);
    else if (roomName == "Royal Library")
        return Enemy("Ghost Scholar", 30, 7);
    else if (roomName == "Dungeon")
        return Enemy("Dungeon Keeper", 50, 12);

    // Backup enemy in case the room name does not match
    return Enemy("Castle Shadow", 25, 5);
}

// Lets the player collect the item inside the current room
void collectRoomItem(const Room& room, Player& player, InventoryManager& inventory)
{
    string item = room.getItem();

    // If the room does not have an item, nothing is added
    if (item == "Nothing" || item.empty())
    {
        cout << "There is no item to pick up in this room.\n";
        return;
    }

    // This prevents the player from collecting the same item twice
    if (inventory.hasItem(item))
    {
        cout << "You already collected the " << item << ".\n";
        return;
    }

    char choice;
    cout << "You found a " << item << ". Pick it up? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
    {
        inventory.addItem(item);
        player.addScore(10);
        cout << item << " was added to your inventory.\n";
        cout << "You earned 10 points.\n";
    }
    else
    {
        cout << "You left the item behind.\n";
    }
}

// Handles the fight between the player and one enemy
void battleEnemy(Player& player, Enemy& enemy)
{
    if (enemy.isDefeated())
    {
        cout << "This enemy has already been defeated.\n";
        return;
    }

    cout << "\nAn enemy appears: " << enemy.getName() << "!\n";

    // Battle keeps going until the enemy is defeated, the player dies, or the player runs
    while (player.getHealth() > 0 && !enemy.isDefeated())
    {
        cout << "\n===== BATTLE =====\n";
        cout << player.getName() << " Health: " << player.getHealth() << endl;
        cout << enemy.getName() << " Health: " << enemy.getHealth() << endl;
        cout << "1. Attack\n";
        cout << "2. Run\n";
        cout << "Choice: ";

        int choice = getValidatedChoice(1, 2);

        if (choice == 1)
        {
            // Player attacks first
            cout << "You attack the " << enemy.getName() << "!\n";
            enemy.takeDamage(20);

            // If the enemy reaches 0 health, the player wins the fight
            if (enemy.isDefeated())
            {
                cout << "You defeated the " << enemy.getName() << "!\n";
                player.addScore(25);
                cout << "You earned 25 points.\n";
                return;
            }

            // Enemy attacks back if still alive
            cout << enemy.getName() << " attacks back!\n";
            player.takeDamage(enemy.attack());
        }
        else
        {
            cout << "You ran away from the battle.\n";
            return;
        }
    }
}

// Starts a new game by asking for the player's name
void startNewGame(Player& player)
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string name;
    cout << "Enter your player name: ";
    getline(cin, name);

    if (name.empty())
    {
        name = "Player";
    }

    player.setName(name);
    player.setHealth(100);
    player.setScore(0);
}

// Makes the room actions from rooms.csv actually do something
void playRoomAction(const string& action, const Room& room, Player& player)
{
    cout << "\nYou chose: " << action << endl;

    if (action.find("Sit") != string::npos)
    {
        cout << "You sit on the throne and feel like castle royalty.\n";
        player.addScore(5);
        cout << "You earned 5 points.\n";
    }
    else if (action.find("Observe") != string::npos || action.find("Look") != string::npos)
    {
        cout << "You carefully look around the " << room.getName() << ".\n";
        cout << "You notice more details about the room.\n";
        player.addScore(3);
        cout << "You earned 3 points.\n";
    }
    else if (action.find("Inspect") != string::npos)
    {
        cout << "You inspect the area closely and find signs of past battles.\n";
        player.addScore(3);
        cout << "You earned 3 points.\n";
    }
    else if (action.find("Take a photo") != string::npos)
    {
        cout << "You take a photo to remember this part of the castle.\n";
        player.addScore(2);
        cout << "You earned 2 points.\n";
    }
    else if (action.find("Read") != string::npos)
    {
        cout << "You read an old book filled with castle secrets.\n";
        player.addScore(5);
        cout << "You earned 5 points.\n";
    }
    else if (action.find("Browse") != string::npos || action.find("Search") != string::npos)
    {
        cout << "You search the area and find something interesting.\n";
        player.addScore(4);
        cout << "You earned 4 points.\n";
    }
    else if (action.find("Scream") != string::npos)
    {
        cout << "You scream for help, but only echoes answer back.\n";
        player.takeDamage(3);
        cout << "The stress costs you 3 health.\n";
    }
    else
    {
        cout << "You complete the action, but nothing special happens.\n";
    }
}

// Shows both the room actions and the extra game options
void showRoomMenu(const Room& room)
{
    vector<string> actions = room.getActions();

    cout << "\nWhat would you like to do?\n";

    int optionNumber = 1;

    // These are the actions loaded from the CSV file
    for (int i = 0; i < actions.size(); i++)
    {
        cout << optionNumber << ". " << actions[i] << endl;
        optionNumber++;
    }

    // These are extra actions added for the game features
    cout << optionNumber++ << ". View player status\n";
    cout << optionNumber++ << ". Pick up room item\n";
    cout << optionNumber++ << ". View inventory\n";
    cout << optionNumber++ << ". Sort inventory\n";
    cout << optionNumber++ << ". Fight enemy\n";
    cout << optionNumber++ << ". Move to next room\n";
    cout << optionNumber++ << ". Save game\n";
    cout << optionNumber++ << ". Quit game\n";
    cout << "Choice: ";
}

int main()
{
    LinkedList castleRooms;
    GameMap gameMap;
    InventoryManager inventory;
    SaveManager saveManager;
    Player player;

    // Load the castle rooms from the CSV file
    if (!gameMap.loadRooms("rooms.csv", castleRooms))
    {
        cout << "Error: Could not load rooms.csv.\n";
        return 1;
    }

    introduction();

    cout << "1. Start new game\n";
    cout << "2. Load saved game\n";
    cout << "Choice: ";

    int startChoice = getValidatedChoice(1, 2);

    if (startChoice == 1)
    {
        startNewGame(player);
    }
    else
    {
        // If there is no save file, the game starts new instead
        if (saveManager.loadGame(player, inventory))
        {
            cout << "Saved game loaded successfully.\n";
        }
        else
        {
            cout << "No save file found. Starting a new game.\n";
            startNewGame(player);
        }
    }

    // Start at the first room in the linked list
    auto currentRoomNode = castleRooms.getHead();

    // Game keeps going while there are rooms left and the player is alive
    while (currentRoomNode != nullptr && player.getHealth() > 0)
    {
        Room currentRoom = currentRoomNode->room;
        Enemy roomEnemy = createEnemyForRoom(currentRoom.getName());

        bool roomFinished = false;

        cout << "\n=====================================\n";
        cout << currentRoom.toString();
        cout << "=====================================\n";

        while (!roomFinished && player.getHealth() > 0)
        {
            showRoomMenu(currentRoom);

            int actionCount = currentRoom.getActions().size();
            int totalOptions = actionCount + 8;

            int choice = getValidatedChoice(1, totalOptions);

            // If the player chooses one of the room actions
            if (choice >= 1 && choice <= actionCount)
            {
                string selectedAction = currentRoom.getActions()[choice - 1];

                // Leave action moves the player to the next room
                if (selectedAction.find("Leave") != string::npos)
                {
                    cout << "You leave the room and move forward.\n";
                    currentRoomNode = currentRoomNode->next;
                    roomFinished = true;
                }
                else
                {
                    playRoomAction(selectedAction, currentRoom, player);
                }
            }
            else
            {
                // Extra choices start after the room action choices
                int extraChoice = choice - actionCount;

                if (extraChoice == 1)
                {
                    showPlayerStatus(player);
                }
                else if (extraChoice == 2)
                {
                    collectRoomItem(currentRoom, player, inventory);
                }
                else if (extraChoice == 3)
                {
                    inventory.showInventory();
                }
                else if (extraChoice == 4)
                {
                    inventory.sortInventory();
                    cout << "Inventory sorted alphabetically.\n";
                    inventory.showInventory();
                }
                else if (extraChoice == 5)
                {
                    battleEnemy(player, roomEnemy);
                }
                else if (extraChoice == 6)
                {
                    cout << "You leave the room and move forward.\n";
                    currentRoomNode = currentRoomNode->next;
                    roomFinished = true;
                }
                else if (extraChoice == 7)
                {
                    saveManager.saveGame(player, inventory);
                    cout << "Game saved successfully.\n";
                }
                else if (extraChoice == 8)
                {
                    cout << "Thanks for playing.\n";
                    return 0;
                }
            }
        }
    }

    cout << "\n=====================================\n";

    if (player.getHealth() > 0)
    {
        cout << "You survived the castle adventure!\n";
    }
    else
    {
        cout << "Game over. You did not survive the castle.\n";
    }

    cout << "Final score: " << player.getScore() << endl;
    inventory.showInventory();

    return 0;
}