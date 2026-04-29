# Castle Adventure RPG

## Course
CPSC-25-12703

## Students
- Brenda Romero
- Ashley Linares Garcia.

## Project Overview
Castle Adventure RPG is a text-based C++ game where the player explores different rooms inside a castle. The player can choose room actions, collect items, fight enemies, earn points, and save or load progress.

The goal of the game is to survive the castle while collecting items and earning the highest score possible.

## Features
- Castle room exploration
- Playable room actions
- Player health system
- Enemy battle system
- Inventory system
- Inventory sorting
- Score system
- Save and load system using `save.txt`
- Input validation
- Room navigation using a linked list

## Classes Used
1. `Player`
2. `Enemy`
3. `Room`
4. `Node`
5. `LinkedList`
6. `GameMap`
7. `InventoryManager`
8. `SaveManager`

## Team Contributions

### Brenda Romero
Brenda worked on the `Player` class and `InventoryManager` class. These classes help manage the player's health, score, and inventory items.

Brenda also helped with:
- inventory features
- item collection
- scoring
- README documentation

### Ashley G.
Ashley worked on the `Enemy` class and `GameMap` class. These classes help manage enemy battles and loading rooms from the CSV file.

Ashley also helped with:
- combat features
- room loading
- room navigation
- testing gameplay

### Shared Work
Both team members helped with:
- UML planning
- main game loop
- debugging
- save/load testing
- final code cleanup

## Reflection

One problem we had to solve was making the room actions actually playable instead of only displaying them. We fixed this by reading the actions from each room and adding them to the player's menu options.

Another issue we ran into was opening the GitHub Classroom repository for the final project. At first, we had trouble getting access to the repo correctly, so some of the project work was started in our own local files first. Once the repository was working, we moved our completed files into the correct project repo and continued development there.

One design improvement we discovered was separating the inventory system and save/load system into their own classes. This made the code cleaner, easier to organize, and easier to manage as the project got bigger.

In version 2, we would definitely like to add visuals and graphics to make the game feel more interactive and exciting. We would also like to add weapons, armor, pets, upgrades, and more rooms to expand the gameplay.

## Data Structures Used

### 1. Vector
Used in:
- `Room`
- `InventoryManager`

What it stores:
- room actions
- inventory items

Why we used it:
A vector works well because the amount of actions and inventory items can change.

### 2. Linked List
Used in:
- `LinkedList`
- `Node`

What it stores:
- the castle rooms in order

Why we used it:
A linked list works well because the player moves from one room to the next.

### 3. String
Used in:
- almost every class

What it stores:
- player name
- enemy name
- room name
- room descriptions
- item names

Why we used it:
Strings are needed because this is a text-based game with a lot of written information.

## Algorithms Used

### 1. Linear Search
Used in:
- `InventoryManager::hasItem()`

What it does:
Checks each item in the inventory to see if the player already has that item.

Big-O:
`O(n)`

### 2. Selection Sort
Used in:
- `InventoryManager::sortInventory()`

What it does:
Sorts the inventory items alphabetically.

Big-O:
`O(n^2)`

### 3. Linked List Traversal
Used in:
- `LinkedList::addRoom()`
- main room movement

What it does:
Moves through each room node until the correct room or end of the list is reached.

Big-O:
`O(n)`

### 4. File Parsing
Used in:
- `GameMap::loadRooms()`
- `SaveManager::loadGame()`

What it does:
Reads data from a file and turns it into usable game information.

Big-O:
`O(n)`

### 5. Battle Logic
Used in:
- `battleEnemy()`

What it does:
Checks player and enemy health, lets the player attack, and lets the enemy attack back.

Big-O:
`O(n)` depending on how many battle turns happen.

## How to Compile

```bash
make