**Désinstaller tous les autres mods FTL avant de continuer !

## Downgrader & Installer la librairie d'Hyperspace

Ce downgrade fonctionne **UNIQUEMENT** pour la version 1.6.14 de Steam de FTL, si vous avez une autre installation de FTL que celle de Steam, vous devez consulter les [autres instructions d'installation pour votre source](/FTL-Hyperspace/install-guides/windows/).

1. Démarrez FTL, dans le menu principal en bas à droite il ***DOIT*** y avoir `Steam Version : 1.6.14`, s'il y a `1.6.9` vous avez déjà downgradé. Si c'est autre chose, il se peut que des mods soient encore installés !
2. Téléchargez [`FTL-Hyperspace.x.x.x.zip` ici](https://github.com/FTL-Hyperspace/FTL-Hyperspace/releases/latest)
   - (où x.x.x est la version d'Hyperspace)
   - Ne téléchargez pas le code source zip ou tar.gz, seulement le zip `FTL-Hyperspace`.
3. Naviguez dans Steam vers FTL et parcourez les fichiers locaux. ![image](https://user-images.githubusercontent.com/1423894/173640622-7c442fc2-89a2-418f-ba28-354568381263.png)
4. Vos fichiers locaux devraient ressembler à ceci : (veuillez noter qu'il y a des différences de langue dans Windows ici)
   - Vous devriez voir *les __mêmes tailles de fichiers__ et les mêmes fichiers présents*
   - ![image](https://user-images.githubusercontent.com/1423894/173657085-225a9560-411e-4a20-b707-b836ba36e551.png)

5. Ouvrez `FTL-Hyperspace.x.x.x.zip` que vous avez téléchargé.
6. Ouvrez le dossier `Windows - Extract these files into where FTLGame.exe is` dans le zip ![FT1](https://user-images.githubusercontent.com/1423894/173667147-1cc5f424-7d9b-455b-a5db-83c2b9aba2a4.png)

7. Extrayez tous les fichiers et dossiers du dossier `Windows` au même endroit où se trouve `FTLGame.exe` sur votre ordinateur.
   - *ne pas extraire tout le zip dans le dossier, vous n'avez besoin que du contenu du dossier Windows pour cette étape*
   - NOTE:** Hyperspace 1.2.0 et plus ont aussi un `lua.dll` qui doit aussi être extrait mais qui n'est pas montré dans ces captures d'écran.
   - ![FT2](https://user-images.githubusercontent.com/1423894/173667301-421fb58e-57c8-43e9-8339-7a01490fd18a.png)

8. A ce stade, votre dossier de jeu devrait ressembler à ceci :
   - Vous pouvez avoir un dossier `crashlogs` ou un fichier settings ou quelques fichiers log supplémentaires mais il ne devrait pas y avoir d'autres fichiers ici, pas de fichiers `.ftl` pas de fichiers `zip`.
   - NOTE:** Hyperspace 1.2.0 et plus ont aussi un fichier `lua.dll` qui n'est pas montré dans ces captures d'écran.
   - Votre `ftl.dat` **doit être très proche ou exactement de la même taille** sinon vous pourriez encore avoir des mods installés.
   - ![image](https://user-images.githubusercontent.com/1423894/173661274-86382f69-9141-4ff9-a23f-f7cbd0c8aec0.png)
9. Double-cliquez et exécutez `downgrade.bat`
10. Après la rétrogradation, votre dossier de jeu devrait ressembler à ce qui suit
   - Veuillez noter la taille** de `FTLGame.exe` et `FTLGame_orig.exe` si `FTLGame.exe` n'est pas `122MB` alors la rétrogradation n'a pas été réussie.
   - ![image](https://user-images.githubusercontent.com/1423894/173661659-51d293fa-7f33-4292-8a13-80b7050e5e9d.png)
11. Hyperspace est maintenant **à moitié installé** vous devez encore patcher un Mod FTL qui utilise l'hyperspace.

## Patching des mods basés sur Hyperspace avec Slipstream
{% include_relative windows-slipstream.md %}

#### Remerciements
Remerciements à Cedric pour avoir fourni la plupart des images d'installation de Windows ci-dessus.
