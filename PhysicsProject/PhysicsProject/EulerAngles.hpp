//================================================================
//                     EulerAngles.hpp
//================================================================
#pragma once
#ifndef  _EulerAngles_
#define  _EulerAngles_


class EulerAngles
{
public:	

	EulerAngles() 
		:m_rollX(0.0f)
		,m_pitchY(0.0f)
		,m_yawZ(0.0f)
	{};

	EulerAngles( float initialRoll_X, float initialPitch_Y, float intialYaw_Z) 
		: m_rollX(initialRoll_X)
		, m_pitchY(initialPitch_Y)
		, m_yawZ(intialYaw_Z)
	{};


	float m_rollX;
	float m_pitchY;
	float m_yawZ; 

};

#endif