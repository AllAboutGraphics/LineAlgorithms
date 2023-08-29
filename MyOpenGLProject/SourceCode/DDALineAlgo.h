#pragma once
#include "2DCoordinates.h"
#include <vector>

class DDALineAlgo
{
	private:
		TwoDimentionalCoordinates			   m_LineStartingCoords;
		TwoDimentionalCoordinates			   m_LineEndingCoords;
		int									   m_dX;
		int									   m_dY;
		std::vector<TwoDimentionalCoordinates> m_LineCoordinatesVector;

	public:
		DDALineAlgo(TwoDimentionalCoordinates startCoords, TwoDimentionalCoordinates endCoords);
		std::vector<TwoDimentionalCoordinates> GetCoordinates();

	private:
		void PutPixel();
		void ComputePoints();
};