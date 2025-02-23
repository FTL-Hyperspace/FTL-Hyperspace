### Installation de Slipstream

1. **Assurez-vous** d'avoir une installation de FTL vanilla avant de faire une nouvelle installation de Slipstream ou une mise à jour de Slipstream.
   - Si vous vérifiez la taille de `ftl.dat` dans votre dossier d'installation FTL, elle devrait être d'environ 270MB (ou 212MB pour GoG), si elle est significativement plus grande, vous avez encore des mods installés et vous devez d'abord revenir à la version vanilla !
   - Slipstream 1.9.1 n'est pas capable de vérifier si le fichier est vanilla, il utilisera le `ftl.dat` qui existe lorsque vous l'ouvrez pour la première fois (donc si vous avez des mods installés et que vous lancez une nouvelle installation de Slipstream, il considérera ce fichier comme "vanilla" même s'il ne l'est pas !)
   - *Épargnez-vous beaucoup d'hécatombes et de problèmes en vous assurant que vous avez un ftl.dat vanilla propre en premier lieu*.
2. [Télécharger slipstream 1.9.1](https://subsetgames.com/forum/viewtopic.php?f=12&t=17102)
3. Extrayez-le dans un dossier où vous le garderez, ***ne l'exécutez pas depuis le zip***
4. Vous devez avoir Java installé sur votre machine (Cela ne devrait pas poser problème pour la plupart des gens).

### Patcher avec Slipstream

1. Téléchargez les mods basés sur Hyperspace qui vous intéressent.
2. Lancez Slipstream
3. Cliquez sur `Ouvrir les mods/`
   - ![image](https://user-images.githubusercontent.com/1423894/173680447-24bdb0df-0a50-44a9-ad79-1f9a6a38f61d.png)
4. Déplacez les fichiers `.ftl` ou `.zip` de l'endroit où vous les avez téléchargés dans ce dossier mods.
5. Rescanner les mods
   - Allez dans `file` `Re-Scan mods/`
   - ![image](https://user-images.githubusercontent.com/1423894/173680307-c9d1da5f-9a7e-43af-a933-d53431da27ad.png)


#### Pour la plupart des mods basé sur Hyperspace
1. Déplacer `Hyperspace` en haut de la liste dans le couloir de navigation
2. Patcher Hyperspace et tous les autres mods Hyperspace que vous voulez ensuite
   - ![image](https://user-images.githubusercontent.com/1423894/173682067-297f466c-bfad-4493-904c-0c27c836657b.png)
   - ***Ne pas patcher Multiverse*** Voir ci-dessous pour les instructions concernant Multiverse.
3. Cliquez sur "Patch"
4. Lancez FTL
5. Voir : [Vérifier si Hyperspace est installé correctement](#installed-correctly)

#### Multiverse uniquement
1. Activer l'option de Slipstream qui lui permet de reconnaître les fichiers ZIP comme des mods
   - Allez dans les préférences de Slipstream
   - ![image](https://user-images.githubusercontent.com/1423894/173679563-2f5dbe3d-dabf-4278-b8c0-f26351426021.png)
   - Cochez la case `allow_zip`
   - ![image](https://user-images.githubusercontent.com/1423894/173679698-b2f5d369-182e-41a1-939c-39c40b6a0bd5.png)
2. Re-scanner les mods
   - Allez dans `file` `Re-Scan mods/`
   - ![image](https://user-images.githubusercontent.com/1423894/173680307-c9d1da5f-9a7e-43af-a933-d53431da27ad.png)
3. Patcher multiverse
   - Patchez `FTL-Multiverse` **en premier de la liste**
   - **Ne sélectionnez pas Hyperspace**
   - Patchez tous les mods compatibles FTL Multiverse après multiverse
   - Ne patchez pas les mods qui ne sont pas conçus pour FTL Multiverse ou ils peuvent entrer en conflit (même les petits mods d'interface utilisateur peuvent parfois entrer en conflit, demandez de l'aide sur le Discord Multiverse si vous avez des questions sur la compatibilité d'un de vos mods préférés).
   - Exemple: ![image](https://user-images.githubusercontent.com/1423894/173681032-76e9b056-ede6-42f5-ad5a-ffa0fece384a.png)
   - Cliquez sur `Patch`
4. Voir : [Vérifier si Hyperspace est installé correctement](#installed-correctly)

### Installation correcte

- Si la DLL d'hyperspace est installée correctement, vous verrez un petit message en haut à droite de FTL à peu près à mi-chemin de l'écran de chargement et dans l'écran de menu qui ressemble à ceci (il sera un peu différent pour chaque version) :
   - ![image](https://user-images.githubusercontent.com/1423894/173682629-6aa843d8-bb36-4a3b-afad-bd6b23463a8a.png)

- Après cela, si vous obtenez une version ET que vous avez patché avec Slipstream correctement

- Vous devriez arriver au menu principal de votre mod sans erreur ni avertissement, Multiverse 5.2.3 installé correctement ressemble à ceci :
   - ![image](https://user-images.githubusercontent.com/1423894/173683306-2b92a3e2-d0d2-4bff-ac19-33ff6ef0a749.png)

- FTL Strawberry Edition ressemble à ceci :
   - ![image](https://user-images.githubusercontent.com/1423894/173683567-598bc5fe-a7f8-4bad-8dd1-2b6ff161d695.png)

- FTL Hyperspace sans aucun autre mod ressemble à ceci :
   - ![image](https://user-images.githubusercontent.com/1423894/173684224-64a24d41-e5ae-4c52-b45f-82fafb42abea.png)



### Installation incorrecte

- Si vous voyez le menu principal de votre mod mais qu'il n'y a pas d'information sur la version en haut à droite, il se peut que la DLL d'Hyperspace n'ait pas été installée correctement.

- Si vous obtenez un message d'erreur à propos de `AchievementTracker`, vous n'avez pas réussi à downgrader FTL en 1.6.9.

- Si vous voyez un message d'erreur à propos de `hyperspace.xml` qui est introuvable, il se peut que vous n'ayez pas réussi à patcher correctement `Hyperspace.ftl` ou `Multiverse` avec slipstream.

- Si vous voyez un message d'erreur concernant le patching de multiverse & hyperspace, soit vous avez patché les deux dans Slipstream et vous devez corriger cela, soit vous n'aviez pas un FTL.dat propre avant d'installer slipstream et slipstream a pensé que votre FTL.dat était vanilla et vous devez vider le cache de slipstream et revenir à un FTL.dat vanilla.
