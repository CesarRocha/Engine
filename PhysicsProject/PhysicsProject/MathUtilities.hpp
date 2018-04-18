//================================================================
//              MathUtilities.hpp                                  
//================================================================
#pragma once
#ifndef _MathUtilities_
#define _MathUtilities_

const float PI = 3.1415926535897932384626433832795f;
const float RAD2DEG = 57.295779513082320876798154814105f; // (float)180.0f/PI;
const float DEG2RAD = 0.01745329251994329576923690768489f; // (float)PI/180.0f;

float	ToDegrees(float radians);
float	ToRadians(float degrees);

#endif //!_MathUtilities_