//================================================================
//              Texture.hpp                                  
//================================================================
#pragma once
#ifndef _Texture_
#define _Texture_
#include "IntVector2.hpp"
#include "Vector2.hpp"
#include <string>
#include <map>

class Texture;
typedef std::map< std::string, Texture* >	TextureMap;
//================================================================
class Texture
{
public:
	Texture(const std::string& texturePath);

	static Texture*		CreateOrGetTexture(const std::string& texturePath);
	
	const std::string&	GetName() const { return m_pathName; }
	unsigned int		GetTextureID() const { return m_textureID; }

private:
	std::string			m_pathName;
	IntVector2			m_textureDimensions;
	unsigned int		m_textureID;
	static TextureMap	s_globalTextures;
};

#endif //!_Texture_