#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <memory>
#include "Room.h"

using namespace std;

/*
Author: Brenda Romero and Ashley G.
Course: CPSC-25-12703

Class: Node

Description:
Each node stores one room and points to the next room.
This is used to build our linked list of castle rooms.
*/

class Node
{
public:
    Room room;
    shared_ptr<Node> next;

    Node(Room room);
};

/*
Author: Brenda Romero and Ashley G.

Class: LinkedList

Description:
This class stores the rooms in order.
It lets the player move from one room to the next.
*/

class LinkedList
{
private:
    shared_ptr<Node> head;

public:
    LinkedList();

    void addRoom(const Room& room);
    shared_ptr<Node> getHead() const;
};

#endif