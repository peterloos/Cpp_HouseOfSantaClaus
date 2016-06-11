#include <iostream>
using namespace std;

#include <stdio.h>
#include "HouseOfSantaClaus.h"

// c'tor
HouseOfSantaClausIterative::HouseOfSantaClausIterative()
{
    for (int i = 0; i < 9; i ++)
        m_digits[i] = 0;
}

// public interface
void HouseOfSantaClausIterative::Solve()
{
    for (int n = Min; n <= Max; n++)
    {
        if (! IsSolution(n))
            continue;

        AddSolution (n);
    }
}

// private helper methods
bool HouseOfSantaClausIterative::IsSolution(int number)
{
    NumberToDigits (number);

    // verify range of numbers (1..5)
    if (!CheckValidRangeOfDigits())
        return false;

    // exclude consecutive identical digits
    if (!CheckValidSequenceOfDigits())
        return false;

    // exclude edges between 1 and 5 or 2 and 5
    if (!CheckValidEdges())
        return false;

    // exclude duplicate edges
    if (!CheckForDuplicateEdges())
        return false;

    return true;
}

bool HouseOfSantaClausIterative::CheckValidRangeOfDigits()
{
    for (int i = 0; i < 9; i++)
    {
        if (m_digits[i] == 0 || m_digits[i] > 5)
            return false;
    }
    return true;
}

bool HouseOfSantaClausIterative::CheckValidSequenceOfDigits()
{
    for (int i = 1; i < 9; i++)
    {
        if (m_digits[i-1] == m_digits[i])
            return false;
    }
    return true;
}

bool HouseOfSantaClausIterative::CheckValidEdges()
{
    for (int i = 1; i < 9; i ++)
    {
        int edge = m_digits[i-1] * 10 + m_digits[i];
        if (edge == 15 || edge == 51 || edge == 25 || edge == 52)
            return false;
    }

    return true;
}

bool HouseOfSantaClausIterative::CheckForDuplicateEdges()
{
    for (int i = 1; i < 9; i ++)
    {
        int edge1 = m_digits[i-1] * 10 + m_digits[i];
        int edge2 = m_digits[i] * 10 + m_digits[i-1];

        for (int j = i; j < 8; j ++)
        {
            int edge = m_digits[j] * 10 + m_digits[j+1];
            if(edge == edge1 || edge == edge2)
                return false;
        }
    }

    return true;
}

void HouseOfSantaClausIterative::NumberToDigits (int number)
{
    for (int i = 8; i >= 0; i --)
    {
        m_digits[i] = number % 10;
        number /= 10;
    }
}
