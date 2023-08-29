#include <iostream>
#include "DDALineAlgo.h"

DDALineAlgo::DDALineAlgo(TwoDimentionalCoordinates startCoords, TwoDimentionalCoordinates endCoords) : m_LineStartingCoords(startCoords), m_LineEndingCoords(endCoords)
{
	m_dX = endCoords.x - startCoords.x;
	m_dY = endCoords.y - startCoords.y;
	ComputePoints();
	PutPixel();
}

std::vector<TwoDimentionalCoordinates> DDALineAlgo::GetCoordinates()
{
	return m_LineCoordinatesVector;
}

void DDALineAlgo::PutPixel()
{
	//For now printing on console
	int coordinatesVectorSize = (int)m_LineCoordinatesVector.size();
	for (int i = 0; i < coordinatesVectorSize; i++)
	{
		std::cout << "[ " << m_LineCoordinatesVector[i].x << ", " << m_LineCoordinatesVector[i].y << " ]" << std::endl;
	}
}

void DDALineAlgo::ComputePoints()
{
	int	  steps	     = std::abs(m_dX) > std::abs(m_dY) ? std::abs(m_dX) : std::abs(m_dY);
	float xIncrement = (float)m_dX / (float)steps;
	float yIncrement = (float)m_dY / (float)steps;
	float currX		 = m_LineStartingCoords.x;
	float currY		 = m_LineStartingCoords.y;
	m_LineCoordinatesVector.push_back(m_LineStartingCoords);
	for (int i = 0; i < steps; i++)
	{
		currX += xIncrement;
		currY += yIncrement;
		m_LineCoordinatesVector.push_back(TwoDimentionalCoordinates(currX + 0.5f, currY + 0.5f));
	}
}
