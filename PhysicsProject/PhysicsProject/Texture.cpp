//================================================================
//              Texture.cpp                                
//================================================================
#include "Utilities.hpp"
#include "Texture.hpp"
#include "glut.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define GL_CLAMP_TO_EDGE 0x812F


//================================================================
Texture::Texture(const std::string& texturePath)
	: m_textureDimensions(IntVector2(0, 0))
{
	int				x;
	int				y;
	int				numberOfColorComponents;

	//stbi_set_flip_vertically_on_load(true);
	unsigned char*	pixelData = stbi_load(texturePath.c_str(), &x, &y, &numberOfColorComponents, 0);

	m_textureDimensions.x = x;
	m_textureDimensions.y = y;
	m_pathName = texturePath;

	//Enable texturing
	glEnable(GL_TEXTURE_2D);

	//Tell OpenGL that our pixel data is single-byte aligned
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	//Ask OpenGL for an unused texName (ID number) to use for this texture
	glGenTextures(1, (GLuint*)&m_textureID);

	//Tell OpenGL to bind (set) this as the currently active texture
	glBindTexture(GL_TEXTURE_2D, m_textureID);

	//Set texture clamp vs. wrap (repeat)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	// Set magnification (texel > pixel) and minification (texel < pixel) filters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);


	GLenum bufferFormat = GL_RGBA;
	if (numberOfColorComponents == 3)
		bufferFormat = GL_RGB;
	else
	{
		if (numberOfColorComponents == 1)
			bufferFormat = GL_RED;
	}

	GLenum internalFormat = bufferFormat;

	glTexImage2D(
		GL_TEXTURE_2D,
		0,
		internalFormat,
		(int)m_textureDimensions.x,
		(int)m_textureDimensions.y,
		0,
		bufferFormat,
		GL_UNSIGNED_BYTE,
		pixelData);

	stbi_image_free(pixelData);
}


//================================================================
Texture* Texture::CreateOrGetTexture(const std::string& texturePath)
{
	if (DoesFileExist(texturePath))
	{
		TextureMap::iterator textureIter = s_globalTextures.find(texturePath);

		if (textureIter != s_globalTextures.end())
			return textureIter->second;

		Texture* newTexture = new Texture(texturePath);
		s_globalTextures[texturePath] = newTexture;
		return newTexture;
	}
	else
	{
		ConsolePrintf("Texture path not valid. Unable to create: %s\n", texturePath);
		return nullptr;
	}
}


//================================================================
TextureMap Texture::s_globalTextures;
