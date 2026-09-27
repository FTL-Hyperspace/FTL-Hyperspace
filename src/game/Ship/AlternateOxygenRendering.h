#include "Global.h"

class AlternateOxygenManager
{
public:
    typedef std::pair<float,GL_Color> GradientColor;

    bool IsGradientEmpty()
    {
        return oxygenGradient.empty();
    }

    void ParseGradientNode(rapidxml::xml_node<char> *node);
    void SetMissingGradientPoints();
    void CreateDefaultGradient();
    GL_Color CalculateGradient(float value);

    static AlternateOxygenManager* GetInstance()
    {
        return &instance;
    }
private:
    std::vector<GradientColor> oxygenGradient;
    static AlternateOxygenManager instance;
};
