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

#### Mein Spiel beschwert sich über `-opengl`
- Sie sollten auf den `-opengl` Anhängsel verzichten, seit Hyperspace 1.5.0 wird er nicht mehr benötigt.

#### Mein Spiel stürzt ab bevor es Multiverse zu laden beginnt
- ***Versichern Sie sich, dass sie die neuste Hyperspace version nutzen, der Multiverse Installer ist häufig nicht auf dem neusten Stand!***
- Dieses Problem sollte so weit es geht behoben sein, es sei denn, Ihre Speicherstände sind beschädigt. Es ist jedoch immer noch möglich diesem Fehler über den Weg zu laufen.
***Nur auf Laptops***
- Sollten sie keinen Laptop nutzen, **sind Ihre Speicherstände beschädigt** und sorgen dafür, dass es nicht startet. Siehe nächstes.
- Falls Ihr Laptop keine dedizierte Grafikeinheit verbaut hat (gemeint sind z.B. AMD oder Nvidia GPUs, nicht die integrierte Grafikeinheit in der CPU) dann **sind Ihre Speicherstände beschädigt** und verursachen das Problem.
- If your laptop **DOES** actually have a dedicated GPU, you may need to force FTL to run on either the dedicated or internal GPU, one of them might be causing you a problem.
- **Falls** ihr Laptop eine dedizierte GPU besitzt, dann müssen Sie möglicherweise FTL dazu zwingen entweder die dedizierte oder integrierten GPU zu nutzen, eine der beiden löst möglicherweise das Problem aus.

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
