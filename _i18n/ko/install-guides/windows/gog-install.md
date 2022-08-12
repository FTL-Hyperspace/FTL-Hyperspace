## FTL 설치 및 1.6.9 로 다운그레이드하기

1. GoG Galaxy 를 설치합니다.
   - 네, 어쩔 수 없습니다. Galaxy 를 *반드시* 설치해야 합니다. GoG 가 제공하는 유일한 다운그레이드 수단입니다. 그 외에 GoG 에서 직접 예전 1.6.9 버전의 EXE 를 다운로드하는 방법은 없습니다.
2. GoG Galaxy 를 실행합니다.
3. 로그인합니다.
4. FTL: Faster Than Light 를 설치합니다.
5. 게임이 설치를 완료할 때까지 기다립니다 (설치가 완료될 떄까지 버전 선택 옵션은 표시되지 않습니다)
6. 게임 옵션에서 `manage installation` -> `configure` 를 선택합니다
   - ![image](https://user-images.githubusercontent.com/1423894/173690397-d192730c-06b1-46dd-b78c-d0c4f14c3de1.png)
   - ![image](https://user-images.githubusercontent.com/1423894/173690647-c66f13dd-5b02-4104-bfee-1ca3e57843d4.png)
7. `show more versions` 를 선택하고 `1.6.9` 를 선택합니다.
   - ![image](https://user-images.githubusercontent.com/1423894/173690919-3f27ea0f-60e5-41f7-a9f4-35b7462361a6.png)
8. 확인 버튼을 누르고 1.6.9 버전이 다운로드 및 설치되기를 기다립니다.
9. 경우에 따라 여러 이유로 몇 번 실패할 수도 있습니다. 몇 회 재시도하다보면 결국 설치될 것입니다.
10. 옵션을 확인해보면 이제 1.6.9 라고 표기될 것입니다.
   - ![image](https://user-images.githubusercontent.com/1423894/173694163-c9b2eb75-7bd4-4826-94de-557989c21959.png)
11. `manage installation` -> `show folder` 를 선택한 뒤, 하이퍼스페이스 설치 단계로 넘어갑니다.
   - ![image](https://user-images.githubusercontent.com/1423894/173691147-8ba9eb0f-5dfd-4534-b93b-3ecf9f680274.png)

## 하이퍼스페이스 바이너리 설치하기

1. [여기서 `FTL-Hyperspace.x.x.x.zip`](https://github.com/FTL-Hyperspace/FTL-Hyperspace/releases/latest) 파일을 받습니다.
   - `x.x.x` 는 하이퍼스페이스 버전입니다.
   - `Source code (zip)` 혹은 `Source code (tar.gz)` 는 **받지 마세요**. 여러분이 원하는 게 아닙니다.
2. 압축 파일을 엽니다.
3. 압축 파일의 `Windows - Extract these files into where FTLGame.exe is` 폴더를 엽니다.
   ![FT1](https://user-images.githubusercontent.com/1423894/173667147-1cc5f424-7d9b-455b-a5db-83c2b9aba2a4.png)
5. 이 중 `DLL` 파일들만 복사합니다. `Hyperspace.dll`, `xinput1_4.dll` 및 (Hyperspace 1.2.0+ 의 경우) `lua.dll` 이 해당합니다.
6. 위 GoG #11 스텝에서 열었던 FTL 설치 폴더에 이 DLL 파일들만 추출합니다.
   - 설치를 완료하면 아래와 같은 모습이 되어야 합니다. 추가적인 파일이 없어야 하고, **특히 `ftl.dat` 의 경우 파일 크기까지 똑같아야** 합니다. 만약 `ftl.dat` 파일의 크기가 다르다면 이미 다른 모드를 설치한 경우이므로, 슬립스트림 모드 매니저로 먼저 모드를 제거해야 할 수도 있습니다.
   - ![FT8](https://user-images.githubusercontent.com/1423894/173696617-18831745-856b-4d91-a5f1-da891aa3a0cb.png)

## 슬립스트림 모드 매니저로 하이퍼스페이스 기반 모드 설치하기
{% include_relative windows-slipstream.md %}
