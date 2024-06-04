# CG
To study Computer graphics 

## Main System Flow
- Start program 
- Init Engine 
- Run Engine 
  - Setting Model, RenderSystem.
- Engine Loop (Using ECS Design pattern)
  - Game Thread Update from Scene
  - Render() Scene



아마도 Code architecture 를 고쳐서 해야 할듯 하다. 
나는 이 프로젝트를 진행한 이유가 Rendering Techniques 들을 습득하기 위해서 진행 한것이다. 
하지만 맥북에서 Compute shader를 사용하려고 한다면 Metal API 를 사용하는 것이 좋다. 
따라서 크로스 플랫폼을 포기해야 빠른 시간안에 할 수 있을 듯 하다. 