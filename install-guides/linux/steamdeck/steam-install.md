---
layout: default
title: "SteamDeck Steam Hyperspace Install"
---
<script>
fetch('https://api.github.com/repos/FTL-Hyperspace/FTL-Hyperspace/releases/latest')
    .then((res) => res.json())
    .then((data) => data.assets[0].browser_download_url)
    .then(downloadUrl => {
        document.getElementById('hyperspace-download-link').href=downloadUrl
    })
</script>
{% tf install-guides/linux/steamdeck/steam-install.md %}

{% tf install-guides/linux/multiverse-install.md %}