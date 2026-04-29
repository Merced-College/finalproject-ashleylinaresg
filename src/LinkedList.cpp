/*
Author: Brenda Romero and Ashley G.
Course: CPSC-25-12703

File: LinkedList.cpp

Description:
This file defines the linked list functions.
The linked list stores all castle rooms in order.
*/

#include "LinkedList.h"

// Creates a node with one room inside it
Node::Node(Room room)
{
    this->room = room;
    next = nullptr;
}

// Starts an empty linked list
LinkedList::LinkedList()
{
    head = nullptr;
}

// Adds a room to the end of the linked list
void LinkedList::addRoom(const Room& room)
{
    shared_ptr<Node> newNode = make_shared<Node>(room);

    // If the list is empty, this becomes the first room
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    shared_ptr<Node> current = head;

    // Move through the list until the last room
    while (current->next != nullptr)
    {
        current = current->next;
    }

    // Connect the new room at the end
    current->next = newNode;
}

// Returns the first room in the list
shared_ptr<Node> LinkedList::getHead() const
{
    return head;
}