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
		:m_roll(0.0f)
		,m_pitch(0.0f)
		,m_yaw(0.0f)
	{};

	EulerAngles( float initialRoll_X, float initialPitch_Y, float intialYaw_Z) 
		: m_roll(initialRoll_X)
		, m_pitch(initialPitch_Y)
		, m_yaw(intialYaw_Z)
	{};


	float m_roll;
	float m_pitch;
	float m_yaw; 

};

#endif