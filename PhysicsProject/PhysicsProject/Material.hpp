//================================================================
//              Material.hpp                                  
//================================================================
#pragma once
#ifndef _Material_
#define _Material_

//================================================================
class Material
{
public:
	Material()
	{
	}
	unsigned int m_diffuseID;
	unsigned int m_specularID;
	unsigned int m_normalID;
	float m_shininess;
private:
};


#endif //!_Material_