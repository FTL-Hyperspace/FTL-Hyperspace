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

#### Multiverse 로딩 전에 게임이 튕깁니다
- ***Nvidia*** GPU 를 사용할 경우 **절대로** `-opengl` 옵션을 사용하지 마세요. 아니면 게임이 크래시납니다.
- ***AMD & Intel*** GPU 의 경우, `-opengl` 옵션을 사용해 FTL 을 실행해야 합니다.
   - 만약 바로가기를 만들었다면, 바로가기의 명령에 있는 마지막 `"` 뒤에 `-opengl`을 삽입하세요.
      - ![image](https://user-images.githubusercontent.com/1423894/173691599-b8fa5b9a-0663-437b-99a4-48216602700c.png)
   - 혹은 만약 Steam 을 사용한다면 시작 옵션을 변경하시면 됩니다.
      - ![image](https://user-images.githubusercontent.com/1423894/173692491-3e2a597a-29b3-44a0-9e3b-c8843708054e.png)


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
