#pragma once
#include <vector>
#include "2DCoordinates.h"

class BresenhamsLine
{
	private:
		TwoDimentionalCoordinates			   m_StartingCoordinates;
		TwoDimentionalCoordinates			   m_EndingCoordinates;
		std::vector<TwoDimentionalCoordinates> m_LineCoordinatesVector;
		int									   m_dX;
		int									   m_dY;

	public:
		BresenhamsLine(TwoDimentionalCoordinates startCoords, TwoDimentionalCoordinates endCoords);
		std::vector<TwoDimentionalCoordinates> GetCoordinates();

	private:
		void PutPixel();
		void ComputePoints();
		void PutValueInLineCoordinatesVector(int base, int compute);
};