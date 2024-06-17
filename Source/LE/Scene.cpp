#include "Scene.h"

namespace LE
{
    Scene::Scene()
    {
        m_Width = Display::GetDisplayWidth();
        m_Height = Display::GetDisplayHeight();
        
        MTL::TextureDescriptor* textureDescriptor = MTL::TextureDescriptor::alloc()->init();
        textureDescriptor->setPixelFormat(MTL::PixelFormatRGBA8Unorm);
        textureDescriptor->setWidth(m_Width);
        textureDescriptor->setHeight(m_Height);
        m_Scene = g_Device->newTexture(textureDescriptor);

        MTL::Region region = MTL::Region(0, 0, 0, m_Width, m_Height, 1);
        NS::UInteger bytesPerRow = 4 * m_Width;

        m_Scene->replaceRegion(region, 0, 255, bytesPerRow);

        textureDescriptor->release();
    }

    void Scene::Update(unsigned char* pData)
    {
        MTL::Region region = MTL::Region(0, 0, 0, m_Width, m_Height, 1);
        NS::UInteger bytesPerRow = 4 * m_Width; 
        m_Scene->replaceRegion(region, 0, 255, bytesPerRow); 
    }
}