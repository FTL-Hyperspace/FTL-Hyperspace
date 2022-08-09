---
layout: default
title: "Windows Hyperspace Install Instructions"
permalink: /install-guides/windows/
---

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

#### Mein Spiel crasht, bevor Multiverse lädt
- ***Nvidia*** GPUs ***dürfen nicht*** `-opengl` nutzen oder sie crashen.
- ***AMD & Intel*** GPUs müssen das Spiel mit der Option `-opengl` starten.
   - Wenn du einen Shortcut machst, kreiere einen Shortcut und schreibe `-opengl` hinter dem letzten `"`
      - ![image](https://user-images.githubusercontent.com/1423894/173691599-b8fa5b9a-0663-437b-99a4-48216602700c.png)
   - Wenn du Steam nutzt, kannst du es in Starteinstellungen schreiben
      - ![image](https://user-images.githubusercontent.com/1423894/173692491-3e2a597a-29b3-44a0-9e3b-c8843708054e.png)


#### Mein Spiel hängt dich bei dem E von Multiversum auf
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