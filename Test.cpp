/**
*	@file Test.cpp
*	@author Daniel Zolotor
*	@date 11-08-18
*	@brief An implementation file for Test class
*/

#include "Test.h"

void Test::unitTest()
{
    std::cout << "running unit tests...\n\n\n";

    validateIsEmpty();
    validateSize();
    validateSearch();
    validateAddBack();
    validateAddFront();
    validateRemoveBack();
    validateRemoveFront();

    std::cout << "\n\n";
}

bool Test::validateIsEmpty()
{
    //const => verify only return

    bool valid = false;

    LinkedListOfInts list;
    auto v0 = list.toVector();
    valid = v0.empty() == list.isEmpty();

    std::cout << "empty list is empty: ";
    if( valid ){ std::cout << "PASSED\n"; }else{ std::cout << "FAILED\n"; }


    //edge case
    list.addBack(1);
    auto v1 = list.toVector();
    if( v1.empty() != list.isEmpty() )
    {
        valid = false;
    }

    //past edge case
    list.addBack(2.8); //double trucated as expected

    auto v2 = list.toVector();
    for(auto i : v2)
    {
        std::cout << i << ", ";
    }
    std::cout << "\n";
    if( v1.empty() != list.isEmpty() )
    {
        valid = false;
    }

    std::cout << "non-empty list is not empty: ";
    if( valid ){ std::cout << "PASSED\n"; }else{ std::cout << "FAILED\n"; }


    return(valid);
}


bool Test::validateSize()
{
    //const => verify only return

    bool valid = false;

    LinkedListOfInts list;
    auto v0 = list.toVector();
    valid = v0.size() == 0;

    std::cout << "size of empty list is zero: ";
    if( valid ){ std::cout << "PASSED\n"; }else{ std::cout << "FAILED\n"; }

    //edge case
    list.addBack(1);
    auto v1 = list.toVector();
    if( v1.size() != 1 )
    {
        valid = false;
    }

    std::cout << "list of size 1 has correct size: ";
    if( valid ){ std::cout << "PASSED\n"; }else{ std::cout << "FAILED\n"; }

    //past edge case
    list.addBack(2);
    auto v2 = list.toVector();
    if( v2.size() != 2 )
    {
        valid = false;
    }
    std::cout << "list of size 2 has correct size: ";
    if( valid ){ std::cout << "PASSED\n"; }else{ std::cout << "FAILED\n"; }

    //approach infinity
    for(int i = 3; i <= 10000; i++)
    {
        list.addBack(i);
    }
    auto v3 = list.toVector();
    if( v3.size() != 10000 )
    {
        valid = false;
    }
    std::cout << "list of size 10000 has correct size: ";
    if( valid ){ std::cout << "PASSED\n"; }else{ std::cout << "FAILED\n"; }

    return(valid);
}


bool Test::validateSearch()
{
    //const => verify only return

    bool valid = true;

    LinkedListOfInts list;
    //alternatively, we could use stl vector's search to compare

    for(int i = 1000; i < 2000; i++)
    {
        list.addBack(i);
    }

    //check values not in list
    for(int i = 0; i < 1000; i++)
    {
        if( list.search(i) )
        {
            valid = false;
        }
    }

    for(int i = 2000; i < 3000; i++)
    {
        if( list.search(i) )
        {
            valid = false;
        }
    }

    //check values that are in list
    for(int i = 1000; i < 2000; i++)
    {
        if( !list.search(i) )
        {
            valid = false;
        }
    }

    std::cout << "each value in list from 1000-1999 can be found but no others can be: ";
    if( valid ){ std::cout << "PASSED\n"; }else{ std::cout << "FAILED\n"; }


    return(valid);
}


bool Test::validateAddBack()
{
    bool valid = true;
    bool validSize = true;

    LinkedListOfInts list;
    auto v0 = list.toVector();
    std::vector<int> v1;

    for(int i = 0; i < 10; i++)
    {
        list.addBack(i);
        v0 = list.toVector();
        v1.emplace_back(i);

        if( v0 != v1 )
        {
            valid = false;
        }

        if( list.size() != i+1 )
        {
            validSize = false;
        }
/*
        for(int j : v0)
        {
            std::cout << j << ", ";
        }
        std::cout << "\n";

        for(int j : v1)
        {
            std::cout << j << ", ";
        }
        std::cout << "\n\n";
*/
    //COMMENTED BLOCK PROVES addBack() FUNCTIONS AS addFront()
    }

    std::cout << "list of values 1-10 pushed back in order are added correctly: ";
    if( valid ){ std::cout << "PASSED\n"; }else{ std::cout << "FAILED\n"; }

    std::cout << "list of values 1-10 pushed to front correctly updates size: ";
    if( validSize ){ std::cout << "PASSED\n"; }else{ std::cout << "FAILED\n"; }

    return(valid);
}


bool Test::validateAddFront()
{
    bool valid = true;
    bool validSize = true;

    LinkedListOfInts list;
    auto v0 = list.toVector();
    std::vector<int> v1;

    for(int i = 0; i < 10; i++)
    {
        list.addFront(i);
        v0 = list.toVector();
        v1.emplace( v1.begin(), i);

        if( v0 != v1 )
        {
            valid = false;
        }

        if( list.size() != i+1 )
        {
            validSize = false;
        }
/*
        for(int j : v0)
        {
            std::cout << j << ", ";
        }
        std::cout << "\n";

        for(int j : v1)
        {
            std::cout << j << ", ";
        }
        std::cout << "\n\n";
*/
    }

    std::cout << "list of values 1-10 pushed to front in order are added correctly: ";
    if( valid ){ std::cout << "PASSED\n"; }else{ std::cout << "FAILED\n"; }

    std::cout << "list of values 1-10 pushed to front correctly updates size: ";
    if( validSize ){ std::cout << "PASSED\n"; }else{ std::cout << "FAILED\n"; }


    return(valid);
}

bool Test::validateRemoveBack()
{
    bool valid = true;
    bool validSize = true;
    bool validEmptyReturn = true;
    bool validNonEmptyReturn = true;

    LinkedListOfInts list;
    std::vector<int> v0;

    for(int i = 0; i < 10; i++)
    {
        list.addFront(i);
        v0.emplace( v0.begin(), i );
    }

    for(int i = 0; i < 10; i++)
    {
        list.removeBack();
        auto v1 = list.toVector();
        v0.pop_back();

        if( v0 != v1 )
        {
            valid = false;
        }

        if( 10-(i+1) != list.size() )
        {
            validSize = false;
        }
/*
        std::cout << "v0: ";
        for(int j : v0)
        {
            std::cout << j << ", ";
        }
        std::cout << "\n";

        std::cout << "v1: ";
        for(int j : v1)
        {
            std::cout << j << ", ";
        }
        std::cout << "\n\n";
*/
        //COMMENTED BLOCK PROVES removeBack() does not remove any nodes
    }

    LinkedListOfInts emptyList;
    //std::cout << emptyList.removeFront() << "\n";
    validEmptyReturn = !emptyList.removeFront(); //should return false

    emptyList.addFront(1);
    //std::cout << emptyList.removeFront() << "\n";
    validNonEmptyReturn = !emptyList.removeFront(); //should return false

    //NOTE: seems to always return false BUT functions as specified in header

    std::cout << "list of values 1-10 in order are removed from back to front: ";
    if( valid ){ std::cout << "PASSED\n"; }else{ std::cout << "FAILED\n"; }

    std::cout << "calling removeBack() decrements list size: ";
    if( validSize ){ std::cout << "PASSED\n"; }else{ std::cout << "FAILED\n"; }

    std::cout << "removeBack() from an empty list returns whether a node was removed: ";
    if( validEmptyReturn ){ std::cout << "PASSED\n"; }else{ std::cout << "FAILED\n"; }

    std::cout << "removeBack() from a non-empty list returns whether a node was removed: ";
    if( validNonEmptyReturn ){ std::cout << "PASSED\n"; }else{ std::cout << "FAILED\n"; }

    return(valid && validSize);
}


bool Test::validateRemoveFront()
{
    bool valid = true;
    bool validSize = true;
    bool validEmptyReturn = true;
    bool validNonEmptyReturn = true;

    LinkedListOfInts list;
    std::vector<int> v0;

    for(int i = 0; i < 10; i++)
    {
        list.addFront(i);
    }

    for(int i = 0; i < 10; i++)
    {
        auto v1 = list.toVector();
        v1.erase(v1.begin());

        list.removeFront();
        auto v0 = list.toVector();

        if( v0 != v1 )
        {
            valid = false;
        }

        if( 10-(i+1) != list.size() )
        {
            validSize = false;
        }
/*
        for(int j : v0)
        {
            std::cout << j << ", ";
        }
        std::cout << "\n";

        for(int j : v1)
        {
            std::cout << j << ", ";
        }
        std::cout << "\n\n";
*/
    }

    LinkedListOfInts emptyList;
    //std::cout << emptyList.removeFront() << "\n";
    validEmptyReturn = !emptyList.removeFront(); //should return false

    emptyList.addFront(1);
    //std::cout << emptyList.removeFront() << "\n";
    validNonEmptyReturn = !emptyList.removeFront(); //should return false

    //NOTE: seems to always return false but that functions as specified in header

    std::cout << "list of values 1-10 in order are removed from front to back: ";
    if( valid ){ std::cout << "PASSED\n"; }else{ std::cout << "FAILED\n"; }

    std::cout << "calling removeBack() decrements list size: ";
    if( validSize ){ std::cout << "PASSED\n"; }else{ std::cout << "FAILED\n"; }

    std::cout << "removeFront() from an empty list returns whether a node was removed: ";
    if( validEmptyReturn ){ std::cout << "PASSED\n"; }else{ std::cout << "FAILED\n"; }

    std::cout << "removeFront() from a non-empty list returns whether a node was removed: ";
    if( validNonEmptyReturn ){ std::cout << "PASSED\n"; }else{ std::cout << "FAILED\n"; }

    return(valid && validSize);
}

//isEmpty() returns true when the list is not empty
//addBack() adds to front
//removeBack does not remove the node from the list or decrement the list size
//removeFront does not remove the node from the list or decrement the list size

//removeBack always returns false
//removeFront always returns False
