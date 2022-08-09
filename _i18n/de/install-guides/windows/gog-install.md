## Installieren von FTL und downgraden auf 1.6.9

1. Installiere GoG Galaxy
   - Ja du *musst* Galaxy nutzen, es ist die einzige Optiondie GoG zum downgraden anbietet, du kannst keine Exe direkt von GoG runterladen, die älter ist
2. Starte GoG Galaxy
3. Melde dich an
4. Installiere FTL: Faster Than Light
5. WARTE bis die Installation vollständig fertig ist (ernsthaft, die Optionen werden nicht auftauchen, bis es vollständig installiert ist)
6. Wähle die Optionen für das Spiel aus und gehe zu `manage installation` -> `configure`
   - ![image](https://user-images.githubusercontent.com/1423894/173690397-d192730c-06b1-46dd-b78c-d0c4f14c3de1.png)
   - ![image](https://user-images.githubusercontent.com/1423894/173690647-c66f13dd-5b02-4104-bfee-1ca3e57843d4.png)
7. Wähle `show more versions` und dann wähle `1.6.9`
   - ![image](https://user-images.githubusercontent.com/1423894/173690919-3f27ea0f-60e5-41f7-a9f4-35b7462361a6.png)
8. Drücke okay und warte dass GoG Galaxy es herunterlädt & 1.6.9 installiert
9. Du mustst gegebenfalls GoG es öfters versuchen lassen, es kann zufällig nicht funktionieren aber sollte letztendlich klappen
10. Überprüfe die Optionen nochmal, es sollte nun 1.6.9 sagen
   - ![image](https://user-images.githubusercontent.com/1423894/173694163-c9b2eb75-7bd4-4826-94de-557989c21959.png)
11. Gehe zu `manage installation` -> `show folder` und mache mit den nächsten Schritten der Hyperspace Installierung weiter.
   - ![image](https://user-images.githubusercontent.com/1423894/173691147-8ba9eb0f-5dfd-4534-b93b-3ecf9f680274.png)

## Installing Hyperspace Binary

1. Lade die neuste Version von Hyperspace herunter und zwar die [`FTL-Hyperspace.x.x.x.zip` von hier](https://github.com/FTL-Hyperspace/FTL-Hyperspace/releases/latest)
   - `x.x.x` is the hyperspace version
   - **Lade nicht** den `Source code (zip)` oder `Source code (tar.gz)` runter, das ist nicht was du willst.
2. Öffne die Zip
3. Öffne den `Windows - Extract these files into where FTLGame.exe is` Ordner in der Zip ![FT1](https://user-images.githubusercontent.com/1423894/173667147-1cc5f424-7d9b-455b-a5db-83c2b9aba2a4.png)
5. Kopiere alle `DLL` Dokumente und keine anderen Daten von dieser Zip, du solltest `Hyperspace.dll` `xinput1_4.dll` und mit Hyperspace 1.2.0+ eine `lua.dll` haben
6. Extrahiere alle DLLs und nichts anderes, in das Installierungsverzeichnis das von GoG in Schritt #11 oben geöffnet wurde
   - Nachdem du FTL installiert hast sollte es so aussehen, keine weiteren Dokumente und `ftl.dat` **sollte die gleiche Größe haben** oder du hast vielleicht bereits Mods installiert und musst Slipstream wieder umkehren
   - ![FT8](https://user-images.githubusercontent.com/1423894/173696617-18831745-856b-4d91-a5f1-da891aa3a0cb.png)

## Patching in hyperspace-based mods with Slipstream

{% include_relative windows-slipstream.md %}
