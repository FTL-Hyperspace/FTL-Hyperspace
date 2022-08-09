---
layout: default
title: "Steam Windows Hyperspace Install Instructions"
permalink: /install-guides/windows/steam-install/
---

**Deinstalliere alle anderen FTL Mods, bevor du weiter machst!**

## Downgrading & Installieren der Hyperspace Bibliothek

Dieser downgrader wird **NUR** funktionieren, für Steams 1.6.14 Version von FTL, wenn du irgend eine andere Installation von FTL hast, die nicht von Steam ist, musst du [andere Installations Anleitungen anschauen](/FTL-Hyperspace/install-guides/windows/).

1. Starte FTL, im Hauptmenü in der rechten unteren Ecke ***MUSS*** es sagen `Steam Version: 1.6.14`, wenn es `1.6.9` sagt, hast du es bereits gedowngraded. Wenn es etwas anderes sagt, hast du wahrscheinlich schon Mods installiert!
2. Downloade [`FTL-Hyperspace.x.x.x.zip` von hier](https://github.com/FTL-Hyperspace/FTL-Hyperspace/releases/latest)
   - (wobei x.x.x die neueste Version von Hyperspace ist)
   - Lade nicht die Source Code Zip oder tar.gr runter, sondern nur `FTL-Hyperspace` zip
3. Navigiere in Steam zu FTL und durchsuche die lokalen Dateien. ![image](https://user-images.githubusercontent.com/1423894/173640622-7c442fc2-89a2-418f-ba28-354568381263.png)
4. Deine Dateien sollten etwas so aussehen: (Bitte beachte, dass einige Bilder in anderen Sprachen sein können)
   - Du solltest *die __gleiche Dateien Größe__ und Dateien haben*
   - ![image](https://user-images.githubusercontent.com/1423894/173657085-225a9560-411e-4a20-b707-b836ba36e551.png)

5. Öffne `FTL-Hyperspace.x.x.x.zip` dass du runtergeladen hast
6. Öffne den `Windows - Extract these files into where FTLGame.exe is` 	Ordner in der Zip ![FT1](https://user-images.githubusercontent.com/1423894/173667147-1cc5f424-7d9b-455b-a5db-83c2b9aba2a4.png)

7. Extrahiere alle Dateien & Ordner in den `Windows` Ordner zum gleichen Ort wo `FTLGame.exe` auf deinem Computer ist
   - *extrahiere nicht die gesamte Zip in den Ordner, du brauchst nur die Windows Inhalte für diesen Schritt*
   - **NOTIZ:** Hyperspace 1.2.0 und höher wird eine `lua.dll` haben die extrahiert werden muss, wird aber nicht in diesen Screenshots gezeigt.
   - ![FT2](https://user-images.githubusercontent.com/1423894/173667301-421fb58e-57c8-43e9-8339-7a01490fd18a.png)

8. Zum jetzigen Zeitpunkt sollte dein Spiel Ordner genau so aussehen:
   - Du hast vielleicht einen `crashlogs` Ordner oder ein settings Dokument oder ein paar extra log Dokumente, aber es sollten keine anderen Dateien hier drin sein, keine `.ftl` Dateien keine `zip` Dateien.
   - **NOTE:** Hyperspace 1.2.0 und höher wird eine `lua.dll` haben die extrahiert werden muss, wird aber nicht in diesen Screenshots gezeigt.
   - Dein `ftl.dat` **sollte sehr nahe oder die gleiche Größe haben** oder sonst hast du vielleicht weitere Mods installiert
   - ![image](https://user-images.githubusercontent.com/1423894/173661274-86382f69-9141-4ff9-a23f-f7cbd0c8aec0.png)
9. Doppel clicke und starte `downgrade.bat`
10. Nachdem du dein Spiel gedowngraded hast, soll es so aussehen wie hier
   - **Bitte beachte die Größe** von `FTLGame.exe` und `FTLGame_orig.exe` , `FTLGame.exe` , wenn sie nicht `122MB` beträgt, war das downgrading nicht erfolgreich
   - ![image](https://user-images.githubusercontent.com/1423894/173661659-51d293fa-7f33-4292-8a13-80b7050e5e9d.png)
11. Hyperspace ist jetzt **Halb-installiert** du musst noch einen Mod patchen, welcher Hyperspace nutzt.

## Patching von Hyperspace-basierten Mods in Splipstream
{% include_relative windows-slipstream-german.md %}

#### Zusätzliche Hilfe
Vielen Dank an Cedric für mehrere Bilder oben

