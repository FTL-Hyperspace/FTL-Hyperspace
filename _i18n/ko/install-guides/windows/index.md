## 업데이트

단순히 FTL 설치 디렉토리에 있는  `Hyperspace.dll` 및 기타 DLL 을 신규 버전의 파일로 교체하시면 됩니다. Multiverse 는 항상 최신 버전의 하이퍼스페이스를 사용해 제작되므로 `Hyperspace.dll` 의 **업데이트가 필수적**입니다.

만약 사용중인 모드가 `Hyperspace.ftl` 을 요구한다면, 슬립스트림 모드 매니저에서 해당 모드도 새로운 버전으로 다시 패치해주십시오. (*Multiverse 를 사용한다면 `Hyperspace.ftl` 을 패치하지 마십시오*)

## 최초 설치

하이퍼스페이스는 FTL 1.6.9 버전에서만 작동하므로, 다음 가이드를 참조해 다운그레이드 및 설치를 진행해주시기 바랍니다.

### FTL 을 어디서 설치하셨습니까?

- [Steam](./steam-install)
- [GoG](./gog-install)
- [Humble Bundle](./humble-install)
- [Epic Games](./other-install#epic)
- [Origin](./other-install#origin)
- [Microsoft Store/Xbox Game Pass](./other-install#microsoft-storexbox-game-pass)

## 문제 해결

#### My game complains about `-opengl`
- Stop using `-opengl` flag, it was removed in Hyperspace 1.5.0 and is no longer needed

#### My game crashes before loading Multiverse
- ***Ensure you're on the latest version of Hyperspace, the Multiverse installer is frequently not up to date!***
- This problem should be pretty much eliminated unless your save file is corrupt but there are some instances where this can still occur on ***laptops only***
- If you're not using a laptop, **your save file is corrupt** and that's why it's not launching, see below.
- If your laptop does not have dedicated graphics (i.e. AMD or Nvidia GPU, not the one built into the CPU) then **your save file is corrupt** and that's the problem.
- If your laptop **DOES** actually have a dedicated GPU, you may need to force FTL to run on either the dedicated or internal GPU, one of them might be causing you a problem.

#### Multiverse 로딩 중 마지막 `E`에서 튕깁니다
- [세이브 파일이 손상된 경우입니다](#손상된-세이브-파일-복구하기)

#### 게임 로딩에서 그냥 멈춰 있는데 튕기진 않고 음악만 나옵니다
- [세이브 파일이 손상된 경우입니다](#손상된-세이브-파일-복구하기)

#### 손상된 세이브 파일 복구하기
다음 방법을 사용하여 손상된 세이브 파일을 복구하는 것을 시도할 수 있습니다.
1. `Documents/My Games/FasterThanLight` 위치를 여세요. `hs_mv_prof.sav` 및 `hs_mv_version.sav` 파일이 있을 것입니다.
2. `hs_mv_version.sav` 파일을 지웁니다.
3. `hs_mv_prof.sav` 파일을 다른 폴더로 잠시 옮겨둡니다 (**이 파일은 지우면 안 됩니다**)
4. 게임을 실행하고, 정상적으로 실행되었다면 종료합니다.
5. 옮겨두었던 `hs_mv_prof.sav` 파일을 본래 자리로 되돌려놓습니다. 게임이 새로 만든 파일은 그냥 덮어쓰면 됩니다.
