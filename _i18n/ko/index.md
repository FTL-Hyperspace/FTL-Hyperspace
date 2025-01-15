# FTL Hyperspace

FTL: Faster Than Light 를 위한 바이너리 모드입니다.

## 개요

FTL: Hyperspace 는 FTL 의 바이너리 (실행 파일) 에 직접적으로 변경을 가하여 모딩 가능성을 확장하는 모드입니다. 더 복잡한 모드를 위한 기반 모드로써, 이 모드는 기존에 불가능했던 기능을 구현하게 해 줍니다. 별도의 능력치를 가진 새로운 종족, 무한한 숫자의 페이지를 지원하는 함선 선택창, 기존의 보조장비를 합쳐 완전히 새로운 보조장비를 만드는 기능이 그러한 예제입니다.

또한 하이퍼스페이스는 시드 설정을 지원합니다. 게임을 시작하기 전에 시드를 입력하면, 추가 해금이 비활성화 된 상태로 지도가 시드에 따라 생성됩니다. 이를 사용해 특정 런을 반복하거나, 혹은 다른 사람과 같은 런을 두고 경주할 수도 있습니다!

그 외 선체 체력 표시가 숫자로 표시되는 등 몇몇 QoL 변경 또한 포함되어 있습니다.

현재 하이퍼스페이스를 사용하는 가장 큰 모드는 [FTL: Multiverse](https://subsetgames.com/forum/viewtopic.php?f=11&t=35332) 입니다. 가서 확인해보세요!

## 설치

아래에서 적합한 설치 가이드를 참조해주세요.
- [Windows](install-guides/windows/index.html)
- [Linux & Steam Deck](install-guides/linux/)
- [MacOS](install-guides/mac/)

## 모드 제작자용 문서

하이퍼스페이스가 제공하는 대부분의 기능은 `Hyperspace.ftl` 의 `data/hyperspace.xml` 에 문서화되어 있습니다. `hyperspace.xml.append` 파일을 사용해 당신의 모드에 필요한 기능을 추가하시면 됩니다. 일반적으로는 사용자가 하이퍼스페이스와 당신의 모드를 각각 다운로드하고, `Hyperspace.ftl` 을 먼저 적용한 뒤 당신의 모드를 적용하는 순서로 설치하게 될 것입니다. 다른 모드와의 호환성을 최대한 보장하기 위해, Hyperspace 의 리소스나 바이너리를 재배포하지 마세요. 대신 사용자가 직접 하이퍼스페이스를 받도록 안내해주시기 바랍니다.

1.2.0 이상에서 지원하는 Lua API 를 포함한 기타 문서는 [위키](https://github.com/FTL-Hyperspace/FTL-Hyperspace/wiki)에서 관리됩니다. 위키에 변경/개선을 제안하려면 GitHub 에 이슈를 남겨주시기 바랍니다. 이슈에는 위키 저장소를 수정한 포크로의 링크를 남겨주시거나, 혹은 단순히 추가/변경할 Markdown 예제만 남겨주셔도 됩니다.

[***FTL Multiverse 디스코드***](https://discord.gg/hhs5ecx)의 하이퍼스페이스 관련 채널에서 저희에게 연락하실 수 있습니다.

### 제작자

개발:
- TheSwiftTiger
- Winderps
- ih8ih8sn0w
- Admiral Billy
- laszlogasd
- mathchamp93
- Mr. Doom/Nasa62
- ChronoVortex
- Pepson
- ranhai

아트:
- SaltyFriedRice

### 감사드릴 분들

- \_Kilburn
- slow (slowriderxcorps)
- Masala
- bamalf
- Puffias Leroy McBillington III (KingdomKrafters/Kix)
- BlizzArchonJ (mr_easy_money)
- Paradigm
- FTL Multiverse Team
