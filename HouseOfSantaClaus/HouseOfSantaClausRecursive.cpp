#include <iostream>
using namespace std;

#include <stdio.h>
#include "HouseOfSantaClaus.h"

// initialization of adjacency matrix
bool HouseOfSantaClausRecursive::m_adjacent[MaxNodes][MaxNodes] =
{
    { false, true,  true,  true,  false },
    { true,  false, true,  true,  false },
    { true,  true,  false, true,  true  },
    { true,  true,  true,  false, true  },
    { false, false, true,  true,  false }
};

HouseOfSantaClausRecursive::HouseOfSantaClausRecursive()
{
    m_currentPath = 1;   // first node is always '1'      
    m_paintedEdges = 0;  // number of painted edges

    // empty trial matrix
    for (int i = 0; i < MaxNodes; i ++)
        for (int j = 0; j < MaxNodes; j ++)
            m_painted[i][j] = false;
}

// public interface
void HouseOfSantaClausRecursive::Solve()
{
    TryPaintingEdge(0);
}

// private helper methods
void HouseOfSantaClausRecursive::PaintEdge (int from, int to)
{
    m_painted[from][to] = true;
    m_painted[to][from] = true;

    m_currentPath = 10 * m_currentPath + (to + 1);
    m_paintedEdges ++;
}

void HouseOfSantaClausRecursive::ClearEdge (int from, int to)
{
    m_painted[from][to] = false;
    m_painted[to][from] = false;

    m_currentPath = m_currentPath / 10;
    m_paintedEdges --;
}

void HouseOfSantaClausRecursive::TryPaintingEdge(int from)
{
    for (int to = 0; to < MaxNodes; to++)
    {
        if (m_adjacent[from][to])
        {
            if (!m_painted[from][to])
            {
                PaintEdge(from, to);

                if (! (m_paintedEdges == MaxEdges))
                {
                    TryPaintingEdge(to);
                }
                else
                {
                    // found solution !!!
                    AddSolution (m_currentPath);
                }

                ClearEdge(from, to);
            }
        }
    }
}

