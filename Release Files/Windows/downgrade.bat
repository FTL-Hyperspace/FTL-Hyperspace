@pushd %~dp0
copy FTLGame.exe FTLGame_orig.exe
"%CD%/patch/flips.exe" -a "%CD%/patch/patch-1.6.22.bps" "%CD%/FTLGame.exe"
"%CD%/patch/flips.exe" -a "%CD%/patch/patch-1.6.14.bps" "%CD%/FTLGame.exe"
@pause
@popd
