This file is for a list of differences directly affecting the XML or mods in relation to different variants of hyperspace between OSes because of FTL differences.


**Linux** & **MacOS**
baseRarity is not set to 0 by default on blueprints as the Description constructor is inlined.
If a modder forgets blueprint rarity it will work on Windows but still has undefined behavior on Linux/MacOS
