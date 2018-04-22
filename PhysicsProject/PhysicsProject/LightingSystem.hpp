//================================================================
//              LightingSystem.hpp                                  
//================================================================
#pragma once
#ifndef _LightingSystem_
#define _LightingSystem_
#include "LightSource.hpp"
#include <vector>



//================================================================
class LightingSystem
{
public:
	static LightingSystem* g_theLightSystem;
	static LightingSystem* InitalizeLightingSystem()
	{
		LightingSystem* newSystem = g_theLightSystem;
		if (!g_theLightSystem)
		{
			LightingSystem* newSystem = new LightingSystem();
			g_theLightSystem = newSystem;
		}
		return g_theLightSystem;		
	}
	LightSource* CreateDirectionalLight(Vector3 direction, Vector3 ambient, Vector3 diffuse, Vector3 specular)
	{
		LightSource* newLight = new LightSource();

		newLight->SetBaseValues(ambient, diffuse, specular);
		newLight->CreateDirectionalLight(direction);

		m_directionalLights.push_back(newLight);
		return newLight;
	}
	LightSource* CreatePointLight(Vector3 position, float constant, float linear, float quadratic, Vector3 ambient, Vector3 diffuse, Vector3 specular)
	{
		LightSource* newLight = new LightSource();

		newLight->SetBaseValues(ambient, diffuse, specular);
		newLight->CreatePointLight(position, constant, linear, quadratic);

		m_pointLights.push_back(newLight);
		return newLight;
	}
	LightSource* CreateSpotLight(Vector3 position, Vector3 direction, float cutoff, float outerCutoff, float constant, float linear, float quadratic, Vector3 ambient, Vector3 diffuse, Vector3 specular)
	{
		LightSource* newLight = new LightSource();

		newLight->SetBaseValues(ambient, diffuse, specular);
		newLight->CreateSpotLight(position, direction, cutoff, outerCutoff, constant, linear, quadratic);

		m_spotLights.push_back(newLight);
		return newLight;
	}

	unsigned int GetNumDirectionalLights()	{ return m_directionalLights.size(); }
	unsigned int GetNumPointLights()		{ return m_pointLights.size(); }
	unsigned int GetNumSpotLights()			{ return m_spotLights.size(); }

	LightSource* GetDirectionalLightAt(unsigned int index)
	{
		if (index < m_directionalLights.size())
		{
			return m_directionalLights[index];
		}
		return nullptr;
	}
	LightSource* GetPointLightAt(unsigned int index)
	{
		if (index < m_pointLights.size())
		{
			return m_pointLights[index];
		}
		return nullptr;
	}
	LightSource* GetSpotLightAt(unsigned int index)
	{
		if (index < m_spotLights.size())
		{
			return m_spotLights[index];
		}
		return nullptr;
	}

private:
	LightingSystem() 
	{
	}
	std::vector<LightSource*> m_directionalLights;
	std::vector<LightSource*> m_pointLights;
	std::vector<LightSource*> m_spotLights;
};

__declspec(selectany) LightingSystem* LightingSystem::g_theLightSystem;

#endif //!_LightingSystem_