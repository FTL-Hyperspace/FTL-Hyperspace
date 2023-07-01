## Updating

Ersetze einfach `Hyperspace.dll` (und alle anderen DLLs in der Hyperspace ZIP Datei) mit den neuen in deinerm FTL Installations Verzeichnis.
Das Updaten der `Hyperspace.dll` ist **essentiell** für Multiversum Updates, da sie immer die neueste Hyperspace Version nutzen.

Patche die neue `Hyperspace.ftl` mit Slipstream, wenn du einen Mod nutzt der es benötigt (*patche nicht `Hyperspace.ftl` für Multiverse*)

## Erstmalige Installation

Hyperspace funktioniert nur mit FTL 1.6.9, die nachfolgenden Links werden dir erklären, wie du es herunterlädst und downgradest, je nachdem von wo du FTL gekauft hast:

### Welche FTL Installation hast du?

- [Steam](./steam-install)
- [GoG](./gog-install)
- [Humble Bundle](./humble-install)
- [Epic Games](./other-install#epic)
- [Origin](./other-install#origin)
- [Microsoft Store/Xbox Game Pass](./other-install#microsoft-storexbox-game-pass)

## Problembehebung

#### My game complains about `-opengl`
- Stop using `-opengl` flag, it was removed in Hyperspace 1.5.0 and is no longer needed

#### My game crashes before loading Multiverse
- ***Ensure you're on the latest version of Hyperspace, the Multiverse installer is frequently not up to date!***
- This problem should be pretty much eliminated unless your save file is corrupt but there are some instances where this can still occur on ***laptops only***
- If you're not using a laptop, **your save file is corrupt** and that's why it's not launching, see below.
- If your laptop does not have dedicated graphics (i.e. AMD or Nvidia GPU, not the one built into the CPU) then **your save file is corrupt** and that's the problem.
- If your laptop **DOES** actually have a dedicated GPU, you may need to force FTL to run on either the dedicated or internal GPU, one of them might be causing you a problem.

#### Mein Spiel hängt dich bei dem `E` von Multiversum auf
- [Du hast einen korrumpierten Spielstand](#einen-korrumpierten-spielstand-reparieren)

#### Mein Spiel hängt im Ladebildschirm, aber es crasht nicht und ich höre Musik
- [Du hast einen korrumpierten Spielstand](#einen-korrumpierten-spielstand-reparieren)

#### Einen korrumpierten Spielstand reparieren
Um potentiell einen korrumpierten Spielstand zu beheben:
1. Gehe zu `Dokumente/My Games/FasterThanLight`, du solltest einen `hs_mv_prof.sav` und `hs_mv_version.sav` haben
2. Lösche `hs_mv_version.sav`
3. Bewege `hs_mv_prof.sav` in einen anderen Ordner (**lösche es nicht**)
4. Starte das Spiel erneut und wenn es geladen ist, schließe es wieder
5. Bewege deine originale `hs_mv_prof.sav` zurück wo sie war, wobei du die neue vom Spiel geschaffene Datei überschreibst
