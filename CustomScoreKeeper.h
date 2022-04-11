#include "Global.h"

extern std::unordered_map<std::string, int> metaVariables;

class CustomScoreKeeper
{
public:
    void LoadShipScores(int file);
    void LoadMetaVars(int file);
    void SaveShipScores(int file);
    void SaveMetaVars(int file);

    std::vector<TopScore> GetTopScores(const std::string& shipBlueprint, int variant);
    void AddTopScore(TopScore& topScore, int type);
    void WipeProfile();

    static CustomScoreKeeper* instance;
private:
    std::unordered_map<std::string, std::vector<TopScore>> customShipScores;
};
