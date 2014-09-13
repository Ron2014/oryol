#pragma once
//------------------------------------------------------------------------------
/**
    @class Oryol::Render::textureLoaderBase
    @brief private: base class for texture loaders
*/
#include "Render/base/loaderBase.h"
#include "Render/Core/texture.h"
#include "IO/Stream/Stream.h"

namespace Oryol {
namespace Render {

class texture;
class textureFactory;

class textureLoaderBase : public loaderBase {
public:
    /// constructor
    textureLoaderBase();
    /// destructor
    virtual ~textureLoaderBase();
    
    /// resource type of this loader
    ResourceType::Code resourceType() const {
        return ResourceType::Texture;
    };
    
    /// test if the loader accepts the resource
    virtual bool Accepts(const texture& resource) const = 0;
    /// test if the loader accepts the resource, with data stream
    virtual bool Accepts(const texture& resource, const Ptr<IO::Stream>& data) const = 0;
    /// start to load, or continue loading
    virtual void Load(texture& resource) const = 0;
    /// start to load, or continue loading, with data stream
    virtual void Load(texture& resource, const Ptr<IO::Stream>& data) const = 0;
    
    /// called when attached to factory
    void onAttachToFactory(textureFactory* factory);
    /// called when detached from factory
    void onDetachFromFactory();
    
protected:
    textureFactory* texFactory;
};

} // namespace Render
} // namespace Oryol
