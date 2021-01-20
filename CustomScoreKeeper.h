#include "Global.h"

class CustomScoreKeeper
{
public:
    void LoadShipScores(int file);
    void SaveShipScores(int file);

    std::vector<TopScore> GetTopScores(const std::string& shipBlueprint, int variant);
    void AddTopScore(TopScore& topScore, int type);
    void WipeProfile();

    static CustomScoreKeeper* instance;
private:
    std::unordered_map<std::string, std::vector<TopScore>> customShipScores;
};
