### Installieren von Slipstream

1. **Stelle sicher** dass du die Vanilla Version von FTL installiert hast bevor du Slipstream neu installierst oder upgradest
   - Wenn du die Größe von `ftl.dat` in deinem FTL Installierungs Ordner anschaust sollte es bei 270MB (oder 212MB für GoG) sein, wenn es größer ist hast du noch weitere Mods installiert und musst FTL erst wieder zu Vanilla ändern!
   - Slipstream 1.9.1 ist nicht schlau was das Überprüfen ob FTL Vanilla ist angeht, und wird jede `ftl.dat` nutzen die existiert, wenn du es zum ersten Mal öffnest (wenn du also Mods nutzt und Slipstream neu installierst, wird es FTL als "Vanilla" sehen, selbst wenn es nicht so ist!)
   - *Du wirst dir viele Probleme sparen, wenn du vorher sicherstellst, ob ftl.dat Vanilla ist oder nicht*
2. [Downloade slipstream 1.9.1](https://subsetgames.com/forum/viewtopic.php?f=12&t=17102)
3. Extrahiere es in einen Ordner wo du es haben möchtest, ***starte es nicht aus der Zip Datei heraus***
4. Du musst Java auf deinem Computer installiert haben (was für die meisten funktionieren sollte)

### Patching mit Slipstream

1. Lade die Hyperspace-basierten Mods herunter, die dich interessieren
2. Starte Slipstream
3. Clicke `Open mods/`
   - ![image](https://user-images.githubusercontent.com/1423894/173680447-24bdb0df-0a50-44a9-ad79-1f9a6a38f61d.png)
4. Bewege die `.ftl` or `.zip` Dateien von wo du sie heruntergeladen hast, in diesen Ordner
5. Scanne Mods nochmal
   - Gehe zu `file` `Re-Scan mods/`
   - ![image](https://user-images.githubusercontent.com/1423894/173680307-c9d1da5f-9a7e-43af-a933-d53431da27ad.png)


#### Die meisten Hyperspace Mods
1. Bewege `Hyperspace` ganz nach oben in der Slipstream Liste
2. Patche Hyperspace und alle anderen Hyperspace Mods die du willst danach
   - ![image](https://user-images.githubusercontent.com/1423894/173682067-297f466c-bfad-4493-904c-0c27c836657b.png)
   - ***PATCHE NICHT MULTIVERSUM*** Schaue unten für Multiversum Anleitung.
3. Clicke `Patch`
4. Starte FTL
5. Betrachte: [Überprüfen ob Hyperspace richtig installiert ist](#inkorrekt-installiert)

#### Nur für Multiversum
1. Schalte Slipstream's Eigenschaft an Zip Dateien als Mods zu sehen
   - Gehe zu den Slipstream Präferenzen
   - ![image](https://user-images.githubusercontent.com/1423894/173679563-2f5dbe3d-dabf-4278-b8c0-f26351426021.png)
   - Kreuze `allow_zip` an
   - ![image](https://user-images.githubusercontent.com/1423894/173679698-b2f5d369-182e-41a1-939c-39c40b6a0bd5.png)
2. Scanne Mods erneut
   - Geh zu `file` `Re-Scan mods/`
   - ![image](https://user-images.githubusercontent.com/1423894/173680307-c9d1da5f-9a7e-43af-a933-d53431da27ad.png)
3. Patche Multiversum
   - Patche `FTL-Multiverse` **als erstes in der Liste**
   - **WÄHLE NICHT HYPERSPACE AUS**
   - Patche alle weiteren mit FTL Multiversum kompatiblen Mods die du nutzen willst, nach Multiversum
   - **Auf keinen Fall** sollst du Mods patchen die nicht für die Nutzung mit Multiversum gedacht sind oder sich ausschließen (selbst kleine UI Mods können Probleme verursachen, suche im Multiverse Discord Hilfe, wenn du wissen willst ob der Mod den du installieren willst mit Multiverse funktioniert)
   - Example: ![image](https://user-images.githubusercontent.com/1423894/173681032-76e9b056-ede6-42f5-ad5a-ffa0fece384a.png)
   - Clicke `Patch`
4. Betrachten: [Überprüfen ob Hyperspace richtig installiert ist](#inkorrekt-installiert)

### Richtig installiert

- Wenn Hyperspace.dll richtig installiert ist, wirst du eine kleine Nachricht in der rechten oberen Ecke sehen, wenn das Spiel halb geladen ist die etwa so aussieht (kann je nach Version unterschiedlich aussehen):
   - ![image](https://user-images.githubusercontent.com/1423894/173682629-6aa843d8-bb36-4a3b-afad-bd6b23463a8a.png)

- Danach wenn du eine Version hast und sie mit Slipstream richtig installiert hast

- Solltest du in das Mod Menü ohne irgendwelche Probleme oder Warnungen gelangen, Multiverse 5.2.3 korrekt installiert sieht so aus:
   - ![image](https://user-images.githubusercontent.com/1423894/173683306-2b92a3e2-d0d2-4bff-ac19-33ff6ef0a749.png)

- FTL Strawberry Edition sieht so aus:
   - ![image](https://user-images.githubusercontent.com/1423894/173683567-598bc5fe-a7f8-4bad-8dd1-2b6ff161d695.png)

- FTL Hyperspace ohne andere Mods sieht so aus:
   - ![image](https://user-images.githubusercontent.com/1423894/173684224-64a24d41-e5ae-4c52-b45f-82fafb42abea.png)



### Inkorrekt installiert

- Wenn du das Mod Hauptmenü siehst, aber keine Nachricht oben rechts, ist Hyperspace's DLL wahrscheinlich nicht richtig installiert.

- Wenn du eine Fehlernachtricht wegen `AcheivementTracker` bekommst, hast du dein Spiel nicht richtig auf 1.6.9 gedowngraded.

- Wenn du eine Fehlernachricht erhältst, dass `hyperspace.xml` nicht gefunden wurde, hast du wahrscheinlich `Hyperspace.ftl` oder `Multiverse` nicht richtig mit Slipstream gepatched.

- Wenn du eine Fehlernachricht siehst, dass Multiversum und Hyperspace beide gepatched wurden, hast du entweder beide in Slipstream gepatched und musst das korregieren, oder du hattest keine richtige FTL.dat Datei bevor du Slipstream installiert hast und Slipstream dachte, dass die Datei Vanilla wäre, weshalb du die Slipstream Cache leeren musst und FTL.dat zur Vanilla Version konvertieren musst.
