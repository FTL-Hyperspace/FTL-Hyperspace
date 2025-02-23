# Avant de commencer
**Désinstallez tous les autres mods FTL avant de commencer !**

***NOTE***
Ce guide suppose que la version installée par GoG est installée dans `~/GOG Games/FTL Advanced Edition` (le dossier `GOG Games` dans le répertoire personnel de votre utilisateur). Si vous utilisez la version Humble Bundle ou si vous avez installé la version GOG ailleurs, les instructions sont *exactement les mêmes*, mais l'emplacement du jeu peut évidemment différer.

***NOTE***
Ce guide suppose que votre système utilise KDE Plasma comme environnement de bureau (le même que Steam Deck et Kubuntu) et montre les raccourcis et la navigation dans le navigateur de fichiers et les applications communes à KDE, si vous utilisez un environnement de bureau différent, les choses peuvent être légèrement différentes mais elles devraient être suffisamment proches pour vous envoyer sur le bon chemin. Une chose à noter : `Konsole` est la forme de KDE du terminal/ligne de commande/xterm/gterm/quel que soit le nom que lui donne votre système.

1. Lancez FTL pour vous assurer que vous utilisez la bonne version
![image]({{ '/assets/img/install/steamdeck/gog-humble/1.png' | relative_url }})
![image]({{ '/assets/img/install/steamdeck/gog-humble/2.png' | relative_url }})
2. Assurez-vous que la version indique `1.6.12` en bas à droite.
![image]({{ '/assets/img/install/steamdeck/gog-humble/3.png' | relative_url }})
5. Téléchargez Hyperspace <a id="hyperspace-download-link" href="https://github.com/FTL-Hyperspace/FTL-Hyperspace/releases/latest">`FTL-Hyperspace.x.x.x.zip` à partir d'ici</a> dans votre dossier `Downloads`.
***Ne pas extraire ce ZIP pour l'instant***
6. Téléchargez [Vhati's Slipstream 1.9.1 for Linux](https://sourceforge.net/projects/slipstreammodmanager/files/Slipstream/1.9.1/SlipstreamModManager_1.9.1-Unix.tar.gz/download) dans votre dossier `Downloads`.
***N'extrayez pas encore ce tar.gz***
7. Ouvrez votre navigateur de fichiers et naviguez jusqu'au dossier d'installation de FTL et dans les dossiers de jeu et de données.
![image]({{ '/assets/img/install/steamdeck/gog-humble/4.png' | relative_url }})
![image]({{ '/assets/img/install/steamdeck/gog-humble/5.png' | relative_url }})
![image]({{ '/assets/img/install/steamdeck/gog-humble/6.png' | relative_url }})
![image]({{ '/assets/img/install/steamdeck/gog-humble/7.png' | relative_url }})
10. Cela devrait ressembler à ceci, pour une installation vanilla non modifiée
![image]({{ '/assets/img/install/steamdeck/gog-humble/8.png' | relative_url }})
11. Ouvrez le dossier Downloads dans une nouvelle fenêtre où nous avons précédemment téléchargé Hyperspace & Slipstream.
![image]({{ '/assets/img/install/steamdeck/gog-humble/9.png' | relative_url }})
![image]({{ '/assets/img/install/steamdeck/gog-humble/10.png' | relative_url }})
12. Faites un clic droit sur le fichier zip Hyperspace et `Ouvrir avec Ark` car nous avons besoin d'extraire seulement quelques fichiers et pas tout.
![image]({{ '/assets/img/install/steamdeck/steam/steamdeck_15.png' | relative_url }})
![image]({{ '/assets/img/install/steamdeck/steamdeck_16.png' | relative_url }})
13. Développez le dossier `Linux` dans Ark en cliquant sur la petite flèche à sa gauche.
![image]({{ '/assets/img/install/steamdeck/steam/steamdeck_17.png' | relative_url }})
14. Sélectionnez seulement `Hyperspace.1.6.12.amd64.so` et `liblua5.3.so.0` et glissez-les dans le dossier data pour les extraire.
![image]({{ '/assets/img/install/steamdeck/gog-humble/11.png' | relative_url }})
15. Votre dossier de données devrait maintenant ressembler à ceci
![image]({{ '/assets/img/install/steamdeck/gog-humble/12.png' | relative_url }})
16. Faites un clic droit sur le fichier `FTL` et `Ouvrez avec KWrite` ou n'importe quel éditeur de texte que vous voulez
![image]({{ '/assets/img/install/steamdeck/gog-humble/13.png' | relative_url }})
![image]({{ '/assets/img/install/steamdeck/gog-humble/14.png' | relative_url }})
17. Modifiez les dernières lignes du fichier pour qu'elles ressemblent ***EXACTEMENT*** à ceci
Vous devez ajouter ces deux lignes avant la ligne `exec` mais après les autres lignes `export`.
``sh
export LD_LIBRARY_PATH="$here":${LD_LIBRARY_PATH}
export LD_PRELOAD=Hyperspace.1.6.12.amd64.so
```
Pour référence, ***Avant*** cela ressemblera à ceci :
```sh
export LANG="${LC_ALL:-$LANG}"
export LC_ALL=
export LC_NUMERIC=C
exec "$here/$command.$arch" "$@"
```
***APRES*** cela doit ressembler exactement à ceci à la fin du fichier :
```sh
export LANG="${LC_ALL:-$LANG}"
export LC_ALL=
export LC_NUMERIC=C
export LD_LIBRARY_PATH="$here":${LD_LIBRARY_PATH}
export LD_PRELOAD=Hyperspace.1.6.12.amd64.so
exec "$here/$command.$arch" "$@"
```
Pour être clair, vous ajoutez juste ces deux lignes mais il est ***très important*** de les ajouter avant la dernière ligne du fichier qui contient `exec`
![image]({{ '/assets/img/install/steamdeck/gog-humble/15.png' | relative_url }})
18. Enregistrez le fichier et fermez KWrite
![image]({{ '/assets/img/install/steamdeck/gog-humble/16.png' | relative_url }})
#### Slipstream
19. Retournez dans le dossier des téléchargements
20. Faites un clic droit sur `SlipstreamModManager_1.9.1-Unix.tar.gz` et descendez jusqu'à `Extract` et sélectionnez `Extract archive here`
![image]({{ '/assets/img/install/steamdeck/downloads_extract_slipstream.png' | relative_url }})
21. Naviguez dans le dossier `SlipstreamModManager_1.9.1-Unix`.
***NOTE*** A ce stade, nous en avons fini avec la fenêtre Ark pour Slipstream (mais pas avec l'autre fenêtre Ark qui a ouvert Hyperspace.zip) nous en avons aussi fini avec toute utilisation de `SlipstreamModManager_1.9.1-Unix.tar.gz` donc vous pouvez l'effacer maintenant si vous voulez libérer de l'espace.
![image]({{ '/assets/img/install/steamdeck/steam/steamdeck_27.png' | relative_url }})
22. Naviguez dans le dossier `mods`.
![image]({{ '/assets/img/install/steamdeck/steam/steamdeck_29.png' | relative_url }})
Cela devrait ressembler à ceci sans aucun mod ajouté
![image]({{ '/assets/img/install/steamdeck/steam/steamdeck_30.png' | relative_url }})
23. Retournez dans la fenêtre Ark qui a le fichier zip Hyperspace ouvert et sélectionnez `Hyperspace.ftl`
24. Glissez `Hyperspace.ftl` dans le dossier `mods` de Slipstream
![image]({{ '/assets/img/install/steamdeck/steam/steamdeck_32.png' | relative_url }})
![image]({{ '/assets/img/install/steamdeck/steamdeck_33.png' | relative_url }})
***NOTE*** Vous pouvez maintenant fermer la fenêtre Ark d'Hyperspace et supprimer `Hyperspace.x.x.x.zip` de vos téléchargements si vous le souhaitez, nous en avons fini avec lui pour de bon.
25. Naviguez de nouveau vers le dossier Slipstream (vous pouvez cliquer sur `SlipstreamModManager` dans la barre de titre comme montré ici)
![image]({{ '/assets/img/install/steamdeck/steam/35.png' | relative_url }})
26. Lancez Slipstream en faisant un clic droit sur `modman.command` et en sélectionnant `Run In Konsole`
![image]({{ '/assets/img/install/steamdeck/steam/37.png' | relative_url }})
27. Slipstream ne détectera probablement pas automatiquement une installation GoG ou Humble, vous devrez lui indiquer où se trouve le fichier `FTL.dat`.
![image]({{ '/assets/img/install/steamdeck/gog-humble/17.png' | relative_url }})
![image]({{ '/assets/img/install/steamdeck/gog-humble/18.png' | relative_url }})
![image]({{ '/assets/img/install/steamdeck/gog-humble/19.png' | relative_url }})
![image]({{ '/assets/img/install/steamdeck/gog-humble/20.png' | relative_url }})
![image]({{ '/assets/img/install/steamdeck/gog-humble/21.png' | relative_url }})
![image]({{ '/assets/img/install/steamdeck/gog-humble/22.png' | relative_url }})
28. Sélectionnez qu'il n'a pas été installé via Steam
![image]({{ '/assets/img/install/steamdeck/gog-humble/23.png' | relative_url }})
29. Votre choix, oui/non si vous voulez qu'il vérifie les mises à jour
![image]({{ '/assets/img/install/steamdeck/slipstream_update_prompt.png' | relative_url }})
30. Slipstream fonctionne, cochez la case à côté de `Hyperspace` et appuyez sur `Patch`
![image]({{ '/assets/img/install/steamdeck/slipstream_checkhyperspace_hit_patch.png' | relative_url }})
32. Sélectionnez ***NO*** à "run the game right now", nous devons d'abord désactiver les sauvegardes dans le cloud de steam et supprimer les fichiers de sauvegarde pour assurer un démarrage réussi.
![image]({{ '/assets/img/install/steamdeck/steam/51.png' | relative_url }})
#### Suppression des anciennes sauvegardes qui risquent de bloquer le jeu
36. Retournez dans votre navigateur de fichiers (Dolphin) et sélectionnez `Home` sur le côté gauche.
![image]({{ '/assets/img/install/steamdeck/steam/56.png' | relative_url }})
37. Sélectionnez le menu hamburger en haut à droite et cochez la case "Afficher les fichiers cachés".
![image]({{ '/assets/img/install/steamdeck/steam/57.png' | relative_url }})
38. Naviguez dans le dossier `.local`.
![image]({{ '/assets/img/install/steamdeck/steam/58.png' | relative_url }})
39. Et ensuite le dossier `share`
![image]({{ '/assets/img/install/steamdeck/steam/59.png' | relative_url }})
40. Trouvez le dossier `FasterThanLight`, vous pouvez le sauvegarder quelque part à ce stade si vous voulez garder votre sauvegarde vanilla.
![image]({{ '/assets/img/install/steamdeck/steam/60.png' | relative_url }})
41. Faites un clic droit sur `FasterThanLight` et sélectionnez `Move to Trash`
![image]({{ '/assets/img/install/steamdeck/steam/61.png' | relative_url }})
42. Lancez FTL
43. Vous devriez voir un sélecteur de langue si vous avez supprimé toutes les sauvegardes correctement.
![image]({{ '/assets/img/install/steamdeck/steam/63.png' | relative_url }})
44. Vous devriez remarquer qu'il est écrit `HS-x.x.x x64` dans le coin supérieur droit, ce qui indique que le fichier Hyperspace.so est en cours d'exécution
Le `1.6.12 (Hyperspace x.x.x)` en bas à droite indique un patching réussi de Hyperspace.ftl avec Slipstream.
Vous devriez voir **LES DEUX** indicateurs montrant qu'Hyperspace fonctionne correctement.
![image]({{ '/assets/img/install/steamdeck/gog-humble/24.png' | relative_url }})
