# Mise à jour

Remplacez simplement `Hyperspace.1.6.13.amd64.so` (pour Steam) ou `Hyperspace.1.6.12.amd64.so` (pour GoG/Humble) par la nouvelle version du zip d'hyperspace.
La mise à jour du fichier SO hyperspace est **cruciale** pour les mises à jour Multiverse car elles sont toujours construites avec la dernière version d'hyperspace.

Patcher le nouveau `Hyperspace.ftl` avec Slipstream si vous utilisez un mod qui le nécessite (*ne pas patcher `Hyperspace.ftl` pour Multiverse*).

# Installation

<div class="selector-grid">
    <a class="item" href="steamdeck/select-game-copy">
        <img class="sub-item selector-grid-image" src="{{ '/assets/img/Steam_Deck_colored_logo.svg' | relative_url }}" alt="Steam Deck" />
        <div class="sub-item selector-item-text">Instructions pour Steam Deck</div>
    </a>
    <a class="item" href="genericlinux/select-game-copy">
        <img class="sub-item selector-grid-image" src="{{ '/assets/img/Tux.svg' | relative_url }}" alt="Generic Linux" />
        <div class="sub-item selector-item-text">Instructions pour Linux</div>
    </a>
</div>

# Dépannage

#### Mon jeu se bloque au chargement du dernier `E` de Multiverse.
- [Vous avez un fichier de sauvegarde corrompu](#resolving-a-corrupt-save-file)

#### Mon jeu se bloque au chargement mais ne plante pas et j'entends de la musique.
- [Vous avez un fichier de sauvegarde corrompu](#resolving-a-corrupt-save-file)

#### Réparer un fichier de sauvegarde corrompu
Pour éventuellement réparer une sauvegarde corrompue :
1. Allez dans `~/.local/share/FasterThanLight/`, vous devriez avoir un `hs_mv_prof.sav` et `hs_mv_version.sav`
2. Supprimez le `hs_mv_version.sav`
3. Déplacez le `hs_mv_prof.sav` dans un autre dossier (**ne le supprimez pas**)
4. Lancez le jeu et une fois qu'il s'est chargé sur le menu principal, fermez-le à nouveau.
5. Déplacez votre `hs_mv_prof.sav` original à l'endroit où il se trouvait auparavant, en remplaçant celui qui a été créé par le jeu.
6. Si cela ne fonctionne toujours pas, supprimez tout le dossier `~/.local/share/FasterThanLight/`.
7. Désactivez également Steam Cloud Sync si vous utilisez une version de FTL à partir de steam, cela corrompt souvent les fichiers de sauvegarde.
