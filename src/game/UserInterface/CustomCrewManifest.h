#pragma once
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
        bool isValidPage = page >= 0 && page < crewEquipBoxes.size();
        return isValidPage ? crewEquipBoxes[page] : std::vector<CrewEquipBox*>();
    }

    void OnInit(CrewManifest *manifest, ShipManager *ship);
    void OnRender();
    void Update();
    void OnTextInput(SDLKey key);
    void OnTextEvent(CEvent::TextEvent event);
    void Close();
    void MouseClick(int mX, int mY);
    void MouseUp(int mX, int mY);
    void MouseMove(int mX, int mY);
    void OnScrollWheel(float direction);

#ifdef HS_ANDROID
    void OnTouch(TouchAction action, int id, int x, int y, int initialX, int initialY);
    void RenderPageButtons();
    void ShowCurrentPage();
    void KeepGameBoxes(CrewManifest *manifest);
    void ReturnGameBoxes(CrewManifest *manifest);
#endif

    int GetEffectiveCrewLimit(ShipManager *ship);
    bool IsOverCrewBox(CrewEquipBox *box)
    {
        return overCrewBox == box;
    }
    static CustomCrewManifest* GetInstance()
    {
        return &instance;
    }

private:
    CrewManifest *crewManifest = nullptr;
    Button *leftButton = nullptr;
    Button *rightButton = nullptr;

    CrewEquipBox *overCrewBox = nullptr;
    std::vector<std::vector<CrewEquipBox*>> crewEquipBoxes;

    int currentPage = 0;
    int crewLimit = -1;

    CrewMember *draggingCrewMember = nullptr;
#ifdef HS_ANDROID
    std::vector<CrewEquipBox*> gameBoxes;
#endif

    static CustomCrewManifest instance;
};
