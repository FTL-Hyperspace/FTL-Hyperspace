#include "Global.h"


struct CrewDefinition
{
    std::string race;

    bool canFight = true;
    bool canSuffocate = true;
    bool canBurn = true;
    int maxHealth = 100;
    float moveSpeedMultiplier = 1.f;
    float repairSpeed = 1.f;
    float damageMultiplier = 1.f;
    bool providesPower = false;
    float fireRepairMultiplier = 1.2f;
    float suffocationModifier = 1.f;
    bool isTelepathic = false;
    bool isAnaerobic = false;
};





class CustomCrewManager
{
public:
    CustomCrewManager()
    {

    }



    void AddCrewDefinition(CrewDefinition crew);
    void ParseCrewNode(rapidxml::xml_node<char> *node);
    CrewMember* CreateCrewMember(CrewBlueprint* bp, int shipId, bool intruder);
    bool IsRace(const std::string& race);
    void SetupVTable(CrewMember *crew);
    void SwapVTable(void** vtable, int index, void* swapTo);

    CrewDefinition& GetDefinition(std::string& name)
    {
        return this->blueprintNames[name];
    }

    static CustomCrewManager *GetInstance()
    {
        return &instance;
    }

private:
    static CustomCrewManager instance;

    std::map<std::string, CrewDefinition> blueprintNames;
};
