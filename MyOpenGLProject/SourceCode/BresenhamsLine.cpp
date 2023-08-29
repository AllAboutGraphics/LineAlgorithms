#include <iostream>
#include "BresenhamsLine.h"

BresenhamsLine::BresenhamsLine(TwoDimentionalCoordinates startCoords, TwoDimentionalCoordinates endCoords) : m_StartingCoordinates(startCoords), m_EndingCoordinates(endCoords)
{
	m_dX = m_EndingCoordinates.x - m_StartingCoordinates.x;
	m_dY = m_EndingCoordinates.y - m_StartingCoordinates.y;
	ComputePoints();
	PutPixel();
}

std::vector<TwoDimentionalCoordinates> BresenhamsLine::GetCoordinates()
{
	return m_LineCoordinatesVector;
}

void BresenhamsLine::PutPixel()
{
	//Printing on console
	int vectorSize = (int)(m_LineCoordinatesVector.size());
	for (int i = 0; i < vectorSize; i++)
	{
		std::cout << "[ " << m_LineCoordinatesVector[i].x << ", " << m_LineCoordinatesVector[i].y << " ]" << std::endl;
	}
}

void BresenhamsLine::ComputePoints()
{
	int baseStart	 = (std::abs(m_dX) > std::abs(m_dY)) ? m_StartingCoordinates.x : m_StartingCoordinates.y;
	int baseEnd		 = (std::abs(m_dX) > std::abs(m_dY)) ? m_EndingCoordinates.x : m_EndingCoordinates.y;
	int computeStart = (std::abs(m_dX) <= std::abs(m_dY)) ? m_StartingCoordinates.x : m_StartingCoordinates.y;
	int computeEnd   = (std::abs(m_dX) <= std::abs(m_dY)) ? m_EndingCoordinates.x : m_EndingCoordinates.y;

	int changeInBase	    = baseEnd - baseStart;
	int changeInCompute     = computeEnd - computeStart;
	int decisionParameter   = (2 * std::abs(changeInCompute)) - std::abs(changeInBase);
	int steps			    = std::abs(changeInBase);
	int baseIncrementDir    = changeInBase == 0 ? 0 : (changeInBase / std::abs(changeInBase));
	int computeIncrementDir = (changeInCompute == 0) ? 0 : (changeInCompute / std::abs(changeInCompute));
	for (int i = 0; i <= steps; i++)
	{
		PutValueInLineCoordinatesVector(baseStart, computeStart);
		baseStart += baseIncrementDir;
		if (decisionParameter < 0) { decisionParameter += (2 * std::abs(changeInCompute)); }
		else
		{
			decisionParameter += ((2 * std::abs(changeInCompute)) - (2 * std::abs(changeInBase)));
			computeStart	  += computeIncrementDir;
		}
	}
}

void BresenhamsLine::PutValueInLineCoordinatesVector(int base, int compute)
{
	if (std::abs(m_dX) > std::abs(m_dY)) { m_LineCoordinatesVector.push_back(TwoDimentionalCoordinates(base, compute)); }
	else { m_LineCoordinatesVector.push_back(TwoDimentionalCoordinates(compute, base)); }
}
