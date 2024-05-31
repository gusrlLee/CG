#include "Compponent.h"
#include "Math/Color.h"

#include <iostream>
#include <vector>
namespace LE 
{
    class ColorComponent : public Component
    {
        public:
            ColorComponent();
            ~ColorComponent() override; 

        private:
            std::vector<Color> m_Colors;
    };
}