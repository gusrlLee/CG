# my Engine 
## Flow chart
- Init()
- Engine Loop()
- Release()

### Renderer Flow chart 
- Init()
  - Setting Device
  - Setting RenderPass & SwapChain
- Rendering Scene



Device->Get()     --   SwapChain
  |                 |  
MtDevice->Get()        MtSwapChain
  |                 |  
MTL::Device*    CA::MetalLayer*->setDevice(MTL::Device*)



method 
- static variable 
- overiding 


renderer->SetSwapChain(SwapChain, pDevice, pWindow)