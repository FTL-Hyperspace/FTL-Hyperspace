### 슬립스트림 모드 매니저 설치하기

1. 슬립스트림 모드 매니저를 설치하거나 업데이트 하기 전에, 먼저 바닐라 FTL 이 설치된 상태인지 확인하세요.
   - FTL 설치 폴더의 `ftl.dat` 파일의 크기를 확인하세요. 270 MB 부근이어야 합니다. (GoG 의 경우 212 MB) 만약 이보다 훨씬 크다면 이미 모드가 설치되어 있는 것이고, 따라서 바닐라로 먼저 되돌려놓아야 합니다!
   - 슬립스트림 1.9.1 은 `ftl.dat` 파일이 바닐라인지 아닌지 똑똑하게 판단하지 못합니다. 따라서 첫 실행을 할 때 설치 폴더에 있는 `ftl.dat` 파일을 바닐라라고 간주할 것입니다. (따라서 만약 모드가 설치된 상태라면 슬립스트림은 모드가 설치된 상태의 `ftl.dat` 파일을 바닐라로 간주해버립니다!)
   - *다시 강조하지만 바닐라 ftl.dat 인지 확인하시기 바랍니다. 이를 확인하는 것만으로도 수많은 설치 관련 문제를 방지할 수 있습니다.*
2. [슬립스트림 모드 매니저 1.9.1](https://subsetgames.com/forum/viewtopic.php?f=12&t=17102) 을 받습니다.
3. 원하는 곳에 압축 해제합니다. ***압축 해제를 하지 않은 상태로 zip 파일 안에서 직접 실행하지 마십시오.***
4. Java 가 설치되어 있어야 합니다 (대부분의 사람들에게 이미 설치되어 있을 것입니다).

### 슬립스트림으로 패치하기

1. 원하는 하이퍼스페이스 기반 모드를 받습니다.
2. 슬립스트림 모드 매니저를 실행합니다.
3. `Open mods/` 버튼을 클릭합니다.
   - ![image](https://user-images.githubusercontent.com/1423894/173680447-24bdb0df-0a50-44a9-ad79-1f9a6a38f61d.png)
4. 받은 모드 (`.ftl` 혹은 `.zip` 파일) 를 이 mods 폴더 안에 넣습니다.
5. 모드를 다시 스캔합니다.
   - `file` -> `Re-Scan mods/` 를 선택합니다.
   - ![image](https://user-images.githubusercontent.com/1423894/173680307-c9d1da5f-9a7e-43af-a933-d53431da27ad.png)


#### (Multiverse 외) 대부분의 하이퍼스페이스 기반 모드의 경우
1. `Hyperspace` 를 목록의 최상단으로 설정합니다.
2. `Hyperspace` 와 원하는 하이퍼스페이스 기반 모드를 체크합니다.
   - ![image](https://user-images.githubusercontent.com/1423894/173682067-297f466c-bfad-4493-904c-0c27c836657b.png)
   - ***단 Multiverse 는 이렇게 설치하면 안 됩니다.*** 아래 Multiverse 전용 가이드를 참조하세요.
3. `Patch` 를 선택합니다.
4. FTL 을 실행합니다.
5. [제대로 설치되었는지 확인합니다.](#설치-확인)

#### Multiverse 의 경우
1. 슬립스트림이 .zip 파일도 모드로 인식하도록 설정합니다.
   - `File` -> `Preferences` 를 선택합니다.
   - ![image](https://user-images.githubusercontent.com/1423894/173679563-2f5dbe3d-dabf-4278-b8c0-f26351426021.png)
   - `allow_zip` 을 체크합니다.
   - ![image](https://user-images.githubusercontent.com/1423894/173679698-b2f5d369-182e-41a1-939c-39c40b6a0bd5.png)
2. 모드를 다시 스캔합니다.
   - `file` -> `Re-Scan mods/` 를 선택합니다.
   - ![image](https://user-images.githubusercontent.com/1423894/173680307-c9d1da5f-9a7e-43af-a933-d53431da27ad.png)
3. Multiverse 를 패치합니다.
   - `FTL-Multiverse` 를 **목록의 첫 번째로 체크합니다**.
   - **Hyperspace 를 체크하지 마세요**
   - FTL Multiverse 호환 모드가 있다면 그 뒤에 배치하고 체크합니다.
   - FTL Multiverse 호환 모드를 제외하면 **선택하지 마세요**. 거의 대부분의 경우L Multiverse 와 충돌합니다. (아주 단순한 UI 모드조차도 충돌하는 경우가 잦습니다. 만약 특정 모드가 호환되는지 알고 싶다면 MV 디스코드에서 질문하실 수 있습니다)
   - 예제: ![image](https://user-images.githubusercontent.com/1423894/173681032-76e9b056-ede6-42f5-ad5a-ffa0fece384a.png)
   - `Patch` 를 선택합니다.
4. [제대로 설치되었는지 확인합니다.](#설치-확인)

### 설치 확인

- 하이퍼스페이스의 DLL 이 제대로 설치되어 있다면, 로딩이 반쯤 진행된 순간부터 FTL 의 우상단에 작은 메시지가 표시될 것입니다: (버전에 따라 내용이 조금씩 다릅니다):
   - ![image](https://user-images.githubusercontent.com/1423894/173682629-6aa843d8-bb36-4a3b-afad-bd6b23463a8a.png)

- 또한 슬립스트림 모드 매니저로 모드를 제대로 설치되었다면, 별도의 에러 메시지 없이 모드의 메인 메뉴를 볼 수 있을 것입니다.

- 아래는 Multiverse 5.2.3 이 설치된 모습입니다:
   - ![image](https://user-images.githubusercontent.com/1423894/173683306-2b92a3e2-d0d2-4bff-ac19-33ff6ef0a749.png)

- 아래는 FTL Strawberry Edition 이 설치된 모습입니다:
   - ![image](https://user-images.githubusercontent.com/1423894/173683567-598bc5fe-a7f8-4bad-8dd1-2b6ff161d695.png)

- 아래는 별도의 모드 없이 FTL Hyperspace 만 설치된 모습입니다:
   - ![image](https://user-images.githubusercontent.com/1423894/173684224-64a24d41-e5ae-4c52-b45f-82fafb42abea.png)



### 잘못 설치된 경우

- 만약 모드의 메인 메뉴는 떴지만 우상단에 버전 정보가 없다면, DLL 설치가 잘못된 것입니다.

- `AcheivementTracker` 에러가 뜬다면 FTL 을 1.6.9 로 성공적으로 다운그레이드하지 못한 것입니다.

- `hyperspace.xml` 이 없다는 에러가 뜬다면 `Hyperspace.ftl` 도 `Multiverse` 도 전부 슬립스트림으로 패치하지 않은 것입니다. (둘 중 하나가 설치되어 있어야 합니다)

- Multiverse 와 Hyperspace 를 동시에 패치했다는 에러가 뜬다면, 슬립스트림에서 두 개를 동시에 체크했거나, 혹은 `ftl.dat` 파일이 바닐라가 아닌 상태로 슬립스트림이 설치되어 잘못된 데이터를 기준으로 패치된 것일 가능성이 높습니다.
