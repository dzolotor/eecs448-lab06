/**
*	@file Test.h
*	@author Daniel Zolotor
*	@date 11-08-18
*	@brief A header file for Test class
*/

#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <vector>
#include "LinkedListOfInts.h"


class Test
{
public:
  	/** @pre all unit tests called are well defined.
  	*   @post Unit tests are run.
  	*/
  	void unitTest();

private:

    /*GIVEN FOR ALL THAT toVector() FUNCTIONS CORRECTLY*/

    //NOTE: compiler enforces "@pre the value is a valid T" exept in the case of a double (is truncated)

    /** @pre addBack can at least successfully add an element to the list.
  	*   @post linked lists will be created and emptiness will be checked.
    *   @return bool isEmpty() is validated successfully
  	*/
    bool validateIsEmpty();

    /** @pre addBack can at least successfully add an element to the list.
    *   @post linked lists will be created and size will be checked.
    *   @return bool size() is validated successfully
    */
    bool validateSize();

    /** @pre addBack can at least successfully add an element to the list.
    *   @post linked lists will be created and search() functionality will be checked.
    *   @return bool search() is validated successfully
    */
    bool validateSearch();

    /** @pre none
    *   @post linked lists will be created and addBack() functionality will be checked.
    *   @return bool addBack() is validated successfully
    */
    bool validateAddBack();

    /** @pre none
    *   @post linked lists will be created and addFront() functionality will be checked.
    *   @return bool addFront() is validated successfully
    */
    bool validateAddFront();

    /** @pre addFront() functions correctly
    *   @post linked lists will be created and then removeBack() functionality will be checked.
    *   @return bool removeBack() is validated successfully
    */
    bool validateRemoveBack();

    /** @pre addFront() functions correctly
    *   @post linked lists will be created and then removeFront() functionality will be checked.
    *   @return bool removeFront() is validated successfully
    */
    bool validateRemoveFront();

};

#endif
