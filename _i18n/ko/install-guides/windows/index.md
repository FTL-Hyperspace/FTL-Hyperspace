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

#### 게임에서 `-opengl` 관련 메시지가 나와요
- `-opengl` 옵션은 하이퍼스페이스 1.5.0 에서 제거되었고, 더 이상 필요하지 않습니다. 만약 해당 옵션을 사용하고 있었다면 제거해주세요.

#### Multiverse 로딩 전에 게임이 튕깁니다
- ***최신 버전의 하이퍼스페이스를 사용하고 있는지 확인해주세요. 공식 영문 Multiverse 인스톨러는 잘 최신화 되지 않습니다!***
- 이 문제는 대개 두 가지 경우에 대해 보고되어 있습니다. 하나는 세이브 파일이 손상된 경우이고, 다른 하나는 ***랩탑***에서 플레이하는 경우입니다.
- **랩탑**에서 플레이하고 있으며 NVIDIA Optimus 및 AMD Dynamic Switchable Graphics 가 설정되어 있는 경우, 그래픽 카드 설정에서 FTL 이 전용 GPU 나 내장 GPU 중 하나에서만 실행되도록 강제할 필요가 있습니다.
- **그 외에는** 십중팔구 세이브 파일이 손상되었습니다. 아래의 복구 지침을 참고하십시오.

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
