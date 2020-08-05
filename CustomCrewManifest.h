#include "Global.h"
#include <array>
#include <algorithm>
#include <boost/algorithm/string/predicate.hpp>

class CustomCrewManifest
{
public:
    CustomCrewManifest()
    {

    };

    std::vector<CrewEquipBox*> GetPage(int page)
    {
        return crewEquipBoxes[page];
    }

    void OnInit(CrewManifest *manifest, ShipManager *ship);
    void OnRender();
    void Update();
    void OnTextInput(SDLKey key);
    void OnTextEvent(CEvent::TextEvent event);
    void Close();
    void MouseClick(int mX, int mY);
    void MouseMove(int mX, int mY);

    static CustomCrewManifest* GetInstance()
    {
        return &instance;
    }
private:
    CrewManifest *crewManifest;
    Button *leftButton;
    Button *rightButton;

    CrewEquipBox *overCrewBox;
    std::vector<std::vector<CrewEquipBox*>> crewEquipBoxes;

    int currentPage = 0;
    int crewLimit = 8;

    static CustomCrewManifest instance;
};
