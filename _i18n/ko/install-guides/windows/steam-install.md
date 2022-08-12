**진행하기 전에 먼저 다른 FTL 모드를 전부 제거한 뒤 진행하세요!**

## 다운그레이드 및 하이퍼스페이스 라이브러리 설치하기

본 가이드의 다운그레이더는 Steam 1.6.14 버전에만 작동합니다. 만약 Steam 외 다른 플랫폼에서 FTL 을 설치했다면, [플랫폼에 맞는 가이드를 참조하셔야 합니다](/FTL-Hyperspace/install-guides/windows/).

1. FTL 을 실행합니다. 메인 메뉴 우측 하단에 **반드시** `Steam Version: 1.6.14` 라고 적혀 있어야 합니다. 만약 `1.6.9` 라고 표시되어 있으면 이미 다운그레이드가 끝난 것이고, 그도 아니라 아예 다른 내용이 적혀있다면 다른 모드가 아직 설치되어 있는 것일 수 있습니다!
2. [여기서 `FTL-Hyperspace.x.x.x.zip`](https://github.com/FTL-Hyperspace/FTL-Hyperspace/releases/latest) 파일을 받습니다.
   - `x.x.x` 는 하이퍼스페이스 버전입니다.
   - `Source code (zip)` 혹은 `Source code (tar.gz)` 는 **받지 마세요**. 여러분이 원하는 게 아닙니다.
3. Steam 에서 FTL 을 찾아 로컬 파일 보기를 선택합니다. ![image](https://user-images.githubusercontent.com/1423894/173640622-7c442fc2-89a2-418f-ba28-354568381263.png)
4. 로컬 파일이 아래와 같이 표시될 것입니다: (Windows 의 언어 표시 차이가 있을 수 있습니다)
   - *파일 목록과 __파일 크기__가 반드시 일치해야 합니다*
   - ![image](https://user-images.githubusercontent.com/1423894/173657085-225a9560-411e-4a20-b707-b836ba36e551.png)

5. 다운로드 한 `FTL-Hyperspace.x.x.x.zip` 압축 파일을 엽니다.
6. 압축 파일의 `Windows - Extract these files into where FTLGame.exe is` 폴더를 엽니다.
   ![FT1](https://user-images.githubusercontent.com/1423894/173667147-1cc5f424-7d9b-455b-a5db-83c2b9aba2a4.png)

7. `Windows - Extract these files into where FTLGame.exe is` 폴더의 모든 파일/폴더 내용물을 `FTLGame.exe` 파일이 있는 위치로 추출합니다.
   - *zip 파일 전체를 추출하지 마세요. Windows 폴더의 내용물만 필요합니다.*
   - **참고:** Hyperspace 1.2.0 이후부터는 `lua.dll` 파일이 추가되었지만, 이하 스크린샷에는 표시되어 있지 않습니다.
   - ![FT2](https://user-images.githubusercontent.com/1423894/173667301-421fb58e-57c8-43e9-8339-7a01490fd18a.png)

8. 이 시점에서 게임 설치 폴더는 아래와 같은 모습이 되어야 합니다:
   - 여기에 추가로 `crashlogs` 폴더 및 몇몇 log 파일이 있을 수도 있습니다. 하지만 그 외에는 추가적인 파일이 있어서는 안됩니다. 특히 .ftl 파일이나 .zip 파일은 있어서는 안됩니다.
   - **참고:** Hyperspace 1.2.0 이후부터는 `lua.dll` 파일이 추가되었지만, 이하 스크린샷에는 표시되어 있지 않습니다.
   - `ftl.dat` 파일의 크기는 **아래 스크린샷과 일치하거나 매우 비슷해야 합니다**. 만약 `ftl.dat` 파일의 크기가 다르다면 아직 다른 모드가 설치되어 있다는 뜻입니다.
   - ![image](https://user-images.githubusercontent.com/1423894/173661274-86382f69-9141-4ff9-a23f-f7cbd0c8aec0.png)
9. `downgrade.bat` 파일을 더블클릭합니다.
10. 다운그레이드가 끝나면 아래와 같은 모습이 되어야 합니다.
   - `FTLGame_orig.exe` 파일이 있어야 합니다. 또한 **`FTLGame.exe` 파일의 크기에 주목하세요**. 만약 `FTLGame.exe` 파일이 `122MB` 가 아니라면 다운그레이드가 실패한 것입니다.
   - ![image](https://user-images.githubusercontent.com/1423894/173661659-51d293fa-7f33-4292-8a13-80b7050e5e9d.png)
11. 이제 하이퍼스페이스가 **절반 정도** 설치되었습니다! 이제 하이퍼스페이스를 사용하는 모드를 설치할 단계입니다.

## 슬립스트림 모드 매니저로 하이퍼스페이스 기반 모드 설치하기
{% include_relative windows-slipstream.md %}

#### 감사드릴 분
다수의 Windows 설치 관련 스크린샷을 제공해주신 Cedric 에게 감사드립니다.

