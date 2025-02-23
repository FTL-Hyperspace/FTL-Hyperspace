## Installation de FTL et mise à jour vers la version 1.6.9

1. Installer GoG Galaxy
   - Oui, vous *devez* utiliser Galaxy, c'est la seule option que GoG fournit pour la mise à jour, vous ne pouvez pas télécharger un EXE directement de GoG qui est l'ancienne version 1.6.9.
2. Lancez GoG Galaxy
3. Ouvrez une session
4. Installez FTL : Faster Than Light
5. ATTENDRE que l'installation se termine (sérieusement, les options de version ne s'affichent qu'après l'installation).
6. Sélectionnez les options pour le jeu et descendez à `manage installation` -> `configure`
   - ![image](https://user-images.githubusercontent.com/1423894/173690397-d192730c-06b1-46dd-b78c-d0c4f14c3de1.png)
   - ![image](https://user-images.githubusercontent.com/1423894/173690647-c66f13dd-5b02-4104-bfee-1ca3e57843d4.png)
7. Sélectionnez `show more versions` et sélectionnez ensuite `1.6.9`
   - ![image](https://user-images.githubusercontent.com/1423894/173690919-3f27ea0f-60e5-41f7-a9f4-35b7462361a6.png)
8. Cliquez sur OK et attendez que GoG Galaxy télécharge et installe la version 1.6.9.
9. Il se peut que GoG doive réessayer plusieurs fois, il échoue pour des raisons aléatoires, mais il finira par l'installer.
10. Vérifiez à nouveau les options, la version 1.6.9 devrait être affichée.
   - ![image](https://user-images.githubusercontent.com/1423894/173694163-c9b2eb75-7bd4-4826-94de-557989c21959.png)
11. Allez dans `manage installation` -> `show folder` et procédez aux étapes suivantes de l'installation d'hyperspace.
   - ![image](https://user-images.githubusercontent.com/1423894/173691147-8ba9eb0f-5dfd-4534-b93b-3ecf9f680274.png)

## Installation du binaire d'Hyperspace

1. Téléchargez la dernière version [`FTL-Hyperspace.x.x.x.zip` à partir d'ici](https://github.com/FTL-Hyperspace/FTL-Hyperspace/releases/latest)
   - `x.x.x` est la version hyperspace
   - Ne téléchargez pas `Code source (zip)` ou `Code source (tar.gz)`, ce n'est pas ce que vous voulez.
2. Ouvrez le zip
3. Ouvrez le dossier `Windows - Extract these files into where FTLGame.exe is` dans le zip ![FT1](https://user-images.githubusercontent.com/1423894/173667147-1cc5f424-7d9b-455b-a5db-83c2b9aba2a4.png)
5. Copiez tous les fichiers `DLL` et aucun des autres fichiers de ce zip, vous devriez avoir `Hyperspace.dll` `xinput1_4.dll` et dans Hyperspace 1.2.0+ un `lua.dll`
6. Extrayez les DLLs et rien d'autre dans le répertoire d'installation ouvert par GoG à l'étape #11 ci-dessus.
   - Après votre installation FTL devrait ressembler à ceci, pas de fichiers supplémentaires, et `ftl.dat` **devrait être exactement de la même taille** sinon vous pourriez avoir d'autres mods déjà patchés et avoir besoin de revenir en arrière avec Slipstream d'abord
   - ![FT8](https://user-images.githubusercontent.com/1423894/173696617-18831745-856b-4d91-a5f1-da891aa3a0cb.png)

## Patching des mods basés sur Hyperspace avec Slipstream

{% include_relative windows-slipstream.md %}
